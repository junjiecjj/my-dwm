#!/bin/bash


#多显示器设置
/bin/bash  ./dualmon.sh  &


# 状态栏
# /bin/bash ./dwm-status.sh &

/bin/bash ./wp-autochange.sh &

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

fcitx &

fcitx5 &

redshift-gtk &

dunst  &

copyq  &

flameshot &

numlockx on



#音频相关的托盘
pasystray  &
kmix &
pa-applet  &

#轻量级系统托盘应用程序，可让您使用 PulseAudio 控制麦克风状态和音量。
mictray  &

xautolock -time 5 -locker '/usr/bin/betterlockscreen -l' -corners ---- -cornersize 30 &

betterlockscreen -w dim

bash ~/.fehbg


# 状态栏
# dwmblocks &

# sleep 4

#状态栏
# killall slstatus
slstatus &


#状态栏.dwnstatus、slstatus、dwmblocks、./dwm_status.sh只需要启动一个
# dwmstatus 2>&1 >/dev/null &
