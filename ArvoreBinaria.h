
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct btNode {
    int data;
    struct btNode* left;
    struct btNode* right;
} btNode;

//the exercise pdf says to use reference return, so i created this struct named closestValues, its members are updated whenever the value isnt find in the tree
typedef struct {
    btNode* greatest;
    btNode* smallest;
} closestValues; 

// Function prototypes

btNode* newNode(int val);
void insert(int val, btNode** root);
void printResult(int data, btNode* current, bool found, closestValues* closest);

// Iterative and recursive search functions
void consultaIntervalarArvBinIter(btNode* root, closestValues* closest, int data);

bool consultaIntervalarArvBinRec(btNode* root, closestValues* closest, int data);