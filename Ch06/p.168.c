//測資
//5 7
//1 2 2
//1 5 10
//2 3 3
//2 5 7
//3 4 4
//4 5 5
//5 3 3


#include <stdio.h>

int main(){
    int n, m, i, j, k;

    //u、v和w的陣列大小要根據實際情況來設定
    int u[8], v[8],w[8];

    //first要比n的最大值要大1，next要比m的最大值要大1
    int first[6], next[8];

    int dis[6]={0}, book[6]={0};
    //book陣列用來紀錄那些頂點已經在佇列中
    //用book陣列比起用迴圈檢查一遍，時間複雜度減少很多!!

    int que[101]={0}, head=1, tail=1;   //定義一個佇列，並初始化佇列
    int inf=99999999;   //用inf(infinity的縮寫)儲存一個我們認為的正無窮值

    //讀入n和m，n表示個數，m表示邊的條數
    scanf("%d %d", &n, &m);

    //初始化dis陣列，這裡是1號頂點到其餘各個頂點的初始路程
    for(i=1;i<=n;i=i+1){
        dis[i]=inf;
    }
    dis[1]=0;

    //初始化book陣列，初始化為0，剛開始都不在佇列中
    for(i=1;i<=n;i=i+1){
        book[i]=0;
    }

    //初始化first陣列下標1~n的值為-1，表示1~n頂點暫時都沒有邊
    for(i=1;i<=n;i=i+1){
        first[i]=-1;
    }

    for(i=1;i<=m;i=i+1){
        //讀入每一條邊
        scanf("%d %d %d", &u[i], &v[i],&w[i]);

        //下面兩句是鄰接串列的關鍵
        next[i]=first[u[i]];
        first[u[i]]=i;
    }

    //1號頂點入佇列
    que[tail]=1;
    tail=tail+1;
    book[1]=1;  //標記1號頂點已經入陣列

    while(head<tail){   //佇列不為空的時候迴圈
        printf("\n現在換誰囉：%d", que[head]);
        k=first[que[head]]; //目前需要處理的佇列首頂點

        //掃描目前頂點所有的邊
        while(k!=-1){
            if(dis[v[k]]>dis[u[k]]+w[k]){
                printf("\n有做調整的點：%d", v[k]);
                dis[v[k]]=dis[u[k]]+w[k];   //更新頂點1到頂點v[k]的路程

                //這邊book陣列用來判斷頂點v[k]是否在佇列中
                //如果不使用伊格陣列來標記的話，判斷一個頂點是否在佇列中
                //每次都需要從佇列的head到tail掃一遍，很浪費時間
                if(book[v[k]]==0){
                    printf("\n加入佇列尾的點：%d", v[k]);
                    //下面兩句是佇列操作
                    que[tail]=v[k];
                    tail=tail+1;
                    book[v[k]]=1;   //同時標記頂點v[k]已經入佇列
                }
            }
            k=next[k];
        }
        //出佇列
        printf("\n離開佇列首囉：%d", que[head]);
        book[que[head]]=0;
        head=head+1;

    }

    printf("\n");
    //輸出1號頂點到其餘各個頂點的最短路徑
    for(i=1;i<=n;i=i+1){
        printf("%d ", dis[i]);
    }

    getchar();
    getchar();
    return 0;
}




