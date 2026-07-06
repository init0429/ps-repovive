// 0G. Critical Distances
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  
  return 0;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(2, 0))));

  auto dfs = [&](auto& self, int u, int p) -> void {
      for (int f = 0; f <= n; ++f) {
          dp[u][f][0][f == 0 ? 1 : 0] = 1;
      }

      for (int v : adj[u]) {
          if (v == p) continue;
          
          self(self, v, u);

          vector<vector<vector<int>>> next_dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
          
          for (int f_u = 0; f_u <= n; ++f_u) {
              for (int d = -1; d <= 1; ++d) {
                  int f_v = f_u + d;
                  if (f_v < 0 || f_v > n) continue;

                  for (int inc_u = 0; inc_u <= 1; ++inc_u) {
                      for (int dec_u = 0; dec_u <= 1; ++dec_u) {
                          if (!dp[u][f_u][inc_u][dec_u]) continue;

                          for (int inc_v = 0; inc_v <= 1; ++inc_v) {
                              for (int dec_v = 0; dec_v <= 1; ++dec_v) {
                                  if (!dp[v][f_v][inc_v][dec_v]) continue;
                                  if (v > k && f_v > 0 && inc_v == 0) {
                                      if (f_u != f_v + 1) continue;
                                  }

                                  if (v <= k && dec_v == 0) {
                                      if (f_u != f_v - 1) continue;
                                  }

                                  int next_inc = inc_u | (f_v == f_u + 1 ? 1 : 0);
                                  int next_dec = dec_u | ((f_v == f_u - 1 && dec_v == 1) ? 1 : 0);
                                  
                                  int ways = mul(dp[u][f_u][inc_u][dec_u], dp[v][f_v][inc_v][dec_v]);
                                  add(next_dp[f_u][next_inc][next_dec], ways);
                              }
                          }
                      }
                  }
              }
          }
          dp[u] = next_dp;
      }
  };

  dfs(dfs, 1, 0);

  int ans = 0;
  for (int f_1 = 0; f_1 <= n; ++f_1) {
      for (int inc = 0; inc <= 1; ++inc) {
          if (1 > k && f_1 > 0 && inc == 0) continue; 
          
          add(ans, dp[1][f_1][inc][1]);
      }
  }
  
  cout << ans << "\n";
}
