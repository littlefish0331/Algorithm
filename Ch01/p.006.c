#include <stdio.h>
int main(){
    int book[1001], i, j, t, n;

    for(i=0;i<=1000;i=i+1){
        book[i]=0;
    }

    scanf("%d", &n);
    //輸入一個數字n，表示接下來有n個數字要排序。

    for(i=1;i<=n;i=i+1){
        scanf("%d", &t);
        book[t]=book[t]+1;
    }
    //迴圈輸入n個數字，並進行桶子排序。
    //小心迴圈的起始值。
    //每一次的迴圈，把數字讀到變數t中
    //接著進行計數，對編號為t的桶子(也就是book[t])，放上一個小旗子。

    for(i=1000;i>=0;i=i-1){
        for(j=1;j<=book[i];j=j+1){
            printf("%d ", i);
        }
    }

    getchar();
    getchar();

    return 0;

}
