#include "src/bloom.h"
#include "src/MurmurHash3.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  cout << "****** Starting BloomFilter Test ******" << endl;

  BloomFilter* filter = new BloomFilter(20, .05);

  string toAdd[20] = {"one","two","three","four","five","six","seven","eight","nine",
  "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};

  string toTest[5] = {"taka","koutso","one","forty","fifteen"};

  for (int i=0; i<20; i++) {
    string s = toAdd[i];
    char c[s.length()+1];
    strcpy(c, s.c_str());

    filter->add(c);
  }

  cout << "Testing values:" << endl;

  for (int i=0; i<5; i++) {
    string s = toTest[i];
    char c[s.length()+1];
    strcpy(c, s.c_str());
    bool result = filter->contains(c);

    cout << s << ": " <<  result << endl;
  }

  cout << "****** Bloom Filter Test Complete ******" << endl;
}
