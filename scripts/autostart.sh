#!/bin/bash

#笔记本，三个显示器，一个原屏幕，两个外界，下面三行：关闭原屏幕，只用两个外界显示器
# xrandr --output DP-1-8 --primary
# xrandr --output DP-1-8 --auto --output eDP-1 --off
# xrandr --output DP-1-9  --right-of DP-1-8  --auto


/bin/bash ./dwm-status.sh &
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

dwmstatus 2>&1 >/dev/null &

redshift &


numlockx on
