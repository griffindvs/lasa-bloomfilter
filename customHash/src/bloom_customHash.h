#ifndef bloom_customHash
#define bloom_customHash

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <array>

using namespace std;

class BloomFilter {
  int items, arrSize;
  int hashCount;
  float falseProb;
  vector<bool> bitArr;

  public:
      BloomFilter(int items, float falseProb);
      int getArrSize();
      int getHashCount();
      void initArr();
      void add(char* item);
      bool contains(char* item) const;
};

#endif
