#include <stdio.h>

int a[10], book[10], total=0;

//step表示站在第幾個盒子面前
void dfs(int step){
    int i;


    //如果站在第10個盒子面前，則表示前9個盒子已經放好撲克牌了
    if(step==10){
        //判斷是否滿足等式口口口+口口口=口口口
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]
           ==a[7]*100+a[8]*10+a[9]){
            //如果滿足要求，可行解+1，並列印這個解
            total=total+1;
            printf("%d%d%d+%d%d%d=%d%d%d\n", a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }

        //返回到之前的一步(最近呼叫的地方)
        return;
    }


    //此時站在第step個盒子前面，應該放哪張牌呢?
    //按照1、2、3、...n的撲克牌順序一一嘗試
    for(i=1;i<=9;i=i+1){

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
    dfs(1);

    printf("\ntotal=%d", total/2);

    getchar();
    getchar();

    return 0;
}
