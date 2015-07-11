/*Complexity: O(n^2) time – O(n^2) space
  Use dynamic programming (DP).
  In a matrix dp[i][j]:
  i is the first letter of the string to build (0 <= i < N),
  j is the length of that string, i.e. s[i..i+j-1].
  So dp[i][j] = minimum number of insertions to make s[i..i+j-1] a palindrome:
  if end characters are equal s[i] == s[i+j-1]: then we don’t insert any character to the previous string s[i+1..i+j-2].
  otherwise: the minimum between inserting a character in s[i..i+j-2] or in s[i+1..i+j-1].
  The answer for s[0..N-1] is in dp[0][N].
*/
/* dp state 大概就是这个样子的
 *      1    2   3   4   5     
 *a     0   1   2   4   5 
 *b     0   1   2   4   4   
 *c     0   1   2   3   3      
 *d     0   1   2   2   2   
 *e     0   1   1   1   1   
 *f     0   0   0   0   0   
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
static int dp[6101][6101];
main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        char s[6102];
        scanf("%s",s);
        int len=strlen(s);
        memset(dp,0,sizeof dp);
        /// 这里j是需要处理的字符,k是长度
        // 如果首尾相等,则不需要插入值,状态等于前一个字符串的值s[i+1..i+j-2]
        // 具体看上面的dp state吧
        for(int i=1;i<len;i++)
            for(int j=0,k=i;k<len;k++,j++)
                dp[j][k]=(s[j]==s[k])?dp[j+1][k-1]:min(dp[j][k-1],dp[j+1][k])+1;
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}
