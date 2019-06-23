/**
 * C program to convert string to unsigned long int using strtoul() library function.
 */

#include <stdio.h>
#include <stdlib.h>     // Used for strtoul()


int main()
{
  char *p, *s;
  unsigned long uli;

  s = "123 dheeraj kumar";
  uli = strtoul(s, &p, 10);
  printf ("\n%lu \n%s\n\n", uli, p);

    return 0;
}
 
 // %lu format specifier is used to print unsigned long int type.
 //
 
 Output
 
 123 
 dheeraj kumar




