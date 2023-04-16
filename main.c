#include "APR.h"

int main() {
	TrieNode* root = createTrie();
	printf("Root node address: %p\n", root);
	
	char transaction[] = "A B C D A B A C D D B C D A D A A B A C D";
	readTransaction(root, transaction);
	printTrie(root, 0);

	return 0;
}
