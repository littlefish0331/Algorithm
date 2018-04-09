#include <stdio.h>
int main(){
    int a=10;
    int *p;     //定義一個指標p

    p=&a;       //指標p獲取變數a的位址
    printf("%d", *p);   //輸出指標p所指向記憶體中的值

    getchar();
    getchar();
    return 0;
}
