#include <stdio.h>

long long dp[1000001] = {0};

int main() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    printf("0");
    return 0;
  }

  dp[1] = 1;
  dp[2] = 1;

  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
  }

  printf("%lld", dp[n]);

  return 0;
}
