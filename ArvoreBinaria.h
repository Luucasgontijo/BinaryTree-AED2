// LUCAS GONTIJO DE MORAES -> 202403082

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} bstNode;

//the exercise pdf says to use reference return, so i created this struct named closestValues, its members are updated whenever the value isnt find in the tree
typedef struct {
    bstNode* greatest;
    bstNode* smallest;
} closestValues; 

// Function prototypes

bstNode* newNode(int val);
void insert(int val, bstNode** root);
void printResult(int data, bstNode* current, bool found, closestValues* closest);

// Iterative and recursive search functions
void consultaIntervalarArvBinIter(bstNode* root, closestValues* closest, int data);

bool consultaIntervalarArvBinRec(bstNode* root, closestValues* closest, int data);