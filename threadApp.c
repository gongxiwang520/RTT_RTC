#include <rtthread.h>
#include <rtdevice.h>


/*
 * 程序清单：这是一个 RTC 设备使用例程
 * 例程导出了 rtc_sample 命令到控制终端
 * 命令调用格式：rtc_sample
 * 程序功能：设置RTC设备的日期和时间，延时一段时间后获取当前时间并打印显示。
*/


static int rtc_sample(int argc, char *argv[])
{
  rt_err_t ret = RT_EOK;
  time_t now;

  // 设置日期
  ret = set_date(2018, 12, 3);
  if (ret != RT_EOK)
  {
    rt_kprintf("set RTC date failed.\n");
    return ret;
  }

  ret = set_time(11, 15, 50);
  if (ret != RT_EOK)
  {
    rt_kprintf("set RTC time failed.\n");
    return ret;    
  }

  rt_thread_mdelay(3000);

  now = time(RT_NULL);
  rt_kprintf("%s\n", ctime(&now));

  return ret;
}



MSH_CMD_EXPORT(rtc_sample, rtc sample);


