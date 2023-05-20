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
	
	int pjg=0,i=0;
	while(arr[i]!=NULL){
		pjg++;
		i++;	
	}
	return pjg;
	
}

nodeTrie *creat_trie(char* arr[]){
	
	nodeTrie* root=NULL;
	nodeTrie* a;
	nodeTrie* b;
	nodeTrie* c;
	nodeTrie* d;
	nodeTrie* e;
	int Total;
	
	
	Total=totalItem(arr);
	int Tnode=pow(2,Total)-1;
	
	int i=0,j=0,pjg=0;
	

	//printf("%d dan %d\n",Tnode,pjg);
	i=1;
	root=make_node(0,0,0);
	while(i<=Total){
		
		a=make_node(idItem(arr[j]),i,1);
		//printf("\ni = %d\n",i);
		a->pr=root;
		
		if(root->fs==NULL){
			
			root->fs=a;
			
		}
		
		else{
			b=root->fs;
			while(b->nb!=NULL){
				
				b=b->nb;
				
			}
			b->nb=a;
			
		}
		
		j++;
		i++;

	}

	a=root->fs;
	b=a;
	c=b;
//	printf("\nindex b %d",b->index);
	while(i<=Tnode){
		
		
		if(c != NULL && c->nb != NULL){
			c=c->nb;
			d=make_node(c->info,i,c->level+1);
			//printf("\ni = %d\n",i);
			d->pr=b;
			if(b->fs==NULL){
			
				b->fs=d;
			
			}
			
			else{
				e=b->fs;
				while(e->nb!=NULL){
					
					e=e->nb;
					
				}
				e->nb=d;
				
			}
			i++;
			
		}
		else{
//			printf("tes");
			b=find_index(root,b->index+1);
			c=b;
		}

	}
	
	
	return root;
	
}

	

void sortTransaksi(char** transaksi) {
    int i, j;
    char* temp;
    int n;
	
	
	n=totalItem(transaksi);

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            int id1 = idItem(transaksi[j]);
            int id2 = idItem(transaksi[j+1]);
            if (id1 > id2) {
                // swap the items
                temp = transaksi[j];
                transaksi[j] = transaksi[j+1];
                transaksi[j+1] = temp;
            }
        }
    }
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
		if(a->support>=minimum){
			
			fprintf(fp, "%s", itemName(a->info));
			b=a->pr;
			while(b->info!=0){
				fprintf(fp, " %s",itemName(b->info));
				b=b->pr;
			}
			fprintf(fp, "      support : %d\n",a->support);
		}
		
		i++;
	}
	
	fclose(fp); 
	
	i=1;
	while(i<=totalNode){
		a=find_index(root, i);
		if(a->support>=minimum){
			
			printf("\n%s",itemName(a->info));
			b=a->pr;
			while(b->info!=0){
				printf(" %s",itemName(b->info));
				b=b->pr;
				
				
			}
			printf("      support : %d",a->support);
			printf("      level : %d",a->level);
		}
		
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
