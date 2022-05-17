#!/bin/bash
#########################################################################
# File Name: up-vol.sh
# Author:陈俊杰
# mail: 2716705056@qq.com
# Created Time: 2022年05月17日 星期二 16时12分18秒

# 此程序的功能是：
#########################################################################

# pactl set-sink-volume @DEFAULT_SINK@ +8%
# 或
# /usr/bin/pactl  set-sink-volume   0   +8%

#cjj
#这行是判断当前是否为静音，返回[on]:非静音，[off]静音
CURRENT_STATE=`amixer get Master | egrep 'Playback.*?\[o' | egrep -o '\[o.+\]'`

if [[ $CURRENT_STATE == '[on]' ]]; then
    pactl set-sink-volume @DEFAULT_SINK@ +8%
else
    #首先非静音
    pactl set-sink-mute @DEFAULT_SINK@ toggle
    pactl set-sink-volume @DEFAULT_SINK@ +8%
    # /usr/bin/amixer -D pulse set Master 1+ toggle
    # /usr/bin/amixer -qM set Master 8%+ umute
fi






#cjj
results=$(ps ax|grep -v grep|grep dwm-status)
echo  $results
if [ "${results}" == "" ];then
    echo  "没有使用dwm-status"   > /dev/null
else
    /bin/bash   ~/scripts/dwm-status-refresh.sh
fi


results=$(ps ax|grep -v grep|grep dwmblocks)

echo -e ${results}

if [ "${results}" == "" ];then
    echo  "没有使用dwmblocks"  > /dev/null
else
    # echo  "正在使用dwmblocks"
    killall dwmblocks
    dwmblocks &
fi



results=$(ps ax|grep -v grep|grep slstatus)
if [ "${results}"  == "" ];then
    echo  "没有使用slstatus"  > /dev/null
else
    # echo  "正在使用slstatus"
    # killall slstatus
    # slstatus &
    # 更新状态栏
    status=$(slstatus -1)
    xsetroot -name "$status"
fi



