#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
  int w;
  int v;
};

int main() {
  int n, W;
  cin >> n >> W;

  vector<Item> item(n);

  for (int i = 0; i < n; i++) {
    cin >> item[i].w >> item[i].v;
  }

  vector<long long> dp(W + 1, 0);

  for (auto i : item) {
    int w = i.w;
    int v = i.v;

    for (int j = W; j >= w; j--) {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }

  cout << dp[W];

  return 0;
}