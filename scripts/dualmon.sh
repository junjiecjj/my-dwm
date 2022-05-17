#!/bin/bash


#TheCW
# xrandr --auto --output DP-2 --same-as eDP-1 --size 1920x1080
# xrandr --auto --output HDMI-1  --right-of DP-2 --size 1920x1080



#cjj
##========================================================================================================================================
#============= #笔记本，三个显示器，一个原屏幕，两个外界，下面三行：关闭原屏幕，只用两个外界显示器
##========================================================================================================================================

# xrandr --auto --output DP-1-8 --primary
# xrandr  --output eDP-1 --off
# xrandr --auto  --output DP-1-9  --right-of DP-1-8  --auto


## 或
# xrandr --auto --output  DP-1-8  --mode  1920x1080  --pos 0x0  --prime  --output  DP-1-9  --mode  1920x1080  --right-of  DP-1-8   --output  eDP-1  --off

## 或
# xrandr --output DP-1-8 --mode 1920x1080 --primary
#  xrandr --output DP-1-9 --mode 1920x1080  --right-of DP-1-8  --auto
#  xrandr  --output eDP-1 --off


##=======================================================================
#============= 如果为笔记本外接1个显示器================================
##=======================================================================
## 设置主屏
# xrandr --auto --output eDP-1 --mode 1920x1080 --primary

## 复制模式
# xrandr --auto --output eDP1 --pos 0x0 --mode 1920x1080 --output HDMI1 --same-as eDP1

## 扩展模式
# xrandr --auto --output eDP1 --pos 0x0 --mode 1920x1080 --primary --output HDMI1 --mode 1920x1080 --right-of eDP1
# xrandr --output HDMI1 --mode 1920*1080 --right-of eDP1

## 单屏模式
# xrandr --output eDP1 --pos 0x0 --mode 1920x1080 --primary --output HDMI-1 --off


## --auto：可以自动启用关闭的屏幕。
## --primary：设置主屏。
## –-output:指定显示器。
## –-mode:指定一种有效的分辨率。
## –-rate:指定刷新率。
# -–off:关闭某个屏幕.

##=======================================================================
#=============  如果为台式机外接2个显示器 ================================
##=======================================================================

#  xrandr --auto --output HDMI-1 --pos 0x0 --mode 1920x1080 --primary  --output  HDMI-2  --mode 1920x1080  --right-of  HDMI-1
## 或
#  xrandr --auto --output HDMI-1  --mode 1920x1080 --primary
#  xrandr --output HDMI-2  --mode 1920*1080 --right-of HDMI-1

