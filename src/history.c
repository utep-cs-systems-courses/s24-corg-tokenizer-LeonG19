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
  Item *new = malloc(sizeof(Item));
  new -> str = str;
  new -> next = 0;
    
  if (list->root == 0){
    list->root = new;
    new -> id= 1;
    return;
  }
  int id_number = 1;
  Item *temp = list->root;
  while ((temp = temp->next)!=0){
    id_number+=1;
  }
  new->id = id_number;
  temp -> next = new;
}

char *get_history(List *list,int id){
  if (list->root == 0){
    return 0;
  }

  Item *temp = list->root;
  while((temp->id != id) || (temp = temp->next)!=0);
  if (temp == 0)return 0;
  return temp->str;




  
}
