#include<stdio.h>

int test_func1(int param);
double test_func2(char ch);
float test_func3(int param1,double param2);
void test_func4();
char test_func5(double x);

int main(int argc,char** argv){
    test_func1(1);
    return 0;
}

/******************************************************************************/
int test_func1(int param){
    int x=1;
    test_func2('a');
    test_func5(1.111111);
    return 0;
}

double test_func2(char ch){
    int y=2;
    test_func3(1,99.999);
    test_func4();
    return 0.0;
}

float test_func3(int param1,double param2){
    int z=3;
    return 0.0;
}

void test_func4(){
    int a=0;
}

char test_func5(double x){
    int b=0;
}
