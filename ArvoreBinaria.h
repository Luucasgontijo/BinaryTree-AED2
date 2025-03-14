#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} bstNode;

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