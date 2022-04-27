# jjchen's build of dwm

```c
/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL};
static const char *roficmd[] = {"rofi", "-show", "drun", NULL};
static const char *termcmd[] = {"st", NULL};
static const char *xtermcmd[] = {"xterm", NULL};
static const char *typoracmd[] = {"typora", NULL};
static const char *browsercmd[] = {"google-chrome-stable", NULL};
static const char *trayercmd[] = {"/home/jack/scripts/trayer-toggle.sh", NULL};
static const char *upvol[] = {"/home/jack/scripts/vol-up.sh", NULL};
static const char *downvol[] = {"/home/jack/scripts/vol-down.sh", NULL};
static const char *mutevol[] = {"/home/jack/scripts/vol-toggle.sh", NULL};
//static const char *wpcmd[] = {"/home/jack/scripts/wp-change.sh", NULL};
static const char *wpcmd[] = {"feh", "--recursive", "--randomize", "--bg-fill", "~/图片/", NULL};      
static const char *sktogglecmd[] = {"/home/jack/scripts/sck-tog.sh", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = {"st", "-t", scratchpadname, "-g", "120x34", NULL};
static const char *setcolemakcmd[] = {"/home/jack/scripts/setxmodmap-colemak.sh", NULL};
static const char *setqwertycmd[] = {"/home/jack/scripts/setxmodmap-qwerty.sh", NULL};
//static const char *suspendcmd[] = {"/home/jack/scripts/suspend.sh", NULL};
static const char *suspendcmd[] = {"systemctl","suspend", NULL};
static const char *screenshotcmd[] = {"flameshot", "gui", NULL};
 static const char *slockcmd[] = { "slock", NULL };
//以下是增加的
static const char *volup[] = {"amixer", "-qM", "set", "Master", "2%+", "umute", NULL};
static const char *voldown[] = {"amixer", "-qM", "set", "Master", "2%-", "umute", NULL}; //#定义系统音量大小调节的快捷键功能
static const char *mute[] = {"amixer", "-qM", "set", "Master", "toggle", NULL};			 //#定义开 / 关静音的快捷键功能
static const char *lightup[] = {"xbacklight", "-inc", "2", NULL};
static const char *lightdown[] = {"xbacklight", "-dec", "2", NULL};					  //#定义屏幕亮度调节的快捷键功能
static const char *chromium[] = {"google-chrome-stable", "--disk-cache-dir=/tmp/google-chrome-stable", NULL}; //#定义chrome浏览器的快捷键功能
static const char *dolphin[] = {"dolphin", NULL};	 	  //#定义dolphin文件管理器的快捷键功能
static const char *nautilus[] = {"nautilus", NULL};	 	  //#定义dolphin文件管理器的快捷键功能
static const char *slimlockcmd[]  = { "slimlock", NULL };


static Key keys[] = {
	// modifier            key                      function        argument 
    { MODKEY,              XK_s,                    spawn,          {.v = dmenucmd } }, // win+s打开 dmen 面板（应用菜单）呼出dmenu应用程序启动器
    { MODKEY,              XK_r,                    spawn,          {.v = roficmd } }, // win+r打开 rofi 面板（应用菜单）呼出dmenu应用程序启动器
    { 0,                   XK_Print,                spawn,          {.v = screenshotcmd } },  //PrtSc 截图
    { MODKEY,              XK_f,                    spawn,          {.v = screenshotcmd } },  //win+f  截图
    { MODKEY,              XK_Return,               spawn,          {.v = termcmd } },// win+回车新建一个窗格，（开一个终端应用（st））
    { MODKEY,              XK_grave,                togglescratch,  {.v = scratchpadcmd } },//win+` 打开一个命令行终端小窗格窗口
    { MODKEY,              XK_x,                    spawn,          {.v = xtermcmd } },// win+x 新建一个窗格，（开一个终端应用（xterm））
    { MODKEY,              XK_t,                    spawn,          {.v = typoracmd } },// win+t 新建一个窗格，（开一个终端应用（typora））
    { MODKEY,              XK_c,                    spawn,          {.v = browsercmd } },// win+c 呼出chromium浏览器
    { MODKEY|ShiftMask,    XK_t,                    spawn,          {.v = trayercmd } },// win+shift+t 呼出系统托盘
    { MODKEY|ShiftMask,    XK_s,                    spawn,          {.v = sktogglecmd } },//调出screenkey
    // { MODKEY|Mod1Mask,     XK_l,                    spawn,          {.v = slockcmd } },//锁屏
    { MODKEY|Mod1Mask,     XK_l,                    spawn,          SHCMD("slock") },  //锁屏
    { 0,                   XF86XK_AudioLowerVolume, spawn,          {.v = downvol } },//降低音量
    { 0,                   XF86XK_AudioMute,        spawn,          {.v = mutevol } },  //静音
    { 0,                   XF86XK_AudioRaiseVolume, spawn,          {.v = upvol   } },//增加音量
    { MODKEY,              XK_bracketleft,          spawn,          {.v = downvol } },// win+[ 降低音量
    { MODKEY,              XK_backslash,            spawn,          {.v = mutevol } },// win+\ 静音
    { MODKEY,              XK_bracketright,         spawn,          {.v = upvol   } },// win+] 增加音量
    { MODKEY|ControlMask,  XK_b,                    spawn,          {.v = wpcmd } }, //win+b换壁纸
    //{ MODKEY|ShiftMask|ControlMask,    XK_q,        spawn,          {.v = setqwertycmd } },//win+shift+ctrl+q 键盘模式为qwerty
    //{ MODKEY|ShiftMask|ControlMask,    XK_c,        spawn,          {.v = setcolemakcmd } },//win+shift+ctrl+c 键盘模式为colemal
    { MODKEY|ControlMask,  XK_s,                    spawn,          {.v = suspendcmd } },  // win+ctrl+s休眠
    { MODKEY|ShiftMask,    XK_j,                    rotatestack,    {.i = +1 } }, 	//顺时针循环滚动当前窗口的窗格位置	
    { MODKEY|ShiftMask,    XK_k,                    rotatestack,    {.i = -1 } },	//逆时针循环滚动当前窗口的窗格位置
    { MODKEY,              XK_Up,                   focusstack,     {.i = +1 } },	//将光标焦点移动到下一个窗格
    { MODKEY,              XK_Down,                 focusstack,     {.i = -1 } },   	//将光标焦点移动到上一个窗格 
    { MODKEY,              XK_j,                    incnmaster,     {.i = +1 } },	//插入主窗格的堆栈，窗口竖向排列
    { MODKEY,              XK_k,                    incnmaster,     {.i = -1 } },	//减少主窗格的堆栈数，窗口横向排列
    { MODKEY,              XK_Left,                 setmfact,       {.f = -0.03} },	//将当前的窗格宽度减向左扩展或缩小
    { MODKEY,              XK_Right,                setmfact,       {.f = +0.03} },   	// win+左/右方向键，调整程序窗口的大小
    { MODKEY,              XK_m,                    hidewin,        {0} }, 	// win+m 最小化/隐藏藏 当前窗格
    { MODKEY|ShiftMask,    XK_m,                    restorewin,     {0} }, 	// win+shift+m 恢复当前窗口下隐藏的窗格,非全部，一次一个恢复
    { MODKEY,              XK_o,                    hideotherwins,  {0}},  	// win+ o 最小化/隐藏藏除当前外的其他窗格
    { MODKEY|ShiftMask,    XK_o,                    restoreotherwins, {0}},	// win+shift+o 恢复当前窗口下隐藏除当前外的其他窗格
    { MODKEY|ShiftMask,    XK_Return,               zoom,           {0} }, 	//win+shift+回车，窗口位置互换， 将当前窗口与主窗口互换，若是当前是主窗口则将其与上一个窗格互换，并聚焦在主窗格
    { MODKEY,              XK_Tab,                  view,           {0} }, //查看桌面标签。最后参数可以是NULL（全局查看）或是tags[数字]指定的桌面标签
    { MODKEY,              XK_0,                    view,           {.ui = ~0 } },
    { MODKEY|Mod1Mask,     XK_0,                    setlayout,     {.v = &layouts[0]} },
    { MODKEY|Mod1Mask,     XK_1,                    setlayout,     {.v = &layouts[1]} },
    { MODKEY|Mod1Mask,     XK_2,                    setlayout,     {.v = &layouts[2]} },  //将当前窗口的模式改为排版,主格居左，副窗格居右，新增窗格水平分割
    { MODKEY|Mod1Mask,     XK_3,                    setlayout,     {.v = &layouts[3]} },  //
    { MODKEY|Mod1Mask,     XK_4,                    setlayout,     {.v = &layouts[4]} },  //改变当前窗口的模式为浮动
    { MODKEY|Mod1Mask,     XK_5,                    setlayout,     {.v = &layouts[5]} },  //将当前窗口的副窗格堆模式改为垂直排列布局方式,主窗堆在上，副窗堆在下，副窗格垂直分
    { MODKEY|Mod1Mask,     XK_6,                    setlayout,     {.v = &layouts[6]} },  //将当前窗口的副窗格堆布局模式改为底部水平排列局方式,主窗堆在上，副窗堆在下，副窗格水平分割
    { MODKEY|Mod1Mask,     XK_7,                    setlayout,      {.v = &layouts[7]} },  //将当前窗口的副窗格堆模式改为垂直排列布局方式
    { MODKEY|Mod1Mask,     XK_8,                    setlayout,      {.v = &layouts[8]} },  //将当前窗口的窗格模式改为中心排列布局方式,主窗格在中心占大位，副窗口分列在左右水平分割
    { MODKEY,              XK_space,                setlayout,      {0} },   		//窗口模式切换,Alt + 空格,Alt + shift + 空格
    { MODKEY|ShiftMask,    XK_space,                togglefloating, {0} },		//切换是否浮动。最后参数NULL
    { MODKEY,              XK_9,                    setlayout,      {.v = &layouts[9]} },  //将当前窗口的窗格模式改为网格模式,一列两行、两行两列、三行三列..
    { MODKEY|ShiftMask,    XK_f,                    fullscreen,     {0} },  		// win+shift+f全屏
    { MODKEY|ShiftMask,    XK_0,                    tag,            {.ui = ~0 } },	//切换指定的窗口到达指定的桌面标签。最后参数tags[数字]指定的桌面标签
    { MODKEY,              XK_comma,                focusmon,       {.i = -1 } },  	//win+,  在主副屏之间移动焦点# 移动焦点至左边屏幕，
    { MODKEY,              XK_period,               focusmon,       {.i = +1 } },  	//win+.  # 移动焦点至右边屏幕
    { MODKEY|ShiftMask,    XK_comma,                tagmon,         {.i = -1 } },	//win+shift+,  在主副屏之间移动窗口 # 移动窗口至左边屏幕
    { MODKEY|ShiftMask,    XK_period,               tagmon,         {.i = +1 } },	//win+shift+. # 移动窗口至右边屏幕
    { MODKEY,              XK_h,                    viewtoleft,     {0} },
    { MODKEY,              XK_l,                    viewtoright,    {0} },
    { MODKEY|ShiftMask,    XK_h,                    tagtoleft,      {0} },
    { MODKEY|ShiftMask,    XK_l,                    tagtoright,     {0} },
    //{ MODKEY|ShiftMask,    XK_1,             tag,              tags[0] },     //Mod + shift + num,移动窗口至某标签页
    //{ MODKEY|ShiftMask,    XK_2,             tag,              tags[1] },
    //{ MODKEY|ShiftMask,    XK_3,             tag,              tags[2] },
    //{ MODKEY|ShiftMask,    XK_4,             tag,              tags[3] },
    //{ MODKEY|ShiftMask,    XK_5,             tag,              tags[4] },
	TAGKEYS(               XK_1,                      0)     // win+1/2/3/4/5/6/7/8/9，切换到不同的dwm顶部菜单栏的标签里,切换标签页
	TAGKEYS(               XK_2,                      1)
	TAGKEYS(               XK_3,                      2)
	TAGKEYS(               XK_4,                      3)
	TAGKEYS(               XK_5,                      4)
	TAGKEYS(               XK_6,                      5)
	TAGKEYS(               XK_7,                      6)
	TAGKEYS(               XK_8,                      7)
	TAGKEYS(               XK_9,                      8)
    { MODKEY|Mod1Mask,     XK_Down,                spawn,          SHCMD("transset-df -a --dec .1") },  //减少当前窗格应用的透明度
    { MODKEY|Mod1Mask,     XK_Up,                  spawn,          SHCMD("transset-df -a --inc .1") },  //增加当前窗格应用的透明度
    { MODKEY|Mod1Mask,     XK_Home,                spawn,          SHCMD("transset-df -a .75") },  //恢复当前窗格应用的初始默认的透明度
    { MODKEY|ShiftMask,    XK_q,                   killclient,     {0} },	//关闭当前窗口，强制关闭窗口。最后参数NULL
    { MODKEY|ControlMask,  XK_Escape,              quit,           {0} }, 	//Ctrl+Alt+del，关闭并退出整个dwm桌面，且强制关闭所有当前运行于dwm下的程序
    //以下是增加的
    { MODKEY|ControlMask,   XK_l,                    spawn,          {.v = slimlockcmd } },  //锁屏
    { MODKEY|ShiftMask,     XK_Up,                   spawn,          {.v = lightup} },
    { MODKEY|ShiftMask,     XK_Down,                 spawn,          {.v = lightdown} },  // Shift+win+上/下方向键，调整屏幕亮度
    { MODKEY|ShiftMask,     XK_Right,                spawn,          {.v = volup} },
    { MODKEY|ShiftMask,     XK_Left,                 spawn,          {.v = voldown} },   // Shift+win+左/右方向键，调整音量大小
    { MODKEY|ShiftMask,     XK_m,                    spawn,          {.v = mute} },  	   // Shift+win+m，开启/关闭静音
    { MODKEY,               XK_d,                    spawn,          {.v = dolphin } },   // win+d，呼出dolphin文件管理器
    { MODKEY,               XK_n,                    spawn,          {.v = nautilus } },   // win+d，呼出dolphin文件管理器
    { MODKEY,               XK_g,                    spawn,          {.v = chromium } },   // win+j，呼出chromium浏览器
};

