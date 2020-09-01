#include <iostream>
#include <limits>

void sizeOfTest() {
  std::cout << "size of int: " << sizeof(int) << "\n";
  std::cout << "size of unsigned int: " << sizeof(unsigned int) << "\n";
  std::cout << "size of float: " << sizeof(float) << "\n";
  std::cout << "size of double: " << sizeof(double) << "\n";
  std::cout << "size of char: " << sizeof(char) << "\n";
  std::cout << "size of bool: " << sizeof(bool) << "\n";
  std::cout << "size of int*: " << sizeof(int*) << "\n";
  std::cout << "size of char*: " << sizeof(char*) << "\n";
  std::cout << "size of double*: " << sizeof(double*) << "\n";
  
}
void overflow() {
  unsigned int maxNumber = std::numeric_limits<int>::max();
  
  std::cout << maxNumber + 1 << "\n";
}

void outputBinary(unsigned int x) {
  char bin32[] = "00000000000000000000000000000000";
  for(int pos = 31; pos >=0; pos--) {
    if (x%2) {
      bin32[pos] = '1';
    }
    x/=2;
  }
  std::cout << bin32 << "\n";
}

int main() {
  unsigned int x;
  std::cout << "Please enter single integer value: ";
  std::cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  
}

  
