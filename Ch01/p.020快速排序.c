#include <stdio.h>

//定義全域變數，這兩個變數需要在子函數中使用。
int a[101], n;

void quicksort(int left, int right){
    int i, j, t, temp, k;
    if(left>right) return; //這邊不可以寫return 0;因為quicksort這個子函數回傳的是void。
    //這一行是避免主程式的變數n輸入小於1的數字。
    //我覺得這裡可以改>=

    temp=a[left];   //temp中存的就是基準數。
    i=left;
    j=right;

    while(i!=j){
        //順序很重要，要先從右往左找。
        while(a[j]>=temp && i<j){   //這個while打破的條件，就是找到比基準數小的數，或是i=j了。
            j=j-1;
        }

        //再從左往右找。
        while(a[i]<=temp && i<j){   //這個while打破的條件，就是找到比基準數大的數，或是i=j了。
            i=i+1;
        }

        //交換兩個數在陣列中的位置。
        //if的前提是衛兵i與衛兵j沒有相遇
        if(i<j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;

//            for(k=1;k<=n;k=k+1){      //這邊可以看到過程中是怎麼交換的。
//                printf("%d ", a[k]);
//            }
//            printf("\n");
        }

    }

    //最終將基準數歸位。
    a[left]=a[i];   //我覺得這裡可以是a[j]，因為就是上面while的部分結束了，所以這時i=j。
    a[i]=temp;      //我覺得這裡可以是a[j]，因為就是上面while的部分結束了，所以這時i=j。

//    for(k=1;k<=n;k=k+1){
//        printf("%d ", a[k]);
//    }
//    printf("基準數歸位\n");

    quicksort(left, i-1);   //繼續處理基準數左邊的序列，是一個遞迴的過程。
    quicksort(i+1, right);  //繼續處理基準數右邊的序列，是一個遞迴的過程。

}

int main(){
    int i, j;

    scanf("%d", &n);
    for(i=1;i<=n;i=i+1){
        scanf("%d", &a[i]);
    }

    quicksort(1, n);    //快速排序呼叫。

    for(i=1;i<=n;i=i+1){
        printf("%d ", a[i]);
    }
    //printf("最終結果。\n");

    getchar();
    getchar();

    return 0;
}

