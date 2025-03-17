// LUCAS GONTIJO DE MORAES -> 202403082

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"


int main() {
    btNode* root = NULL;
    insert(6, &root);
    insert(5, &root);
    insert(3, &root);
    insert(2, &root);
    insert(4, &root);
    insert(8, &root);
    insert(17, &root);
    insert(49, &root);
    

    closestValues* closestVals = (closestValues*)malloc(sizeof(closestValues));
    

    bool result;


	printf("\nITERATIVE SEARCH: \n");
	closestVals->greatest = NULL;
    closestVals->smallest = NULL;
    closestVals->val = 0;
    
    result = consultaIntervalarArvBinIter(root, closestVals, 2);

    printResult(result, closestVals);

	

	printf("\nRECURSIVE SEARCH: \n");
    closestVals->greatest = NULL;
    closestVals->smallest = NULL;
    closestVals->val = 0;
	
    result = consultaIntervalarArvBinRec(root, closestVals, 50);

    printResult(result, closestVals);

    return 0;
}
