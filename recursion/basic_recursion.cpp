//递归的原理
//反向打印字符串

#include <iostream>

using namespace std;

void printReverse(const char *str)
{
    if(!*str) return;

    printReverse(str + 1);

    putchar(*str);
}

int main()
{
    const char *str;

    char tmp[] = "My name is Lin Jiawei.";
    
    str = tmp;

    printReverse(str);

    system("pause");

    return 0;
}