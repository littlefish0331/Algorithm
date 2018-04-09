#include <stdio.h>
int main(){
    int a[101], n, i ,j, t;

    scanf("%d", &n);
    for(i=1;i<=n;i=i+1){
        scanf("%d", &a[i]);
    }

    //開始氣泡排序
    for(i=1;i<=n-1;i=i+1){
        for(j=1;j<=n-i;j=j+1){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

    printf("%d ", a[1]);
    for(i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            printf("%d ", a[i]);
        }
    }

    getchar();
    getchar();
    return 0;

}
