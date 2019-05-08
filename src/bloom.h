#ifndef bloom
#define bloom

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <array>

using namespace std;

class BloomFilter {
  int items, arrSize;
  uint8_t hashCount;
  float falseProb;
  vector<bool> bitArr;

  public:
      BloomFilter(int items, float falseProb);
      int getArrSize();
      int getHashCount();
      void add(char* item);
      bool contains(char* item) const;
      //void initArr();
};

#endif
