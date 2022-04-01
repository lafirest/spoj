#include <stdio.h>
#define MAX 10000010

int prime[MAX], s[MAX], sum[MAX];

int pow4(int x) {
  x *= x;
  x *= x;
  return x;
}

int main() {
  for (int i = 2; i < MAX; ++i) {
    if (prime[i])
      continue;

    for (int j = i + i; j < MAX; j += i)
      prime[j] = 1;
  }

  for (int i = 1; i * i < MAX; ++i)
    s[i * i] = 1;

  for (int i = 1; i < MAX; i++) {
    sum[i] = sum[i - 1];
    if (prime[i])
      continue;
    for (int j = 1; pow4(j) <= i; ++j) {
      if (s[i - pow4(j)]) {
        ++sum[i];
        break;
      }
    }
  }
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", sum[n]);
  }

  return 0;
}
