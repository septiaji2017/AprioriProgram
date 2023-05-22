#include "APR.h"

// void readTransaction(struct TrieNode *root, char *transaction) {
//     char *token = strtok(transaction, " \n");

//     while (token != NULL) {
//   		struct TrieNode *current = root;
//         struct TrieNode *child = getChildNode(current, token);
//         if (child == NULL) {
//             child = createTrieNode(token);
//             addChildNode(current, child);
//         }
//         child->support++;
//         current = child;
//         token = strtok(NULL, " \n");
//     }
// }

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
//            memset((*items)[*itemQty],'\0',1);
            (*items)[*itemQty] = strdup(itemToken);
            (*itemQty)++;
        }

        itemToken = strtok(NULL, itemDelim); // Move to the next item
    }
    printf("\nExtractDone\n");

    // Recursively process the next trsc
    extractItemsHelper(strtok(NULL, "\0"), itemDelim, items, itemQty);
}

char** extractItems(const char* transactions, int* itemQty) {
    const char* itemDelim = ", \n";
//    char** items = (char**)malloc(sizeof(char*));
	char** items = NULL;
    *itemQty = 0;

    // Tokenize the transactions string to extract individual transactions
    char* trscCopy = strdup(transactions);
    char* trscToken = strtok(trscCopy, "\0");

    // Process transactions recursively
    extractItemsHelper(trscToken, itemDelim, &items, itemQty);

    free(trscCopy);
    return items;
}

int idItem(char* item){
	
	int id;
	
	if(strcmp(item,"Susu")==0){
	
		id=1;
	
	}
	
	else if(strcmp(item,"Gula")==0){
	
		id=2;
	
	}
	
	else if(strcmp(item,"Kopi")==0){
	
		id=3;
	
	}
	
	else if(strcmp(item,"Roti")==0){
	
		id=4;
	
	}
	
	else if(strcmp(item,"Teh")==0){
	
		id=5;
	
	}
	
	
	return id;
}

char* itemName(int id){
	
	char* name;
	
	if(id==1){
	
		name="Susu";
	
	} 
	
	else if(id==2){
	
		name="Gula";
	
	}
	
	else if(id==3){
	
		name="Kopi";
	
	}
	
	else if(id==4){
	
		name="Roti";
	
	}
	
	else if(id==5){
	
		name="Teh";
	
	}
	
	
	return name;
}

nodeTrie *make_node(int id,int idIndex, int lvl){
	
	nodeTrie* PNew;
	PNew = (nodeTrie*) malloc(sizeof(nodeTrie));
	PNew->fs=NULL;
	PNew->nb=NULL;
	PNew->pr=NULL;
	//PNew->info = (int) malloc(sizeof(int));
//	strcpy(PNew->info, Item);
	PNew->info=id;
	//PNew->info = (int) malloc(sizeof(int));
//	strcpy(PNew->info, Item);
	PNew->level=lvl;
	PNew->index=idIndex;
	PNew->support=0;
//	printf("\nbuat node %d dengan index %d",PNew->info,PNew->index);
	return PNew;
}

nodeTrie *find_index(nodeTrie *root, int index) {
	//digunakan untuk menemukan node dengan indeks tertentu
    if (root == NULL) {
        return NULL;
    } else if (root->index == index) {
        return root;
    } else {
        // Traversal ke anak pertama
        nodeTrie* found = find_index(root->fs, index);
        if (found != NULL) {
            return found;
        }

        // Traversal ke sibling selanjutnya
        found = find_index(root->nb, index);
        if (found != NULL) {
            return found;
        }

        return NULL; // Jika tidak ditemukan pada sub-tree ini dan sub-tree berikutnya
    }
}


int totalItem(char* arr[]){
	
	int i=0;
	while(arr[0][i]>=33 && arr[0][i]<=122){
		i++;
	}
	return ++i;
}

