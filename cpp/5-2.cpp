#include <iostream>
#include <string>
#include <utility>
#include <vector>

using ll = long long;

int main(){
  std::string line;
  std::vector<std::pair<ll, ll>> ranges;
  std::vector<std::pair<ll, bool>> pois;
  while(std::getline(std::cin, line)){
    if(line.empty()){
      break;
    }

    ll delimiter = line.find('-');
    ll first = std::stoll(line.substr(0, delimiter));
    ll second = std::stoll(line.substr(delimiter + 1));
    ranges.push_back({first, second});
    pois.push_back({first, false});
    pois.push_back({second, true});
  }

  std::sort(pois.begin(), pois.end());

  ll numActive = 0;
  ll ans = 0;
  ll prev = -1;
  for(auto p : pois){
    if(numActive > 0){
      ans += p.first - prev;
      std::cerr << p.first << " " << prev << " " << p.first - prev << std::endl;
    }

    if(!p.second){
      numActive++;
    } else {
      numActive--;
      if (numActive == 0){
        std::cerr << p.first << std::endl;
        ans++;
      }
    }

    prev = p.first;
  }

  std::cout << ans << std::endl;
}