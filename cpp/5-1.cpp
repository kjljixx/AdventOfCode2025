#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using ll = long long;

auto main() -> int {
  std::string line;
  std::vector<std::pair<ll, ll>> ranges;
  while(std::getline(std::cin, line)) {
    if (line.empty()){
      break;
    }
    size_t delimiter = line.find('-');
    ll num1 = std::stoll(line.substr(0, delimiter));
    ll num2 = std::stoll(line.substr(delimiter + 1));
    ranges.emplace_back(num1, num2);
  }

  ll ans = 0;
  while(std::getline(std::cin, line)) {
    ll num = std::stoll(line);
    for (auto range : ranges) {
      if (num >= range.first && num <= range.second) {
        ans++;
        break;
      }
    }
  }

  std::cout << ans << "\n";
}