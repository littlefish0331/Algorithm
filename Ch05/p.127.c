//5 5
//圖的邊
//1 2
//1 3
//1 5
//2 4
//3 5


#include <stdio.h>

int book[101], sum, n, e[101][101];

//cur是目前所在的頂點編號
void dfs(int cur){
    int i;
    printf("%d ", cur);

    sum=sum+1;  //每存取一個點，sum就加1。
    if(sum==n){ //所有頂點都已經被存取過則退出
        return;
    }

    for(i=1;i<=n;i=i+1){    //從1號頂點到n號頂點依次嘗試，看有哪些點和目前頂點cur有邊相連
        //判斷目前頂點cur到頂點i是否有邊
        //判斷頂點i是否已存取過
        if(e[cur][i]==1 && book[i]==0){
            book[i]=1;  //標記頂點i已經存取過
            dfs(i); //從頂點i再出發繼續走訪
        }
    }

    return;
}



int main(){
    int i, j, m, a, b;
    scanf("%d %d", &n, &m);

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
    for(i=1;i<=n;i=i+1){
        scanf("%d %d", &a, &b);
        e[a][b]=1;
        e[b][a]=1;  //這是無向圖，所以需要將e[b][a]也賦值為1
    }

    //從1號城市出發
    book[1]=1;  //標記1號頂點已存取
    dfs(1); //從一號頂點開始走訪

    getchar();
    getchar();
    return 0;

}

