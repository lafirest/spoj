#include <stdio.h>
#define MOD 10000007

long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int main() {

  long long n, k, r;

b:
  scanf("%lld %lld", &n, &k);
  if (n == 0 && k == 0)
    goto e;

  r = (binpow(n, k, MOD) + 2 * binpow(n - 1, k, MOD) + binpow(n, n, MOD) +
       2 * binpow(n - 1, n - 1, MOD)) %
      MOD;

  printf("%lld\n", r);
  goto b;
 e:

  return 0;
}
