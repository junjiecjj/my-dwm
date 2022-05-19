#!/bin/bash

#这行只能静音，但是不能从静音变成非静音
# /usr/bin/amixer set Master toggle

# # 这行是完美解决静音/非静音切换
/usr/bin/amixer -D pulse set Master 1+ toggle

# bash ~/scripts/dwm-status-refresh.sh





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
    echo  "没有使用dwmblocks"   > /dev/null
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




exec notify-send 'amixer静音/非静音成功切换'

