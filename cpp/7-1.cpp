#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::vector<std::vector<int>> manifold;
std::vector<std::vector<bool>> visited;

auto dfs(std::pair<int, int> pos) -> int {
  std::cerr << pos.first << ", " << pos.second << "\n";
  if(pos.first >= manifold.size() || pos.second < 0 || pos.second >= manifold[0].size()){
    return 0;
  }
  if(visited[pos.first][pos.second]){
    return 0;
  }
  visited[pos.first][pos.second] = true;

  while(pos.first < manifold.size() && manifold[pos.first][pos.second] == 0){
    pos.first++;
  }

  if(pos.first >= manifold.size()){
    return 0;
  }

  if(visited[pos.first][pos.second]){
    return 0;
  }
  visited[pos.first][pos.second] = true;
  return dfs({pos.first, pos.second + 1}) + dfs({pos.first, pos.second - 1}) + 1;
}

auto main() -> int {
  std::string line;
  std::pair<int, int> startPos;
  while(std::getline(std::cin, line)){
    if(line.empty()){
      break;
    }
    manifold.emplace_back();
    for(char currChar : line){
      if(currChar == 'S'){
        startPos = {manifold.size() - 1, manifold.back().size()};
      }
      manifold.back().push_back(currChar == '^' ? 1 : 0);
    }
    std::cerr << line << "\n";
  }
  visited.resize(manifold.size(), std::vector<bool>(manifold[0].size(), false));
  std::cout << dfs(startPos) << "\n";
}