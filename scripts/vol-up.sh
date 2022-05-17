#!/bin/bash

/usr/bin/amixer -qM set Master 8%+ umute
#pactl set-sink-volume @DEFAULT_SINK@ +5%

# bash ~/scripts/dwm-status-refresh.sh




#cjj
results=$(ps ax|grep -v grep|grep dwm-status-refresh)
echo  $results
if [ "${results}" == "" ];then
    echo  "没有使用dwm-status-refresh"
else
    /bin/bash   ~/scripts/dwm-status-refresh.sh
fi


results=$(ps ax|grep -v grep|grep dwmblocks)

echo -e ${results}

if [ "${results}" == "" ];then
    echo  "没有使用dwmblocks"
else
    # echo  "正在使用dwmblocks"
    killall dwmblocks
    dwmblocks &
fi



results=$(ps ax|grep -v grep|grep slstatus)
if [ "${results}"  == "" ];then
    echo  "没有使用slstatus"
else
    # echo  "正在使用slstatus"
    # killall slstatus
    # slstatus &
    # 更新状态栏
    status=$(slstatus -1)
    xsetroot -name "$status"
fi





