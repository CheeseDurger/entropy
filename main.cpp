/*!
  * \brief prints a file entropy (between 0 and 8)
  * \details
  * Usage : [prog_name] [file_name]
  * Example: entropy.exe filename.ext
  */

#include <stdio.h>
#include <math.h>
#include <string.h>

/*!
  * \brief calculates entropy
  * \details entropy = sum( character_frequency * log2( 1/character_frequency ) )
  * \param buffer buffer and char
  * \param buffer_length length of buffer
  * \return entropy of the buffer content
  */
double calculate_entropy(unsigned char *buffer, int buffer_length) {
  double entropy = 0.0;
  unsigned long character_count[256];
  double character_frequency[256];

  memset(character_count, 0, 256*4);

  for (int i = 0; i < buffer_length; i++)
    character_count[buffer[i]]++;

  for (int i = 0; i < 256; i++)
    character_frequency[i] = (double) character_count[i] / buffer_length;

  for (int i = 0; i < 256; i++)
    if (character_frequency[i] > 0.0)
      entropy += character_frequency[i] * log2((1.0 / character_frequency[i]));

  return entropy;
}


int main(int argc, char *argv[]) {

  char *filename = argv[1];
  FILE *file;

  // Build a buffer with input file content
  if ((file = fopen(filename, "rb")) == NULL) {
    perror("Error in fopen(filename, \"rb\")");
    exit(-1);
  }
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);  /* same as rewind(file); */
  unsigned char *buffer = (unsigned char *)malloc(file_size + 1);
  fread(buffer, file_size, 1, file);
  fclose(file);

  // Calculate entropy
  double entropy = calculate_entropy(buffer, file_size);
  free(buffer);

  printf("Entropy: %f", entropy);
  return 0;
}
