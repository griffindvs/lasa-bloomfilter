gcc -c src/bloom.cpp src/MurmurHash3.cpp
ar rsv BloomFilter.a bloom.o MurmurHash3.o
gcc server.cpp -o server BloomFilter.a