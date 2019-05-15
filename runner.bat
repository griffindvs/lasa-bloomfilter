gcc -c src/bloom.cpp src/MurmurHash3.cpp
ar rsv BloomFilter.a bloom.o MurmurHash3.o
g++ bloomRunner.cpp -o bloomRunner.exe BloomFilter.a
bloomRunner.exe
