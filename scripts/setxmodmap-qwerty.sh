#!/bin/bash

xmodmap ~/.Xmodmap-cn
xset r rate 250 30



exec notify-send  "设置键盘映射模式为qwerty..."
