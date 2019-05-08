#include "src/bloom.h"
#include "src/MurmurHash3.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  cout << "Running" << endl;
  BloomFilter* filter = new BloomFilter(2, .001);
  cout << "Created filter" << endl;
  string firstString = "one";
  char firstChar[firstString.length()+1];
  strcpy(firstChar, firstString.c_str());
  cout << "strcpy1" << endl;
  filter->add(firstChar);
  cout << "Added" << endl;
  string secondString = "two";
  char secondChar[secondString.length()+1];
  strcpy(secondChar, secondString.c_str());
  cout << "strcpy2" << endl;
  filter->add(secondChar);
  cout << "Removed" << endl;

  cout << "" + filter->contains(firstChar) << endl;
}
