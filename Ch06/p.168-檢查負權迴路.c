//測資
//5 7
//1 2 2
//1 5 10
//2 3 3
//2 5 7
//3 4 4
//4 5 5
//5 3 3



//這裡不能使用 p.164 的檢查負迴圈方式
//因為 p.164 的檢查是建立在最短路徑不超過 n-1 條邊的前提上
//所以當 n-1 次迴圈跑完
//再檢查一次m條邊可否鬆弛，就知道是不是有負權迴路了。
//
//但是Bellman-Ford的佇列優化，會不斷更新有改變的頂點放到佇列尾
//因為沒有 n-1 次的停止，所以也無法做再一次的檢查
//但是程式依舊會停止，是因為佇列que有大小限制。
//
//不過其實只要能夠檢查一個點進入佇列的次數超過n次，就肯定有負權迴圈(負環)了!
//因為總共n個點，所以最大的環也只是n-1而已!!




#include <stdio.h>

int main(){
    int n, m, i, j, k;

    //u、v和w的陣列大小要根據實際情況來設定
    int u[8], v[8],w[8];

    //first要比頂點數n的最大值要大1，next要比m的最大值要大1
    int first[6], next[8];

    int dis[6]={0}, book[6]={0};
    //book陣列用來紀錄那些頂點已經在佇列中
    //用book陣列比起用迴圈檢查一遍，時間複雜度減少很多!!

    int que[101]={0}, head=1, tail=1;   //定義一個佇列，並初始化佇列
    int inf=99999999;   //用inf(infinity的縮寫)儲存一個我們認為的正無窮值

    //檢查負權迴路是否存在的變數
    int check[6]={0};   //first要比頂點數n的最大值要大1
    int flag;


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
    flag=0;
    check[1]=1;

    while(head<tail){   //佇列不為空的時候迴圈

        //如果有一個數字進入佇列的次數超過n次(>=n)，就代表有負環!
        if(check[que[head]]==n){
            flag=1;
            break;  //跳出while(head<tail)的迴圈
        }

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

                    check[v[k]]=check[v[k]]+1;
                }
            }
            k=next[k];
        }
        //出佇列
        printf("\n離開佇列首囉：%d", que[head]);
        book[que[head]]=0;
        head=head+1;

    }

    printf("\n\n");
    if(flag==1){
        printf("有負迴圈存在\n");
    }else{
        printf("沒有負迴圈存在\n");
    }
    //輸出1號頂點到其餘各個頂點的最短路徑
    for(i=1;i<=n;i=i+1){
        printf("%d ", dis[i]);
    }

    getchar();
    getchar();
    return 0;
}




