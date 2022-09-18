#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paritize(void *p, unsigned int num_bytes) {
   unsigned char *bytearr = (unsigned char *) p;

  for(int i = 0; i < num_bytes; i++)
    {
      unsigned int hold = bytearr[i];
      unsigned int count = 0;

      for(int j = 0; j < 7; j++)
        {
          if(hold & 1)
            {
              count++;
            }
          hold = hold >> 1;
        }

      if(count%2 == 0)
        {
          bytearr[i] = (bytearr[i] & 0x7f);
        }
      else
        {
          bytearr[i] = (bytearr[i] | 0x80);
        }
    }

}

int main(){
  unsigned int x = 0xdeadbeef;
  unsigned long y = 0x12345678deadc0de;
  printf("Test cases:\n");
  printf("byte-array = %x num_bytes = %lu ", x, sizeof(x));
  paritize(&x, 4);
  printf("result = %x\n", x);
  printf("byte-array = %lx num_bytes = %lu ", y, sizeof(y));
  paritize(&y, 8);
  printf("result = %lx\n", y);
  
  return 0;
}
