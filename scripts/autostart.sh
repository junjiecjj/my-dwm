#!/bin/bash

#笔记本，三个显示器，一个原屏幕，两个外界，下面三行：关闭原屏幕，只用两个外界显示器
# xrandr --output DP-1-8 --primary
# xrandr --output DP-1-8 --auto --output eDP-1 --off
# xrandr --output DP-1-9  --right-of DP-1-8  --auto



# 如果为笔记本外接两个显示器，关闭笔记本的显示器
# xrandr --output DP-1-8 --mode 1920x1080 --primary
#  xrandr --output DP-1-9 --mode 1920x1080  --right-of DP-1-8  --auto
#  xrandr  --output eDP-1 --off


# 如果为笔记本外接1个显示器
# xrandr --output eDP-1 --mode 1920x1080 --primary
# xrandr --output HDMI1 1920*1080 --right-of eDP1



# 如果为台式机外接2个显示器
#  xrandr --output HDM-1 --mode 1920x1080 --primary
#  xrandr --output HDMI-2  1920*1080 --right-of HDM-1



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
