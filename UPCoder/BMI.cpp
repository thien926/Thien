#include<stdio.h>

int main(){
    double a,b,res;
    scanf("%lf%lf",&a,&b);
    res=b/(a*a);
    if(res<18.5){
        printf("Chi so BMI: %0.2lf\nKet qua: gay",res);
    }
    else{
        if(res>=25) printf("Chi so BMI: %0.2lf\nKet qua: thua can",res);
        else printf("Chi so BMI: %0.2lf\nKet qua: binh thuong",res);
    }
    return 0;
}
