#ifndef bloom
#define bloom

#include <iostream>
#include <string>
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
      void bloomAdd(const uint8_t *data, size_t len);
      bool bloomContains(const uint8_t *data, size_t len) const;
      void initArr();
};

#endif
