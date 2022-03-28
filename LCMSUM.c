#include <stdio.h>
#define MAX 1000002
#define LL long long int

LL phi[MAX + 2], sums[MAX + 2];

void etf() {
  for (int i = 1; i <= MAX; ++i) {
    phi[i] = i;
  }

  for (int i = 2; i <= MAX; ++i) {
    if (phi[i] == i) {
      phi[i] = i - 1;
      for (int j = 2 * i; j <= MAX; j += i) {
        phi[j] = (phi[j] * (i - 1)) / i;
      }
    }
  }

  for (int i = 1; i <= MAX; ++i) {
    for (int j = i; j <= MAX; j += i) {
      sums[j] += (i * phi[i]);
    }
  }
}

LL calc(int m)
{
  LL sum = sums[m];
  sum = (sum + 1) * m;
  sum = sum / 2;
  return sum;
}

int main()
{
  etf();
  int t, n;
  scanf("%d\n", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%lld\n", calc(n));
  }

  return 0;
}
