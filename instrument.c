
#include <stdio.h>
#include <stdlib.h>

/*
 * 在main函数开始的地方执行; 负责创建 trace.txt 文件用于存放函数地址信息
 */
void main_enter() __attribute__ ((no_instrument_function,constructor));

/*
 * 在main函数结尾处执行; 负责关闭 trace.txt 文件
 */
void main_exit() __attribute__((no_instrument_function,destructor));


/*
 * gcc加上-finstrument-functions, 会自动在函数的入口调用 __cyg_profile_func_enter()
 * no_instrument_function属性防止 __cyg_profile_func_enter 自身被插入这个函数,从而形成递归
 * 负责打印当前函数(即__cyg_profile_func_enter插入的那个函数)地址
 */
void __cyg_profile_func_enter (void *this_fn, void *caller_fn)
    __attribute__((no_instrument_function));

/*
 * gcc加上-finstrument-functions,会自动在函数的出口调用 __cyg_profile_func_exit()
 * no_instrument_function属性防止 __cyg_profile_func_exit 自身被插入这个函数,从而形成递归
 */ 
void __cyg_profile_func_exit  (void *this_fn, void *caller_fn)
    __attribute__((no_instrument_function));


/*********************************** 实现 ***************************************************/

/* trace.txt */
static FILE* fp;

void main_enter(){
    fp=fopen("trace.txt","w");
    if(!fp){
        printf("open trace.txt failed");
        exit(-1);
    }
}


void main_exit(){
    if(!fp){
        printf("fp of trace.txt is NULL");
        exit(-1);
    }
    fclose(fp);
}


void __cyg_profile_func_enter (void *this_fn, void *caller_fn){
    fprintf(fp,"Enter\t%p\n",(unsigned int*)this_fn);
}


void __cyg_profile_func_exit  (void *this_fn, void *caller_fn){
    fprintf(fp,"Exit\t%p\n",(unsigned int*)this_fn);
}