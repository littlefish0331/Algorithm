#include <stdio.h>

//定義全域變數
int a[101], n;

int main(){
    int i;
    scanf("%d", &n);
    for(i=1;i<=n;i=i+1){
        scanf("%d", &a[i]);
    }

    quicksort(1,n);

    //輸出排序後的結果
    printf("%d ", a[1]);
    for(i=2;i<=n;i=i+1){
        if(a[i]!=a[i-1]){
            printf("%d ", a[i]);
        }
    }
}


void quicksort(int left, int right){
    int i, j, t, temp;  //函式裡面的i，不會和主程式的i衝突。
    if(left>right){
        return;
    }

    temp=a[left];   //temp即為基準數。

    i=left;
    j=right;

    while(i!=j){
        //順序很重要，要先從右往左找。
        while(a[j]>=temp && i<j){
            j=j-1;
        }

        //再從左往右找。
        while(a[i]<=temp && i<j){
            i=i+1;
        }

        //交換兩數在陣列中的位置。
        if(i<j){    //當哨兵i和哨兵j還沒有相遇時。
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }

    //最終將基準數歸位。
    a[left]=a[i];
    a[i]=temp;

    quicksort(left, i-1);
    quicksort(i+1, right);

}



