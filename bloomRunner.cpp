#include "src/bloom.h"
#include "src/MurmurHash3.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Running" << endl;
  BloomFilter* filter = new BloomFilter(100, .001);
  cout << "Created filter" << endl;
  const uint8_t* one = new uint8_t(4);
  filter->bloomAdd(one, 8);
  cout << "Added" << endl;
  const uint8_t* two = new uint8_t(3);
  filter->bloomAdd(two, 8);
  cout << "Removed" << endl;

  cout << "" + filter->bloomContains(one, 8) << endl;
}
