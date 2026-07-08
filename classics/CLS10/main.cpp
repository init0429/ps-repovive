#include <iostream>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int cnt = 0;

  for (auto i : s) {
    for (auto j : t) {
      if (i == j) {
        cnt++;
      }
    }
  }

  cout << cnt;

  return 0;
}
