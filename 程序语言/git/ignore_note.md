# ignore_note

## 设置跟踪忽略文件夹和文件夹中文件

### 常用规则


/mtk/        过滤整个文件夹
规则	 作用
/mtk/		过滤整个文件夹
*.zip	 过滤所有.zip文件
/mtk/do.c	 过滤某个具体文件
!/mtk/one.txt  追踪（不过滤）某个具体文件
注意：如果你创建.gitignore文件之前就push了某一文件，那么即使你在.gitignore文件中写入过滤该文件的规则，该规则也不会起作用，git仍然会对该文件进行版本管理。


### 配置语法
* 以斜杠“/”开头表示目录；
* 以星号“*”通配多个字符；
* 以问号“?”通配单个字符
* 以方括号“[]”包含单个字符的匹配列表；
* 以叹号“!”表示不忽略(跟踪)匹配到的文件或目录。
* 注意： git 对于 .gitignore配置文件是按行从上到下进行规则匹配的 
1. 示例： 假设想要忽略根目录下所有的名为Win7Release或release的文件夹，可在.gitignore文件中添加如下规则
```
*[Rr]elease/
```
2. 若想忽略类似test/bin/目录下名为Win7Release或release的文件夹，则添加规则
```
*/bin/*[Rr]elease/
```
注意：当添加的规则中包含目录层级时，该目录应为相对于根目录的完整路径，上面的规则若修改为bin/*[Rr]elease/是无效的。若想只忽略根目录下名为Win7Release或release的文件夹，可添加规则
```
/*[Rr]elease/
```
3. 跟踪忽略文件夹中文件
假设想要忽略所有的名为Win7Release或release的文件夹下除.txt文件之外的文件，很容易写成如下错误形式
```
*[Rr]elease/
!*[Rr]elease/*.txt
```
注意：上面已经说过git对于.gitignore配置文件是按行从上到下进行规则匹配的，由于先执行*[Rr]elease/忽略了所有符合条件的文件夹，接下来执行!*[Rr]elease/*.txt时找不到名为*[Rr]elease的文件夹，也就无法追踪这些文件夹下的txt文件了。

所以，在这里，第一步我们不应该忽略这些文件夹，而应该忽略这些文件夹下的所有文件，正确规则添加如下
```
*[Rr]elease/*
!*[Rr]elease/*.txt

*/bin/*[Rr]elease/*
!*/bin/*[Rr]elease/*.txt
```
注意：在这里不能交换忽略规则与追踪规则额执行顺序，因为若先执行追踪规则（如!*[Rr]elease/*.txt），接下来执行的忽略规则（如*[Rr]elease/*）会忽略所有文件，包括txt文件！

4. 若我们想要追踪的txt文件在*[Rr]elease文件夹下名为files的文件夹内，上面的规则是错误的，因为执行的忽略规则的时候已经忽略了files文件夹，所以在后面直接添加追踪命令（如!*[Rr]elease/files/*.txt）是无效的，正确规则添加如下
```
*[Rr]elease/*
!*[Rr]elease/*.txt
!*[Rr]elease/files/
*[Rr]elease/files/*
!*[Rr]elease/files/*.txt

*/bin/*[Rr]elease/*
!*/bin/*[Rr]elease/*.txt
!*/bin/*[Rr]elease/files/
*/bin/*[Rr]elease/files/*
!*/bin/*[Rr]elease/files/*.txt
```

说明： 
1. 执行*[Rr]elease/*，忽略根目录下符合条件的文件夹下的所有文件 
2. 执行!*[Rr]elease/*.txt，追踪根目录下符合条件的文件夹下的txt文件 
3. 执行!*[Rr]elease/files/，追踪根目录下符合条件的文件夹下的files文件夹 
4. 执行*[Rr]elease/files/*，忽略files文件夹下的所有文件 
5. 执行!*[Rr]elease/files/*.txt，追踪files文件夹下的txt文件

参考链接 
http://www.cnblogs.com/kevingrace/p/5690241.html 
http://stackoverflow.com/questions/5533050/gitignore-exclude-folder-but-include-specific-subfolder