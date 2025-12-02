#include <iostream>
#include <string>
using ll = long long;
int main(){
  std::string line;
  std::getline(std::cin, line);
  ll strStart = 0;
  ll strEnd = line.find(',');
  ll ans = 0;
  while (strEnd != std::string::npos){
    strEnd = line.find(',', strStart);
    std::string token = line.substr(strStart, strEnd - strStart);
    
    ll dashIdx = token.find('-');
    ll rangeStart = std::stoll(token.substr(0, dashIdx));
    
    ll rangeEnd = std::stoll(token.substr(dashIdx + 1));
    
    for(ll i=rangeStart; i<=rangeEnd; i++){
      std::string s = std::to_string(i);
      for(ll j=2; j<=s.size(); j++){
        if (s.size() % j == 0){
          bool broken = false;
          for (ll k=0; k<s.size(); k+=s.size()/j){
            std::string part = s.substr(k, s.size()/j);
            if (part != s.substr(0, s.size()/j)){
              broken = true;
              break;
            }
          }
          if (!broken){
            ans+=i;
            break;
          }
        }
      }
    }

    strStart = strEnd + 1;
  }
  std::cout << ans << std::endl;
}
