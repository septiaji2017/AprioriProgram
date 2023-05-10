#ifndef APR_H
#define APR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MIN_SUPPORT 2
#define MIN_CONFIDENCE 0.6

// typedef struct TrieNode {
//     char* item;
//     int support;
//     struct TrieNode* child;
//     struct TrieNode* sibling;
// } TrieNode;

// TrieNode* createTrie();

// struct TrieNode *createTrieNode(char* item);

// struct TrieNode *getChildNode(struct TrieNode *node, char* item);

// void addChildNode(struct TrieNode *parent, struct TrieNode *child);

// void readTransaction(struct TrieNode *root, char *transaction);

// void printTrie(struct TrieNode *node, int level);

// void generateFrequentItemsetsFromNode(struct TrieNode* current, struct TrieNode* node, int minSupport);

// void generateFrequentItemsets(struct TrieNode* root, int minSupport);

// typedef struct node *nodeTrie;
typedef struct nodeTrie {
	int info;
	int index;
	int support;
	struct nodeTrie* fs;
	struct nodeTrie* nb;
	struct nodeTrie* pr;
} nodeTrie;

int idItem(char* item);

nodeTrie *make_node(int id,int idIndex);

nodeTrie *find_index(nodeTrie *root, int index);

int totalItem(char* arr[]);

nodeTrie *creat_trie(char* arr[]);

void sortTransaksi(char** transaksi);

void print_trie(nodeTrie *node, int level);

int find_level(nodeTrie *root, nodeTrie *node);

void updateTrie(nodeTrie *root, nodeTrie *trans, int Total, int Total2);

void printMinimum(nodeTrie *root, int total, int minimum);


#endif
