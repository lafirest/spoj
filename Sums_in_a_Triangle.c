// 简单的dp问题
// 题目只能提交256b的源代码.在最后时缩减到270b,现在是250b
// 技巧是dp数组都从1开始,而不是从0开始,这样就能省区越界判断了
// 将={0}去掉可以缩减到246b,但是不太安全
#define m(a,b) (a>b?a:b)
#define s(x) scanf("%d",&x)
int d[102][102]={0};main(){int n,t,i,j,v,m;s(n);while(n--){m=0;s(t);for(i=1;i<=t;++i){for(j=1;j<i+1;++j){s(v);d[i][j]=v+m(d[i-1][j],d[i-1][j-1]);}}--i;while(j--)m=m(d[i][j],m);printf("%d\n",m);}}