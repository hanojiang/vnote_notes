# source code + contrib 编译安装笔记

## 文件下载

* source code https://github.com/opencv/opencv/releases
* contrib code https://github.com/opencv/opencv_contrib/releases

## cmake 配置

目的是通过cmakelist 生成Makefile

* 配置vs编译器 选择vs2015 win64 ，点击finish 开始第一次配置
* 添加不同配置选项，如example -> c、python example; module -> contrib module 路径;python -> 版本选择，python3.5等，点击configure 开始第二次配置。
* 点击generate 开始生成项目
* 点击open project 使用vs 打开项目，准备编译。

## vs2015 生成

* 对整个项目生成解决方案
* 右击 INSTALL 仅应用于项目->仅生成 INSTALL，开始生成相关文件
* 注：在debug和release模式下分别生成一次，得到对应的*r.dll和*.dll文件。

## 配置项目环境

* https://www.zhihu.com/question/24400428/answer/88284063
* 注意备份制作的项目属性表，在不同项目下，添加复制即可

## 安装时的其它问题

* 第三方文件下载问题，如FFmpeg，ippicv等，自己下载，并放到对应位置上，具体位置通过cmake错误获取，一般要与文件的hash码作为文件名
* 参考https://blog.csdn.net/Kelvin_Yan/article/details/53635641