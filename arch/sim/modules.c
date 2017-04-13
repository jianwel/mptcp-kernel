#include "sim-assert.h"
#include <linux/moduleparam.h>
#include <linux/kmod.h>
#include <linux/module.h>

int modules_disabled = 0;
char modprobe_path[KMOD_PATH_LEN] = "/sbin/modprobe";

static struct kernel_param g_empty_param_buffer;
static struct module_version_attribute g_empty_attr_buffer;
// we make the array empty by default because, really, we don't need
// to look at the builtin params
struct kernel_param *__start___param = &g_empty_param_buffer;
struct kernel_param *__stop___param = &g_empty_param_buffer;
const struct module_version_attribute *__start___modver[] = {&g_empty_attr_buffer};
const struct module_version_attribute *__stop___modver[] = {&g_empty_attr_buffer};

struct module_attribute module_uevent;
struct ctl_table usermodehelper_table[] = {};

int __request_module(bool wait, const char *fmt, ...)
{
  // we really should never be trying to load modules that way.
  //  sim_assert (false);
  return 0;
}
