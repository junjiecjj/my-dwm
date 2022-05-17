#!/bin/bash

results=$(ps ax|grep -v grep|grep trayer)
if [ "${results}" == "" ];then
    eval  "trayer --transparent true --expand false --align right --width 20 --SetDockType false --tint 0x88888888 &"
else
    echo $results
    killall trayer
fi





