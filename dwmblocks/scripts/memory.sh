#! /usr/bin/env bash
#########################################################################
# File Name: memory.sh
# Author:陈俊杰
# mail: 2716705056@qq.com
# Created Time: 2022年05月17日 星期二 09时13分30秒

# 此程序的功能是：
#########################################################################



memfree=$(($(grep -m1 'MemAvailable:' /proc/meminfo | awk '{print $2}')))
memtotal=$(($(grep -m1 'MemTotal:' /proc/meminfo | awk '{print $2}')))

useage=$(echo "scale=2;100 * ($memfree/$memtotal)" | bc)
echo -e "$useage%"
