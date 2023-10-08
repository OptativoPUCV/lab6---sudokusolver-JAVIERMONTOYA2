#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

    return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  int i,j,k;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        for(k=1;k<=9;k++){
          Node* copiaN = copy(n);
          copiaN->sudo[i][j]=k;
          pushBack(list, copiaN);
        }
        break;
      }
    }
  if(j<9) break;
  } 
  return list;
}


int is_final(Node* n){
  int i,j,k,p;
  int marca[10];
  for(i=0;i<9;i++){
    for(k=0;k<10;k++) marca[k]=0;
    for(j=0;j<9;j++){
      int valor = n->sudo[i][j];
      if(valor!=0){
        if(marca[valor]==1) return 0;
      }
    }
  }
  
  
  return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/