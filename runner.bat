gcc -c src/*.cpp
ar rsv BloomFilter.a bloom.o MurmurHash3.o
g++ bloomRunner.cpp -o bloomRunner.exe BloomFilter.a
