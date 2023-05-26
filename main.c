#include "APR.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	root=creat_trie(item);
	
	printf("\n\nTest: %c\n", *(transactions+2));
	printf("\n\nTest: %d\n", strlen(transactions));

    while(i<strlen(transactions)){
    	printf("\nString belum habis.");
    	if(transactions[i] == '\n'){
    		j+=1;
    		printf("\nThis is end of transactions");
		}
		i++;
	}
	j++;
//	
	printf("\nj = %d\n", j);
	
	i = 0;
//    
//    while(i<j){
//    	sortTransaksi(transactions);
//    	i++;
//	}
//	
//	i=0;
//	while(i<j){
//		totalPerTransaksi[i]=totalItem(transactions);	
//		i++;
//	}
////    
////    
////
////    
//    for(i=0;i<j;i++){
//    	root2=creat_trie(transactions[i]);
//		updateTrie(root, root2, total ,totalPerTransaksi[i]);
//	}
////
////
//	printMinimum(root, total, minimumSupport, "output.txt");
//	
	//assosiationRules(root, minimumConfidence, total, minimumSupport);
	//removeNode(root,minimumSupport,total);
    //	printMinimum(root, total, minimumSupport, "outputMinimum.txt");

	
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
