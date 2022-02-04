#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints a region of memory to stdout as hex digits
 *
 * @param src: starting address in memory to print
 * @param len: the number of bytes to print
 */
void hex(const void* src, size_t len) {
  if(len)
    printf("%02X", ((const unsigned char*) src)[0]);
  for(size_t i = 1; i < len; ++i)
    printf(" %02X", ((const unsigned char*) src)[i]);
  printf("\n");
}

/**
 * @brief Prints information about a buffer to stdout
 *
 * @note: Prints the following in order:
 *          * Buffer name
 *          * Size of the buffer
 *          * Contents of the buffer in hex
 *          * Character representation of the buffer
 *
 * @param   name: name of the buffer
 * @param buffer: starting address of the buffer
 * @param    len: size of the buffer
 */
void bufferInfo(const char* name, const void* buffer, size_t len) {
  printf("Buffer '%s':\n", name);
  printf("\tsizeof: %zu\n", len);
  printf("\tcontents: ");
  hex(buffer, len);
  if(((char*) buffer)[len - 1])
    printf("\tstring: %.*s\n", (int) len, (const char*) buffer);
  else
    printf("\tstring: %s\n", (const char*) buffer);
}

int main(int argc, char* argv[]) {

  /**
   * // Integral Types:
   * // Signed:
   *      signed char c;  // At least one byte
   *      short s;        // At least two bytes
   *      int i;          // At least two bytes
   *      long l;         // At least four bytes
   *      long long ll;   // At least eight bytes
   *
   * // Unsigned:
   *      unsigned char uc;
   *      unsigned short us;
   *      unsigned int ui;
   *      unsigned long ul;
   *      unsigned long long ull;
   */

  /**
   * Fixed size types, located in stdint.h
   *
   * int8_t i8;     // Signed 8-bit integer
   * uint32_t ui32; // Unsigned 32-bit integer
   */

  // Modifiable lvalues
  // myInt: integer, lvalue, can appear on left or right side of "="
  // 5: integer constant, rvalue, can appear only on right side of "="
  int myInt = 5;

  int a;
  int b = 5;
  // a = 1; Fine, 'a' is an lvalue, 1 is an rvalue
  // a = b; Fine, 'a' is an lvaluse, b is an lvalue
  // 3 = a; Bad, 3 is an rvalue!

  // Non-modifiable lvalue
  const int c = 10;
  // a = c; Fine, 'a' is a modifiable lvalue, c is an lvalue
  // c = b; Bad, c is an lvalue, but a *non-modifiable* lvalue

  int intArray[] = {0, 1, 2, 3, 4};
  // intArray = {5, 6, 7, 8, 9}; Bad, intArray is a non-modifiable lvalue

  char hello[] = "Hello World!";
  bufferInfo("hello", hello, sizeof(hello));

  char singleByte[] = "\xFF";
  bufferInfo("singleByte", singleByte, sizeof(singleByte));

  char happy[] = "\xF0\x9F\x98\x8A";
  bufferInfo("happy", happy, sizeof(happy));

  char sad[] = "🙁";
  bufferInfo("sad", sad, sizeof(sad));

  char bye[] = {'B', 'y', 'e', '!'};
  bufferInfo("bye", bye, sizeof(bye));
}
