// LUCAS GONTIJO DE MORAES -> 202403082

#include "ArvoreBinaria.h"

// i ve create this function take takes an value as argument, create an node in heap and makes it data member equals to the paramether received
bstNode* newNode(int val){
    bstNode* Node = (bstNode*)malloc(sizeof(bstNode));
    Node->left = Node->right = NULL;
    Node->data = val;
    return Node;
}
//this one just inserts an node in the correct position of the tree

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

//for printing the results

void printResult(int data, bstNode* current, bool found, closestValues* closest){
    printf("\n================== SEARCH RESULTS ===============\n\n");

    if (found){
        printf("Element %d found in the tree.\n", data);
        return;
    } else {
        printf("Value %d was not found in the tree. \n\nClosest ones \n", data);

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
void consultaIntervalarArvBinIter(bstNode* root, closestValues* closest,int data) {
    bstNode* current = root;
    closest->greatest = NULL;
    closest->smallest = NULL;

    while (current) {
        if (current->data == data) {
            printResult(data, current, true, closest);
            return;
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

    printResult(data, current, false, closest);
    return;
}


bool consultaIntervalarArvBinRec(bstNode* root, closestValues* closest, int data){
    
    if (!root) {
        printResult(data, NULL, false, closest); 
        return false; 
    }

    if (data == root->data ){
        printResult(data, root, true, closest);
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