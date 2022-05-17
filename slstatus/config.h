/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * separator           string to echo                  NULL
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */

static const char wk[] = "wlp59s0";

static const struct arg args[] = {
	/* function format          argument */
	/* { cpu_perc, "[CPU %s%%]", NULL    }, */
	/* { ram_perc, "[RAM %s%%]", NULL    }, */
	/* { wifi_perc, "[WIFI %s%%]", "wlp59s0"    }, */
	/* { wifi_essid, "[NET %s]", "wlp59s0"    }, */
	/* { battery_perc, "[BAT %2s%%]", "BAT0"    }, */
	/* { battery_state, "[CHR %s]", "BAT0"    }, */
	/* { disk_perc, "[HD %s%%]", "/"    }, */
	/* { datetime, "[%s]", "%F %H:%M" }, */

    // 函数           格式           参数
	{ netspeed_rx,     "⬇️:%s ",           wk   },
	{ netspeed_tx,     "⬆️:%s",            wk    },
    // 用 "|" 间隔两项信息；参数 NULL 表示空，就是没有参数
    { separator,      "|",                NULL },
    // %s 代表 ipv4 的值；参数需要用双引号引起来，不能是单引号，
	{ wifi_essid,     ":%s@",            wk   },
    { ipv4,           "%s",               wk },
    /* { ipv6,           "IPV6:%s",         "wlp59s0" }, */
	{ wifi_perc,      "-%s%% ",           wk  },
    // 因为 C 语言里单引号内的是字符常量，双引号内的是字符串常量，两者不一样。
    { separator,      "|",                 NULL },
    { battery_perc,    "🔌:%s%% ",        "BAT0" },
    // 在 C 语言里 "%" 需要转义，用 "%%" 来表示💻🔋🔌🕑 
    /* { battery_state,   "🔌:%s",          "BAT0" }, */
    { separator,      "|",               NULL },
    { disk_free,       "⛁/:%s",            "/" },
    { disk_total,      "/%s",              "/" },
    /* { disk_free,       "/home:%s",         "/home" }, */
    /* { disk_total,      "/%s]",              "/home" }, */
	/* { disk_perc,      "[HD %s%%]",       "/"  }, */
    { separator,      "|",               NULL },
    { ram_used,        "💻:%s",          NULL },
    { ram_total,       "/%s",               NULL },
    /* { swap_used,       ":%s",         NULL }, */
    /* { swap_total,      "/%s",             NULL }, */
    { separator,       "|",                NULL },
    { cpu_perc,        "CPU:%s%%",         NULL },
    /* { cpu_freq,        "/%s%%",            NULL }, */
    { separator,       "|",                NULL },
    /* { vol_perc,        "🔊 %s",         "/dev/mixer" }, */
    /* { separator,       "|",              NULL }, */
    { datetime,        "🕑%s",            "%Y-%m-%d/%u %H:%M:%S" },

};
