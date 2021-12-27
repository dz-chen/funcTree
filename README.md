
# 概述
函数调用关系动态分析,借助gcc的-finstrument-functions编译选项实现  
**原理**:-finstrument-functions选项会在所有函数调用前后插入钩子函数,我们在钩子函数中将当前函数的地址输出到文件,最终读取地址文件并到ELF文件中查找函数名,得到函数调用关系  
```
./instrument.c      -finstrument-functions选项对应的钩子函数及其实现
./test.c            示例代码,包含待跟踪函数
./Makefile          执行make test编译出可执行文件
./trace.txt         执行可执行文件后生成,记录函数地址
./get_functree.sh   shell脚本,读取trace.txt并到ELF文件中查找函数名,最终打印函数调用关系
```

# 测试
- 1.编译出可执行文件test
```
make test
```
- 2.执行test
```
./test

得到trace.txt 如下:
Enter	0x400783
Enter	0x4007cd
Enter	0x400832
Enter	0x40089f
Exit	0x40089f
......
```
- 3.通过脚本获取函数调用关系
```
get_functree.sh test trace.txt
```
- 4.结果示例
```
the func tree is:
main
    test_func1
        test_func2
            test_func3
            test_func4
        test_func5
```