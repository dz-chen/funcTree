#!/bin/bash
 
if [ $# != 2 ]; then
    echo 'Usage: get_functree.sh executefile addressfile'
    exit
fi;
 

echo "the func tree is:"

# 打印当前函数时应该缩进多少
indent_cnt=0


while read line
    do
        if  [[ "$line" == *Enter* ]]; then
            let indent_cnt=indent_cnt+1
        elif [[ "$line" == *Exit* ]] ; then
            let indent_cnt=indent_cnt-1
            continue
        fi

        indent=""
        for (( i=1; i< $indent_cnt; i++ ))
            do
                indent=${indent}"    "
            done

        echo -n "$indent"                                # -n不换行
        arr=($(echo $line | tr "    " " "))              # 必须要外层括号才构成数组
        # -e --exe=<executable>  Set the input file name (default is a.out)
        # -f --functions         Show function names
        addr2line ${arr[1]} -e $1 -f | grep -v ':'       # 过滤掉函数所在文件及行号
        
    done < $2
