#include <X11/XF86keysym.h>
#include "grid.c"
/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const unsigned int gappih    = 3;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 3;       /* vert inner gap between windows */
static const unsigned int gappoh    = 3;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 3;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */
// static const char *fonts[]          = { "JetBrains Mono:size=12" }; //[>设置dwm采用图标字体<]
// static const char *fonts[]          = { "Fira Code:size=12" };
// static const char *fonts[]          = { "FiraCode Nerd Font:size=12" };
// static const char *fonts[]          = { "FiraCode Nerd Font Mono:size=12" };
// static const char *fonts[]          = { "JetBrainsMono Nerd Font Mono:size=12" };
// static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=12" };
// static const char *fonts[]          = { "YaHei Consolas Hybrid:size=12" };
// static const char *fonts[]          = { "Cascadia Code SemiLight:size=12" };
// static const char *fonts[]          = { "Cascadia Code ExtraLight:size=12" };
// static const char *fonts[]          = { "CaskaydiaCove Nerd Font:style=Regular:size=12" };
// static const char *fonts[]          = { "CaskaydiaCove Nerd Font:style=SemiLight:size=12" };
// static const char *fonts[]          = { "CaskaydiaCove Nerd Font:style=Light:size=12" };
// static const char *fonts[]          = { "CaskaydiaCove Nerd Font:style=ExtraLight:size=12" };
// static const char *fonts[]          = { "CaskaydiaCove Nerd Font Mono:style=Regular:size=12" };
static const char *fonts[]          = { "CaskaydiaCove Nerd Font Mono:style=SemiLight:size=12" };
// static const char *fonts[]          = { "CaskaydiaCove Nerd Font Mono:style=Light:size=12" };
// static const char *fonts[]          = { "CaskaydiaCove Nerd Font Mono:style=ExtraLight:size=12" };
// static const char *fonts[]          = { "SauceCodePro Nerd Font:size=12" };
// static const char *fonts[]          = { "SauceCodePro Nerd Font Mono:size=12" };

// static const char dmenufont[]       = "JetBrains Nerd Font Mono:size=12";
// static const char dmenufont[]       = "SauceCodePro Nerd Font Mono:size=12";
static const char dmenufont[]       = "CaskaydiaCove Nerd Font Mono:style=SemiLight:size=12";

static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#ffffff";
static const char col_cyan[]        = "#37474F";
static const char col_border[]        = "#42A5F5";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_border  },
	[SchemeHid]  = { col_cyan,  col_gray1, col_border  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
// static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
static const char *tags[] = { "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };
// static const char *tags[] = { "\uf120", "\uf7ae", "\uf121", "\uf04b", "\ue62e", "\uf251", "\ue727", "\uf537", "\uf684" };  [>图标对应的ASCLL码：https://www.nerdfonts.com/cheat-sheet<]

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                  instance    title       tags mask     isfloating   monitor */
	{ "Gimp",                 NULL,       NULL,       0,            1,           -1 },
	{ "Android Emulator",     NULL,       NULL,       0,            1,           -1 },
	{ "Emulator",             NULL,       NULL,       0,            1,           -1 },
	{ "quemu-system-i386",    NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",              NULL,       NULL,       1 << 8,       0,           -1 },
	{ "google-chrome-stable", NULL,       NULL,       1 << 8,       0,           -1 },
	{ "google-chrome",        NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },

	{ "[]{",      tile },    /* first entry is default */
	{ ">v<",      NULL },    /* no layout function means floating behavior */
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "HHH",      grid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL};
static const char *roficmd[] = {"rofi", "-show", "drun", NULL};
static const char *termcmd[] = {"st", NULL};
static const char *xtermcmd[] = {"xterm", NULL};
static const char *typoracmd[] = {"typora", NULL};
static const char *browsercmd[] = {"google-chrome-stable", NULL};
static const char *trayercmd[] = {"~/tmp/my-dwm/scripts/trayer-toggle.sh", NULL};
static const char *upvol[] = {"~/tmp/my-dwm/scripts/vol-up.sh", NULL};
static const char *downvol[] = {"~/tmp/my-dwm/scripts/vol-down.sh", NULL};
static const char *mutevol[] = {"~/tmp/my-dwm/scripts/vol-toggle.sh", NULL};
static const char *wpcmd[] = {"bash", "~/tmp/my-dwm/scripts/wp-change.sh", NULL};
/* static const char *wpcmd[] = {"feh", "--recursive", "--randomize", "--bg-fill", "~/图片/Wallpapers/", NULL}; */
static const char *sktogglecmd[] = {"~/tmp/my-dwm/scripts/sck-tog.sh", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = {"st", "-t", scratchpadname, "-g", "120x34", NULL};
static const char *setcolemakcmd[] = {"~/tmp/my-dwm/scripts/setxmodmap-colemak.sh", NULL};
static const char *setqwertycmd[] = {"~/tmp/my-dwm/setxmodmap-qwerty.sh", NULL};
//static const char *suspendcmd[] = {"~/tmp/my-dwm/scripts/suspend.sh", NULL};
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
static const char *slocklockcmd[]  = { "slock", NULL };
static const char *xscreensaverlockcmd[]  = { "xscreensaver", NULL };



static Key keys[] = {
	/* modifier            key                      function        argument */
    { MODKEY,              XK_s,                    spawn,          {.v = dmenucmd } }, // win+s打开 dmen 面板（应用菜单）呼出dmenu应用程序启动器
    { MODKEY,              XK_r,                    spawn,          {.v = roficmd } }, // win+s打开 dmen 面板（应用菜单）呼出dmenu应用程序启动器
    { 0,                   XK_Print,                spawn,          {.v = screenshotcmd } },  //PrtSc 截图
    { MODKEY,              XK_f,                    spawn,          {.v = screenshotcmd } },  //win+f  截图
    { MODKEY,              XK_Return,               spawn,          {.v = termcmd } },// win+回车新建一个窗格，（开一个终端应用（st））
    { MODKEY,              XK_grave,                togglescratch,  {.v = scratchpadcmd } },//win+` 打开一个命令行终端小窗格窗口
    { MODKEY,              XK_x,                    spawn,          {.v = xtermcmd } },// win+x 新建一个窗格，（开一个终端应用（xterm））
    { MODKEY,              XK_t,                    spawn,          {.v = typoracmd } },// win+t 新建一个窗格，（开一个终端应用（typora））
    { MODKEY,              XK_c,                    spawn,          {.v = browsercmd } },// win+c 呼出chromium浏览器
    { MODKEY|ShiftMask,    XK_t,                    spawn,          {.v = trayercmd } },// win+shift+t 呼出系统托盘
    { MODKEY|ShiftMask,    XK_s,                    spawn,          {.v = sktogglecmd } },//调出screenkey
	{ MODKEY|Mod1Mask,     XK_l,                    spawn,          SHCMD("slock") },  //减少当前窗格应用的透明度
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
    { MODKEY|ShiftMask,    XK_j,                    rotatestack,    {.i = +1 } }, //顺时针循环滚动当前窗口的窗格位置
    { MODKEY|ShiftMask,    XK_k,                    rotatestack,    {.i = -1 } },//逆时针循环滚动当前窗口的窗格位置
    { MODKEY,              XK_Up,                   focusstack,     {.i = +1 } },	//将光标焦点移动到下一个窗格
    { MODKEY,              XK_Down,                 focusstack,     {.i = -1 } },   //将光标焦点移动到上一个窗格
    { MODKEY,              XK_j,                    incnmaster,     {.i = +1 } },//插入主窗格的堆栈，窗口竖向排列
    { MODKEY,              XK_k,                    incnmaster,     {.i = -1 } },//减少主窗格的堆栈数，窗口横向排列
    { MODKEY,              XK_Left,                 setmfact,       {.f = -0.03} },//将当前的窗格宽度减向左扩展或缩小
    { MODKEY,              XK_Right,                setmfact,       {.f = +0.03} },   // win+左/右方向键，调整程序窗口的大小
	{ MODKEY,              XK_m,                    hidewin,        {0} }, // win+m 最小化/隐藏藏 当前窗格
	{ MODKEY|ShiftMask,    XK_m,                    restorewin,     {0} }, // win+shift+m 恢复当前窗口下隐藏的窗格,非全部，一次一个恢复
	{ MODKEY,              XK_o,                    hideotherwins,  {0}},  // win+ o 最小化/隐藏藏除当前外的其他窗格
	{ MODKEY|ShiftMask,    XK_o,                    restoreotherwins, {0}},// win+shift+o 恢复当前窗口下隐藏除当前外的其他窗格
	{ MODKEY|ShiftMask,    XK_Return,               zoom,           {0} }, //win+shift+回车，窗口位置互换， 将当前窗口与主窗口互换，若是当前是主窗口则将其与上一个窗格互换，并聚焦在主窗格
	{ MODKEY,              XK_Tab,                  view,           {0} }, //查看桌面标签。最后参数可以是NULL（全局查看）或是tags[数字]指定的桌面标签
    { MODKEY,              XK_0,                    view,           {.ui = ~0 } },
	{ MODKEY|Mod1Mask,     XK_0,                    setlayout,     {.v = &layouts[0]} },
	{ MODKEY|Mod1Mask,     XK_1,                    setlayout,     {.v = &layouts[1]} },
	{ MODKEY|Mod1Mask,     XK_2,                    setlayout,     {.v = &layouts[2]} },  //将当前窗口的模式改为排版,主格居左，副窗格居右，新增窗格水平分割
	{ MODKEY|Mod1Mask,     XK_3,                    setlayout,     {.v = &layouts[3]} },  //
	{ MODKEY|Mod1Mask,     XK_4,                    setlayout,     {.v = &layouts[4]} },  //改变当前窗口的模式为浮动
	{ MODKEY|Mod1Mask,     XK_5,                    setlayout,     {.v = &layouts[5]} },  //将当前窗口的副窗格堆模式改为垂直排列布局方式,主窗堆在上，副窗堆在下，副窗格垂直分割
	{ MODKEY|Mod1Mask,     XK_6,                    setlayout,     {.v = &layouts[6]} },  //将当前窗口的副窗格堆布局模式改为底部水平排列局方式,主窗堆在上，副窗堆在下，副窗格水平分割
	{ MODKEY|Mod1Mask,     XK_7,                    setlayout,      {.v = &layouts[7]} },  //将当前窗口的副窗格堆模式改为垂直排列布局方式
	{ MODKEY|Mod1Mask,     XK_8,                    setlayout,      {.v = &layouts[8]} },  //将当前窗口的窗格模式改为中心排列布局方式,主窗格在中心占大位，副窗口分列在左右水平分割
	{ MODKEY,              XK_space,                setlayout,      {0} },   //窗口模式切换,Alt + 空格,Alt + shift + 空格
	{ MODKEY|ShiftMask,    XK_space,                togglefloating, {0} },//切换是否浮动。最后参数NULL
	{ MODKEY,              XK_9,                    setlayout,      {.v = &layouts[9]} },  //将当前窗口的窗格模式改为网格模式,一列两行、两行两列、三行三列..
	{ MODKEY|ShiftMask,    XK_f,                    fullscreen,     {0} },  // win+shift+f全屏
	{ MODKEY|ShiftMask,    XK_0,                    tag,            {.ui = ~0 } },//切换指定的窗口到达指定的桌面标签。最后参数tags[数字]指定的桌面标签
	{ MODKEY,              XK_comma,                focusmon,       {.i = -1 } },  //win+,  在主副屏之间移动焦点# 移动焦点至左边屏幕，
	{ MODKEY,              XK_period,               focusmon,       {.i = +1 } },  //win+.  # 移动焦点至右边屏幕
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
    { MODKEY|ShiftMask,    XK_q,                   killclient,     {0} },//关闭当前窗口，强制关闭窗口。最后参数NULL
	{ MODKEY|ControlMask,  XK_Escape,              quit,           {0} }, 	//Ctrl+Alt+del，关闭并退出整个dwm桌面，且强制关闭所有当前运行于dwm下的程序
	//以下是增加的
	/* { MODKEY|ControlMask,   XK_l,                    spawn,          {.v = slimlockcmd } },  //锁屏 */
    { MODKEY|ControlMask,   XK_l,                    spawn,          {.v = slockcmd } },//锁屏
    { MODKEY|ControlMask,   XK_x,                    spawn,          {.v = xscreensaverlockcmd } },//锁屏
    { MODKEY|ShiftMask,     XK_Up,                   spawn,          {.v = lightup} },
    { MODKEY|ShiftMask,     XK_Down,                 spawn,          {.v = lightdown} },  // Shift+win+上/下方向键，调整屏幕亮度
    { MODKEY|ShiftMask,     XK_Right,                spawn,          {.v = volup} },
    { MODKEY|ShiftMask,     XK_Left,                 spawn,          {.v = voldown} },   // Shift+win+左/右方向键，调整音量大小
    { MODKEY|ShiftMask,     XK_m,                    spawn,          {.v = mute} },  	   // Shift+win+m，开启/关闭静音
    { MODKEY,               XK_d,                    spawn,          {.v = dolphin } },   // win+d，呼出dolphin文件管理器
    { MODKEY,               XK_n,                    spawn,          {.v = nautilus } },   // win+d，呼出dolphin文件管理器
    { MODKEY,               XK_g,                    spawn,          {.v = chromium } },   // win+j，呼出chromium浏览器
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

