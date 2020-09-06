#ifndef MYHASH_H
#define MYHASH_H
#include <iostream>

class MyHashSet() {
  
 public:
  MyHashSet();
  void insert(string input);
  bool contains(string input);
  void remove(string input);

 private:
  int table_size;
  float load_factor;

  int hash(string input);
  void rehash();
};
#endif
