#!/bin/bash

VOL=$(amixer get Master | tail -n1 | sed -r "s/.*\[(.*)%\].*/\1/")

if [ "$VOL" -eq 0 ]; then
    printf "ﱝ  "
elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 33 ]; then
    printf " %s%%" "$VOL"
elif [ "$VOL" -gt 33 ] && [ "$VOL" -le 66 ]; then
    printf "墳 %s%%" "$VOL"
else
    printf "🔊 %s%%" "$VOL"
    # printf " %s%%" "$VOL"
fi
