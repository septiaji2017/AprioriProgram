#include "APR.h"

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
