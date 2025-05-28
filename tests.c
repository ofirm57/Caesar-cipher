#include <string.h>
#include "tests.h"

#define K_1 3
#define K_2 2
#define MINUS_K -1
#define MINUS3_K -3
#define K_29 29

int test_encode_non_cyclic_lower_case_positive_k ()
{
  char in[] = "abc";
  char out[] = "def";
  encode (in, K_1);
  return strcmp (in, out) != 0;
}

int test_encode_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = " yY,zZ.";
  char out[] = " aA,bB.";
  encode (in, K_2);
  return strcmp (in, out) != 0;
}

int test_encode_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "$bB$kK% ";
  char out[] = "$aA$jJ% ";
  encode (in, MINUS_K);
  return strcmp (in, out) != 0;
}

int test_encode_cyclic_lower_case_negative_k ()
{
  char in[] = "rilu";
  char out[] = "ofir";
  encode (in, MINUS3_K);
  return strcmp (in, out) != 0;
}

int test_encode_cyclic_upper_case_positive_k ()
{
  char in[] = "XYZ";
  char out[] = "ABC";
  encode (in, K_29);
  return strcmp (in, out) != 0;
}

int test_decode_non_cyclic_lower_case_positive_k ()
{
  char in[] = "def";
  char out[] = "abc";
  decode (in, K_1);
  return strcmp (in, out) != 0;
}

int test_decode_cyclic_lower_case_special_char_positive_k ()
{
  {
    char in[] = " aA,bB.";
    char out[] = " yY,zZ.";
    decode (in, K_2);
    return strcmp (in, out) != 0;
  }
}

int test_decode_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "$aA$jJ ";
  char out[] = "$bB$kK ";
  decode (in, MINUS_K);
  return strcmp (in, out) != 0;
}

int test_decode_cyclic_lower_case_negative_k ()
{
  char in[] = "ofir";
  char out[] = "rilu";
  decode (in, MINUS3_K);
  return strcmp (in, out) != 0;
}

int test_decode_cyclic_upper_case_positive_k ()
{
  char in[] = "ABC";
  char out[] = "XYZ";
  decode (in, K_29);
  return strcmp (in, out) != 0;
}
