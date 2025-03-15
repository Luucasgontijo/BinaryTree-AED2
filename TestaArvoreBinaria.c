// LUCAS GONTIJO DE MORAES -> 202403082

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"


int main() {

    // criei uma arvore binaria simples
    bstNode* root = NULL;
    insert(6, &root);
    insert(5, &root);
    insert(3, &root);
    insert(2, &root);
    insert(4, &root);
    insert(8, &root);
    insert(17, &root);
    insert(50, &root);
    

    closestValues* closestVals = (closestValues*)malloc(sizeof(closestValues));
    
    


	printf("\nITERATIVE SEARCH: \n");
	closestVals->greatest = NULL;
    closestVals->smallest = NULL;
    consultaIntervalarArvBinIter(root, closestVals, 50);
	
	printf("\nRECURSIVE SEARCH: \n");
    closestVals->greatest = NULL;
    closestVals->smallest = NULL;
	bool found = consultaIntervalarArvBinRec(root, closestVals, 7);


    // Searching for a value that is in the tree (e.g., 6)
    // consultaIntervalarArvBinIter(root, 6, &closestLeft, &closestRight);
    // printf("Closest values to 6: Left: %d, Right: %d\n", closestLeft, closestRight);

    return 0;
}
