
#include <algorithm>
#include <bits/stdc++.h>
#include <print>
#include <vector>

using namespace std;

#define intinput(var)                                                          \
  {                                                                            \
    string _buf;                                                               \
    getline(cin, _buf);                                                        \
    (var) = stoi(_buf);                                                        \
  }

#define strinput(var)                                                          \
  {                                                                            \
    getline(cin, (var));                                                       \
  }

// Split `str` at `delim` into a vector of strings
vector<string> split(const string &str, char delim) {
  vector<string> out;
  size_t start = 0, end;

  while ((end = str.find(delim, start)) != string::npos) {
    out.push_back(str.substr(start, end - start));
    start = end + 1;
  }
  out.push_back(str.substr(start));
  return out;
}

void game_case(int n, int k, std::vector<int> a) {
  int total = 0;
  std::vector<int> dp(n, 0);
  dp[0] = 1;
  for (int i = 1; i < n; ++i) {

    // dp[4] = 1 + dp[3] + dp[2] + dp[1]
    // dp[5] = 1 + dp[4] + dp[3] + dp[2]
    //
    // dp[5] = 2*dp[4] - dp[1]
    dp[i] = 2 * dp[i - 1];
    if (i - k - 1 >= 0) {
      dp[i] -= dp[i - k - 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    auto a_i = a[i];
    total += a_i * dp[i];
  }
  if (total % 2 == 0) {
    println("Bob");
  } else {
    println("Alice");
  }
}

int main(void) {
  int t;
  intinput(t);
  for (int i = 0; i < t; ++i) {
    string line1, line2;
    strinput(line1);
    strinput(line2);
    auto split_1 = split(line1, ' ');
    auto split_2 = split(line2, ' ');

    int n = stoi(split_1[0]), k = stoi(split_1[1]);
    vector<int> a(n, 0);
    if (n != 0) {

      transform(split_2.begin(), split_2.end(), a.begin(),
                [](string s) { return stoi(s); });
    }
    game_case(n, k, a);
  }
  return 0;
}
