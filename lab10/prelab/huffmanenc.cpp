#include <iostream>
#include <fstream>
#include "heap.h"

using namespace std;
int main() {
  string filename;
  ifstream fileReader;
  cout << "Enter the name of the file to encode: ";
  cin >> filename;
  fileReader.open(filename);
  if(fileReader.is_open()) {
    while(!fileReader.eof())
      
}
