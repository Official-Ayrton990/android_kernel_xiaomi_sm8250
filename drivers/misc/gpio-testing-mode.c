#include <linux/device.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/wait.h>
#include <linux/types.h>
#include <linux/device.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/poll.h>
#include <linux/slab.h>
#include <linux/pm_wakeirq.h>
#include <linux/irq.h>
#include <linux/interrupt.h>

struct testing_mode_data {
	struct device *dev;
	int debounce_time;
	int status_gpio;
	int gpio_status;
	int irq;
	struct delayed_work debounce_work;
};

MODULE_AUTHOR("Tao Jun<taojun@xiaomi.com>");
MODULE_DESCRIPTION("A dummy driver for GPIO testing mode");
MODULE_LICENSE("GPL");
