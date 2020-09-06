#include "myHash.h"
#include <algorithm>

using namespace std;
MyHashSet::MyHashSet() : table_size(11), load_factor(1.0), bcount(0) {
  buckets = new string[table_size]();
}

MyHashSet::~MyHashSet() {
  delete[] buckets;
}

unsigned long MyHashSet::hash(string input) {
  unsigned long result = 0;
  int e = 1;
  int realMin = min((unsigned long)(10), input.size());
  for(int i = 0; i < realMin; i++) {
    result += ((int)(input[i]))*e;
    e *= 37;
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
    key = (key+1) % table_size;
  }
  buckets[key] = input;
}
bool MyHashSet::contains(string input) {
  int key = hash(input) % table_size;
  while(buckets[key] != "") {
    if(buckets[key] == input) {
      return true;
    }else{
      key = (key+1) % table_size;
    }
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
      key = (key+1) % table_size;
    }
    return;
  }
}
 
void MyHashSet::rehash() {
  string * oldBuckets = buckets;
  int oldTable = table_size;
  table_size = getNextPrime(table_size*2);
  buckets = new string[table_size]();
  bcount = 0;
  for(int i = 0; i < oldTable; i++) {
    if(oldBuckets[i] != "") {
      insert(oldBuckets[i]);
    }
  }
  delete[] oldBuckets;
}


bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n;
}
