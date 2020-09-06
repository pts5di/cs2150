#ifndef MYHASH_H
#define MYHASH_H
#include <iostream>

using namespace std;

bool checkprime(unsigned int p);
int getNextPrime(unsigned int n);

class MyHashSet {
  
 public:
  MyHashSet();
  ~MyHashSet();
  void insert(string input);
  bool contains(string input);
  void remove(string input);

 private:
  int table_size;
  float load_factor;
  int bcount;

  int hash(string input);
  void rehash();
  string * buckets;
};
#endif
