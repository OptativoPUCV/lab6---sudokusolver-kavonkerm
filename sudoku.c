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
  // Validar filas
  for (int row = 0; row < 9; row++) {
    int numVistos[9] = {0};
      for (int col = 0; col < 9; col++) {
        int num = n->sudo[row][col];
        if (num != 0) {
          if (numVistos[num - 1]) {
            return 0;
          } else {
            numVistos[num - 1] = 1;
          }
        }
      }
  }
  // Validar columnas
  for (int col = 0; col < 9; col++) {
    int numVistos[9] = {0};
    for (int row = 0; row < 9; row++) {
      int num = n->sudo[row][col];
      if (num != 0) {
        if (numVistos[num - 1]) {
          return 0;
        } else {
          numVistos[num - 1] = 1;
        }
      }
    }
  }
  // Validar submatrices de 3x3
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      int numVistos[9] = {0};
      for (int row = i; row < i + 3; row++) {
        for (int col = j; col < j + 3; col++) {
          int num = n->sudo[row][col];
          if (num != 0) {
            if (numVistos[num - 1]) {
              return 0;
            } else {
              numVistos[num - 1] = 1;
            }
          }
        }
      }
    }
  }
  return 1;
}

List* get_adj_nodes(Node* n){
  List* list = createList();
  int fil, col;
  for (fil = 0; fil < 9; fil++){
    for (col = 0; col < 9; col++){
      if (n->sudo[fil][col] == 0){
        for (int num = 1; num <= 9; num++) {
          if (is_valid(n)) {
            Node *adjNode = (Node*) malloc(sizeof(Node));
            for (int i = 0; i < 9; i++) {
              for (int j = 0; j < 9; j++){
                adjNode->sudo[i][j] = n->sudo[i][j];
              }
            }
            adjNode->sudo[fil][col] = num;
            pushBack(list, adjNode);
          }
          free(n);
        }
        return list;
      }
      
    }
    
  }
  return list;
}


int is_final(Node* n){
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (n->sudo[i][j] == 0) {
        return 0;
      }
    }
  }
  if (!is_valid(n)){
    return 1;
  }   
  return 0;
}

Node* DFS(Node* initial, int* cont){
  /*Stack* stack = createStack();
  push(stack,initial);
  *cont = 0;
  while(get_size(stack) != 0){
    Node* n = top(stack);
    pop(stack);
    if (is_final(n)) return n;
    List* adj = get_adj_nodes(n);
    Node* aux = first(adj);
    while(aux){
      push(stack,aux);
      aux = next(adj);
    }
    (*cont)++;
  }*/
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