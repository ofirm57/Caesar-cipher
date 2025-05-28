#include "cipher.h"
#include <string.h>
/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.



// Macros
#define BIG_MIN     96
#define BIG_MAX     123
#define SMALL_MIN   64
#define SMALL_MAX   91
#define NUM_LETTERS 26



void change_s (char s[], int k, int min_val, int max_val)
{
  int i = 0;
  while (s[i] != '\0')
  {
    if(s[i] > min_val && s[i] < max_val)
    {
      if ( (s[i] + (k % NUM_LETTERS) > max_val))
      {
        s[i] = s[i] - (NUM_LETTERS - k % NUM_LETTERS);
      }
      else
      {
        if( k >=0 || min_val < s[i] + (k % NUM_LETTERS) )
        { s[i] = s[i] + (k % NUM_LETTERS); }
        else
        {
          s[i] = s[i] + (NUM_LETTERS + (k % NUM_LETTERS) );}

      }
    }
    i++;
  }
}

// See full documentation in header file
void encode (char s[], int k)
{
  change_s (s, k,  BIG_MIN,  BIG_MAX); //Big letters
  change_s (s, k,  SMALL_MIN,  SMALL_MAX); // small letters
}
// See full documentation in header file
void decode (char s[], int k)
{
  change_s (s, -k,  BIG_MIN,  BIG_MAX); //Big letters
  change_s (s, -k,  SMALL_MIN, SMALL_MAX); // small letters
}
