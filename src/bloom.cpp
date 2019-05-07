#include "src/bloom.h"
#include "src/MurmurHash3.h"

using namespace std;

// Calculates the hash of a given item
// Returns an array of two 64 bit hashes
/* Parameters:
  *Constant unsigned 8 bit integer for the data
  (constant prevents modification inside function)
  *sizeof() operator type (size_t) len for the length of data
*/
array<uint64_t, 2> runHash(const uint8_t *data, size_t len) {
  array<uint64_t, 2> hashVal;
  MurmurHash3_x64_128(data, len, 0, hashVal.data());
  return hashVal;
}

// Returns the output of the nth hash function. Modulo length of the array for index.
inline uint64_t nthHash(uint8_t n, uint64_t hashA, uint64_t hashB, uint64_t arrSize) {
  return (hashA + n * hashB) % arrSize;
}

BloomFilter::BloomFilter(int items, float falseProb) {
  this->falseProb = falseProb;
  this->arrSize = this->getArrSize();
  this->hashCount = this->getHashCount();
  this->bitArr[arrSize];
  this->initArr();
}

int BloomFilter::getArrSize() {
  int i = this->items;
  int f = this->falseProb;
  // Calculates the optimal bit array size for
  // a given number of items and false positive probability
  int s = -(i*log(f))/(pow(log(2),2));
  return s;
}

int BloomFilter::getHashCount() {
  int s = this->arrSize;
  int i = this->items;
  // Calculates the optimal hash function count for
  // a given bit array size and number of items
  int h = (s/i) * log(2);
  return h;
}

void BloomFilter::bloomAdd(const uint8_t *data, size_t len) {
  auto hashVal = runHash(data, len);

  for (int i = 0; i < this->hashCount; i++) {
    bitArr[nthHash(i, hashVal[0], hashVal[1], bitArr.size())] = true;
  }
}

bool BloomFilter::bloomContains(const uint8_t *data, size_t len) const {
  auto hashVal = runHash(data, len);

  for (int i = 0; i < this->hashCount; i++) {
    if (!bitArr[nthHash(i, hashVal[0], hashVal[1], bitArr.size())]) {
      return false;
    }
  }
  return true;
}
