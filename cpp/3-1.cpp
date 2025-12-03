#include <iostream>
#include <string>
int main(){
  std::string line;
  int ans = 0;
  while(std::getline(std::cin, line)){
    if(line == "END"){
      break;
    }
    int idx = 0;
    int dig1 = 0;
    for(int i=0; i<line.size()-1; i++){
      if(line[i] - '0' > dig1){
        dig1 = line[i] - '0';
        idx = i;
      }
    }
    idx = idx + 1;
    int dig2 = 0;
    for(int i=idx; i<line.size(); i++){
      if(line[i] - '0' > dig2){
        dig2 = line[i] - '0';
      }
    }
    ans += dig1*10+dig2;
  }
  std::cout << ans << std::endl;
}