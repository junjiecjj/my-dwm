#!/bin/bash

feh --recursive --randomize --bg-fill   ~/图片/Wallpapers/

# feh --recursive --randomize --bg-fill  $(xdg-user-dir PICTURES)'/Wallpapers/'

#feh --recursive --randomize --bg-fill ~/Pictures/wallpapers/view



exec notify-send 'feh更换壁纸...'
