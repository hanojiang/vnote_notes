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

参考链接:https://www.jianshu.com/p/80d0ec113c0a