#! /usr/bin/env bash
#########################################################################
# File Name: toggle-vol.sh
# Author:陈俊杰
# mail: 2716705056@qq.com
# Created Time: 2022年05月17日 星期二 16时19分34秒

# 此程序的功能是：
#########################################################################



pactl set-sink-mute @DEFAULT_SINK@ toggle
# /usr/bin/pactl  set-sink-mute 0 toggle




#cjj
results=$(ps ax|grep -v grep|grep dwm-status)
echo  $results
if [ "${results}" == "" ];then
    echo  "没有使用dwm-status-refresh"  >/dev/null
else
    /bin/bash   ~/scripts/dwm-status-refresh.sh
fi


results=$(ps ax|grep -v grep|grep dwmblocks)

echo -e ${results}

if [ "${results}" == "" ];then
    echo  "没有使用dwmblocks"  >/dev/null
else
    # echo  "正在使用dwmblocks"
    killall dwmblocks
    dwmblocks &
fi



results=$(ps ax|grep -v grep|grep slstatus)
if [ "${results}"  == "" ];then
    echo  "没有使用slstatus"  >/dev/null
else
    # echo  "正在使用slstatus"
    # killall slstatus
    # slstatus &
    # 更新状态栏
    status=$(slstatus -1)
    xsetroot -name "$status"
fi



