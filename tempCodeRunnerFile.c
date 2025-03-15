// LUCAS GONTIJO DE MORAES -> 202403082

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


bstNode* newNode(int val){
    bstNode* Node = (bstNode*)malloc(sizeof(bstNode));
    Node->left = Node->right = NULL;
    Node->data = val;
    return Node;
}

void insert(int val, bstNode** root){
    if (*root == NULL){
        (*root) = newNode(val);
    }
    else if (val <= (*root)->data) {
        insert(val, &((*root)->left));
    } else {
        insert(val, &((*root)->right));
    }
}

// Function to find closest values to the given data
bool consultaIntervalarArvBinIter(bstNode** root, closestValues** closest,int data) {

    while (*root) {
        if ((*root)->data == data) {
            return true;
        }
        if (data < (*root)->data) {
            // Update closest right if root->info is larger than data
            (*closest)->greatest = (*root);
            root = (*root)->left;  // Move to the left child
        } else {
            // Update closest left if root->info is smaller than data
            (*closest)->smallest = (*root);
            root = (*root)->right;  // Move to the right child
        }
    }
    return false;
}

int main() {
    // criei uma arvore binaria simples
    bstNode* root = NULL;
    insert(5, &root);
    insert(3, &root);
    insert(7, &root);
    insert(2, &root);
    insert(4, &root);
    insert(6, &root);
    insert(8, &root);

    closestValues* result = (closestValues*)malloc(sizeof(closestValues));


    consultaIntervalarArvBinIter(&root, &result, 5);


    printf("Closest values to 5: Left: %d, Right: %d\n", result->greatest ? result->greatest->data : -1, result->smallest ? result->smallest->data : -1);

    // Searching for a value that is in the tree (e.g., 6)
    // consultaIntervalarArvBinIter(root, 6, &closestLeft, &closestRight);
    // printf("Closest values to 6: Left: %d, Right: %d\n", closestLeft, closestRight);

    return 0;
}