# DWM安装与配置

i3wm、DWM、Awesome、Xmond、Bspwm等都是Linux系统上的平铺式窗口管理器，一般只有顶级用户才需要定制自己的窗口管理器，但是对于喜欢折腾的人来说，是很好的消遣方式。



相比于集成了窗口管理器的Gnome、KDE等桌面环境来说，平铺式窗口管理器优点如下：

+ 节约内存和机器的CPU。一般Windows开机啥也不干，需要3G内存，Ubuntu开机啥也不干，需要2G，而平铺窗口管理器因为只需要开启的基本程序，只需要1G。
+ 高效。因为定义了很多在窗口、工作区、显示器之间切换的快捷键，可以很方便的快速切换，这一优点可以克服显示器少和屏幕小的缺点，使得一个笔记本就可以高效办公、Code等。
+ 界面美观。
+ 不需要鼠标。当只用neovim(类vim编辑器)、ST(终端)、ranger(终端文件管理器)、zathura(PDF阅读器)等类vim软件时，完全不需要鼠标就可以使用；但对于需要使用wps，VSCode，PyCharm等或者其他专业领域的IDE的用户来说，当熟悉IDE快捷键时，也不需要鼠标，但是不熟悉IDE快捷键时还是需要鼠标会比较方便。
+ 可以定制状态栏。