nodeTrie *creat_trie(char* arr[]){
	
	nodeTrie* root=NULL;
	nodeTrie* a;
	nodeTrie* b;
	nodeTrie* c;
	nodeTrie* d;
	nodeTrie* e;
	int Total = 0;
	int Tnode = 0;
	
	Total=totalItem(arr);
	printf("\nTotal: %d", Total);
	Tnode=pow(2,Total)-1;
	printf("\nTnode: %d", Tnode);
	
	int i=0,j=0,pjg=0;
	

	printf("\n%d dan %d\n",Tnode,pjg);
	i=1;
	root=make_node(0,0,0);
	while(i<=Total){
		
		a=make_node(idItem(arr[j]),i,1);
		printf("\ni = %d",i);
		a->pr=root;
		
		if(root->fs==NULL){
			
			root->fs=a;
			printf("\nRoot->FS = a = %p", a->pr);
		}
		
		else{
			b=root->fs;
			printf("\nb = Root->FS = %p", b);
			while(b->nb!=NULL){
				
				b=b->nb;
				printf("\nb = b->NB = %p", b);
			}
			b->nb=a;
			printf("\nb->NB = a = %p", b->nb);
			
		}
		
		j++;
		i++;

	}
	
	printf("\nroot->FS = %p", root->fs);
	a=root->fs;
	printf("\na = root->FS = %p", a);
	b=a;
	printf("\nb = a = %p", b);
	c=b;
	printf("\nc = a = %p", b->nb);
	printf("\nindex b %d",b->index);
	while(i<=Tnode){
		
		
		if(c != NULL && c->nb != NULL){
			c=c->nb;
			printf("\nc = c->NB = %p", c);
			d=make_node(c->info,i,c->level+1);
			printf("\ni = %d\n",i);
			d->pr=b;
			printf("\nd->PR = b = %p", d->pr);
			if(b->fs==NULL){
				b->fs=d;
				printf("\nb->FS = d = %p", b->fs);
			}
			else{
				e=b->fs;
				printf("\ne = b->FS = %p", e);
				while(e->nb!=NULL){
					
					e=e->nb;
					printf("\ne = e->NB = %p", e);
					
				}
				e->nb=d;
				printf("\ne->NB = d = %p", e->nb);
			}
			i++;
			
		}
		else{
			b=find_index(root,b->index+1);
			c=b;
			printf("\nc = b = %p", c);
		}

	}
	
	
	return root;
	
}

	

void sortTransaksi(char* transaksi) {
    int i = 0, j;
    char* prevTemp, nextTemp; //temp
    int n;
	
	n=totalItem(transaksi);

//    for (i = 0; i < n-1; i++) {
//        for (j = 0; j < n-i-1; j++) {
//            int id1 = idItem(transaksi[j]);
//            int id2 = idItem(transaksi[j+1]);
//            if (id1 > id2) {
//                // swap the items
//                temp = transaksi[j];
//                transaksi[j] = transaksi[j+1];
//                transaksi[j+1] = temp;
//            }
//        }
//    }

//    while(i<strlen(transaksi)){
//    	printf("\nString belum habis.");
//    	if(transaksi[i] != '\n'){
//    		strcat(prevTemp, transactions[i]);
//    		printf("\nThis is end of transactions");
//		}
//		else{
//			
//		}
//		i++;
//	}
}


