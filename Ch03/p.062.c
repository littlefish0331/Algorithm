#include <stdio.h>
int main(){
    int a[10], i, total=0, book[10], sum;
    //這裡用a[1]~a[9]來代替剛才的a,b,c,d,e,f,g,h,i。

    for(a[1]=1;a[1]<=9;a[1]=a[1]+1){
        for(a[2]=1;a[2]<=9;a[2]=a[2]+1){
            for(a[3]=1;a[3]<=9;a[3]=a[3]+1){
                for(a[4]=1;a[4]<=9;a[4]=a[4]+1){
                    for(a[5]=1;a[5]<=9;a[5]=a[5]+1){
                        for(a[6]=1;a[6]<=9;a[6]=a[6]+1){
                            for(a[7]=1;a[7]<=9;a[7]=a[7]+1){
                                for(a[8]=1;a[8]<=9;a[8]=a[8]+1){
                                    for(a[9]=1;a[9]<=9;a[9]=a[9]+1){

                                        //初始化book陣列
                                        for(i=1;i<=9;i=i+1){
                                            book[i]=0;
                                        }

                                        //某數有出現就標記一下
                                        for(i=1;i<=9;i=i+1){
                                            book[a[i]]=1;
                                        }

                                        //統計出現多少個不同的數字
                                        sum=0;
                                        for(i=1;i<=9;i=i+1){
                                            sum=sum+book[i];
                                        }

                                        //若正好出現9個不同的數字，且滿足等式條件，則可以輸出
                                        if( sum==9 && a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]==a[7]*100+a[8]*10+a[9]){
                                            total=total+1;
                                            printf("%d%d%d+%d%d%d=%d%d%d\n", a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
                                        }

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("total=%d", total/2);

    getchar();
    getchar();

    return 0;

}
