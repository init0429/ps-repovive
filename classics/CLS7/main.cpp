#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  const long long MOD = 1000000007;

  long long ans = 1;

  for (int i = 1; i <= n; i++)
    ans = ans * i % MOD;

  cout << ans;

  return 0;
}
