#include <stdio.h>
int main(){

    int a, b, c, d, e, f, g, h, i, total=0;

    for(a=1;a<=9;a=a+1){//第一個數字的百位
        for(b=1;b<=9;b=b+1){//第一個數字的十位
            for(c=1;c<=9;c=c+1){//第一個數字的個位
                for(d=1;d<=9;d=d+1){//第二個數字的百位
                    for(e=1;e<=9;e=e+1){//第二個數字的十位
                        for(f=1;f<=9;f=f+1){//第二個數字的個位
                            for(g=1;g<=9;g=g+1){//第三個數字的百位
                                for(h=1;h<=9;h=h+1){//第三個數字的十位
                                    for(i=1;i<=9;i=i+1){//第三個數字的個位
                                        if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i
                                                && b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=i
                                                        && c!=d && c!=e && c!=f && c!=g && c!=h && c!=i
                                                                && d!=e && d!=f && d!=g && d!=h && d!=i
                                                                        && e!=f && e!=g && e!=h && e!=i
                                                                                && f!=g && f!=h && f!=i
                                                                                        && g!=h && g!=i
                                                                                                && h!=i
                                                        && a*100+b*10+c+d*100+e*10+f==g*100+h*10+i){
                                               total=total+1;
                                               printf("%d%d%d+%d%d%d=%d%d%d\n", a, b, c, d, e, f, g, h, i);
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
    //因為同一種組合只算一種
    //可是上面printf的時候，同一種組合仍會輸出兩次

    getchar();
    getchar();
    return 0;

}
