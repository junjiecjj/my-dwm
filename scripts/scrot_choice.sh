#! /usr/bin/env bash
#########################################################################
# File Name: scrot_choice.sh
# Author:陈俊杰
# mail: 2716705056@qq.com
# Created Time: 2022年05月19日 星期四 14时27分17秒

# 此程序的功能是：
#########################################################################



scrot -cd 2  -q 1 -s $(xdg-user-dir PICTURES)/'Scrot_%Y-%m-%d_%H:%M:%S_$wx$h.png' -e 'viewnior $f'

exec notify-send 'Scrot截图 选择区域 保存指定路径'
