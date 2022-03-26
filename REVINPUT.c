#include <stdio.h>
#include <ctype.h>
int main(){int n,i,c,s,j,b[1048576];scanf("%d",&n);while((c=getchar())!=EOF){b[i]=c;++i;}s=j=--i;i=n;while(j>=0){h:c=b[j];putchar(c);--j;if(isspace(c)||!j){--i;if(i>0){if(!j)putchar(' ');j=s;goto h;}else{s=j;i=n;}};}return 0;}
