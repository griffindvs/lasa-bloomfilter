gcc -c src/bloom_customHash.cpp src/hashFunction.cpp
ar rsv BloomFilter_customHash.a bloom_customHash.o hashFunction.o
g++ bloomRunner_customHash.cpp -o bloomRunner_customHash.exe BloomFilter_customHash.a
bloomRunner_customHash.exe
