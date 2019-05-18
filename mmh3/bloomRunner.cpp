#include "src/bloom.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;

int main() {
  cout << "****** Starting BloomFilter Test ******" << endl;
  // Initialize bloom filters
  BloomFilter* fullFilter = new BloomFilter(258001, .005);
  BloomFilter* smallFilter = new BloomFilter(60000, .005);

  // Initialize example array
  string smallArray[60000];

  // Open fstream file
  fstream file;
  file.open("names.csv");

  //Check for opening error
  if (file.fail()) {
      cout << "Error opening file" << endl;
      exit(1);
  }

  // Small name dataset input to smallFilter and smallArray
  string addStr1;
  for (int i=0; i<60000; i++) {
    getline(file, addStr1);
    smallArray[i] = addStr1; // Add to the array
    char c[addStr1.length()+1];
    strcpy(c, addStr1.c_str()); // Convert to char array
    smallFilter->add(c); // Add to the filter
  }

  // Close the file
  file.close();

  // Open fstream file again
  file.open("names.csv");

  // Full name dataset input to fullFilter
  string addStr2;
  while (getline(file, addStr2)) {
    char c[addStr2.length()+1];
    strcpy(c, addStr2.c_str()); // Convert to char array
    fullFilter->add(c); // Add to the filter
  }

  // Close the file
  file.close();

  cout << "Begin linear search example. Enter -1 to finish." << endl << endl;

  string check1; // Initialize string for input
  bool linearRes = false; // Initialize boolean flag for search

  while (check1.compare("-1") != 0) {
    cin >> check1; // Gather input from terminal
    linearRes = false;

    // Start clock 1
    std::clock_t start1;
    double duration1;
    start1 = std::clock();

    if (check1.compare("-1") != 0) {
      // Linear search for test value
      for (int i=0; i<60000; i++) {
        if (check1.compare(smallArray[i]) == 0) {
          linearRes = true;
          break;
        }
      }
    }

    if (check1.compare("-1") != 0) {
      // Calculate search time
      duration1 = ( std::clock() - start1 ) / (double) CLOCKS_PER_SEC;

      // Print result
      string linearResult;
      linearRes ? linearResult="Linear search present" : linearResult="Linear search not present";
      cout << check1 << ": " << linearResult << endl << endl;
      //cout << "Time to search: " << duration1 << "s" << endl << endl;
    }
  }

  cout << endl << "Array Size: " << sizeof(smallArray) << " bytes (" << sizeof(smallArray)/1000000.0 << " megabytes)" << endl;

  // Bloom filter test with small dataset
  cout << endl << "Begin bloom filter example. Enter -1 to finish." << endl << endl;
  string check2; // Initialize string for input

  while (check2.compare("-1") != 0) {
    cin >> check2; // Gather input from terminal

    // Start clock 2
    std::clock_t start2;
    double duration2;
    start2 = std::clock();

    // Convert input to char
    char charCheck2[check2.length()+1];
    strcpy(charCheck2, check2.c_str());

    if (check2.compare("-1") != 0) {
      bool res = smallFilter->contains(charCheck2); // Check for input in filter

      // Calculate search time
      duration2 = ( std::clock() - start2 ) / (double) CLOCKS_PER_SEC;

      // Print result
      string result;
      res ? result="Likely present" : result="Not present";
      cout << check2 << ": " << result << endl << endl;
      //cout << "Time to search: " << duration2 << "s" << endl << endl;
    }
  }

  cout << endl << "Filter Size: " << sizeof(smallFilter) << " bytes" << endl;

  // Bloom filter test with large dataset
  cout << endl << "Begin large dataset example. Enter -1 to finish." << endl << endl;
  string check3; // Initialize string for input

  while (check3.compare("-1") != 0) {
    cin >> check3; // Gather input from terminal

    // Start clock 3
    std::clock_t start3;
    double duration3;
    start3 = std::clock();

    // Convert input to char
    char charCheck3[check3.length()+1];
    strcpy(charCheck3, check3.c_str());

    if (check3.compare("-1") != 0) {
      bool res = fullFilter->contains(charCheck3); // Check for input in filter

      // Calculate search time
      duration3 = ( std::clock() - start3 ) / (double) CLOCKS_PER_SEC;

      // Print result
      string result;
      res ? result="Likely present" : result="Not present";
      cout << check3 << ": " << result << endl << endl;
      //cout << "Time to search: " << duration3 << "s" << endl << endl;
    }
  }

  cout << endl << "Filter Size: " << sizeof(fullFilter) << " bytes" << endl;

  cout << endl << "****** BloomFilter Test Complete ******" << endl;
}
