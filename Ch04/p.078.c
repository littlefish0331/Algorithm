#include <stdio.h>

//C語言的全域變數在沒有指定以前預設為0。
//因此這裡的book陣列無須全部再次指定初始值為0。
int a[10], book[10], n;

//step表示現在站在第幾個盒子前面
void dfs(int step){
    int i;

    //如果站在第n+1個盒子前面，則表示前n個盒子已經放好撲克牌了
    if(step==n+1){
        for(i=1;i<=n;i=i+1){
            printf("%d", a[i]);
        }
        printf("\n");

        //返回之前的一步(即最近一次呼叫dfs函數的地方)
        return;
    }


    //此時站在第step個盒子前面，應該放哪張牌呢?
    //按照1、2、3、...n的撲克牌順序一一嘗試
    for(i=1;i<=n;i=i+1){

        //判斷撲克牌i是否還在手上
        //若book[i]==0則表示i號撲克牌在手上
        if(book[i]==0){

            //開始嘗試使用撲克牌i
            a[step]=i;  //將i號撲克牌放入第step的盒子中
            book[i]=1;  //將book[i]設為1，表示撲克牌已經不在手上了

            //第step個盒子已經放好撲克牌，接下來需要走到下一個盒子前面
            dfs(step+1);    //這裡透過函數的遞迴呼叫來實作自己
            book[i]=0;      //一定要將剛才嘗試的撲克牌收回，才能進行下一次的嘗試。

        }
    }

    //最後所有可能都嘗試完的return
    return;
}

int main(){
    scanf("%d", &n);    //輸入時要注意n為1~9之間的整數
    dfs(1); //首先站在1號盒子前面

    getchar();
    getchar();
    return 0;

}
