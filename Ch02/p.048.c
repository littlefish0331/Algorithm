#include <stdio.h>
#include <stdlib.h>

int main(){
    //兩種寫法等價
    //malloc(4);
    //malloc(sizeof(int))

    int *p;     //定義一個指標
    p=(int *)malloc(sizeof(int));       //指標p獲取動態分配的記憶體空間位址
    *p=10;      //向指標p所指向的記憶體空間存入10
    printf("%d", *p);   //輸出指標p所指向的記憶體中的值。

    getchar();
    getchar();

    // 釋放記憶體空間
    free(p);

    return 0;
}
