//測資
//4 8
//1 2 2
//1 3 6
//1 4 4
//2 3 3
//3 1 7
//3 4 1
//4 1 5
//4 3 12


#include <stdio.h>

int main(){

    int e[10][10], k, i, j, n, m, t1, t2, t3;
    int inf=9999999;    //用inf(infinity的縮寫)儲存一個我們認為的正無窮值

    //讀入n和m。n表示頂點個數，m表示邊的條數。
    scanf("%d %d", &n, &m);

    //初始化
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=n;j=j+1){
            if(i==j){
                e[i][j]=0;
            }else{
                e[i][j]=inf;
            }
        }
    }

    //讀入邊
    for(i=1;i<=m;i=i+1){
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2]=t3;
    }


    //如果要指定一點到其餘各點的最短路徑
    //i=指定的點即可
    //i=2;


    //Floyd-Warshall演算法核心語句
    for(k=1;k<=n;k=k+1){
        for(i=1;i<=n;i=i+1){
            for(j=1;j<=n;j=j+1){
                if(e[i][j]>e[i][k]+e[k][j]){
                    e[i][j]=e[i][k]+e[k][j];
                }
            }
        }
    }

    //輸出最終的結果
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=n;j=j+1){
            printf("%10d", e[i][j]);
        }
        printf("\n");
    }

    return 0;

}



