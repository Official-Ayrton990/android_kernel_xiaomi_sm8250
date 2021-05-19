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

static ssize_t gpio_status_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct testing_mode_data *data = dev_get_drvdata(dev);

	return scnprintf(buf, PAGE_SIZE, "%d\n", gpio_get_value(data->status_gpio));
}
static DEVICE_ATTR(status, S_IRUGO, gpio_status_show, NULL);


static void gpio_debounce_work(struct work_struct *work)
{
	return;
}
static irqreturn_t testing_threaded_irq_handler(int irq, void *irq_data)
{
	return IRQ_HANDLED;
}

static int testing_mode_probe(struct platform_device *pdev)
{
	return 0;
}

static int testing_mode_remove(struct platform_device *pdev)
{
	return 0;
}

MODULE_AUTHOR("Tao Jun<taojun@xiaomi.com>");
MODULE_DESCRIPTION("A dummy driver for GPIO testing mode");
MODULE_LICENSE("GPL");
