#! /usr/bin/env bash
#########################################################################
# File Name: up-vol.sh
# Author:陈俊杰
# mail: 2716705056@qq.com
# Created Time: 2022年05月17日 星期二 16时12分18秒

# 此程序的功能是：
#########################################################################


/usr/bin/pactl  set-sink-volume   0   -8%
/usr/bin/pactl  set-sink-volume   1   -8%





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



