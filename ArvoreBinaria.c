// LUCAS GONTIJO DE MORAES -> 202403082

#include "ArvoreBinaria.h"

// i ve create this function take takes an value as argument, create an node in heap and makes it data member equals to the paramether received
btNode* newNode(int val){
    btNode* Node = (btNode*)malloc(sizeof(btNode));
    Node->left = Node->right = NULL;
    Node->data = val;
    return Node;
}
//this one just inserts an node in the correct position of the tree

void insert(int val, btNode** root){
    if (*root == NULL){
        (*root) = newNode(val);
    }
    else if (val <= (*root)->data) {
        insert(val, &((*root)->left));
    } else {
        insert(val, &((*root)->right));
    }
}

// this print function takes two arguments:
// boolean found: it says if the value was found in the tree or not
// pointer to closestValues struct, wich contains values for greatest, smallest and track a of the searched data

void printResult(bool found, closestValues* closest){
    if (found){
        printf("Element %d found in the tree.\n", closest->val);
        return;
    } else {
        if (closest->greatest) {
            printf("Successor element (%d) found in the tree.\n", closest->greatest->data);
        } else {
            printf("Successor element not found in the tree.\n");
        }
        if (closest->smallest) {
            printf("Predecessor element (%d) found in the tree.\n", closest->smallest->data);
        } else {
            printf("Predecessor element not found in the tree.\n");
        }
    }
}

// Function to find closest values to the given data
bool consultaIntervalarArvBinIter(btNode* root, closestValues* closest,int data) {
    btNode* current = root;
    closest->greatest = NULL;
    closest->smallest = NULL;
    closest->val = data;

    while (current) {
        if (current->data == data) {
            return true;
        }
        if (data < current->data) {
            // update closest right if root->info is larger than data

            closest->greatest = current;
            current = current->left;  // Move to the left child
        } else {
            // Update closest left if root->info is smaller than data
            closest->smallest = current;
            current = current->right;  // Move to the right child
        }
        
    }
    return false;
}


bool consultaIntervalarArvBinRec(btNode* root, closestValues* closest, int data){
    
    if (!root) {
        closest->val = data;
        return false; 
    }

    if (data == root->data ){
        closest->val = data;
        return true;
    } 

    else if (data < root->data) {
        closest->greatest = root;
        return consultaIntervalarArvBinRec(root->left, closest, data);
    }
    else {
        closest->smallest = root;    
        return consultaIntervalarArvBinRec(root->right, closest, data);
    }
}