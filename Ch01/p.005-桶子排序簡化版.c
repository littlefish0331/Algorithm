#include <stdio.h>
int main(){

    int a[11], i, j, t;

    for(i=0;i<=10;i=i+1){   //i=i+1可以用i++。
        a[i]=0;
    }
    //上面這個迴圈是先把大小為11的一為陣列，a[1]到a[10]的值，初始化為0。

    for(i=1;i<=5;i=i+1){
        scanf("%d", &t);
        a[t]=a[t]+1;    //a[t]=a[t]+1;，可以用a[t]++;。
    }
    //把每一個數讀到變數t
    //在對陣列進行計數。

    for(i=0;i<=10;i=i+1){
        for(j=1;j<=a[i];j=j+1){
           printf("%d ", i);
        }
    }
    //依次判斷a[0]到a[10]這一維陣列的值。
    //值為多少，就是出現幾次，那就印出幾次。

    getchar();
    getchar();
    //system("PAUSE");
    //這裡的getchar是用來暫停程式的，以便查看程式輸出的內容。
    //也可以用system("PAUSE");來做代替

    return 0;
}