void print_trie(nodeTrie *node, int level) {
    if (node == NULL) {
        return;
    }
    int i;
    // Print node's info, support, and index
    for (i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%d [Support: %d, Index: %d]\n", node->info, node->support, node->index);

    // Print node's children
    if (node->fs != NULL) {
        print_trie(node->fs, level + 1);
    }

    // Print node's siblings
    if (node->nb != NULL) {
        print_trie(node->nb, level);
    }
}



int find_level(nodeTrie *root, nodeTrie *node) {
    if (node == NULL) {
        return -1;
    }
    int level = 0;
    while (node != root) {
        node = node->pr;
        level++;
    }
    return level;
}


void updateTrie(nodeTrie *root, nodeTrie *trans, int Total, int Total2){
	
	nodeTrie* a;
	nodeTrie* b;
	nodeTrie* c;
	int i=1,j=1;
	int Totalnode2=pow(2,Total2)-1;
	int Totalnode=pow(2,Total)-1;
	bool found=false;
	while(i<=Totalnode2){
		
		a=find_index(trans, i);
		while(found!=true){
			
			b=find_index(root, j);
			if(b->pr->info==a->pr->info&&b->info==a->info&&b->level==a->level){
			//	printf("\ntes1");
				found = true;
				b->support++;
				
			}
			
			else{
			//	printf("\ntes2");
				j++;
				b=find_index(root, j);
				
			}
			
		}
		found=false;
		i++;
	}
	
	
}



void printMinimum(nodeTrie* root, int total ,int minimum, char* filename){
	
	nodeTrie* a;
	nodeTrie* b;
	nodeTrie* c;
	int i=1;
	int totalNode=pow(2,total)-1;
	
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("File tidak dapat dibuat.\n");
		return;
	}
	
	while(i<=totalNode){
		a=find_index(root, i);
		
			
			fprintf(fp, "%s", itemName(a->info));
			b=a->pr;
			while(b->info!=0){
				fprintf(fp, " %s",itemName(b->info));
				b=b->pr;
			}
			fprintf(fp, "      support : %d\n",a->support);
		
		
		i++;
	}
	
	fclose(fp); 
	
	i=1;
	while(i<=totalNode){
		a=find_index(root, i);
		
			
			printf("\n%s",itemName(a->info));
			b=a->pr;
			while(b->info!=0){
				printf(" %s",itemName(b->info));
				b=b->pr;
				
				
			}
			printf("      support : %d",a->support);
			printf("      level : %d",a->level);
		
		
		i++;
	}
}



void assosiationRules(nodeTrie* root, int confidence, int total, int minimum){
	
	nodeTrie* a;
	nodeTrie* b;
	nodeTrie* c;
	nodeTrie* d;
	int i=1, hasil;
	int totalNode=pow(2,total)-1;
	
	while(i<=totalNode){
		
		a=find_index(root, i);
		if(a->support>=minimum&&a->level>1){
			
			c=a;
			while(c->info!=0){
				b=a;
				
				d=root->fs;
				printf("\nJika membeli");
				while(b->info!=0){
					if(b!=c){
						printf(" %s",itemName(b->info));
					}
					
					b=b->pr;
				}
				printf(" Maka membeli %s",itemName(c->info));
				
				while(d->info!=c->info){
					d=d->nb;	
				}
				printf("\n support a : %d", a->support);
				printf("\n support d : %d", d->support);
				hasil=(a->support/d->support)*100;
				printf("\n confindence : %d/%d", a->support,d->support);
				
				
				c=c->pr;
				
			}

			
		}
		
		i++;

	}

}

void removeNode(nodeTrie* root, int minimum, int total){
	
	nodeTrie* now;
	nodeTrie* currRoot;
	nodeTrie* prev;
	nodeTrie* next;
	int nodeTotal=pow(2,total)-1;
	int i=1,j;
	j=nodeTotal;
	while(i<=nodeTotal){
		
		printf("\ntes %d",j);
		now=find_index(root,j);
			
		if(now->support<minimum){
			
			prev=now->pr;
			
			if(prev->fs==now){
				
				next=now->nb;
				prev->fs=next;
				printf("\ntes free %s index %d",itemName(now->info), now->index);
				free(now);
				
			}
			
			else{
				
				prev=prev->fs;
				while(prev->nb!=now){
					
					prev=prev->nb;
					
				}
				next=now->nb;
				prev->nb=next;
				printf("\ntes free %s index %d",itemName(now->info), now->index);
				free(now);
			}
			
	
		}
			
		
		j--;
		i++;
	}
	
	
	
}
