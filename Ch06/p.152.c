//測資
//6 9
//1 2 1
//1 3 12
//2 3 9
//2 4 3
//3 5 5
//4 3 4
//4 5 13
//4 6 15
//5 6 4


#include <stdio.h>

int main(){

    int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
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


    //初始化dis陣列，這裡是1號頂點到其餘各個頂點的初始路程
    for(i=1;i<=n;i=i+1){
        dis[i]=e[1][i];
    }

    //book陣列初始化
    for(i=1;i<=n;i=i+1){
        book[i]=0;
    }
    book[1]=1;   //這裡book中的[1]是因為我們指定的點為1。




    //Dijkstra演算法核心語句
    for(i=1;i<=n-1;i=i+1){  //到n-1是因為剩下的那個點已經透過其他的邊鬆弛成最短路徑了!!

        //找到離1號頂點的最近的頂點
        min=inf;
        for(j=1;j<=n;j=j+1){
            if(book[j]==0 && dis[j]<min){
                min=dis[j];
                u=j;    //u就是從「估計值」變成「確定值」的點
            }
        }
        book[u]=1;

        //透過剛剛選定的點去鬆弛其餘點的路徑。
        for(v=1;v<=n;v=v+1){
            if(e[u][v]<inf){//這一行的目的是為了避免正無窮值的一些運算，讓下面的判斷失效。
                if(dis[v]>dis[u]+e[u][v]){
                    dis[v]=dis[u]+e[u][v];
                    printf("\n%d %d %d--\n", u, v, dis[v]);
                }
            }
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




