#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using ll = long long;

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
  std::vector<int> parents(junctions.size(), -1);
  std::vector<int> sizes(junctions.size(), 1);
  for(int i=0; i<junctions.size(); i++){
    parents[i] = i;
  }
  int numSets = junctions.size();
  for(int i=0; i<pairs.size(); i++){
    int setRoot1 = pairs[i].first;
    while(parents[setRoot1] != setRoot1){
      setRoot1 = parents[setRoot1];
    }
    int setRoot2 = pairs[i].second;
    while(parents[setRoot2] != setRoot2){
      setRoot2 = parents[setRoot2];
    }

    if(setRoot1 != setRoot2){
      numSets--;
      if(sizes[setRoot1] > sizes[setRoot2]){
        parents[setRoot2] = setRoot1;
        sizes[setRoot1] += sizes[setRoot2];
      } else {
        parents[setRoot1] = setRoot2;
        sizes[setRoot2] += sizes[setRoot1];
      }
      if(numSets == 1){
        std::cout << (ll(junctions[pairs[i].first][0]) * ll(junctions[pairs[i].second][0]));
        return 0;
      }
    }
  }
}