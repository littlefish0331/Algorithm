#include <stdio.h>
int main(void){
    int a[1001], n, i, t;

    for(i=1;i<=1000;i=i+1){
        a[i]=0;
    }
    //將陣列先初始化。

    scanf("%d", &n);    //讀入n
    for(i=1;i<=n;i=i+1){
        scanf("%d", &t);
        a[t]=1;
    }
    //迴圈讀入n個號碼
    //把號碼讀入變數t中
    //標記出現過的號碼。

    for(i=1;i<=1000;i=i+1){
        if(a[i]==1){
            printf("%d ", i);
        }
    }

    getchar();
    getchar();
    return 0;

}

