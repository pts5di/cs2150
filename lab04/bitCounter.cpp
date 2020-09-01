#include <iostream>
#include <stdlib.h>

int binaryCounter(int x) {
  
  if (x == 0) {
    return 0;
  }
  else {
    return (x%2) + binaryCounter(x/2);
  }
}

std::string baseConverter(char* x, int startBase, int endBase) {
  int num = 0;
  for(char* c = x; *c != '\0'; c++) {
    num *= startBase;

    if(47 < *c && *c < 58) {
      num += *c-48;
    }
    else if(64 < *c && *c < 91) {
      num += *c-55; 
    }
    else {
      break;
    }
  }

  if(num == 0) {
    return "0";
  }
  
  std::string result = "";
  for(int n = num; n != 0; n/=endBase) {
    int digit = n%endBase;
    if(0 <= digit && digit <= 9) {
      result.push_back((char)(digit+48));
    }
    else if (10 <= digit && digit <= 36) {
      result.push_back((char)(digit+55));
    }
  }
  return result;
}
int main(int argc, char *argv[]) {
  if(argc < 2) {
    std::cerr << "invalid input! too few arguments!(need 1)" << std::endl;
  }
  std::cout << argv[1] << " has " << binaryCounter(atoi(argv[1])) << " 1 bit(s)!" << std::endl;
  if(argc < 5) {
    std::cerr << "invalid input! too few arguments(need 4)" << std::endl;
  }
  std::cout << argv[2] << " (base " << atoi(argv[3]) << ") = " << baseConverter(argv[2], atoi(argv[3]), atoi(argv[4])) << " (base " << argv[4] << ")" << std::endl;
}

