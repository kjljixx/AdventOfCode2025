#include <cmath>
#include <iostream>
#include <string>

using ll = long long;

int main(){
  std::string line;
  ll ans = 0;
  while(std::getline(std::cin, line)){
    if(line == "END"){
      break;
    }
    ll idx = 0;
    ll num = 0;
    for(ll dig=11; dig>=0; dig--){
      ll currDig = 0;
      for(ll i=idx; i<line.size()-dig; i++){
        if(line[i] - '0' > currDig){
          currDig = line[i] - '0';
          idx = i;
        }
      }
      idx = idx + 1;
      num = std::pow(10, dig) * currDig + num;
    }
    ans += num;
  }
  std::cout << ans << std::endl;
}