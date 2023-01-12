# Compile
To compile: `g++ main.cpp -o entropy.exe`

# Run
To run: `entropy.exe [filename]`

It prints the file's entropy, between 0 and 8. Typically, encrypted files will have an entropy very close to 8. Like 7.99... The better the encryption, the higher the entropy.

The formula for entropy is : `entropy = sum( character_frequency * log2( 1/character_frequency ) )`

# Note
Beware, this utility works fine, but is just a proof of concept. It is not intended to be production ready.
