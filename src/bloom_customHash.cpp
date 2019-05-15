#include "bloom_customHash.h"
#include "hashFunction.cpp"

using namespace std;

// Calculates the hash of a given item
// Returns an array of two 64 bit hashes
string runHash(char* item) {
  const char* key = item;
  string hashVal;
  hashVal = hashCharArray(key);
  return hashVal;
}

// Returns the output of the nth hash function. Modulo length of the array for index.
uint64_t nthHash(int n, string hash, uint64_t arrSize) {
  return ((uint128_t)hash * n) % arrSize;
}

// Class constructor
BloomFilter::BloomFilter(int items, float falseProb) {
  this->items = items;
  this->falseProb = falseProb;
  this->arrSize = getArrSize();
  this->hashCount = getHashCount();
  initArr();
}

// Calculates bitset size
int BloomFilter::getArrSize() {
  int i = this->items;
  float f = this->falseProb;
  // Calculates the optimal bit array size for
  // a given number of items and false positive probability
  int s = -(i*log(f))/(pow(log(2),2));
  return s;
}

// Calculates number of hashes
int BloomFilter::getHashCount() {
  int s = this->arrSize;
  int i = this->items;
  // Calculates the optimal hash function count for
  // a given bit array size and number of items
  int h = (s/i) * log(2);
  return h;
}

// Initializes the bit array with a given size
void BloomFilter::initArr() {
  bitArr.reserve(arrSize);
  for (int i = 0; i < arrSize; i++) {
    bitArr.push_back(0);
  }
}

// Add items to the filter
void BloomFilter::add(char* item) {
  string hashVal = runHash(item);

  for (int i = 0; i < this->hashCount; i++) {
    bitArr[nthHash(i, hashVal, bitArr.size())] = true;
  }
}

// Checks for item presence
bool BloomFilter::contains(char* item) const {
  string hashVal = runHash(item);

  for (int i = 0; i < this->hashCount; i++) {
    if (!bitArr[nthHash(i, hashVal, bitArr.size())]) {
      return false;
    }
  }
  return true;
}
