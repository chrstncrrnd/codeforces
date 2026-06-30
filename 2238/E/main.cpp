#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define intinput(var) { \
  string _buf; \
  getline(cin, _buf); \
  (var) = stoi(_buf); \
}

#define strinput(var) {\
  getline(cin, (var)); \
}


int dfs(int cakes, const string &arr, int ***cache,
    int max_diff, int current_diff, int i){
  if (cakes == 0) return 0;

  if (i == cakes){
    return - max_diff;
  }

  if (cache[max_diff][current_diff][i] != -1){
    return cache[max_diff][current_diff][i];
  }
  int result = 0;


  if (arr[i] == 'N'){
    int f_res = 1 + dfs(cakes, arr, cache, max(current_diff + 1, max_diff),
        current_diff + 1, i + 1);
    int t_res = dfs(cakes, arr, cache, max(current_diff, max_diff),
        max(current_diff - 1, 0), i + 1);
    result = max(f_res, t_res);
  }else if (arr[i] == 'F') {
        result = 1 + dfs(cakes, arr, cache, max(max_diff, current_diff + 1), current_diff + 1, i + 1);
  } else {
      result = dfs(cakes, arr, cache, max_diff, max(0, current_diff - 1), i + 1);
  }
  cache[max_diff][current_diff][i] = result;
  return result;
}


int main(void){
  int cases, cakes;

  int ***cache;
  string arrangement;

  intinput(cases);

  for (int i = 0; i < cases; ++i){
    intinput(cakes);

    cache = new int**[cakes];
    for (int i = 0; i < cakes; i ++){
      cache[i] = new int*[cakes];
      for (int j = 0; j < cakes; j ++){
        cache[i][j] = new int[cakes];
        for (int k = 0; k < cakes; k ++){
          cache[i][j][k] = -1;
        }
      }
    }
    strinput(arrangement);
    cout << dfs(cakes, arrangement, cache, 0, 0, 0) << endl;
    for (int i = 0; i < cakes; i ++){
      for (int j = 0; j < cakes; j ++){
        delete[] cache[i][j];
      }
      delete[] cache[i];
    }

    delete[] cache;

  }
  return 0;
}
