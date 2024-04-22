#include <stdlib.h>
#include <stdio.h>
#include "history.h"

List* init_history(){
  List *newList = malloc(sizeof(List));
  newList->root = 0;
  printf("init working");
  return newList;
}

void add_history(List *list, char* str){
  if (list->root == 0){
    list->root = malloc(sizeof(Item));
    list->root->str = str;
    list->root->id = 1;
    list->root->next = 0;
    return;
  }
  int id_number = 1;
  Item *temp = list->root;
  while ((temp = temp->next)!=0){
    id_number+=1;
  }
  temp = malloc(sizeof(Item));
  temp->id = id_number;
  temp->str = str;
  temp->next = 0;
}

char *get_history(List *list,int id){
  if (list->root = 0){
    return 0;
  }

  Item *temp = list->root;
  while((temp->id != id) || (temp = temp->next)!=0);
  if (temp == 0)return 0;
  return temp->str;




  
}
