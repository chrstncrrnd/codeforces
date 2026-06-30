#include <exception>
#include <iostream>
#include <string>
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


void output_grid(char **grid, int n){
  for(int y = 0; y < n; ++y){
    for (int x = 0; x < n; ++x){
      cout << grid[y][x];
    }
    cout << endl;
  }
}


char rot_90(char current_orient){
  switch(current_orient){
    case 'U':
      return 'R';
    case 'R':
      return 'D';
    case 'D':
      return 'L';
    case 'L':
      return 'U';
    default:
      // it is important to catch errors here
      cout << "ERROR with rotation, invalid input!" << endl;
      // E for error
      return 'E';
  }
}

char rot_neg_90(char current_orient){
  switch(current_orient){
    case 'U':
      return 'L';
    case 'R':
      return 'U';
    case 'D':
      return 'R';
    case 'L':
      return 'D';
    default:
      cout << "ERROR with rotation, invalid input!" << endl;
      return 'E';
  }
}

bool can_move(char **grid, int n, int x, int y) {
  // bounded in box
  if (x >= n || x < 0){
    return false;
  }
  if (y >= n || y < 0){
    return false;
  }

  // empty spot
  return grid[y][x] == 'N';
}

void place(char **grid, int x, int y, int* k, char orient){
    if (--*k >= 0){
      grid[y][x] = rot_neg_90(orient);
    }
    else{
      grid[y][x] = orient;
    }
}

void spiral(char **grid, int n, int k){
  // what direction we are heading
  char orient = 'R';

  // coordinates
  int x = 0;
  int y = 0;

  bool moved;
  int rotations;

  while(1){
    moved = false;
    rotations = 0;
    while(!moved){
      // move
      switch (orient){
        case 'U':
          if(can_move(grid, n, x, y-1)){
            place(grid, x, y, &k, orient);
            y--;
            moved = true;
          }
          break;
        case 'R':
          if(can_move(grid, n, x+1, y)){
            place(grid, x, y, &k, orient);
            x++;
            moved = true;
          }
          break;
        case 'D':
          if(can_move(grid, n, x, y+1)){
            place(grid, x, y, &k, orient);
            y++;
            moved = true;
          }
          break;
        case 'L':
          if(can_move(grid, n, x-1, y)){
            place(grid, x, y, &k, orient);
            x--;
            moved = true;
          }
          break;
      }
      if (!moved){
        rotations ++;
        orient = rot_90(orient);
      }
      if (rotations > 4){
        break;
      }
    }
    // we cant move anymore
    if (!moved){
      orient = rot_90(orient);
      place(grid, x, y, &k, orient);
      break;
    }
  }

}

int main(void){
  int cases, n, k;


  intinput(cases);
  string line;


  for (int i = 0; i < cases; ++i){
    strinput(line);
    vector<string> parts = split(line, ' ');

    n = stoi(parts[0]);
    k = stoi(parts[1]);
    if (n*n-k == 1){
      cout << "NO" << endl;
      continue;
    }

    // initialize grid
    char **grid;
    grid = new char*[n];
    for (int j = 0; j < n; j++){
      grid[j] = new char[n];
      for (int k = 0; k < n; k++){
        // N for nothing
        grid[j][k] = 'N';
      }
    }
    spiral(grid, n, k);
    cout << "YES" << endl;
    output_grid(grid, n);

    // delete grid
    for (int j = 0; j < n; j++){
      delete[] grid[j];
    }

    delete[] grid;


  }
  return 0;
}
