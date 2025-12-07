#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using ll = long long;

auto main() -> int {
  std::vector<std::vector<ll>> operands;
  std::vector<ll> operators;
  std::string line;
  while (std::getline(std::cin, line)) {
    if (line.empty()) {
      break;
    }
    std::istringstream iss(line);
    ll operand = 0;
    std::vector<ll> current_operands;
    while (iss >> operand) {
      current_operands.push_back(operand);
    }
    if (!current_operands.empty()){
      operands.push_back(current_operands);
    }
    else{
      char operatorChar = 0;
      iss = std::istringstream(line);
      while (iss >> operatorChar) {
        operators.push_back(operatorChar == '+' ? 1 : 0);
      }
    }
  }

  ll ans = 0;
  for(ll i=0; i<operators.size(); i++){
    ll result = 0;
    std::cerr << ans << "\n";
    if(operators[i] == 1){
      for(auto & operand : operands){
        result += operand[i];
      }
    }
    else{
      result = 1;
      for(auto & operand : operands){
        result *= operand[i];
      }
    }
    ans += result;
  }
  std::cout << ans;
}