#include <iostream>
#include <vector>


using namespace std;

#define intinput(var) { \
  string _buf; \
  getline(cin, _buf); \
  (var) = stoi(_buf); \
}

#define strinput(var) {\
  getline(cin, (var)); \
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


int main(void){

  return 0;
}
