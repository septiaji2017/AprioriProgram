#include "APR.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isItemInArray(char** items, int itemQty, const char* item) {
    if (itemQty == 0) {
        return 0;
    }

    if (strcmp(items[itemQty - 1], item) == 0) {
        return 1; // Item found in the array
    }

    return isItemInArray(items, itemQty - 1, item);
}

void extractItemsHelper(char* trscToken, const char* itemDelim, char*** items, int* itemQty) {
    if (trscToken == NULL) {
        return;
    }

    // Tokenize the trsc to extract individual items
    char* itemToken = strtok(trscToken, itemDelim);

    while (itemToken != NULL) {
        // Check if the item already exists in the items array
        if (!isItemInArray(*items, *itemQty, itemToken)) {
            // Reallocate memory for the items array to accommodate the new item
            *items = (char**)realloc(*items, (*itemQty + 1) * sizeof(char*));
            (*items)[*itemQty] = strdup(itemToken);
            (*itemQty)++;
        }

        itemToken = strtok(NULL, itemDelim); // Move to the next item
    }

    // Recursively process the next trsc
    extractItemsHelper(strtok(NULL, "\n"), itemDelim, items, itemQty);
}

char** extractItems(const char* transactions, int* itemQty) {
    const char* itemDelim = ", ";
    char** items = NULL;
    *itemQty = 0;

    // Tokenize the transactions string to extract individual transactions
    char* trscCopy = strdup(transactions);
    char* trscToken = strtok(trscCopy, "\n");

    // Process transactions recursively
    extractItemsHelper(trscToken, itemDelim, &items, itemQty);

    free(trscCopy);
    return items;
}

// int main() {
//     const char* filename = "transactions.txt";
//     int itemCount = 0;
//     char** items = extractItemsFromFile(filename, &itemCount);

//     if (items != NULL) {
//         // Print the extracted items
//         for (int i = 0; i < itemCount; i++) {
//             printf("%s ", items[i]);
//         }
//         printf("\n");

//         // Free the dynamically allocated memory
//         for (int i = 0; i < itemCount; i++) {
//             free(items[i]);
//         }
//         free(items);
//     }

//     return 0;
// }

int main(){
	nodeTrie* root=NULL;
	nodeTrie* root2=NULL;
	// char* item[7]={"Susu","Gula","Kopi","Roti","Teh",NULL};
	char* transaksi[11][11]={{"Susu","Teh","Gula",NULL},{"Teh","Gula","Roti",NULL},{"Teh","Gula",NULL},{"Susu","Roti",NULL},{"Susu", "Gula", "Roti", NULL},{"Teh","Gula",NULL},{"Kopi", "Gula", "Susu", NULL},{"Kopi", "Gula", "Susu", NULL},{"Susu","Roti","Kopi",NULL},{"Gula","Teh","Kopi",NULL},{NULL}};
	const char* transactions = "Susu, Teh, Gula\nTeh, Gula, Roti\nTeh, Gula\nSusu, Roti\nSusu, Gula, Roti\nTeh, Gula\nKopi, Gula, Susu\nKopi, Gula, Susu\nSusu, Roti, Kopi\nGula, Teh, Kopi";
	int total=5,i=0, minimumSupport=2, minimumConfidence=60;
	int totalPerTransaksi[100];
	int itemQty = 0, j=0;
	char** item = extractItems(transactions, &itemQty);
	
//	root=creat_trie(item);

//    while(transaksi[j][1]!=NULL){    	
//    	j++;
//	}
//	i=0;
//    
//    while(i<j){
//    	sortTransaksi(transaksi[i]);
//    	i++;
//	}
//	
//	i=0;
//	while(i<j){
//		totalPerTransaksi[i]=totalItem(transaksi[i]);	
//		i++;
//	}
//    
//    
//
//    
//    for(i=0;i<j;i++){
//    	
//    	root2=creat_trie(transaksi[i]);
//	
//
//		updateTrie(root, root2, total ,totalPerTransaksi[i]);
//		    	
//    	
//	}
//
//
//	printMinimum(root, total, minimumSupport, "outputAll.txt");
//	
	//assosiationRules(root, minimumConfidence, total, minimumSupport);
	//removeNode(root,minimumSupport,total);
    //	printMinimum(root, total, minimumSupport, "outputMinimum.txt");
//	print_trie(root, 0);
	
    for (int i = 0; i < itemQty; i++) {
        printf("%s ", item[i]);
    }
    printf("\n");

    for (int i = 0; i < itemQty; i++) {
        free(item[i]);
    }
    free(item);

	return 0;
}
