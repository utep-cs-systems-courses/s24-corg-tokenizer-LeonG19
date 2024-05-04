#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
int main(int argc, char **argv){
  /*
  printf("$");
  char str[100];
  fgets(str, sizeof(str), stdin);
  printf("\n%s", str );
  return 0;
  */
  char str[] = "happy happy joy";
  char **str2 =  tokenize(str);
  init_history();

}
