/*//Modify this file to change what commands output to your statusbar, and recompile using the make command.*/
/*static const Block blocks[] = {*/
/*	Icon	Command*		*Update Interval*	*Update Signal*/
/*	{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},*/

/*	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},*/
/*};*/

/*//sets delimeter between status commands. NULL character ('\0') means no delimeter.*/
/*static char delim[] = " | ";*/
/*static unsigned int delimLen = 5;*/





//Modify this file to change what commands output to your statusbar, and recompile using the make command.ð§ ð§­
static const Block blocks[] = {
        /*Icon*/        /*Command*/                                             /*Update Interval*/            /*Update Signal*/
        {"ï« ",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/wlan.sh",             1,              0}, //ç½é
        {"ï:",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/cpu.sh",              5,              0}, //cpuå ç¨ç
        {"ð»:",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/memory.sh",           3,              0}, //åå­å ç¨ç
        {"",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/volume.sh",           0,              11}, //é³é
        {"ï¯¦ ",          "/home/jack/tmp/my-dwm/dwmblocks/scripts/backlight.sh",        0,              11}, //äº®åº¦
        {"",        "/home/jack/tmp/my-dwm/dwmblocks/scripts/battery.sh",            2,              0}, //çµé
        {"ð",           "/home/jack/tmp/my-dwm/dwmblocks/scripts/date.sh",             1,              0}, //æ¶é´
};

//ðððð§ððºðï³ð»ï¡sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static int delimLen = 5;
