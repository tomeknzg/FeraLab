#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/hrtimer.h>
#include <linux/delay.h>
#include <mach/hardware.h>
#include <linux/io.h>
#include <asm/system.h>
#include <asm/mach-types.h>
#include <linux/semaphore.h>
#include <linux/spinlock.h>
#include <linux/fb.h>
#include "mdp.h"
#include "msm_fb.h"

extern spinlock_t mdp_spin_lock;
extern uint32 mdp_intr_mask;

int mdp_dma3_on(struct platform_device *pdev)
{
	struct msm_fb_data_type *mfd;
	struct fb_info *fbi;
	uint8 *buf;
	int bpp;
	int ret = 0;

	mfd = (struct msm_fb_data_type *)platform_get_drvdata(pdev);

	if (!mfd)
		return -ENODEV;

	if (mfd->key != MFD_KEY)
		return -EINVAL;

	fbi = mfd->fbi;
	mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_ON, FALSE);
	bpp = fbi->var.bits_per_pixel / 8;
	buf = (uint8 *) fbi->fix.smem_start;
	buf += calc_fb_offset(mfd, fbi, bpp);
	MDP_OUTP(MDP_BASE + 0xC0008, (uint32) buf >> 3);
	mdp_pipe_ctrl(MDP_DMA3_BLOCK, MDP_BLOCK_POWER_ON, FALSE);
	MDP_OUTP(MDP_BASE + 0xC0004, 0x4c60674);
	MDP_OUTP(MDP_BASE + 0xC0010, 0x20);
	MDP_OUTP(MDP_BASE + 0xC0018, 0xeb0010);
	MDP_OUTP(MDP_BASE + 0xC001C, 0xf00010);
	MDP_OUTP(MDP_BASE + 0xC0020, 0xf00010);
	MDP_OUTP(MDP_BASE + 0xC000C, 0x67686970); 
	MDP_OUTP(MDP_BASE + 0xC0000, 0x1);
	mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_OFF, FALSE);
	ret = panel_next_on(pdev);
	return ret;
}

int mdp_dma3_off(struct platform_device *pdev)
{
	int ret = 0;

	ret = panel_next_off(pdev);
	if (ret)
		return ret;

	mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_ON, FALSE);
	MDP_OUTP(MDP_BASE + 0xC0000, 0x0);
	mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_OFF, FALSE);
	mdp_pipe_ctrl(MDP_DMA3_BLOCK, MDP_BLOCK_POWER_OFF, FALSE);
	mdelay(100);
	return ret;
}

void mdp_dma3_update(struct msm_fb_data_type *mfd)
{
	struct fb_info *fbi = mfd->fbi;
	uint8 *buf;
	int bpp;
	unsigned long flag;

	if (!mfd->panel_power_on)
		return;

	bpp = fbi->var.bits_per_pixel / 8;
	buf = (uint8 *) fbi->fix.smem_start;
	buf += calc_fb_offset(mfd, fbi, bpp);
	MDP_OUTP(MDP_BASE + 0xC0008, (uint32) buf >> 3);
	spin_lock_irqsave(&mdp_spin_lock, flag);
	mdp_enable_irq(MDP_DMA3_TERM);
	INIT_COMPLETION(mfd->dma->comp);
	mfd->dma->waiting = TRUE;
	outp32(MDP_INTR_CLEAR, TV_OUT_DMA3_START);
	mdp_intr_mask |= TV_OUT_DMA3_START;
	outp32(MDP_INTR_ENABLE, mdp_intr_mask);
	spin_unlock_irqrestore(&mdp_spin_lock, flag);
	wait_for_completion_killable(&mfd->dma->comp);
	mdp_disable_irq(MDP_DMA3_TERM);
}

