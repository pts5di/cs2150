#include "myHash.h"

using namespace std;
MyHashSet::MyHashSet() : table_size(11), load_factor(1.0), bcount(0) {
  buckets = new string[table_size]();
}

int MyHashSet::hash(string input) {
  int result = 0;
  int realMin = min(10, input.size());
  for(int i = 0; i < realMin; i++) {
    result += (int)(input[i]);
  }
  return result;
}

void MyHashSet::insert(string input) {
  int key = hash(input) % table_size;
  bcount++;
  if(((float)(bcount) / table_size) >= load_factor) {
    rehash();
  }
  while(buckets[key] != "") {
    key++;
  }
  buckets[key] = input;
}
bool MyHashSet::contains(string input) {
  int key = hash(input) % table_size;
  while(buckets[key] != "") {
    if(buckets[key] == input) {
      return true;
    }else{
      key++;
    }
    return false;
}

void MyHashSet::remove(string input) {
  int key = hash(input) % table_size;
  while(buckets[key] != "") {
    if(buckets[key] == input) {
      buckets[key] = "";
      bcount--;
    }else{
      key++;
    }
    return;
  }
}
void MyHashSet::rehash() {
  // rehash here
}
