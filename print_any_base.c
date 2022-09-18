#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Write the print_any_base function below so it returns the string representation of a base 10 number converted to the given base where the symbols of the base are 0 through 9 followed by A through Z */

char* print_any_base(unsigned long num, unsigned int base) {
  char *output;
  output = (char *) malloc(100);
  if(base < 2 || base > 36)
    {
      char ill[13] = "Illegal base";
      printf("%d", strlen(ill));
      char *ill1 = ill;
      return ill1;
    }
   int count = 0;
   unsigned long number = num;
   unsigned long remainder = 0;
   if(num/base == 0)
     {
       strcpy(output, "0");
       return output;
     }
   while (number != 0)
    {
      remainder = number%base;
      if(remainder > 9)
        {
          output[count++] = (remainder-10)+'A';
        }
      else
        {
          output[count++] = remainder + '0';
        }
      number = number/base;
    }
    //reverse output string
    int length = strlen(output);
    char *begin = output;
    char *end = output;
    char temp;
    for(int i = 0; i < (length - 1) ; i++)
      {
        end++;
      }
    for(int i = 0; i < length/2; i++)
      {
        temp = *end;
        *end = *begin;
        *begin = temp;
        begin++;
        end--;
      }

  return output;
  
}

int main(){
  printf("Test cases:\n");
  printf("num = %u base = %u Output = %s\n", 1234, 2, print_any_base(1234,2));
  printf("num = %u base = %u Output = %s\n", 1234, 3, print_any_base(1234,3));
  printf("num = %u base = %u Output = %s\n", 1234, 16, print_any_base(1234,16));
  printf("num = %u base = %u Output = %s\n", 1234, 36, print_any_base(1234,36));
  printf("num = %u base = %u Output = %s\n", 12345678, 23, print_any_base(12345678,23));
  printf("num = %u base = %u Output = %s\n", 0, 25, print_any_base(0,23));
  printf("num = %u base = %u Output = %s\n", 100, 44, print_any_base(100,44));
  return 0;
}
