#ifndef bloom
#define bloom

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class BloomFilter {
  int items, arrSize;
  uint8_t hashCount;
  float falseProb;
  vector<bool> bitArr;

  public:
      void BloomFilter(int items, float falseProb);
      int getArrSize();
      int getHashCount();
      void bloomAdd(String item);
      bool bloomContains(String item);
      void initArr();
};

#endif
