# vim 插件安装及使用

## vim 主程序安装 vim 8.0以上

* 下载vim源码
* 编译及安装

```bash
git clone https://github.com/vim/vim.git
#编译vim
cd vim
##python版本时具体情况
./configure  --enable-pythoninterp=yes --with-python-config-dir=/usr/lib/python3.7/config
make
#安装vim
#原文：https://blog.csdn.net/rankun1/article/details/78775404
make install
```

## 安装 vim-plug 插件安装管理器

### 下载 vim-plug

```bash
#注意创建文件夹的权限，对于普通用户 whj的要有写权限，sudo chmod 777 -R ~/.vim
mkdir ~/.vim/autoload/
mkdir ~/.vim/plugged
cd ~/.vim/autoload/
wget https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
```

### 配置vim plug

```bash
vim ~/.vimrc
```

将要安装的插件写入~/.vimrc，这里以ycm插件为例（一款c系列自动补全插件），具体内容为：

```txt
call plug#begin('~/.vim/plugged')
Plug 'Valloric/YouCompleteMe'
call plug#end()
```

### 插件安装

在bash 中打开 vim ,在命令模式中输入一下命令，注意出现安装权限不足问题时，检查 ~/.vim 文件夹对 whj 用户的访问权限，主要是写权限。

```vim
# 查看插件类型
:PlugStatus
# 安装插件
:PlugInstall
# 更新插件
:PlugUpdate
# vim-plug本身更新
:PlugUpgrade
```

## YouCompleteMe 安装

使用 :PlugInstall 然后安装完成之后, 输入 :qa 退出 vim, 然后再打开 vim, 如果出现:

Tht ycmd server SHUT DOWN (restart with ':YcmRestartServer'). YCM core library...

他的意思是 ycmd 的服务器关闭了, 需要重启 ycmd 的服务器, 输入:

:YcmRestartServer

如果输入这行命令之后, 关闭 vim 再打开 vim 就没有那行提示的话, 就说明 YCM 插件已经装好了, 已经可以开始畅想 YCM 自动补全的高效率了.

但是…. 有时候偏偏这样就不行….. 那么我们就要采用第三种办法了: 编译安装.

由于前面我们已经把 YCM 插件克隆在本地了, 所以只要安装必要的编译组件就可以开始编译安装了:

```bash
# 主要保证安装了python3 和 cmake
#Debian(vim-plug):
su
aptitude install cmake python3-dev build-essential
python3 /home/你的用户名/.vim/plugged/YouCompleteMe/install.py --clang-completer
#Manjaro(vim-plug):
su
pacman -S cmake python-dev
python3 /home/你的用户名/.vim/plugged/YouCompleteMe/install.py --clang-completer
```

最后，确保正常使用，需要在 .vimrc 中加入

let g:ycm_global_ycm_extra_conf='~/.vim/plugged/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py’

这是全局的YCM配置文件，可以再自己的项目文件中复制，自定义，减小配置文件大小，并在打开vim 时导入。

出现c++ 标准头文件不能自动提示的情况，修改 .ycm_extra_conf 文件，在  Flag 中加入头文件路径，如string 头文件的路径在 /usr/include/c++/版本/，对应的Flag 是 '-isystem'