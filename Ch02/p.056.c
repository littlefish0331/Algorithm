#include <stdio.h>
int main(){
    int data[101], right[101];
    int i, n, t, len;

    //讀入已有的數字
    scanf("%d", &n);

    for(i=1;i<=n;i=i+1){
        scanf("%d", &data[i]);
    }

    len=n;

    //初始化陣列right
    for(i=1;i<=n;i=i+1){
        if(i!=n){
            right[i]=i+1;
        }else{
            right[i]=0;
        }
    }

    //直接在陣列data的末尾增加一個數字
    len=len+1;
    scanf("%d", &data[len]);

    //從鏈結串列的頭部開始走訪
    t=1;
    while(t!=0){

        //如果目前節點下一個節點的值，大於待插入數字，將數插入到中間
        if(data[right[t]]>data[len]){
            right[len]=right[t];
            right[t]=len;\
            break;
        }
        t=right[t];
    }

    //輸出鏈結串列中所有的數字
    t=1;
    while(t!=0){
        printf("%d ", data[t]);
        t=right[t];
    }

    getchar();
    getchar();
    return 0;
}
