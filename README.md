# lasa-bloomfilter

This is a C++ implementation of a [bloom filter](https://en.wikipedia.org/wiki/Bloom_filter) with a dataset of names. It was created as a project for an [Advanced Computer Programming course](http://lasacs.com).

## Compilation & Testing

### Building the Static Library in Windows
1. Compile each individual C++ file in the terminal using `gcc -c src/bloom.cpp src/MurmurHash3.cpp` in the `/mmh3` directory
   - The `-c` switch tells GCC to compile and assemble but not link the files
   - The `*.cpp` will compile every C++ file in the src folder
   - This will create object files outside of the src folder
2. The static library can then be created using `ar rsv BloomFilter.a bloom.o MurmurHash3.o`
   - The `r` switch replaces any previous libraries with that name
   - The `s` switch creates an archive
   - The `v` switch uses verbose to provide additional output
   - The `*.o` will add every compiled C++ file in the directory
3. The library contents can be verified with `ar -t BloomFilter.a`

### Testing the Static Library for Windows
To run the bloomRunner.cpp file, use the command `g++ bloomRunner.cpp -o bloomRunner.exe BloomFilter.a` in the `/mmh3` directory. This will create `bloomRunner.exe` that is linked to the static library. To run the file, type `bloomRunner` into the terminal. Then follow the instructions printed in the command line to begin testing. The runner file also includes a memory size comparison with a string array.

### Using the Runner Script
The `runner.bat` file in `/mmh3` can be used to complete each of the steps above before automatically running the `bloomRunner.exe` file. To keep the terminal open after testing is complete, open the terminal and enter `runner.bat` manually while in the `/mmh3` directory.
