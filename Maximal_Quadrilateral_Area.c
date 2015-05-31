#include<stdio.h> 
#include<math.h> 
int main() 
{ 
    double a,b,c,d,s,k; 
    int t; 
    scanf("%d",&t); 
    while(t--) 
    { 
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d); 
        s=(a+b+c+d)/2; 
        k=(s-a)*(s-b)*(s-c)*(s-d); 
        k=sqrt(k); 
        printf("%.2lf\n",k); 
    } return 0; 
} 
