#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
  long long r = a % b;
  if (r) return gcd(b, r);
  else return b;
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << gcd(a, b);

  return 0;
}