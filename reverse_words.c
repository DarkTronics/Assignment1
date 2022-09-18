#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Implement the reverse_words function below that accepts a string and reverses the word ordering within the string. Note that the characters within the words are not reversed. */

char *reverse_words(char *str){
  char *reverse = str;
  char *pointer;
  pointer = (char *) malloc(strlen(reverse));
  int i;
  int j;
  int length;
  int start;
  int end;
  int count = 0;
  length = strlen(reverse);
  end = length - 1;
  for(i = length-1; i >= 0; i--)
    {
      if(reverse[i] == ' ' || i == 0)
        {
          if(i == 0)
            {
              start = 0;
            }
          else
            {
              start = i+1;
            }
          for(j = start; j <= end; j++)
            {
              pointer[count] = reverse[j];
              count++;
            }
          end = i-1;
          if(i != 0)
            {
              pointer[count] = ' ';
              count++;
            }
        }
    }
  return pointer;
  

}

int main(){
  char * str;
  printf("Test cases:\n");
  str = "Hello World";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str));
  str = "";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str));
  str = "HeyYou";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str));
  str = "What is the question?";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str));
  str = "It is what it is.";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str)); 

  return 0;
}
