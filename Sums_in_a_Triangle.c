// �򵥵�dp����
// ��Ŀֻ���ύ256b��Դ����.�����ʱ������270b,������250b
// ������dp���鶼��1��ʼ,�����Ǵ�0��ʼ,��������ʡ��Խ���ж���
// ��={0}ȥ������������246b,���ǲ�̫��ȫ
#define m(a,b) (a>b?a:b)
#define s(x) scanf("%d",&x)
int d[102][102]={0};main(){int n,t,i,j,v,m;s(n);while(n--){m=0;s(t);for(i=1;i<=t;++i){for(j=1;j<i+1;++j){s(v);d[i][j]=v+m(d[i-1][j],d[i-1][j-1]);}}--i;while(j--)m=m(d[i][j],m);printf("%d\n",m);}}