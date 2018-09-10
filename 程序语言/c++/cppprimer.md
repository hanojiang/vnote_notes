# chapter 9

## 9.3 顺序容器操作

### 9.3.1 添加元素

| 容器类型 | 插入元素合适位置 | push_back | push_front | insert           | emplace          | emplace_front | emplace_back |
| ------------ | ------------------ | --------- | ---------- | ---------------- | ---------------- | ------------- | ------------ |
| vector       | 尾部，随机访问 | T         |            | T                | 在容器中构造对象 |               |              |
| string       | 尾部，随机访问 | T         |            | T                | 区别于前者是拷贝 |               |              |
| deque        | 首尾，随机访问 | T         | T          | T                |                  |               |              |
| list         | 任意位置，双向访问 | T         | T          | T                |                  |               |              |
| forward_list | 任意位置，单项访问 | F         | T          | T特殊版本    |                  |               |              |
| array        | 固定大小，随机访问 | F         |            |                  |                  |               |              |
|              |                    | 尾部添加 | 头部添加 | 指定迭代器前添加 | 对应insert     | push_front    | push_back    |

### 9.3.2 访问元素

* 首尾元素访问，成员函数返回的是引用

```c++
int main(int argc, char const *argv[])
{
    vector <int> a{1, 2, 3, 4};
    auto i = a.front();\\引用指向元素的拷贝
    i = 22;
    for(auto j : a)
    {
        cout << j << endl;
    }
    int & ii = a.front();\\返回首元素的引用
    ii = 2222;
    // a.front() = 222;
    for(auto j : a)
    {
        cout << j << endl;
    }
    system("pause");
    return 0;
}

output:
1
2
3
4
2222
2
3
4
```

* 