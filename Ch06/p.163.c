//測資
//5 5
//2 3 2
//1 2 -3
//1 5 5
//4 5 2
//3 4 3

#include <stdio.h>

int main(){
    int dis[10], i, k, n, m, u[10], v[10], w[10];
    int inf=99999999;   //用inf(infinity的縮寫)儲存一個我們認為的正無窮值

    //讀入n和m，n表示頂點個數，m表示邊的條數
    scanf("%d %d", &n, &m);

    //讀入邊
    for(i=1;i<=m;i=i+1){
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    //初始化dis陣列，這裡是1號頂點(源點)到其餘各點的初始路程，先都設定為無限大。
    for(i=1;i<=n;i=i+1){
        dis[i]=inf;
    }
    dis[1]=0;   //先把自己到自己訂為0。

    //Bellman-Ford演算法核心
    //進行n-1輪，每一輪都做m條邊鬆弛。
    for(k=1;k<=n-1;k=k+1){
        for(i=1;i<=m;i=i+1){
            if(dis[v[i]]>dis[u[i]]+w[i]){
                printf("\n第%d輪-第%d行，原本dis[%d]=%d，經過%d→%d=%d縮短"
                       , k, i, v[i], dis[v[i]], u[i], v[i], dis[u[i]]+w[i]);
                dis[v[i]]=dis[u[i]]+w[i];
            }
        }

        printf("\n第%d輪，m條邊鬆弛後的成果：\n");
        for(i=1;i<=n;i=i+1){
            printf("%d ", dis[i]);
        }

    }

    //輸出最終的結果
    printf("\n");
    for(i=1;i<=n;i=i+1){
        printf("%d ", dis[i]);
    }

    getchar();
    getchar();
    return 0;

}


