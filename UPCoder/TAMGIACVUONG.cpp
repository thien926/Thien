#include<stdio.h>
#include<math.h>

int main(){
    double a,b;
    scanf("%lf%lf",&a,&b);
    printf("Dien tich: %0.2lf\n",a*b*0.5);
    printf("Canh huyen: %0.2lf",sqrt(pow(a,2)+pow(b,2)));
    return 0;
}
