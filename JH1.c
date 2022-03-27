#include <stdio.h>
int main(){long v,p,t,n,c[3];scanf("%ld",&t);while(t--){scanf("%ld",&n);p=1;c[0]=c[2]=0;while(n--){p*=-1;scanf("%ld",&v);if(v*p>0)c[p+1]+=v;}puts(c[2]>=-c[0]?"Some Mirrors Lie!":"Every Girl Lies!");}return 0;}
