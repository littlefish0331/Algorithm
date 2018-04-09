//5 5
//圖的邊
//1 2
//1 3
//1 5
//2 4
//3 5

#include <stdio.h>

int main(){
    int i, j, n, m, a, b, cur, book[101]={0}, e[101][101];
    int que[10001], head, tail;

    scanf("%d %d", &n, &m); //n是點的個數；m是總共有多少邊的資訊要輸入。

    //初始化二維陣列
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=n;j=j+1){
            if(i==j){
                e[i][j]=0;
            }else{
                e[i][j]=99999999;   //我們這裡假設99999999為正無窮。
            }
        }
    }

    //讀入頂點之間的邊
    for(i=1;i<=m;i=i+1){
        scanf("%d %d", &a, &b);
        e[a][b]=1;
        e[b][a]=1;  //這是無向圖，所以需要將e[b][a]也賦值為1
    }

    //佇列初始化
    head=1;
    tail=1;

    //從1號頂點出發，將1號頂點加入佇列
    que[tail]=1;
    tail=tail+1;
    book[1]=1;  //標記1號頂點已存取。

    //當佇列不為空的時候進行迴圈
    while(head<tail){
        cur=que[head];  //目前正在存取的頂點編號
        for(i=1;i<=n;i=i+1){    //1~n依次嘗試
            //判斷目前頂點cur到頂點i是否有邊
            //判斷頂點i是否已存取過
            if(e[cur][i]==1 && book[i]==0){
                //如果從頂點cur到頂點i有邊，並且頂點i沒有被存取過，則將頂點i入佇列
                que[tail]=i;
                tail=tail+1;
                book[i]=1;  //標記頂點i已存取
            }

            //如果tail大於n，則表示所有頂點都已經被存取過了
            if(tail>n){
                break;
            }
        }

        //注意!!當一個點擴展結束之後，head=head+1，然後才能繼續往下擴展。
        head=head+1;

    }

    for(i=1;i<tail;i=i+1){
        printf("%d ", que[i]);
    }

    getchar();
    getchar();
    return 0;

}
