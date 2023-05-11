#include "APR.h"

// int main() {
// 	TrieNode* root = createTrie();
// 	printf("Root node address: %p\n", root);
	
// 	char transaction[] = "A B C D A B A C D D B C D A D A A B A C D";
// 	readTransaction(root, transaction);
// 	printTrie(root, 0);

// 	return 0;
// }

// int main(){
// 	nodeTrie* root=NULL;
// 	nodeTrie* root2=NULL;
// 	char* item[6]={"Susu","Gula","Kopi","Roti",NULL};
// 	char* transaksi[10][10]={{"Susu","Roti",NULL},{"Susu", "Gula", "Roti", NULL},{"Kopi", "Gula", "Susu", NULL},{"Kopi", "Gula", "Susu", NULL}};
// 	int total=4,i=0, minimumSupport=2;
// 	char* item2[5]={"Kopi", "Gula", "Susu", NULL};
// 	int totalPerTransaksi[100];
	
	
// 	root=creat_trie(item);
	
// 	//root = creatTrie(item, total);
// 	print_trie(root, 0);

	
// 	//char* transaksi2[10] = {"Kopi", "Gula", "Susu", "Roti", "Teh", NULL};
//     //int n = 5;
    
//     // memanggil fungsi untuk mengurutkan array transaksi
//     i=0;
//     int j=0;
//     while(i<5){
    	
//     	printf("\nsort");
//     	sortTransaksi(transaksi[i]);
//     	i++;
// 	}
	
// 	i=0;
// 	while(i<5){
		
// 		printf("\ntotal");
// 		totalPerTransaksi[i]=totalItem(transaksi[i]);	
// 		i++;
// 	}
    
    
//     // print isi array transaksi yang sudah diurutkan
//     printf("\nTransaksi setelah diurutkan:\n");
//     for(j=0;j<5;j++){
    	
//     	for ( i = 0; i < totalPerTransaksi[j]; i++) {
//         	printf("%s ", transaksi[j][i]);
//     	}
//     	printf("\n");
    	
// 	}
    
    
//     for(j=0;j<4;j++){
    	
//     	root2=creat_trie(transaksi[j]);
	
// 		//root = creatTrie(item, total);
// 		printf("\n");
// 		print_trie(root2, 0);
// 		updateTrie(root, root2, total ,totalPerTransaksi[j]);
		    	
    	
// 	}

// //	root2=creatTrie(transaksi[0]);
// //
// //	//root = creatTrie(item, total);
// //	printf("\n");
// //	printTrie(root2, 0);
// //	updateTrie(root, root2, total ,totalPerTransaksi[0]);

//     printf("\n");
//     print_trie(root, 0);

// 	printMinimum(root, total, minimumSupport);
// 	return 0;
// }

int main(){
	
	nodeTrie* root=NULL;
	nodeTrie* root2=NULL;
	char* item[7]={"Susu","Gula","Kopi","Roti","Teh",NULL};
	char* transaksi[11][11]={{"Susu","Teh","Gula",NULL},{"Teh","Gula","Roti",NULL},{"Teh","Gula",NULL},{"Susu","Roti",NULL},{"Susu", "Gula", "Roti", NULL},{"Teh","Gula",NULL},{"Kopi", "Gula", "Susu", NULL},{"Kopi", "Gula", "Susu", NULL},{"Susu","Roti","Kopi",NULL},{"Gula","Teh","Kopi",NULL},{NULL}};
	int total=5,i=0, minimumSupport=2, minimumConfidence=60;
	int totalPerTransaksi[100];
	int j=0;
	
	root=creat_trie(item);
	    

    
    
    while(transaksi[j][1]!=NULL){
    	
    	j++;
    	
	}
	i=0;
    
    while(i<j){
    	
    
    	sortTransaksi(transaksi[i]);
    	i++;
	}
	
	i=0;
	while(i<j){
		

		totalPerTransaksi[i]=totalItem(transaksi[i]);	
		i++;
	}
    
    

    
    for(i=0;i<j;i++){
    	
    	root2=creat_trie(transaksi[i]);
	

		updateTrie(root, root2, total ,totalPerTransaksi[i]);
		    	
    	
	}


	printMinimum(root, total, minimumSupport, "output.txt");
	
	//assosiationRules(root, minimumConfidence, total, minimumSupport);
	return 0;
}
