#include <stdio.h>
#define M 1299710
char p[M];int main(){long i,j;for(i=2;i<M;++i)if(!p[i])for(j=i*i;j<M;j+=i)p[j]=1;while(scanf("%ld",&i)!=EOF){for(j=2;i;++j)if(!p[j])--i;printf("%ld\n",j-1);}}
