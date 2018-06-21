# 1. using_note

## 1.1. 启动时出现黑屏现象或是如下警告

警告: MATLAB 先前因底层图形错误而崩溃。为避免在此会话期间再次崩溃，MATLAB 将使用软件 OpenGL 而不再使用图形硬件。要保存该设置以供此后的会话使用，请使用 opengl('save', 'software') 命令。有关详细信息，请参见解决底层的图形问题。

解决方法：
1. 如果能够进入命令窗口（matlab的命令窗口），使用命令：

```matlab
opengl('save', 'software')
```
2. 不能进入，启动黑屏，则在命令行 doc中，输入

```doc
matlab -r opengl('save', 'software')
```