




#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c){
  return (c == ' ') || (c == '\t');
}

int non_space_char(char c){

  return (c != ' ') && (c != '\t') && (c != '\0');
}

char *token_start(char *str){
  while (*str == ' ') str++;

  return str;

}

char *token_terminator(char *token){
  while (*token != ' ' && *token != '\0') token ++;

  return token;
}

int count_tokens(char *str){
  char *token = token_start(str);
  int num_token = 0;
  while (*(token = token_start(token)) != '\0' ){
    num_token ++;
    token = token_terminator(token);
  }

  return num_token;
}

char *copy_str(char *intStr, short len){
  int i = 0;
  char *copy_s = malloc((len+1) * sizeof(char)), c;
  do{
   c=  *(copy_s+i) = *(intStr+i);
   i ++;
  } while (c && i < len);
  return copy_s;
}

char **tokenize(char* str){
  char **tokens = malloc((count_tokens(str) +1) * sizeof(char*));
  char *intoken = token_start(str);
  int i  =0;
  while (*(intoken = token_start(intoken)) != '\0'){
    *(tokens+i) = copy_str(intoken, (token_terminator(intoken) - intoken));
    printf("\nthis is one token %s", *(tokens+i));
    intoken = token_terminator(intoken);
    i++;
  }
  char *c = malloc(sizeof(char));
  *c = '\0';
  *(tokens+count_tokens(str)) = malloc(sizeof(char*));
  *(tokens+count_tokens(str))= c;
  return tokens;
      
  
}

void print_tokens(char **tokens){
  int i = 0;
    while (**(tokens+i) != '\0' ){
      puts(*(tokens+i));
      i+=1;
  }
}
void free_tokens(char **tokens){
  if (**tokens == '\0'){
    free(*tokens);
    return;
  }
  free(*tokens);
  free_tokens(tokens+1);
  *tokens = 0;
}
