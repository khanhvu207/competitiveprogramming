#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef vector<int> bigint;
const int base = 10000;

bigint init(string s) {
  bigint res;
  if (s.empty()) {
    res.push_back(0);
    return res;
  }
  while ((int)s.size() % 4 != 0)
    s = '0' + s;
  for (int i = 0; i < (int)s.size(); i += 4) {
    int val = 0;
    for (int j = 0; j < 4; ++j)
      val = val * 10 + (s[i + j] - 48);
    res.insert(res.begin(), val);
  }
  return res;
}

bigint operator + (const bigint &a, const bigint &b) {
  bigint res;
  int carry = 0;
  for (int i = 0; i < (int)a.size() || i < (int)b.size(); ++i) {
    if (i < (int)a.size())
      carry += a[i];
    if (i < (int)b.size())
      carry += b[i];
    res.push_back(carry % base);
    carry /= base;
  }
  if (carry)
    res.push_back(carry);
  return res;
}

bigint operator - (const bigint &a, const bigint &b) {
  bigint res;
  int carry = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    int val = a[i] - carry;
    if (i < (int)b.size())
      val -= b[i];
    if (val < 0)
      val += base, carry = 1;
    else
      carry = 0;
    res.push_back(val);
  }
  while (*res.rbegin() == 0 && (int)res.size() > 1)
    res.pop_back();
  return res;
}

bigint operator * (const bigint &a, const bigint &b) {
  bigint res((int)a.size() + (int)b.size() + 5, 0);
  for (int i = 0; i < (int)a.size(); ++i) {
    int carry = 0;
    for (int j = 0; j < (int)b.size(); ++j) {
      res[i + j] += a[i] * b[j] + carry;
      carry = res[i + j] / base;
      res[i + j] %= base;
    }
    if (carry)
      res[i + (int)b.size()] += carry;
  }
  while (*res.rbegin() == 0 && (int)res.size() > 1)
    res.pop_back();
  return res;
}

bool operator < (bigint a, bigint b) {
  while (!a.empty() && *a.rbegin() == 0)
    a.pop_back();
  while (!b.empty() && *b.rbegin() == 0)
    b.pop_back();
  if ((int)a.size() != (int)b.size())
    return (int)a.size() < (int)b.size();
  for (int i = (int)a.size() - 1; i >= 0; --i)
    if (a[i] != b[i])
      return a[i] < b[i];
  return false;
}

void print(const bigint &a) {
  int L = (int)a.size();
  cout << a[L - 1];
  cout.fill('0');
  for (int i = L - 2; i >= 0; --i)
    cout << setw(4) << a[i];
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  string sa, sb;
  cin >> sa >> sb;
  bigint a = init(sa);
  bigint b = init(sb);
  print(a + b);
  if (a < b) {
    cout << '-';
    print(b - a);
  }
  else
    print(a - b);
  print(a * b);
}
