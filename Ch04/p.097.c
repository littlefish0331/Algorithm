//以下地圖1
//輸出：將炸彈放置在(9,9)，可以消滅8個敵人
//13 13 3 3
//#############
//#GG.GGG#GGG.#
//###.#G#G#G#G#
//#.......#..G#
//#G#.###.#G#G#
//#GG.GGG.#.GG#
//#G#.#G#.#.###
//##G...G.....#
//#G#.#G###.#G#
//#...G#GGG.GG#
//#G#.#G#G#.#G#
//#GG.GGG#G.GG#
//#############

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

struct note {
    int x;  //橫坐標
    int y;  //縱座標
};

//儲存地圖
char a[20][21];

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


int main(){
    struct note que[401];   //地圖大小不超過20*20，因此佇列擴展不會超過40。
    int head, tail;
    int book[20][20]={0};   //定義一個標記陣列，並全部初始化為0。
    int i,j,k,sum,max=0,mx,my,n,m,startx,starty,tx,ty;

    //定義一個用於表示走的方向的陣列
    int next[4][2]={
        { 0, 1},//向右走
        { 1, 0},//向下走
        { 0,-1},//向左走
        {-1, 0} //向上走
    };

    //讀入n和m，n表示有多少行字元，m表示每行有多少列。
    scanf("%d %d %d %d", &n, &m, &startx, &starty);

    //讀入n行字元
    for(i=0;i<=n-1;i=i+1){
        scanf("%s", a[i]);
    }

    //佇列初始化
    head=1;
    tail=1;

    //往佇列插入小人起始座標
    que[tail].x=startx;
    que[tail].y=starty;
    tail=tail+1;
    book[startx][starty]=1;

    max=getnum(startx, starty);
    mx=startx;
    my=starty;

    //當佇列部為空的時候迴圈
    while(head<tail){
        //列舉四個方向
        for(k=0;k<=3;k=k+1){
            //嘗試走下一個點座標
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            //判斷是否越界
            if(tx<0 || tx>n-1 || ty<0 || ty>m-1){
                continue;
            }

            //判斷是否為平地或者是曾經走過
            if(a[tx][ty]=='.' && book[tx][ty]==0){
                //每個點只入佇列一次，所以需要標記這個點已經走過
                book[tx][ty]=1;

                //插入新的擴展點到佇列中。
                que[tail].x=tx;
                que[tail].y=ty;
                tail=tail+1;

                //統計目前新擴展點可以消滅的敵人總數
                sum=getnum(tx, ty);
                //更新max值
                if(sum>max){
                    //如果目前統計出所能消滅的敵人總數大於max，則更新max
                    //並用mx和my紀錄該點座標。
                    max=sum;
                    mx=tx;
                    my=ty;
                }
            }
        }

        //當一個擴展點結束後
        //必須要head=head+1才能對後面的點進行擴展。
        head=head+1;

    }

    //最後輸出這個點，和最多可以消滅的敵人總數
    printf("\n將炸彈放置在(%d,%d)，可以消滅%d個敵人\n", mx,my,max);

    getchar();
    getchar();
    return 0;

}









