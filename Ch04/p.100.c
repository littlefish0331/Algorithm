//以下地圖2
//輸出：將炸彈放置在(7,11)，可以消滅10個敵人
//13 13 3 3
//#############
//#GG.GGG#GGG.#
//###.#G#G#G#G#
//#.......#..G#
//#G#.###.#G#G#
//#GG.GGG.#.GG#
//#G#.#G#.#.#.#
//##G...G.....#
//#G#.#G###.#G#
//#...G#GGG.GG#
//#G#.#G#G#.#G#
//#GG.GGG#G.GG#
//#############

#include <stdio.h>

char a[20][21];
int book[20][20], max, mx, my, n, m;

int getnum(int i, int j){
    int sum, x, y;
    sum=0;  //sum用來計數(消滅的敵人數)，所以需要初始化為0。

    //將座標i,j複製到兩個新變數x,y中，以便之後向上下左右四個方向統計可以消滅的敵人數。
    //向上統計可以消滅的敵人數
    x=i;
    y=j;
    while(a[x][y]!='#'){    //記得一定要用''，不可用""。
        if(a[x][y]=='G'){
            sum=sum+1;
        }

        //x=x-1的作用是繼續向上統計
        x=x-1;
    }


    //向下統計可以消滅的敵人數
    x=i;
    y=j;
    while(a[x][y]!='#'){    //記得一定要用''，不可用""。
        if(a[x][y]=='G'){
            sum=sum+1;
        }

        //x=x+1的作用是繼續向下統計
        x=x+1;
    }


    //向左統計可以消滅的敵人數
    x=i;
    y=j;
    while(a[x][y]!='#'){    //記得一定要用''，不可用""。
        if(a[x][y]=='G'){
            sum=sum+1;
        }

        //y=y-1的作用是繼續向左統計
        y=y-1;
    }



    //向右統計可以消滅的敵人數
    x=i;
    y=j;
    while(a[x][y]!='#'){    //記得一定要用''，不可用""。
        if(a[x][y]=='G'){
            sum=sum+1;
        }

        //y=y+1的作用是繼續向右統計
        y=y+1;
    }

    return sum;
}


void dfs(int x, int y){
    //定義一個用於表示走的方向的陣列
    int next[4][2]={
        { 0, 1},//向右走
        { 1, 0},//向下走
        { 0,-1},//向左走
        {-1, 0} //向上走
    };

    int k, sum, tx, ty;

    //計算目前這個點可消滅的敵人總數
    sum=getnum(x, y);

    //更新max值
    if(sum>max){
        //如果目前統計出所能消滅的敵人總數大於max，則更新max
        //並用mx和my紀錄該點座標。
        max=sum;
        mx=x;
        my=y;
    }

    //列舉四個方向
    for(k=0;k<=3;k=k+1){
        //嘗試走下一個點座標
        tx=x+next[k][0];
        ty=y+next[k][1];

        //判斷是否越界
        if(tx<0 || tx>n-1 || ty<0 || ty>m-1){
            continue;
        }

        //判斷是否圍牆或者已經走過
        if(a[tx][ty]=='.' && book[tx][ty]==0){
            book[tx][ty]=1; //標記這個點已經走過。
            dfs(tx, ty);    //開始嘗試下一個點。
        }
    }

    return;
}


int main(){
    int i, startx, starty;

    //讀入n和m，n表示有多少行，m表示每行有多少列。
    scanf("%d %d %d %d", &n, &m, &startx, &starty);

    //讀入n行字元
    for(i=0;i<=n-1;i=i+1){
        scanf("%s", a[i]);
    }

    //從小人所佔的位置開始嘗試
    book[startx][starty]=1;
    max=getnum(startx, starty);
    mx=startx;
    my=starty;

    dfs(startx, starty);

    printf("\n將炸彈放置在(%d,%d)，最多可以消滅%d個敵人\n", mx, my, max);

    getchar();
    getchar();
    return 0;

}

