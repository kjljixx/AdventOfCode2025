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
      if (s.size() % 2 == 0){
        std::string firstHalf = s.substr(0, s.size() / 2);
        std::string secondHalf = s.substr(s.size() / 2);
        if (firstHalf == secondHalf){
          ans+=i;
        }
      }
    }

    strStart = strEnd + 1;
  }
  std::cout << ans << std::endl;
}
