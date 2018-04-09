#include <stdio.h>
struct student{
    char name[21];  //規範儲存名字的長度。
    char score;
};
//這裡新建一個結構體用來儲存姓名和分數。
//記得加分號(;)

int main(){
    struct student a[100], t;   //表示student這樣的結構有100個。
    int i, j, n;

    scanf("%d", &n);

    for(i=1;i<=n;i=i+1){
        scanf("%s %d", a[i].name, &a[i].score); //輸入的格式要一致程式才讀得懂。
    }
    //迴圈讀入n個人名與分數。
    //注意儲存人名的地方不用加&，但是儲存分數的地方還是要加&。

    for(i=1;i<=n-1;i=i+1){      //n個數字排序，只需要進行n-1趟。
        for(j=1;j<=n-i;j=j+1){  //從第一位開始比較，到最後一個尚未歸位的數字。注意n-i。
            if(a[j].score<a[j+1].score){    //比較大小並交換。目前為大到小排列。
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

    for(i=1;i<=n;i=i+1){
        printf("%s\n", a[i].name);
    }

    getchar();
    getchar();

    return 0;
}

