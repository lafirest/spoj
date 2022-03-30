#include <stdio.h>

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

int main()
{
  long long t, a, b;
  scanf("%lld", &t);
  while(t--)
    {
      scanf("%lld %lld", &a, &b);
      printf("%lld\n", binpow(a, b, 10));
    }

  return 0;
}
