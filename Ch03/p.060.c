#include <stdio.h>
int main(){
    int i;

    for(i=1;i<=9;i=i+1){
        if( (i*10+3)*6528==(30+i)*8256 ){
            printf("%d ", i);
        }
    }
}
