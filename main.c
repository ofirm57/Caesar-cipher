#include "cipher.h"
#include "tests.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h> //for FILE, fopen, fclose, fprintf
#include <ctype.h>



#define ARG_ERROR "The program receives 1 or 4 arguments only.\n"
#define TEST_ERROR "Usage: cipher test\n"
#define INVALID_COMMAND "The given command is invalid.\n"
#define INVALID_VALUE "The given shift value is invalid.\n"
#define INVALID_FILE "The given file is invalid.\n"
#define COMMAND_ENCODE "encode"
#define COMMAND_DECODE "decode"

#define MAX_OF_CHARS 1024
#define SUCCESS 0
#define FAILURE 1
#define TEST "test"
#define FIRST_ARG 1
#define SEC_ARG 2
#define MAX_VAL_OF_ARGS 5


/**
 * make some test about the args
 * @param argc
 * @param argv
 * @return return SUCCESS if pass the test otherwise return FAILURE
 */
int test_func (int argc, char *argv[])
{
  char *k = argv[2];;
  if (argc != MAX_VAL_OF_ARGS && argc != SEC_ARG)// check the num of args
  {
    fprintf (stderr, ARG_ERROR);
    return FAILURE;
  }
  else if (argc == 2 && (strcmp (argv[FIRST_ARG], TEST)) != 0)//check the test arg
  {
    fprintf (stderr, TEST_ERROR);
    return FAILURE;
  }
  if (argc == MAX_VAL_OF_ARGS)
  {
    if (strcmp (argv[FIRST_ARG], COMMAND_ENCODE) != 0 && strcmp (argv[FIRST_ARG], COMMAND_DECODE) !=0 )// check the
      // first arg
    {
      fprintf (stderr, INVALID_COMMAND);
      return FAILURE;
    }
    int counter = 0;
    if (k[0] == '-' && strlen (k) > 1) //check the minus option
    {
      counter++;
    }
    while (k[counter] != '\0') //check the sec arg
    {
      if (isdigit (k[counter]) == 0)
      {
        fprintf (stderr, INVALID_VALUE);
        return FAILURE;
      }
      counter++;
    }
  }
  return SUCCESS;
}



int apply_tests ()
{
  int num_of_failed_tests = 0;
  num_of_failed_tests += test_encode_non_cyclic_lower_case_positive_k ();
  num_of_failed_tests += test_encode_cyclic_lower_case_special_char_positive_k ();
  num_of_failed_tests += test_encode_non_cyclic_lower_case_special_char_negative_k ();
  num_of_failed_tests += test_encode_cyclic_lower_case_negative_k ();
  num_of_failed_tests += test_encode_cyclic_upper_case_positive_k ();
  num_of_failed_tests += test_decode_non_cyclic_lower_case_positive_k ();
  num_of_failed_tests += test_decode_cyclic_lower_case_special_char_positive_k ();
  num_of_failed_tests += test_decode_non_cyclic_lower_case_special_char_negative_k ();
  num_of_failed_tests += test_decode_cyclic_lower_case_negative_k ();
  num_of_failed_tests += test_decode_cyclic_upper_case_positive_k ();
  return num_of_failed_tests;
}




int main (int argc, char *argv[])
{
  if (test_func (argc, argv) == FAILURE) //make test
    {
      return EXIT_FAILURE;
    }

  if (argc == 2 && strcmp (argv[1], "test") == 0)
    {
    return apply_tests ();
    }
  char line[MAX_OF_CHARS] = {0};
  int k = strtol (argv[2], NULL, 10); //from str to int
  if (argc == MAX_VAL_OF_ARGS)
  {
    FILE *read_file = fopen (argv[3], "r");
    if (read_file == NULL) // check the == !!!!!!//
    {
      fprintf (stderr, INVALID_FILE);
      return EXIT_FAILURE;
    }
    FILE *out_f = fopen (argv[4], "w");
    if (out_f == NULL) // check the == !!!!!!//
    {
      fprintf (stderr, INVALID_FILE);
      printf( "here2 \n");
      fclose (read_file);
      return EXIT_FAILURE;
    }
    while (fgets (line, MAX_OF_CHARS, read_file) != NULL)
    {
      if (strcmp (argv[1], COMMAND_ENCODE) == 0) // if encode
      {
        encode (line, k);
        fputs (line, out_f);
      }
      if (strcmp (argv[1], COMMAND_DECODE) == 0)
      {
        decode (line, k);
        fputs (line, out_f);
      }
    }
    fclose (out_f);
    fclose (read_file);
  }
  return EXIT_SUCCESS;
}
