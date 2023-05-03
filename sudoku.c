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

/*int is_valid(Node* n, int row, int col, int num) {
  // Comprobar si el número ya existe en la misma fila
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (n->sudo[row][i] == num) {
      return 0;
      }
  }
  // Comprobar si el número ya existe en la misma columna
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (n->sudo[i][col] == num) {
      return 0;
    }
  }
  // Comprobar si el número ya existe en el mismo subcuadrado de 3x3
  int sub_row = row - (row % SUB_SIZE);
  int sub_col = col - (col % SUB_SIZE);
  for (int i = sub_row; i < sub_row + SUB_SIZE; i++) {
    for (int j = sub_col; j < sub_col + SUB_SIZE; j++) {
      if (n->sudo[i][j] == num) {
        return 0;
      }
    }
  }
  return 1;
}*/



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
        }
        return list;
      }
    }
  }
  return list;
}


int is_final(Node* n){
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