请看[DWM](https://github.com/junjiecjj/my-dwm)

请看[I3WM](https://github.com/junjiecjj/i3)

请看[Xmoad]()  ,待续

请看[Awesome]() ,待续

请看[BspWM]() ,待续



## 解决安装过程缺少 fatal error: X11/XX.h: No such file or directory



linux系统源码安装软件经常会遇到库文件不存在，错误信息大多如下：

```bash
BBoard.c:27:28: error: X11/IntrinsicP.h: No such file or directory
BBoard.c:28:27: error: X11/Intrinsic.h: No such file or directory
BBoard.c:29:23: error: X11/Xutil.h: No such file or directory
BBoard.c:30:28: error: X11/StringDefs.h: No such file or directory
```



安装库文件libx11-dev

+ sudo apt-get install libx11-dev

安装依赖文件

```bash
sudo apt-get install apt-file
sudo apt-file update
2XXXX.h
```

如：安装Intrinsic.h

```bash
sudo apt-get install apt-file
sudo apt-file update
apt-file search Intrinsic.h
```

搜索结果如下：

```bash
libxt-dev: usr/include/X11/Intrinsic.h
```

因此，只需安装libxt-dev即可：

```bash
sudo apt-get install libxt-dev
```

在安装dmenu/st/dwm过程中会发现少了:

```bash
dwm.c:40:10: fatal error: X11/extensions/Xinerama.h: 没有那个文件或目录
   40 | #include <X11/extensions/Xinerama.h>
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
make: *** [Makefile:18：dwm.o] 错误 1


```

通过上述方法可以发现需要安装以下

```bash
sudo apt install x11-xserver-utils libxrandr-dev libimlib2-dev
sudo apt install libharfbuzz-dev
```



## 安装st

```bash
$: cd ~/tmp
$: git clone  https://github.com/junjiecjj/my-ST.git  
$: cd my-ST
$: sudo make clean install 
```



## 安装slock

```bash
cd ~/tmp

git clone https://github.com/junjiecjj/slock.git

cd slock

sudo make clean install 
```





## 安装dmenus

dmenu 类似于 kde 下菜单栏里的应用启动器，但是比起 kde 来要方便快捷多了。使用方法是按下 win+s 键，dwm 顶部的菜单栏里就会出现 dmenu，然后输入你想打开的图形 gui 程序名，dmenu 会根据你输入的字符迅速自动搜索出当前系统里所有符合输入内容的程序名，按键盘的左右方向键选择想要打开的程序，最后按 Enter 键即可打开。

使用 dmenu，你可以很方便快捷地打开 kde、gnome、xfce 等主流桌面环境里自带的应用程序。由于我之前装的是 kde plasma，所以也习惯了用 kde 家的 dolphin 文件管理器、kate 文本编辑器、okular PDF 阅读器，kde 的自带应用做得确实不错。

注意 dmenu 只能打开带图形界面 gui 的程序，没有 gui 的程序用 dmenu 打开是看不到反应的；没有 gui 的纯命令行程序还是通过 alacritty 终端输入程序名打开吧。

```bash
$: cd ~/tmp

$: git clone https://github.com/junjiecjj/dmenu.git
$: cd dmenu
$: sudo make clean install 
$: cd

```









## picom

picom 可以实现阴影、原生窗口透明(配合 transset 工具)等特效.

在`.xinitrc`中添加：`picom -b`就可以使用compton

```bash
$: cd ~/tmp
$: sudo apt install cmake meson git pkg-config asciidoc libxext-dev libxcb1-dev libxcb-damage0-dev libxcb-xfixes0-dev libxcb-shape0-dev libxcb-render-util0-dev libxcb-render0-dev libxcb-randr0-dev libxcb-composite0-dev libxcb-image0-dev libxcb-present-dev libxcb-xinerama0-dev libxcb-glx0-dev libpixman-1-dev libdbus-1-dev libconfig-dev libgl1-mesa-dev  libpcre2-dev  libevdev-dev uthash-dev libev-dev libx11-xcb-dev
$: git clone https://github.com/jonaburg/picom.git
$: cd picom
$: git submodule update --init --recursive
$: meson --buildtype=release . build
$: LDFLAGS="-L/path/to/libraries" CPPFLAGS="-I/path/to/headers" meson --buildtype=release . build
$: ninja -C build
$: sudo ninja -C build install
$: cd
# 有时使用像 双河濑 你需要指定 – 实验后端 标志如下：
$: picom --config  ~/.config/picom/picom.conf --experimental-backends -b
$: picom --experimental-backends -b


$: sudo apt install compton xcompmgr

```





## compton

compton 可以实现阴影、原生窗口透明(配合 transset 工具)等特效,.  但是现在大多使用picom合成器。

若要禁用所有的阴影特效，需要加上 `-C` 和 `-G` 这两个参数:

```bash
compton -CG
```

若要在登录 X 会话的过程中，以后台进程（[Daemon](https://wiki.archlinux.org/index.php/Daemon)）的形式自动运行 compton，必须加上 `-b` 参数：

```bash
compton -b
```

将前面的参数一起用，效果也就一起有了:

```bash
compton -CGb
```

最后这个例子演示了如何使用需要指定数值的参数:

```bash
compton -cCGfF -o 0.38 -O 200 -I 200 -t 0 -l 0 -r 3 -D2 -m 0.88
```

在`.xinitrc`中添加：`compton -cCGfF -o 0.38 -O 200 -I 200 -t 0 -l 0 -r 3 -D2 -m 0.88`就可以使用compton。



##  xcompmgr+transset-df

xcompmgr+transset-df 可以实现阴影、原生窗口透明(配合 transset 工具)等特效. 但是现在大多使用picom合成器。

```bash
$: sudo apt-get install xcompmgr libxcomposite1 libxcomposite-dev libxfixes3 libxfixes-dev libxdamage1 libxdamage-dev libxrender1 libxrender-dev
# http://forchheimer.se/transset-df/ 下载transset-df压缩包,download transset-df from this page
$: tar zxf transset-df-X.tar.gz //X为版本号
$: cd transset-df-X/
$: make
$: sudo make install  
```

在`.xinitrc`中添加：



## ploybar

```bash
$ sudo apt update
$ sudo apt-get install cmake cmake-data libcairo2-dev libxcb1-dev libxcb-ewmh-dev libxcb-icccm4-dev libxcb-image0-dev libxcb-randr0-dev libxcb-util0-dev libxcb-xkb-dev pkg-config python3-xcbgen xcb-proto libxcb-xrm-dev i3-wm libasound2-dev libmpdclient-dev libiw-dev libcurl4-openssl-dev libpulse-dev
$ sudo apt install libxcb-composite0-dev
$ sudo apt install libjsoncpp-dev
$ sudo ln -s /usr/include/jsoncpp/json/ /usr/include/json

$ git clone https://github.com/jaagr/polybar.git

$ cd polybar && ./build.sh
//启动polybar
$ polybar example


或者
$ vim  /etc/apt/sources.list
#增加以下
deb http://cz.archive.ubuntu.com/ubuntu groovy main universe
#然后
$ sudo apt update
$: sudo apt install polybar
```

## 锁屏管理器：betterlockscreen, xautolock

依赖以下：

+ i3lock-color >= 2.13.c.3
+ ImageMagick
+ xdpyinfo, xrandr, xrdb and xset from X.Org
+ (Optional) Dunst
+ (Optional) feh for wallpaper-functionality

Note: Make sure your system has all dependencies satisfied

```bash
$:  cd ~/tmp
$: wget https://github.com/pavanjadhaw/betterlockscreen/archive/refs/heads/main.zip
$: unzip main.zip

$: cd betterlockscreen-main/
$: chmod u+x betterlockscreen
$: cp betterlockscreen /usr/local/bin/

$: cp system/betterlockscreen@.service /usr/lib/systemd/system/
$: systemctl enable betterlockscreen@$USER


$: sudo apt install xautolock
```




## dunst



```bash

$: sudo apt install dunst

或

$: sudo apt install libnotify-dev  libdbus-1-dev libx11-dev libxinerama-dev libxrandr-dev libxss-dev libglib2.0-dev libpango1.0-dev libgtk-3-dev libxdg-basedir-dev


$: cd ~/tmp
$: git clone https://github.com/dunst-project/dunst.git
$: cd dunst
$: make
$: sudo make install
```






## 安装dwm

```bash
$: cd ~/tmp

$: git clone https://github.com/junjiecjj/my-dwm.git
$: cd dmenu
$: sudo make clean install 

$: cd  dwmblocks
$: sudo make clean install 

$: cd ../slstatus
$: sudo make clean install 


```






## 其他服务软件

```bash
sudo  apt install -y suckless-tools libx11-dev libxft-dev libxinerama-dev gcc make feh

sudo apt install libxcb1-dev libxcb-keysyms1-dev libpango1.0-dev libxcb-util0-dev libxcb-icccm4-dev libyajl-dev libstartup-notification0-dev libxcb-randr0-dev libev-dev libxcb-cursor-dev libxcb-xinerama0-dev libxcb-xkb-dev libxkbcommon-dev libxkbcommon-x11-dev autoconf xutils-dev libtool

sudo apt-get install automake

sudo apt-get install libxcb-xrm-dev


sudo apt install libxcb-shape0-dev

sudo apt-get install libpcre3-dev

sudo apt-get install libcairo2-dev

sudo apt-get install libpango1.0-dev

# 多显示器需要使用配置工具，我用的是 xrandr。其他工具还有 Xinerama 和 winView，另外 arandr 是 xrandr 的图形界面，也可以用。
sudo apt install  arandr  x11-xserver-utils

# Viewnior是一个图像查看器应用程序，它被创建为简单，快速且优雅。
sudo apt install viewnior

#PDF阅读zathura, 文件管理器pcmanfm,thunar
sudo apt install zathura  pcmanfm  thunar

## 背光灯调整工具
sudo  apt install -y light

## 安装数字键盘工具, 用于进入dwm桌面后自动开启数字键盘 #
sudo  apt install -y numlockx

sudo  apt install -y virtualbox-guest-utils virtualbox-guest-X11

##  电源监控工具 #
sudo  apt install -y acpi acpitool

## 透明配置支持  
sudo  apt install -y compton

sudo  apt install -y xcompmg

## 背景图片设置工具
sudo  apt install -y feh

## 用于屏幕亮度的调节
sudo  apt install -y   light  xbacklight

## 安装 nm-applet
sudo  apt install -y network-manager-gnome

##  锁屏 
sudo  apt install slimlock  i3lock-fancy

#查看电脑系统信息
sudo  apt install  screenfetch  neofetch



#终端 文件管理器
sudo  apt install ranger

#图形界面 文件管理器
sudo  apt install  nautilus  thunar

#文本编辑器
sudo  apt install  mousepad（xfce）
sudo  apt install  kwrite（kde）

#setings，鼠标，图标等自定义
sudo  apt install  lxappearance


#视频播放器
sudo  apt install  mpv vlc

#deepin 截图工具
sudo  apt install  deepin-screenshot
#火焰截图
sudo  apt install  flameshot

##  蓝牙 
sudo apt install blueman


sudo apt install alsa-utils  mate-power-manager  acpi  alsa-utils nitrogen xsetroot

# mate-power-manager 电源管理工具
# acpi 电源配置接口工具(用于显示电池信息)
# alsa-utils 声音管理
# xfce4-appfinder 可以快速搜索程序的启动器
# nitrogen 壁纸管理器
# xsetroot  定制、显示简易的系统状态栏(电池电量、音量、日期、时间等)


# 使用Playerctl的通用媒体播放器状态/控件
sudo apt install  playerctl

#mpd是作为一个服务运行在后台，它不具备播放功能，你可以把它理解成一个服务端，你还需要一个客户端MPC来执行播放的功能。
sudo apt-get install mpd mpc

## rofi 是一个快捷的程序启动器
sudo  apt install -y rofi 

sudo apt install nm-applet
network-manager-applet 是一个GTK3+前端小程序，工作在Xorg环境下，带有一个系统托盘。

## 背景图片设置工具
sudo  apt install  variety
#i3 配置文件中添加
exec_always variety -b
#variety设置壁纸时候，普通用户必须有权限
#简单点，直接把壁纸 所有权限设成 777


```



## 声音控制

### Advanced Linux Sound Architecture (简体中文)

` sudo apt install pulseaudio    alsa-utils   asmixer`

https://wiki.archlinux.org/title/Advanced_Linux_Sound_Architecture_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)

[高级 Linux 声音体系](https://en.wikipedia.org/wiki/zh:ALSA)（Advanced Linux Sound Architecture，**ALSA**）提供声卡的内核驱动，代替了原来的开放声音系统（Open Sound System，OSS）。

除了声音设备驱动，**ALSA**还捆绑了一个用户空间驱动的库用于应用开发。开发者可以使用这些 ALSA 驱动进行高级 API 开发，可以通过 ALSA 库达成与声音设备的内核（直接）交互。

[安装](https://wiki.archlinux.org/title/Help:Reading_(简体中文)#安装软件包) 软件包 [alsa-utils](https://archlinux.org/packages/?name=alsa-utils)。其包含 `alsamixer` 、 `amixer` 等实用程序。*amixer*是一个用于更改音频设置的shell命令，而*alsamixer*则提供了一个较为直观的，基于[ncurses](https://en.wikipedia.org/wiki/Ncurses)的界面，用于配置声音设备。

#### 解除各声道的静音

ALSA 默认静音所有声道，必须手动解除。

#### 使用amixer解除静音

可以使用 `amixer` 解除声卡的主音量静音：

```bash
$ amixer sset Master unmute
$ amixer sset Speaker unmute
$ amixer sset Headphone unmute
```

#### 使用alsamixer解除静音

使用 `alsamixer` 可以解除声卡的静音：

```bash
$ alsamixer
```

### PulseAudio (简体中文)

`sudo apt install pulseaudio  `

https://wiki.archlinux.org/title/PulseAudio_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)

[PulseAudio](https://en.wikipedia.org/wiki/PulseAudio) 是在[GNOME](https://wiki.archlinux.org/title/GNOME) 或 [KDE](https://wiki.archlinux.org/title/KDE)等桌面环境中广泛使用的音频服务。它在内核音频组件（比如[ALSA](https://wiki.archlinux.org/title/ALSA) 和 [OSS](https://wiki.archlinux.org/title/OSS)）和应用程序之间充当代理的角色。由于Arch Linux默认包含ALSA，PulseAudio经常和ALSA协同使用。

#### 前端

有多种前端工具可以用以控制 PulseAudio 守护进程：

- GTK GUI：[paprefs](https://archlinux.org/packages/?name=paprefs) 和 [pavucontrol](https://archlinux.org/packages/?name=pavucontrol)
- 按键音量控制: [pulseaudio-ctl](https://aur.archlinux.org/packages/pulseaudio-ctl/)AUR，[pavolume-git](https://aur.archlinux.org/packages/pavolume-git/)AUR
- 控制台 (CLI)混合器：[ponymix](https://aur.archlinux.org/packages/ponymix/)AUR和[pamixer](https://archlinux.org/packages/?name=pamixer)
- 控制台 (curses) 混合器：[pulsemixer](https://archlinux.org/packages/?name=pulsemixer)
- 网页音量控制：[PaWebControl](https://github.com/Siot/PaWebControl)
- 系统托盘图标：[pasystray](https://archlinux.org/packages/?name=pasystray)，[pasystray-git](https://aur.archlinux.org/packages/pasystray-git/)AUR
- KF5 plasma 程序：[kmix](https://archlinux.org/packages/?name=kmix)和[plasma-pa](https://archlinux.org/packages/?name=plasma-pa)

#### 控制台

- **ncpamixer** — 受 pavucontrol 启发的用于 PulseAudio 的 Ncurses 混合器。

- **pacmixer** — PulseAudio 的 Alsamixer 近似。

- **PAmix** — 与 pavucontrol 相似的Ncurses PulseAudio 混合器。

- **pamixer** — PulseAudio CLI 混合器。

- **pavolume** — 带有 libnotify 消息的 PulseAudio 的简单 CLI 音量控制。

- **Ponymix** — PulseAudio 的 CLI 混合器。

- **pulseaudio-ctl** — 用 shell 或快捷键控制 PulseAudio。

- **pulsemixer** — PulseAudio 的 CLI 和 curses 混合器。



#### 图形界面

- **KMix** — [KDE](https://wiki.archlinux.org/title/KDE) 音量控制应用程序支持多个平台，包括 PulseAudio、可配置的系统托盘小程序。

- **MicTray** — 轻量级系统托盘应用程序，可让您使用 PulseAudio 控制麦克风状态和音量。

- **pa-applet** — 带有音量条的 PulseAudio 系统托盘小程序。

- **pasystray** — PulseAudio 的系统托盘小程序。

- **plasma-pa** — [KDE](https://wiki.archlinux.org/title/KDE) 使用 PulseAudio 进行音量管理的 Plasma 小程序

- **PulseAudio Equalizer** — 基于 LADSPA 的 PulseAudio 多频段均衡器。

- **PulseAudio Graph Control** — PulseAudio 图形化控制器

- **PulseAudio Manager** — PulseAudio 的简单 GTK 前端。 停止开发。

- **PulseAudio Preferences** — 简单的 PulseAudio GTK 配置对话框。

- **PulseAudio Volume Control** — 简单的 PulseAudio GTK 音量控制工具（“混音器”）。

- **PulseAudio Volume Control (Qt)** — PulseAudio 混音器（pavucontrol 的 Qt 端口）。

- **PulseAudio Volume Control (Sandsmark)** — LXQt 的 pavucontrol 轻量级分支，实现了 pavucontrol 的缺失功能，错误修复并删除非必要依赖。

- **PulseAudio Volume Meter** — 简单的 PulseAudio GTK 音量计。 停止开发。

- **PulseEffects** — PulseAudio的音频效果。

- **Volctl** — PulseAudio 的每个应用程序系统托盘小程序音量控制。

- **Xfce PulseAudio Panel Plugin** — [Xfce](https://wiki.archlinux.org/title/Xfce)4 面板的 PulseAudio 插件。



**我们着重关注的是系统托盘等功能：**

安装：

```bash
#============================================================================================
# pasystray: PulseAudio 的系统托盘小程序。
# KMix — KDE 音量控制应用程序支持多个平台，包括 PulseAudio、可配置的系统托盘小程序。
# 控制台 (curses) 混合器：pulsemixer
# GTK GUI：paprefs 和 pavucontrol
#============================================================================================
sudo apt install  paprefs pavucontrol  pulsemixer   pasystray  kmix
启动：  pasystray &
kmix &


#============================================================================================
#micty MicTray — 轻量级系统托盘应用程序，可让您使用 PulseAudio 控制麦克风状态和音量。
#============================================================================================
sudo add-apt-repository ppa:mictray/mictray
sudo apt-get update
sudo apt-get install mictray


启动：  mictray &

#============================================================================================
#pa-applet  pa-applet — 带有音量条的 PulseAudio 系统托盘小程序
#============================================================================================
git clone https://github.com/fernandotcl/pa-applet.git

cd pa-applet

$ ./autogen.sh

Compiling and installing it is simple enough:

$ ./configure --prefix=/foo/bar
$ make
$ make install

安装后启动：/foo/bar/bin/pa-applet &

#============================================================================================
#PulseAudio Graph Control：  — PulseAudio 图形化控制器
#============================================================================================
sudo apt install npm python
sudo npm install -g yarn

git clone https://github.com/futpib/pagraphcontrol.git
cd pagraphcontrol

yarn install
yarn build

启动：~/tmp/pagraphcontrol/dist/pagraphcontrol-linux-x64/pagraphcontrol

#To see audio peaks build papeaks and put it on your PATH.
cd ~/tmp

git clone https://github.com/futpib/papeaks.git

cd  papeaks

cargo build --release


#============================================================================================
#== Volctl — PulseAudio 的每个应用程序系统托盘小程序音量控制。
#============================================================================================
#https://buzz.github.io/volctl/ || volctlAUR
# https://github.com/buzz/volctl
git clone  https://github.com/buzz/volctl.git

cd volctl

 sudo cp data/apps.volctl.gschema.xml /usr/share/glib-2.0/schemas
 
 pip3 install setuptools
 
sudo apt-get install build-essential libcairo2-dev libpango1.0-dev libjpeg-dev libgif-dev librsvg2-dev

 sudo apt install libgirepository1.0-dev
 
 
 python -m pip install pycairo
 
 sudo apt install libcairo2 python-cairo
 
 pip install pycairo
 
 


```





## 网络系统托盘



NetworkManager可以通过networkmanager包安装。这个包包括了一个daemon、一个命令行界面(nmcli)和一个基于curses的界面(nmtui)。安装好之后需要[启动/启用](https://wiki.archlinux.org/title/Systemd_(简体中文)#使用单元) `NetworkManager.service` [systemd](https://wiki.archlinux.org/title/Systemd) 服务。NetworkManager 守护进程启动后，会自动连接到任何可用的已经配置的**系统连接**。**用户连接**或未配置的连接需要通过`nmcli`或applet进行配置和连接。

`systemctl start  network-manager`

立即激活单元：

```
# systemctl start <单元>
```

立即停止单元：

```
# systemctl stop <单元>
```

重启单元：

```
# systemctl restart <单元>
```

重新加载配置：

```
# systemctl reload <单元>
```



```bash
╭─   ~/.config/i3 on   main !1                                                                                                                                                              base at  17:27:26
╰─❯ sudo apt install network-manager
 -- package --
network-manager                             network-manager-gnome                       network-manager-openconnect-gnome           network-manager-ssh-gnome
network-manager-config-connectivity-debian  network-manager-iodine                      network-manager-openvpn                     network-manager-strongswan
network-manager-config-connectivity-ubuntu  network-manager-iodine-gnome                network-manager-openvpn-gnome               network-manager-vpnc
network-manager-dev                         network-manager-l2tp                        network-manager-pptp                        network-manager-vpnc-gnome
network-manager-fortisslvpn                 network-manager-l2tp-gnome                  network-manager-pptp-gnome
network-manager-fortisslvpn-gnome           network-manager-openconnect                 network-manager-ssh



```

NetworkManager安装完成后，` sudo apt install network-manager`, 自带：

+  提供图形界面 nm-connection-editor
+ 提供系统托盘图标 network-manager-applet(nm-applet) 

```bash
nmcli 使用示例

1、列出附近wifi
nmcli   dev  wifi    list



#显示附近的 wifi:
❯ nmcli device wifi list
IN-USE  BSSID              SSID                 MODE   CHAN  RATE        SIGNAL  BARS  SECURITY
        4C:77:66:D5:A2:45  409                  Infra  13    270 Mbit/s  97      ▂▄▆█  WPA1 WPA2
        08:40:F3:5D:FB:E1  cmcc                 Infra  5     270 Mbit/s  79      ▂▄▆_  WPA1 WPA2
        08:40:F3:5D:FB:E5  cmcc                 Infra  161   270 Mbit/s  79      ▂▄▆_  WPA1 WPA2
        BC:5F:F6:50:53:52  406                  Infra  12    270 Mbit/s  62      ▂▄▆_  WPA1 WPA2
*       D4:8F:A2:C7:34:88  .小酒馆mm            Infra  1     130 Mbit/s  52      ▂▄__  WPA1 WPA2
        D4:8F:A2:C7:34:8D  --                   Infra  1     130 Mbit/s  40      ▂▄__  WPA2
        C0:C1:70:62:DB:B0  CMCC-v5ad            Infra  8     130 Mbit/s  40      ▂▄__  WPA1 WPA2
        50:0F:F5:E9:4F:D1  Tenda_E94FD0         Infra  4     130 Mbit/s  35      ▂▄__  WPA1 WPA2
        90:76:9F:D2:2D:5F  MERCURY_5G_2D5F      Infra  153   270 Mbit/s  34      ▂▄__  WPA1 WPA2
        50:21:EC:97:36:1C  江西特色饭店         Infra  44    270 Mbit/s  30      ▂___  WPA2
        50:0F:F5:E9:4F:D5  Tenda_E94FD0_5G      Infra  48    540 Mbit/s  30      ▂___  WPA1 WPA2
        50:21:EC:F7:36:1E  江西特色饭店_Wi-Fi5  Infra  44    270 Mbit/s  29      ▂___  WPA2
        28:2C:B2:06:CD:D0  lzw                  Infra  1     135 Mbit/s  25      ▂___  WPA1 WPA2
        34:78:39:53:71:08  threedou2            Infra  8     270 Mbit/s  24      ▂___  WPA1 WPA2
        D4:8F:A2:C7:34:8E  --                   Infra  44    270 Mbit/s  24      ▂___  WPA2
        E4:19:C1:F3:55:B1  --                   Infra  1     270 Mbit/s  22      ▂___  WPA2
        04:40:A9:B1:F5:B2  qianyicangku         Infra  6     130 Mbit/s  22      ▂___  WPA1 WPA2
        D4:8F:A2:C7:34:8C  .小酒馆mm            Infra  44    270 Mbit/s  22      ▂___  WPA1 WPA2
        E4:19:C1:F3:55:B0  ChinaNet-D6UQLT      Infra  153   270 Mbit/s  22      ▂___  WPA1 WPA2
        F4:B5:AA:C6:A0:D8  ChinaNet-G2hg        Infra  3     130 Mbit/s  20      ▂___  WPA1 WPA2
        EC:F8:EB:47:D9:B1  ChinaNet-t4za        Infra  5     130 Mbit/s  20      ▂___  WPA1
        8C:81:72:5F:85:D4  ChinaNet-awAe        Infra  9     130 Mbit/s  20      ▂___  WPA1 WPA2
        58:41:20:5C:AB:D0  办公                 Infra  153   405 Mbit/s  20      ▂___  WPA1 WPA2
        C0:C1:70:62:DB:B1  CMCC-v5ad-5G         Infra  149   270 Mbit/s  19      ▂___  WPA1 WPA2
        04:40:A9:B1:F5:B6  qianyicangku_5G      Infra  153   270 Mbit/s  19      ▂___  WPA1 WPA2
        E4:19:C1:F3:55:B2  --                   Infra  153   270 Mbit/s  19      ▂___  WPA2
        D8:32:14:EF:61:B5  888-5G               Infra  153   270 Mbit/s  15      ▂___  WPA1 WPA2

2、连接wifi
nmcli  dev  wifi  connect  <name>  password  <password>    不指定网卡连接wifi
nmcli   dev  wifi  connect  <name>  password  <password>  ifname  wlan1 [profile_name] 指定网卡

连接 wifi:
$ nmcli device wifi connect 409 password 8888888

3、 查看设备列表
nmcli dev 其中dev是device的简写，wifi是类型，也就是说可以使用类型来引用设备,也可以使用iface和ifname来引用设备，iface是编号，ifname是网卡接口名，例如wlan0

4、打开图形配置界面
文本界面：nmtui
图形界面：nm-connection-editor


#连接到隐藏的 wifi:
$ nmcli device wifi connect SSID password password hidden yes


通过 wlan1 wifi 网卡(interface)连接 wifi:
$ nmcli device wifi connect <SSID>  password <password> ifname wlan1 <profile_name>


断开一个网卡(interface)上的连接:
$ nmcli device disconnect ifname eth0

重新连接一个被标记为“已断开”的网卡：
$ nmcli connection up uuid UUID


显示一个所有连接过的网络的UUID的列表:
$ nmcli connection show


查看所有网络设备及其状态:
$ nmcli device
❯ nmcli device
DEVICE           TYPE      STATE   CONNECTION
wlp59s0          wifi      已连接  .小酒馆mm
p2p-dev-wlp59s0  wifi-p2p  已断开  --
lo               loopback  未托管  --



关掉 wifi:
$ nmcli radio wifi off
```



### nmcli 使用示例

显示附近的 wifi:

```bash
$ nmcli device wifi list
```

连接 wifi:

```bash
$ nmcli device wifi connect SSID password password
```

连接到隐藏的 wifi:

```bash
$ nmcli device wifi connect SSID password password hidden yes
```

通过 `wlan1` wifi 网卡(interface)连接 wifi:

```bash
$ nmcli device wifi connect SSID password password ifname wlan1 profile_name
```

断开一个网卡(interface)上的连接:

```bash
$ nmcli device disconnect ifname eth0
```

重新连接一个被标记为“已断开”的网卡：

```bash
$ nmcli connection up uuid UUID
```

显示一个所有连接过的网络的UUID的列表:

```bash
$ nmcli connection show
```

查看所有网络设备及其状态:

```bash
$ nmcli device
```

关掉 wifi:

```bash
$ nmcli radio wifi off
```



## 护眼工具redshift

`sudo apt-get update`

`sudo apt-get install  redshift  redshift-gtk`



##  Spotify是一个音乐流媒体服务商




```bash

sudo snap install spotify

sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 4773BD5E130D1D45


echo "deb http://repository.spotify.com stable non-free" | sudo tee /etc/apt/sources.list.d/spotify.list

sudo apt update
sudo apt install spotify-client
```



## DWM快捷键





```c

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* static const char *dmenucmd[]       =          {"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL}; */
static const char *dmenucmd[]       =          { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *roficmd[]        =          {"rofi", "-show", "drun", NULL};
static const char *termcmd[]        =          {"st", NULL};
static const char *xtermcmd[]       =          {"xterm", NULL};
static const char *typoracmd[]      =          {"typora", NULL};
static const char *browsercmd[]     =          {"google-chrome-stable", NULL};
static const char *trayercmd[]      =          {"/home/jack/tmp/my-dwm/scripts/trayer-toggle.sh", NULL};
static const char *wpcmd[]          =          {"/home/jack/tmp/my-dwm/scripts/wp-change.sh", NULL};
/* static const char *wpcmd[] = {"feh", "--recursive", "--randomize", "--bg-fill", "~/图片/Wallpapers/", NULL}; */
static const char *sktogglecmd[]    =          {"/home/jack/tmp/my-dwm/scripts/sck-tog.sh", NULL};
static const char scratchpadname[]  =          "scratchpad";
static const char *scratchpadcmd[]  =          {"st", "-t", scratchpadname, "-g", "120x34", NULL};
static const char *setcolemakcmd[]  =          {"/home/jack/tmp/my-dwm/scripts/setxmodmap-colemak.sh", NULL};
static const char *setqwertycmd[]   =          {"/home/jack/tmp/my-dwm/scripts/setxmodmap-qwerty.sh", NULL};
static const char *touchpadcmd[]   =           {"/home/jack/tmp/my-dwm/scripts/touchpad.sh", NULL};
//static const char *suspendcmd[]   =          {"/home/jack/tmp/my-dwm/scripts/suspend.sh", NULL};
static const char *suspendcmd[]     =          {"systemctl","suspend", NULL};
static const char *screenshotcmd[]  =          {"flameshot", "gui", NULL};
static const char *scrotcmd[]       =          {"scrot", "-q", "100", "-s", "$HOME/图片/`date +%Y-%m-%d_%H:%M:%S`.png", NULL};
static const char *deepinscreencmd[]     =     {"deepin-screenshot", NULL};
static const char *slockcmd[]       =          { "slock", NULL };


//控制音量 1
static const char *upvol[]          =          {"/home/jack/tmp/my-dwm/scripts/vol-up.sh", NULL};
static const char *downvol[]        =          {"/home/jack/tmp/my-dwm/scripts/vol-down.sh", NULL};
static const char *mutevol[]        =          {"/home/jack/tmp/my-dwm/scripts/vol-toggle.sh", NULL};

//控制音量和亮度 2
static const char *volup[]          =          {"amixer", "-qM", "set", "Master", "2%+", "umute", NULL};
static const char *voldown[]        =          {"amixer", "-qM", "set", "Master", "2%-", "umute", NULL}; //#定义系统音量大小调节的快捷键功能
static const char *mute[]           =          {"amixer", "-qM", "set", "Master", "toggle", NULL};			 //#定义开 / 关静音的快捷键功能
static const char *lightup[]        =          {"xbacklight", "-inc", "2", NULL};
static const char *lightdown[]      =          {"xbacklight", "-dec", "2", NULL};					  //#定义屏幕亮度调节的快捷键功能



//以下是增加的,控制音量和亮度3
static const char *upVol[]          = {"/home/jack/tmp/my-dwm/scripts/up-vol.sh", NULL};
static const char *downVol[]        = {"/home/jack/tmp/my-dwm/scripts/down-vol.sh",  NULL};
static const char *muteVol[]        = {"/home/jack/tmp/my-dwm/scripts/toggle-vol.sh", NULL};
/* static const char *upVol[]          = {"/usr/bin/pactl",  "set-sink-volume", "0", "+8%",  NULL}; */
/* static const char *downVol[]        = {"/usr/bin/pactl",  "set-sink-volume", "0", "-8%",   NULL}; */
/* static const char *muteVol[]        = {"/usr/bin/pactl",  "set-sink-volume", "0", "toggle", NULL}; */
static const char *upbrt[]          = {"light", "-A", "5", NULL};
static const char *downbrt[]        = {"light", "-U", "5", NULL};
static const char *windowswitchcmd[] = { "rofi", "-show", "window", NULL };


static const char *chromium[]       =          {"google-chrome-stable", "--disk-cache-dir=/tmp/google-chrome-stable", NULL}; //#定义chrome浏览器的快捷键功能
static const char *dolphin[]        =          {"dolphin", NULL};	 	  //#定义dolphin文件管理器的快捷键功能
static const char *nautilus[]       =          {"nautilus", NULL};	 	  //#定义dolphin文件管理器的快捷键功能
static const char *slimlockcmd[]    =          {"slimlock", NULL };
static const char *slocklockcmd[]   =          {"slock", NULL };
static const char *xscreensaverlockcmd[]  =    {"xscreensaver", NULL };


/*
 * 不需要配置的快捷键
 * 缩放窗口: Mod + 鼠标右键
 * 移动窗口: Mod + 鼠标左键
 * */
static Key keys[] = {

    //应用快捷键
	/* modifier            key                      function        argument */
    { MODKEY,              XK_d,                    spawn,          {.v = dmenucmd } },     // win+d打开 dmen 面板（应用菜单）呼出dmenu应用程序启动器
    { MODKEY,              XK_r,                    spawn,          {.v = roficmd } },      // win+r打开 dmen 面板（应用菜单）呼出rofi应用程序启动器
    { MODKEY,              XK_Return,               spawn,          {.v = termcmd } },      // win+回车新建一个窗格，（开一个终端应用（st））
    { MODKEY,              XK_grave,                togglescratch,  {.v = scratchpadcmd } },//win+` 打开一个命令行终端小窗格窗口
    { MODKEY,              XK_x,                    spawn,          {.v = xtermcmd } },     // win+x 新建一个窗格，（开一个终端应用（xterm））
    { MODKEY,              XK_t,                    spawn,          {.v = typoracmd } },    // win+t 新建一个窗格，（开一个终端应用（typora））
    { MODKEY,              XK_c,                    spawn,          {.v = browsercmd } },   // win+c 呼出chromium浏览器
    { MODKEY,              XK_g,                    spawn,          {.v = chromium } },     // win+g，呼出chromium浏览器
    // { MODKEY,               XK_d,                    spawn,          {.v = dolphin } },  // win+d，呼出dolphin文件管理器
    { MODKEY,              XK_n,                    spawn,          {.v = nautilus } },     // win+n，呼出dolphin文件管理器
    { MODKEY|ShiftMask,    XK_b,                    spawn,          {.v = wpcmd } },        //win+b换壁纸
    { MODKEY|ShiftMask,    XK_t,                    spawn,          {.v = trayercmd } },    // win+shift+t 呼出系统托盘
    { MODKEY|ShiftMask,    XK_s,                    spawn,          {.v = sktogglecmd } },  //调出screenkey
    { MODKEY|ShiftMask,    XK_v,                    spawn,          CMD("VBoxManage startvm 'Windows10' --type gui") },

    //系统快捷键
    { 0,                            XK_Print,                   spawn,          {.v = screenshotcmd } },     //PrtSc flameshot截图
    /* { MODKEY,                    XK_f,                       spawn,          {.v = screenshotcmd } },  //win+f  截图 */
    { MODKEY,                       XK_Print,                   spawn,          {.v = screenshotcmd } },     //win+print flameshot 截图
    { MODKEY|ShiftMask,             XK_Print,                   spawn,          {.v = scrotcmd } },          //win+print  截图
	/* { MODKEY|ControlMask,           XK_Print,                   spawn,          SHCMD("scrot -q 1 -s $HOME/图片/$(date +%Y-%m-%d_%H:%M:%S).png") },           //win+print  截图 */
	{ MODKEY|ControlMask,           XK_Print,                   spawn,          {.v= deepinscreencmd} },           //win+Control+print  deepin截图
    { MODKEY|ControlMask,           XK_t,                       spawn,          {.v = touchpadcmd} },    // Control+win+t打开/关闭触控板


    //控制音量 1
    { 0,                                XF86XK_AudioRaiseVolume,    spawn,          {.v = upvol   } },        //增加音量
    { 0,                                XF86XK_AudioLowerVolume,    spawn,          {.v = downvol } },        //降低音量
    { 0,                                XF86XK_AudioMute,           spawn,          {.v = mutevol } },        //静音
    { MODKEY|ShiftMask,                 XK_equal,                   spawn,          {.v = upvol   } },        // win+shift+= 增加音量
    { MODKEY|ShiftMask,                 XK_minus,                   spawn,          {.v = downvol } },        // win+shift+- 降低音量
    { MODKEY|ShiftMask,                 XK_BackSpace,               spawn,          {.v = mutevol } },        // win+shift+Backspace 静音
    /* { MODKEY,                           XK_backslash,               spawn,          {.v = mutevol } },        // win+\ 静音 */

    /* 控制音量和亮度2 */
    { MODKEY|ControlMask,               XK_Up,                       spawn,          {.v = volup} },        // Control+win+上方向键，调整音量大
    { MODKEY|ControlMask,               XK_Down,                     spawn,          {.v = voldown} },      // Control+win+下方向键，调整音量小
    { MODKEY|ControlMask,               XK_m,                       spawn,           {.v = mute} },  	    // Shift+win+m，开启/关闭静音

    { MODKEY|ShiftMask,                XK_Up,                       spawn,          {.v = lightup} },      // Shift+win+上方向键，屏幕变亮
    { MODKEY|ShiftMask,                XK_Down,                     spawn,          {.v = lightdown} },    // Shift+win+下方向键，屏幕变暗

    /* XF86Keys  控制音量和亮度3 */
    {MODKEY|ControlMask,             XK_BackSpace,                 spawn,           {.v = muteVol}},
    {MODKEY|ControlMask,             XK_minus,                     spawn,           {.v = downVol}},
    {MODKEY|ControlMask,             XK_equal,                     spawn,           {.v = upVol}},
    {0,                              XF86XK_MonBrightnessUp,       spawn,           {.v = upbrt}},
    {0,                              XF86XK_MonBrightnessDown,     spawn,           {.v = downbrt}},

    //{ MODKEY|ShiftMask|ControlMask,       XK_q,           spawn,          {.v = setqwertycmd } },  //win+shift+ctrl+q 键盘模式为qwerty
    //{ MODKEY|ShiftMask|ControlMask,       XK_c,           spawn,          {.v = setcolemakcmd } }, //win+shift+ctrl+c 键盘模式为colemal
	{ MODKEY|Mod1Mask,                   XK_Down,                    spawn,          SHCMD("transset-df -a --dec .1") },  //减少当前窗格应用的透明度
	{ MODKEY|Mod1Mask,                   XK_Up,                      spawn,          SHCMD("transset-df -a --inc .1") },  //增加当前窗格应用的透明度
	{ MODKEY|Mod1Mask,                   XK_Home,                    spawn,          SHCMD("transset-df -a .75") },      //恢复当前窗格应用的初始默认的透明度
	//以下是增加的
	// { MODKEY|ControlMask,             XK_l,                    spawn,          {.v = slimlockcmd } },     //锁屏
    { Mod1Mask|ControlMask,             XK_Delete,                spawn,          CMD("betterlockscreen -l") },
	{ MODKEY|Mod1Mask,                   XK_l,                    spawn,          SHCMD("slock") },             //锁屏
    { MODKEY|ControlMask,                XK_l,                    spawn,          {.v = slockcmd } },           //锁屏
    { MODKEY|ControlMask,                XK_x,                    spawn,          {.v = xscreensaverlockcmd } },//锁屏

    { MODKEY|ControlMask,  XK_s,                    spawn,          {.v = suspendcmd } },  // win+ctrl+s休眠
    { MODKEY|ShiftMask,    XK_q,                    killclient,     {0} },                  //关闭当前窗口，强制关闭窗口。最后参数NULL
	{ MODKEY|ControlMask,  XK_Escape,               quit,           {0} },                  //Ctrl+Alt+del，关闭并退出整个dwm桌面，且强制关闭所有当前运行于dwm下的程序


    //窗口快捷键
    { MODKEY,              XK_j,                    incnmaster,     {.i = +1 } },     // Win+j 插入主窗格的堆栈，窗口竖向排列
    { MODKEY,              XK_k,                    incnmaster,     {.i = -1 } },     // Win+k 减少主窗格的堆栈数，窗口横向排列
    { MODKEY|ShiftMask,    XK_j,                    rotatestack,    {.i = +1 } },     // Win+shift+j 顺时针循环滚动当前窗口的窗格位置
    { MODKEY|ShiftMask,    XK_k,                    rotatestack,    {.i = -1 } },     // Win+shift+k 逆时针循环滚动当前窗口的窗格位置
    { MODKEY,              XK_minus,                setmfact,       {.f = -0.03} },   // Win+- 将当前的窗格宽度减向左扩展或缩小,调整窗口大小向左
    { MODKEY,              XK_equal,                setmfact,       {.f = +0.03} },   // win++，调整程序窗口的大小,调整窗口大小向右
    /* { MODKEY,              XK_Left,                 setmfact,       {.f = -0.03} },   // Win+left 将当前的窗格宽度减向左扩展或缩小,调整窗口大小向左 */
    /* { MODKEY,              XK_Right,                setmfact,       {.f = +0.03} },   // win+right，调整程序窗口的大小,调整窗口大小向右 */
	{ MODKEY,              XK_m,                    hidewin,        {0} },      // win+m 最小化/隐藏藏 当前窗格
	{ MODKEY|ShiftMask,    XK_m,                    restorewin,     {0} },      // win+shift+m 恢复当前窗口下隐藏的窗格,非全部，一次一个恢复
	{ MODKEY,              XK_o,                    hideotherwins,  {0}},       // win+ o 最小化/隐藏藏除当前外的其他窗格
	{ MODKEY|ShiftMask,    XK_o,                    restoreotherwins, {0}},     // win+shift+o 恢复当前窗口下隐藏除当前外的其他窗格
	{ MODKEY|ShiftMask,    XK_Return,               zoom,           {0} },      // win+shift+回车，窗口位置互换， 将当前窗口与主窗口互换，若是当前是主窗口则将其与上一个窗格互换，并聚焦在主窗格
	{ MODKEY,              XK_Tab,                  view,           {0} },      // 在当前标签页上次聚焦的标签页之间切换
	{ MODKEY,              XK_b,                    view,           {0} },      // 在当前标签页上次聚焦的标签页之间切换
	{ MODKEY,              XK_p,                    spawn,          {.v = windowswitchcmd } },

	{ MODKEY|Mod1Mask,     XK_0,                    setlayout,      {.v = &layouts[0]} },   // win+alt+0 平铺
	{ MODKEY|Mod1Mask,     XK_1,                    setlayout,      {.v = &layouts[1]} },   // win+alt+1 浮动
	{ MODKEY|Mod1Mask,     XK_2,                    setlayout,      {.v = &layouts[2]} },   // win+alt+2 单窗口
	{ MODKEY|Mod1Mask,     XK_3,                    setlayout,      {.v = &layouts[3]} },   // win+alt+3 网格分割,一列两行、两行两列、三行三列..
	{ MODKEY|Mod1Mask,     XK_4,                    setlayout,      {.v = &layouts[4]} },   // win+alt+4 主窗堆在上，副窗堆在下，副窗格垂直分割
	{ MODKEY|Mod1Mask,     XK_5,                    setlayout,      {.v = &layouts[5]} },   // win+alt+5 主窗堆在上，副窗堆在下，副窗格水平分割
	{ MODKEY|Mod1Mask,     XK_6,                    setlayout,      {.v = &layouts[6]} },   // win+alt+6 主窗口在中间，副窗口在左右边，副窗口垂直分割
	{ MODKEY|Mod1Mask,     XK_7,                    setlayout,      {.v = &layouts[7]} },   // win+alt+7 主窗口浮动在中间，副窗口平铺在后面，副窗口水平分割
	{ MODKEY|Mod1Mask,     XK_8,                    setlayout,      {.v = &layouts[8]} },   // win+alt+8 主窗口在左边，新建窗口在右边螺旋摆放
	{ MODKEY|Mod1Mask,     XK_9,                    setlayout,      {.v = &layouts[9]} },   // win+alt+9 与主8类似
	{ MODKEY|Mod1Mask,     XK_minus,                setlayout,      {.v = &layouts[10]} },  // win+alt+- 主窗口在左边，其他窗口像单窗口一样堆叠在右边


	{ MODKEY|ShiftMask,    XK_space,                setlayout,      {0} },              // Alt +shift + 空格,标签页模式切换,将当前标签页的所有窗口在当前标签页最近所处的模式中切换,默认是在平铺和浮动两模式.
	{ MODKEY,              XK_space,                togglefloating, {0} },              // Alt + 空格,窗口模式切换,将当前窗口在当前标签页在最近所处的模式中切换,默认是在平铺和浮动两模式.
	{ MODKEY|ShiftMask,    XK_f,                    fullscreen,     {0} },              // win+shift+f全屏,只能是平铺窗口，不能是浮动窗口全屏

	// { MODKEY,              XK_comma,                focusmon,       {.i = -1 } },  //win+,多屏时在主副屏之间移动焦点, 移动焦点至左边屏幕，
	// { MODKEY,              XK_period,               focusmon,       {.i = +1 } },  //win+. 在多显示器间进行切换, 移动焦点至右边屏幕
	// { MODKEY|ShiftMask,    XK_comma,                tagmon,         {.i = -1 } },	//win+shift+,  在主副屏之间移动窗口, 移动窗口至左边屏幕,但是仍然聚焦在当前屏幕
	// { MODKEY|ShiftMask,    XK_period,               tagmon,         {.i = +1 } },	//win+shift+. 在多显示器间移动, 移动窗口至右边屏幕,但是仍然聚焦在当前屏幕

    /* [和]与win和shift结合是控制在显示器间切换
     * ,和.是控制在一个标签页内切换聚焦窗口；
     * ;和'是控制在不同标签页移动聚焦和移动窗口.
     *
    */
	{ MODKEY,              XK_bracketleft,          focusmon,       {.i = -1 } },  //win+[多屏时在主副屏之间移动焦点, 移动焦点至左边屏幕，
	{ MODKEY,              XK_bracketright,         focusmon,       {.i = +1 } },  //win+]在多显示器间进行切换. 移动焦点至右边屏幕
	{ MODKEY|ShiftMask,    XK_bracketleft,          tagmon,         {.i = -1 } },	//win+shift+[  在主副屏之间移动窗口, 移动窗口至左边屏幕,但是仍然聚焦在当前屏幕
	{ MODKEY|ShiftMask,    XK_bracketright,         tagmon,         {.i = +1 } },	//win+shift+] 在多显示器间移动, 移动窗口至右边屏幕,但是仍然聚焦在当前屏幕
	/* { MODKEY|ShiftMask,    XK_braceleft,            tagmon,         {.i = -1 } },	//win+shift+{  在主副屏之间移动窗口 # 移动窗口至左边屏幕 */
	/* { MODKEY|ShiftMask,    XK_braceright,           tagmon,         {.i = +1 } },	//win+shift+} 在多显示器间移动# 移动窗口至右边屏幕 */

    /* { MODKEY,              XK_Up,                   focusstack,     {.i = +1 } },	  // win+Up 将光标焦点移动到下一个窗格,在窗口间切换 */
    /* { MODKEY,              XK_Down,                 focusstack,     {.i = -1 } },     // win+Down 将光标焦点移动到上一个窗格 */
    { MODKEY,              XK_h,                    focusstack,     {.i = +1 } },	  // win+h 将光标焦点移动到上一个窗格,在同一个标签页的不同窗口间切换,
    { MODKEY,              XK_l,                    focusstack,     {.i = -1 } },     // win+l 将光标焦点移动到下一个窗格,在同一个标签页的不同窗口间切换,
    { MODKEY,              XK_period,               focusstack,     {.i = +1 } },	  // win+, 将光标焦点移动到上一个窗格,在同一个标签页的不同窗口间切换,
    { MODKEY,              XK_comma,                focusstack,     {.i = -1 } },     // win+. 将光标焦点移动到下一个窗格,在同一个标签页的不同窗口间切换,
    { MODKEY,              XK_q,                    focusstack,     {.i = +1 } },	  // win+q 将光标焦点移动到上一个窗格,在同一个标签页的不同窗口间切换,
    { MODKEY,              XK_w,                    focusstack,     {.i = -1 } },     // win+w 将光标焦点移动到下一个窗格,在同一个标签页的不同窗口间切换,

	{ MODKEY|ShiftMask,    XK_h,                    viewtoleft,       {0} },        // win+Shift+h 将光标焦点移动到左边的标签页
	{ MODKEY|ShiftMask,    XK_l,                    viewtoright,      {0} },        // win+shift+l 将光标焦点移动到右边的标签页
	{ MODKEY|ShiftMask,    XK_comma,                viewtoleft,       {0} },        // win+shift+, 将光标焦点移动到左边的标签页
	{ MODKEY|ShiftMask,    XK_period,               viewtoright,      {0} },        // win+shift+. 将光标焦点移动到右边的标签页
    { MODKEY,              XK_semicolon,            viewtoleft,     {0} },        // win+; 将光标焦点移动到左边的标签页
	{ MODKEY,              XK_quoteright,           viewtoright,    {0} },        // win+' 将光标焦点移动到右边的标签页

	{ MODKEY|ControlMask,    XK_comma,              tagtoleft,         {0} },        // win+shift+, 将当前窗口移动到左边的标签页,但是光标焦点仍然聚焦在当前标签页
	{ MODKEY|ControlMask,    XK_period,             tagtoright,        {0} },        // win+shift+. 将当前窗口移动到右边的标签页,但是光标焦点仍然聚焦在当前标签页
	{ MODKEY|ShiftMask,    XK_semicolon,            tagtoleft,      {0} },        // win+shift+; 将当前窗口移动到左边的标签页,但是光标焦点仍然聚焦在当前标签页
	{ MODKEY|ShiftMask,    XK_quoteright,           tagtoright,     {0} },        // win+shift+' 将当前窗口移动到右边的标签页,但是光标焦点仍然聚焦在当前标签页

    { MODKEY,              XK_Left,                viewtoleft,     {0} },        // win+left 将光标焦点移动到左边的标签页
	{ MODKEY,              XK_Right,               viewtoright,    {0} },        // win+right 将光标焦点移动到右边的标签页
	{ MODKEY|ShiftMask,    XK_Left,                tagtoleft,      {0} },        // win+shift+left  将当前窗口移动到左边的标签页,但是光标焦点仍然聚焦在当前标签页
	{ MODKEY|ShiftMask,    XK_Right,               tagtoright,     {0} },        // win+shift+right 将当前窗口移动到右边的标签页,但是光标焦点仍然聚焦在当前标签页

    // Mod + shift + num(1-9),移动窗口至指定的桌面标签,并聚焦于指定标签的桌面，最后参数tags[数字]指定的桌面标签,
    // win+shift+0将当前窗口移动到所有标签页,再做一次win+shift+1-9可以取消这一操作
	{ MODKEY|ShiftMask,    XK_0,                      tag,            {.ui = ~0 } },
    { MODKEY,              XK_0,                      view,           {.ui = ~0 } },// win+1/2/3/4/5/6/7/8/9，切换到不同的dwm顶部菜单栏的标签里,切换标签页,win+0，全部标签页一起查看
	TAGKEYS(               XK_1,                      0)
	TAGKEYS(               XK_2,                      1)
	TAGKEYS(               XK_3,                      2)
	TAGKEYS(               XK_4,                      3)
	TAGKEYS(               XK_5,                      4)
	TAGKEYS(               XK_6,                      5)
	TAGKEYS(               XK_7,                      6)
	TAGKEYS(               XK_8,                      7)
	TAGKEYS(               XK_9,                      8)
};

```




# 我的 dwm 构建
============================

dwm 是一个非常快速, 小巧并使用动态管理窗口的窗口管理器

顺便说一句, 我的脚本都存放在 [此仓库](https://github.com/theniceboy/scripts) 中

要求
------------
构建 dwm 前, 你需要有 `Xlib` 头文件
In order to build dwm you need the Xlib header files.


安装
------------
编辑 `config.mk` 来匹配你的本地设置 (dwm 将默认安装在 /usr/local)

之后通过以下命令安装 dwm (必须使用 root 用户):

    make clean install

应用的自定义补丁
---------------
- [dwm-alpha-20180613-b69c870.diff](https://dwm.suckless.org/patches/alpha/)
- [dwm-autostart-20161205-bb3bd6f.diff](https://dwm.suckless.org/patches/autostart/)
- [dwm-awesomebar-20191003-80e2a76.diff](https://dwm.suckless.org/patches/awesomebar/)
- [dwm-fullscreen-6.2.diff](https://dwm.suckless.org/patches/fullscreen/)
- [dwm-hide-and-restore.diff](https://github.com/theniceboy/dwm-hide-and-restore-win.diff) (我写的自定义补丁)
- [dwm-hide_vacant_tags-6.2.diff](https://dwm.suckless.org/patches/hide_vacant_tags/)
- [dwm-noborder-6.2.diff](https://dwm.suckless.org/patches/noborder/)
- [dwm-pertag-20170513-ceac8c9.diff](https://dwm.suckless.org/patches/pertag/)
- [dwm-r1522-viewontag.diff](https://dwm.suckless.org/patches/viewontag/)
- [dwm-rotatestack-20161021-ab9571b.diff](https://dwm.suckless.org/patches/rotatestack/)
- [dwm-scratchpad-6.2.diff](https://dwm.suckless.org/patches/scratchpad/)
- [dwm-vanitygaps-20190508-6.2.diff](https://dwm.suckless.org/patches/vanitygaps/)


运行 dwm
-----------
将以下行添加到 .xinitrc 中来通过 `startx` 启动 dwm:

    exec dwm

如果你需要使用多显示器启动 dwm, 你需要设置屏幕变量, 以下是一个例子:

    DISPLAY=foo.bar:1 exec dwm

(这样将会启动 dwm 并显示在显示器一上)

如果你想自定义你的状态栏, 你可以在 .xinitrc 添加行, 以下是一个例子:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm
