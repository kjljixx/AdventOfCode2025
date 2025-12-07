#include <iostream>
#include <queue>
#include <string>
#include <vector>

using ll = long long; 

std::vector<std::vector<ll>> manifold;
std::vector<std::vector<bool>> visited;
std::vector<std::vector<ll>> numTimelines;

auto main() -> int {
  std::string line;
  std::pair<ll, ll> startPos;
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
  numTimelines.resize(manifold.size(), std::vector<ll>(manifold[0].size(), 0));
  numTimelines[startPos.first][startPos.second] = 1;
  std::queue<std::pair<ll, ll>> bfsQueue;
  bfsQueue.push(startPos);
  while(!bfsQueue.empty()){
    auto currPos = bfsQueue.front();
    std::cerr << currPos.first << ", " << currPos.second << "\n";
    bfsQueue.pop();

    ll currNumTimelines = numTimelines[currPos.first][currPos.second];
    
    currPos.first++;
    if(currPos.first >= manifold.size()){
      continue;
    }

    if(manifold[currPos.first][currPos.second]){
      currPos.second += 1;
      if(currPos.second < manifold[0].size()){
        if(!visited[currPos.first][currPos.second]){
          visited[currPos.first][currPos.second] = true;
          bfsQueue.push(currPos);
        }
        numTimelines[currPos.first][currPos.second] += currNumTimelines;
      }
      currPos.second -= 2;
      if(currPos.second >= 0){
        if(!visited[currPos.first][currPos.second]){
          visited[currPos.first][currPos.second] = true;
          bfsQueue.push(currPos);
        }
        numTimelines[currPos.first][currPos.second] += currNumTimelines;
      }
    }
    else{
      numTimelines[currPos.first][currPos.second] += currNumTimelines;
      if(!visited[currPos.first][currPos.second]){
        visited[currPos.first][currPos.second] = true;
        bfsQueue.push(currPos);
      }
    }
  }
  for(ll i=0; i<manifold.size(); i++){
    for(ll j=0; j<manifold[0].size(); j++){
      std::cerr << numTimelines[i][j] << " ";
    }
    std::cerr << "\n";
  }
  ll ans = 0;
  for(ll j=0; j<manifold[0].size(); j++){
    ans += numTimelines[manifold.size() - 1][j];
  }
  std::cout << ans << "\n";
}