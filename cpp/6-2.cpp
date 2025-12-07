#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using ll = long long;

auto main() -> int {
  std::vector<ll> operators;
  std::vector<std::string> inputLines;
  std::string line;
  while (std::getline(std::cin, line)) {
    if (line.empty()) {
      break;
    }
    inputLines.push_back(line);
  }
  ll lineWidth = inputLines[0].size();
  std::vector<std::string> transposedInput(lineWidth, std::string());
  for(auto iterLine : inputLines){
    for(ll i=0; i<lineWidth; i++){
      if(iterLine[i] == '+'){
        operators.push_back(1); 
      }
      else if(iterLine[i] == '*'){
        operators.push_back(0); 
      }
      else{
        transposedInput[i] += iterLine[i];
      }
    }
  }

  std::vector<std::vector<ll>> operands(1);
  for (auto& line : transposedInput) {
    if (line.empty()) {
      break;
    }
    std::istringstream iss(line);
    std::cerr << line << "\n";
    ll operand = 0;
    std::vector<ll> current_operands;
    while (iss >> operand) {
      current_operands.push_back(operand);
      std::cerr << operand << "\n";
    }
    //assert current_operands.size() <= 1;
    if (!current_operands.empty()){
      operands.back().push_back(current_operands[0]);
    }
    else{
      std::cerr << "NEWLINE\n";
      operands.emplace_back();
    }
  }

  std::cerr << "CALCULATING\n";

  ll ans = 0;
  for(ll i=0; i<operators.size(); i++){
    ll result = 0;
    std::cerr << ans << "\n";
    if(operators[i] == 1){
      for(auto & operand : operands[i]){
        std::cerr << "+ " << operand << "\n";
        result += operand;
      }
    }
    else{
      result = 1;
      for(auto & operand : operands[i]){
        std::cerr << "* " << operand << "\n";
        result *= operand;
      }
    }
    ans += result;
  }
  std::cout << ans;
}