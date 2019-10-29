# manjaro using-note

## 更换国内源

```bash

sudo pacman-mirrors -i -c China -m rank
## 更新源列表
sudo pacman-mirrors -g

## 更新pacman数据库并全面更新系统
sudo pacman -Syyu
```

手动设置源

```bash
sudo vi /etc/pacman.conf

## 添加以下内容
[archlinuxcn]
SigLevel = Optional TrustedOnly
Server = http://repo.archlinuxcn.org/$arch
```
记得添加秘钥
sudo pacman -S  archlinuxcn-keyring
参考链接:https://www.jianshu.com/p/80d0ec113c0a

## 安装搜狗拼音

```bash
    sudo pacman -S fcitx-im #默认全部安装
    sudo pacman -S fcitx-configtool
    sudo pacman -S fcitx-sogoupinyin
```
修改 ~/.xprofile 文件
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS="@im=fcitx"
解决候选框乱码问题，使用命令
sudo rm -rf SogouPY* sogou*

记得重启系统
    
如果还有其他问题，参考博客 https://blog.csdn.net/qq_37788081/article/details/78712853 添加相应文件
    
## 安装zsh
https://segmentfault.com/a/1190000013612471
安装zsh 默认是安装的

安装 oh-my-zsh
sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"

替换默认bash

chsh -s /bin/zsh 

或者直接修改 /etc/passwd 关于使用账户对应的sh类型，如haojiang

修该zsh 主题为candy
## 安装vscode

## 安装chrome

sudo pacman -S google-chrome

## texlive

https://mirrors.tuna.tsinghua.edu.cn/CTAN/systems/texlive/Images

sudo mount -o loop texlive.iso /mnt
cd /; sudo umount /mnt

PATH=/usr/local/texlive/2018/bin/x86_64-linux:$PATH;export PATH
MANPATH=/usr/local/texlive/2018/texmf-dist/doc/man:$MANPATH;export MANPATH
INFOPATH=/usr/local/texlive/2018/texmf-dist/doc/info:$INFOPATH;export INFOPATH 

source ~/.bashrc
更换ctan源
tlmgr option repository https://mirrors.tuna.tsinghua.edu.cn/CTAN/systems/texlive/tlnet

tlmgr update --self --all 更新
## 安装texstudio


参考链接: https://www.jianshu.com/p/80d0ec113c0a