#!/bin/bash


#多显示器设置
/bin/bash  ./dualmon.sh  &


# 状态栏
# /bin/bash ./dwm-status.sh &

#自动更换壁纸
# /bin/bash ./wp-autochange.sh &

#固定壁纸
/bin/bash  ./wp-change.sh

#picom -o 0.95 -i 0.88 --detect-rounded-corners --vsync --blur-background-fixed -f -D 5 -c  --experimental-backends  -b
picom   --experimental-backends -b

/bin/bash ./tap-to-click.sh &

/bin/bash ./inverse-scroll.sh &

# /bin/bash ~/scripts/setxmodmap-colemak.sh &

nm-applet &

xfce4-power-manager &

xfce4-volumed-pulse &

/bin/bash ./run-mailsync.sh &

./autostart_wait.sh &


#输入法
fcitx &

fcitx5 &


redshift   &
# redshift-gtk &

#通知
dunst  &

#剪切板
copyq  &

#截图工具
flameshot &

numlockx on


#音频相关的托盘
# 系统托盘图标：pasystray
pasystray  &
# KMix — KDE 音量控制应用程序支持多个平台，包括 PulseAudio、可配置的系统托盘小程序。
kmix &
# pa-applet — 带有音量条的 PulseAudio 系统托盘小程序。
/foo/bar/bin/pa-applet  &
#轻量级系统托盘应用程序，可让您使用 PulseAudio 控制麦克风状态和音量,上下滚轮调节输入音大小。
mictray  &


# betterlockscreen锁屏
xautolock -time 5 -locker '/usr/bin/betterlockscreen -l' -corners ---- -cornersize 30 &

betterlockscreen -w dim

bash ~/.fehbg


# 状态栏
dwmblocks &

# sleep 4

#状态栏
# killall slstatus
# slstatus &


#状态栏.dwnstatus、slstatus、dwmblocks、./dwm_status.sh只需要启动一个
# dwmstatus 2>&1 >/dev/null &
