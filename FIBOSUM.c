#include <stdio.h>
#define LL long long int
#define MOD 1000000007
LL f[MOD] = {0};

LL fib(LL n) {
  if (n == 0)
    return 0;
  if (n == 1 || n == 2)
    return (f[n] = 1);

  if (f[n])
    return f[n];

  LL k = (n & 1) ? (n + 1) / 2 : n / 2;

  __int128 r = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
    : (2 * fib(k - 1) + fib(k)) * fib(k);

  f[n] = r % MOD;

  return f[n];
}

LL calc(LL n) { return fib(n + 2) - 1; }

int main() {
  LL t, a, b;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &a, &b);
    LL r = (calc(b) - calc(a - 1)) % MOD;
    if (r < 0)
      r += MOD;
    printf("%lld\n", r);
  }
  return 0;
}
