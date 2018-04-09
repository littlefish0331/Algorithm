#include <stdio.h>
int main(){
    int a[100], i, j, t, n;     //a[100]表示最多可以排100個數字。

    scanf("%d", &n);

    for(i=1;i<=n;i=i+1){
        scanf("%d", &a[i]);
    }

    for(i=1;i<=n-1;i=i+1){      //n個數字排序，只需要進行n-1趟。
        for(j=1;j<=n-i;j=j+1){  //從第一位開始比較，到最後一個尚未歸位的數字。注意n-i。
            if(a[j]<a[j+1]){    //比較大小並交換。目前為大到小排列。
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

    for(i=1;i<=n;i=i+1){
        printf("%d ", a[i]);
    }

    getchar();
    getchar();

    return 0;
}
