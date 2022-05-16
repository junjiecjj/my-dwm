
//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
        /*Icon*/        /*Command*/                       /*Update Interval*/     /*Update Signal*/
        {" ",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/wlan.sh",             1,              0}, //网速
        {" ",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/cpu.sh",              5,              0}, //cpu占用率
        {" ",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/memory.sh",           3,              0}, //内存占用率
        {"🔊",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/volume.sh",           0,              11}, //音量
        {"ﯦ ",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/backlight.sh",        0,              11}, //亮度
        {"🔌🔋",        "/home/jack/tmp/my-dwm/dwmblocks/scripts/battery.sh",          2,              0}, //电量
        {"",           "/home/jack/tmp/my-dwm/dwmblocks/scripts/date.sh",             1,              0}, //时间
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static int delimLen = 5;
