#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  if(argc != 2) {
    return 1;
  }

  ifstream fReader(argv[1]);
  if(!fReader.is_open()) {
    cout << "Invalid filename! Could not open file " << argv[1];
  }

  int wordsRead = 0;
  string firstWord;
  string secondWord;
  map<string, set<string>*> record;
  map<string, set<string>*>::iterator it;
  vector<string> finalList;

  while(fReader >> firstWord) {
    fReader >> secondWord;
    if(firstWord == "0" && secondWord == "0") {
      break;
    }
    it = record.find(secondWord);
    if(it == record.end()) {
      set<string>* prereqs = new set<string>();
      prereqs->insert(firstWord);
      record.insert(pair<string, set<string>*>(secondWord, prereqs));
    }else{
      it->second->insert(firstWord);
    }
    it = record.find(firstWord);
    if(it == record.end()) {
      set<string>* prereqs = new set<string>();
      record.insert(pair<string, set<string>*>(firstWord, prereqs));
    }
  }
  while(!(record.empty())) {
    vector<string> zeroDepend;
    for(it = record.begin(); it != record.end(); it++) {
      if(it->second->size() == 0) {
	zeroDepend.push_back(it->first);
      }
    }
    for(vector<string>::iterator vit = zeroDepend.begin(); vit != zeroDepend.end(); vit++) {
      it = record.find(*vit);
      if(it != record.end()) {
	delete it->second;
        record.erase(it);
      }
      for(it = record.begin(); it != record.end(); it++) {
        it->second->erase(*vit);
      }
    }
    sort(zeroDepend.begin(), zeroDepend.end());
    finalList.insert(finalList.end(), zeroDepend.begin(), zeroDepend.end());
  }
  for(vector<string>::iterator vit = finalList.begin(); vit != finalList.end(); vit++) {
    cout << *vit << " ";
    cout << endl;
  }
}


    
    
    
