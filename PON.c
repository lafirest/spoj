#include <stdbool.h>
#include <stdio.h>

#define U128 unsigned __int128
#define UL U128

int p[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

UL binpower(UL base, UL e, UL mod) {
  UL result = 1;
  base %= mod;
  while (e) {
    if (e & 1)
      result = (U128)result * base % mod;
    base = (U128)base * base % mod;
    e >>= 1;
  }
  return result;
}

bool check_composite(UL n, UL a, UL d, int s) {
  UL x = binpower(a, d, n);
  if (x == 1 || x == n - 1)
    return false;
  for (int r = 1; r < s; r++) {
    x = (U128)x * x % n;
    if (x == n - 1)
      return false;
  }
  return true;
};

char *miller_rabin(UL n) {
  if (n < 2)
    return "NO";

  int r = 0;
  UL d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for (int i = 0; i < 12; ++i) {
    int a = p[i];
    if (n == a)
      return "YES";
    if (check_composite(n, a, d, r))
      return "NO";
  }
  return "YES";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long unsigned int n;
    scanf("%lld", &n);
    printf("%s\n", miller_rabin(n));
  }
  return 0;
}
