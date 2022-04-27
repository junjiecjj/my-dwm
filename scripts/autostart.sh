#!/bin/bash

/bin/bash ./dwm-status.sh &
/bin/bash ./wp-autochange.sh &
#picom -o 0.95 -i 0.88 --detect-rounded-corners --vsync --blur-background-fixed -f -D 5 -c -b
picom -b
/bin/bash ./tap-to-click.sh &
/bin/bash ./inverse-scroll.sh &
# /bin/bash ~/scripts/setxmodmap-colemak.sh &
nm-applet &
xfce4-power-manager &
xfce4-volumed-pulse &
/bin/bash ./run-mailsync.sh &
./autostart_wait.sh &
