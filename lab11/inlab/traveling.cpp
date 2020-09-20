#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    vector<string>::iterator eraser = dests.begin();
    string startCity = *eraser;
    dests.erase(eraser);
    sort(dests.begin(), dests.end());
    vector<string> bestPath = vector<string>(dests);
    float bestPathLength = computeDistance(me, startCity, dests);
    do {
      float currentPathLength = computeDistance(me, startCity, dests);
      if(currentPathLength < bestPathLength) {
	bestPathLength = currentPathLength;
	bestPath = vector<string>(dests);
      }
    } while(next_permutation(dests.begin(), dests.end()));

    cout << "Minimum path has distance of " << bestPathLength << ": ";
    printRoute(startCity, bestPath);
    cout << endl;
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  vector<string>::iterator vsit = dests.begin();
  float totalDist = me.getDistance(start, *vsit);
  
  for(vsit = dests.begin(); vsit != dests.end(); vsit++) {
    vector<string>::iterator vsit2 = vsit+1;
    string vsit2string;
    if(vsit2 != dests.end()) {
      vsit2string = *vsit2;
    }else{
      vsit2string = start;
    }
    totalDist +=  me.getDistance(*vsit, vsit2string);
  }
  return totalDist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  cout << start;
  
  for(vector<const string>::iterator vsit = dests.begin(); vsit != dests.end(); vsit++) {
    cout << " -> " << *vsit;
  }
  cout << " -> " << start << endl;
}
