#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7fcf9183, "struct_module" },
	{ 0x124064bf, "skb_queue_head" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xf9a482f9, "msleep" },
	{ 0x4b8edde9, "complete_and_exit" },
	{ 0x17a142df, "__copy_from_user" },
	{ 0x2279c877, "plat_disable_wlan_slot" },
	{ 0x1b9981cc, "set_irq_wake" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xa5423cc4, "param_get_int" },
	{ 0x98082893, "__copy_to_user" },
	{ 0x7e531cde, "del_timer" },
	{ 0x97255bdf, "strlen" },
	{ 0x382782f5, "wake_lock_destroy" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x8728140, "malloc_sizes" },
	{ 0x222ec8d4, "sdio_writesb" },
	{ 0x9d360fb4, "sdio_enable_func" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xeb8aaa2c, "sdio_claim_irq" },
	{ 0x1d67ad82, "gpio_clear_detect_status" },
	{ 0x8d5ca6da, "mmc_wait_for_cmd" },
	{ 0xdc2d6493, "netif_carrier_on" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0x912893f, "skb_copy" },
	{ 0xeeb1717c, "param_array_get" },
	{ 0x95bb830, "down_interruptible" },
	{ 0x31c4f073, "netif_carrier_off" },
	{ 0x353e3fa5, "__get_user_4" },
	{ 0x1a41a5ed, "wake_lock" },
	{ 0x6740c1a9, "filp_close" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x999e8297, "vfree" },
	{ 0x28118cb6, "__get_user_1" },
	{ 0xcb32da10, "param_set_int" },
	{ 0x4f099aa5, "wake_unlock" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xab471003, "param_array_set" },
	{ 0x7d11c268, "jiffies" },
	{ 0x16aae5ed, "skb_trim" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xe70877bb, "netif_rx" },
	{ 0xf2afa595, "param_get_charp" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0x25fa6f17, "wait_for_completion" },
	{ 0xfa2a45e, "__memzero" },
	{ 0xb5eeb329, "register_early_suspend" },
	{ 0x5f754e5a, "memset" },
	{ 0x3db443bd, "alloc_etherdev_mq" },
	{ 0x3a419bbd, "netif_rx_ni" },
	{ 0x2ff476d0, "dev_alloc_skb" },
	{ 0xea147363, "printk" },
	{ 0xd4b629a6, "plat_enable_wlan_slot" },
	{ 0x71c90087, "memcmp" },
	{ 0xe52592a, "panic" },
	{ 0x328a05f1, "strncpy" },
	{ 0xc40f91c2, "gpio_set_value" },
	{ 0x96a98b8d, "register_netdev" },
	{ 0xa8f59416, "gpio_direction_output" },
	{ 0x3dc02c00, "wireless_send_event" },
	{ 0xe6423ed4, "skb_push" },
	{ 0x69496641, "mod_timer" },
	{ 0xc8f54bab, "platform_driver_register" },
	{ 0x43b0c9c3, "preempt_schedule" },
	{ 0xa7f78c48, "skb_pull" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0x61651be, "strcat" },
	{ 0xdd45b023, "sdio_readsb" },
	{ 0x41f11b59, "sdio_unregister_driver" },
	{ 0x4ae7b2ed, "skb_queue_tail" },
	{ 0x3ff62317, "local_bh_disable" },
	{ 0xdc74cc24, "kmem_cache_alloc" },
	{ 0xbc10dd97, "__put_user_4" },
	{ 0x16a012cd, "sdio_release_irq" },
	{ 0x2cf190e3, "request_irq" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0x68b193b6, "kfree_skb" },
	{ 0x799aca4, "local_bh_enable" },
	{ 0x5143d4b1, "eth_type_trans" },
	{ 0x78fe2a8, "wake_up_process" },
	{ 0xd8ab500, "param_set_copystring" },
	{ 0x57b5480b, "ether_setup" },
	{ 0x6cb34e5, "init_waitqueue_head" },
	{ 0x366bdeaa, "init_timer" },
	{ 0x8785725d, "param_set_charp" },
	{ 0xb6c70a7d, "__wake_up" },
	{ 0x8b719a0e, "emulate_domain_manager_set" },
	{ 0x992cd8a1, "sdio_memcpy_toio" },
	{ 0xfe990052, "gpio_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x103469c8, "kthread_create" },
	{ 0x9d669763, "memcpy" },
	{ 0x89e9d8e5, "wake_lock_init" },
	{ 0x8085c7b1, "prepare_to_wait" },
	{ 0x4f0ea0c0, "up" },
	{ 0x51493d94, "finish_wait" },
	{ 0xb227ae83, "unregister_early_suspend" },
	{ 0xfd39e1a0, "skb_dequeue" },
	{ 0xb26d77d4, "unregister_netdev" },
	{ 0x701d0ebd, "snprintf" },
	{ 0x8fba79c7, "__netif_schedule" },
	{ 0x3cb8a495, "param_get_string" },
	{ 0xb6db4f85, "sdio_register_driver" },
	{ 0x205a1915, "sdio_memcpy_fromio" },
	{ 0x191d9f68, "sdio_claim_host" },
	{ 0x22dbc230, "platform_driver_unregister" },
	{ 0x312d024b, "skb_put" },
	{ 0x46b79a43, "sdio_set_block_size" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xc3d9e228, "sdio_disable_func" },
	{ 0xf20dabd8, "free_irq" },
	{ 0xe68d917, "sdio_release_host" },
	{ 0xe914e41e, "strcpy" },
	{ 0xd2eed17a, "filp_open" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("sdio:c*v0271d0200*");
MODULE_ALIAS("sdio:c*v0271d0201*");
MODULE_ALIAS("sdio:c*v0271d0300*");