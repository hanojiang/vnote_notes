# bash语法总结

## 排量修改文件后缀名

```bash
# 循环
for name in `ls *.html`;do mv $name ${name%.html}.jpg;done
# sed
ls *jpg|sed -r 's#(.*).jpg#mv &  \1.mp4#'|bash
# rename 需要安装模块
rename txt jpg *
```