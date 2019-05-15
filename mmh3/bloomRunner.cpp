#include "src/bloom.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
  cout << "****** Starting BloomFilter Test ******" << endl;
  BloomFilter* filter = new BloomFilter(258001, .05);

  // Open fstream file
  fstream file;
  file.open("names.csv");

  //Check for opening error
  if (file.fail()) {
      cout << "Error opening file" << endl;
      exit(1);
  }

  string addStr;
  while (getline(file, addStr)) {
    char c[addStr.length()+1];
    strcpy(c, addStr.c_str());

    filter->add(c);
  }

  file.close();

  cout << "Begin testing values. Enter -1 to finish." << endl << endl;

  string check;

  while (check.compare("-1") != 0) {
    cin >> check;

    char charCheck[check.length()+1];
    strcpy(charCheck, check.c_str());

    if (check.compare("-1") != 0) {
      bool res = filter->contains(charCheck);
      string result;
      res ? result="Likely present" : result="Not present";
      cout << check << ": " << result << endl << endl;
    }
  }

  cout << "****** BloomFilter Test Complete ******" << endl;
}
