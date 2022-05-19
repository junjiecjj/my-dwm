#! /usr/bin/env bash
#########################################################################
# File Name: scrot.sh
# Author:陈俊杰
# mail: 2716705056@qq.com
# Created Time: 2022年05月19日 星期四 14时21分19秒

# 此程序的功能是：
#########################################################################



scrot -cd 3 $(xdg-user-dir PICTURES)/'Scrot_%Y-%m-%d_%H:%M:%S_$wx$h.png' -e 'viewnior $f'

exec notify-send 'Scrot截图 截取全屏 无GUI 保存指定路径 延迟3s 打开查看'
