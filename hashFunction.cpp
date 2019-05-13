#include <iostream>
#include <string>
#include <iterator>
#include <bitset>
using namespace std;

string hashCharArray(bitset<128> name){
  //note count is bitset function built into c++ that returns number 1's in bitset
  string numOne = to_string(name.count());
  int exponents;
  for(int i = 0; i < 128; i++){
    if(name[i] == 1){
      exponents += i;
    }
  }
  string strEx = to_string(exponents);
  string hash;
  hash = numOne + strEx;
  return hash;
}
bitset<128> conToBin(char nameChar[]){
    int sizeNc = *(&nameChar + 1) - nameChar;
    int nameNum[sizeNc];
    for(int i = 0; i < sizeNc; i++){
      nameNum[i] = (int)(nameChar[i]);
    }
    string strNum;
    for(int i = sizeNc - 1; i >= 0; i--){
      strNum += to_string(nameNum[i]);
    }
    int num = stoi(strNum);
    string binary;
    int quotiant;
    int addToBin;
    while(quotiant > 0){
        quotiant = num / 2;
        addToBin  = num % 2;
        binary = binary + to_string(addToBin);
        num = quotiant;
    }
    string temp;
    int count = binary.length();
    int intBin;
    intBin = stoi(binary);
    while(count > -1){
        temp += to_string(intBin % 10);
        intBin / 10;
        count --;
    }
    bitset<128> setBin(intBin);
    return setBin;
}
