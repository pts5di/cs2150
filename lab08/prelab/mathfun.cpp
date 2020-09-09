#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);

int main() {
  cout << product(3,4);
}