```




# David's build of dwm
============================
[中文版](./README_cn.md)

dwm is an extremely fast, small, and dynamic window manager for X.

BTW, my scripts are in [this repo](https://github.com/theniceboy/scripts).

Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install

Patches applied
---------------
- [dwm-alpha-20180613-b69c870.diff](https://dwm.suckless.org/patches/alpha/)
- [dwm-autostart-20161205-bb3bd6f.diff](https://dwm.suckless.org/patches/autostart/)
- [dwm-awesomebar-20191003-80e2a76.diff](https://dwm.suckless.org/patches/awesomebar/)
- [dwm-fullscreen-6.2.diff](https://dwm.suckless.org/patches/fullscreen/)
- [dwm-hide-and-restore.diff](https://github.com/theniceboy/dwm-hide-and-restore-win.diff) (a custom patch I wrote)
- [dwm-hide_vacant_tags-6.2.diff](https://dwm.suckless.org/patches/hide_vacant_tags/)
- [dwm-noborder-6.2.diff](https://dwm.suckless.org/patches/noborder/)
- [dwm-pertag-20170513-ceac8c9.diff](https://dwm.suckless.org/patches/pertag/)
- [dwm-r1522-viewontag.diff](https://dwm.suckless.org/patches/viewontag/)
- [dwm-rotatestack-20161021-ab9571b.diff](https://dwm.suckless.org/patches/rotatestack/)
- [dwm-scratchpad-6.2.diff](https://dwm.suckless.org/patches/scratchpad/)
- [dwm-vanitygaps-20190508-6.2.diff](https://dwm.suckless.org/patches/vanitygaps/)


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


