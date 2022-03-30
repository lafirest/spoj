//https://mathworld.wolfram.com/LamesTheorem.html
//https://cp-algorithms.com/algebra/linear-diophantine-equation.html

#include <stdio.h>
#define LL long long int
#define MOD 1000000007

void fib(LL n, LL *a, LL *b) {
  if (n == 0) {
    *a = 0;
    *b = 1;
    return;
  }

  fib(n >> 1, a, b);

  LL x = *a, y = *b, c, d;

  if(y > x)
    c = (x * (2 * y - x)) % MOD;
  else
    c = (x * (2 * (y + MOD) - x)) % MOD;
  d = (x * x + y * y) % MOD;

  if (n & 1) {
    *a = d;
    *b = (c + d) % MOD;
  } else {
    *a = c;
    *b = d;
  }
}

int main() {
  long long int t, n;
  scanf("%lld", &t);
  while (t--) {
    LL a, b, r;
    scanf("%lld", &n);
    if (n == 0)
      r = 0;
    else if (n == 1)
      r = 2;
    else {
      fib(n + 1, &a, &b);
      r = (a + b) % MOD;
    }

    printf("%lld\n", r);
  }
  return 0;
}
