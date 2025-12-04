#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> map;

int numAdjacent(int x, int y){
  int count = 0;
  for(int dx=-1; dx<=1; dx++){
    for(int dy=-1; dy<=1; dy++){
      if(dx == 0 && dy == 0) continue;
      int nx = x + dx;
      int ny = y + dy;
      if(nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size()){
        count += map[nx][ny];
      }
    }
  }
  return count;
}

int main(){
  std::string line;
  while(std::getline(std::cin, line)){
    std::vector<int> row;
    for(char c : line){
      row.push_back(c == '@');
    }
    map.push_back(row);
  }

  int ans = 0;
  for(int i=0; i<map.size(); i++){
    for(int j=0; j<map[i].size(); j++){
      if(map[i][j] && numAdjacent(i, j) < 4){
        ans++;
      }
    }
  }
  std::cout << ans << std::endl;
}