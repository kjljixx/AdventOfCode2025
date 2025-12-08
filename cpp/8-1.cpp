#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

double dist(std::array<int, 3> a, std::array<int, 3> b) {
  return std::sqrt(std::pow(a[0] - b[0], 2) + std::pow(a[1] - b[1], 2) + std::pow(a[2] - b[2], 2));
}

int main(){
  std::string line;
  std::vector<std::array<int, 3>> junctions;
  while(std::getline(std::cin, line)){
    if(line.empty()){
      break;
    }
    junctions.emplace_back();
    int xySep = line.find(',');
    int yzSep = line.find(',', xySep + 1);
    int x = std::stoi(line.substr(0, xySep));
    int y = std::stoi(line.substr(xySep + 1, yzSep - xySep - 1));
    int z = std::stoi(line.substr(yzSep + 1));
    junctions.back() = {x, y, z};
    std::cerr << x << " " << y << " " << z << std::endl;
  }

  std::vector<std::pair<int, int>> pairs;
  for(size_t junc1=0; junc1 < junctions.size(); junc1++){
    for(size_t junc2=junc1+1; junc2 < junctions.size(); junc2++){
      pairs.emplace_back(junc1, junc2);
    }
  }
  std::sort(pairs.begin(), pairs.end(), [junctions](std::pair<int, int> a, std::pair<int, int> b){
    return dist(junctions[a.first], junctions[a.second]) < dist(junctions[b.first], junctions[b.second]);
  });
  
  std::vector<std::vector<int>> adjacencies(junctions.size());
  for(int i=0; i<1000; i++){
    std::cerr << pairs[i].first << " " << pairs[i].second << std::endl;
    adjacencies[pairs[i].first].push_back(pairs[i].second);
    adjacencies[pairs[i].second].push_back(pairs[i].first);
  }

  std::vector<bool> visited(junctions.size(), false);
  std::vector<int> circuits;
  std::queue<int> dfsQueue;
  for(int i=0; i<junctions.size(); i++){
    if(!visited[i]){
      visited[i] = true;
      dfsQueue.push(i);
      circuits.push_back(1);
    }
    while(!dfsQueue.empty()){
      int currJunc = dfsQueue.front();
      dfsQueue.pop();
      for(int adjJunc : adjacencies[currJunc]){
        if(!visited[adjJunc]){
          visited[adjJunc] = true;
          circuits.back()++;
          dfsQueue.push(adjJunc);
        }
      }
    }
  }

  std::sort(circuits.begin(), circuits.end(), std::greater<int>());
  for(auto circuit: circuits){
    std::cerr << circuit << std::endl;
  }
  std::cout << circuits[0]*circuits[1]*circuits[2] << std::endl;
  return 0;
}