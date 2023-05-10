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

typedef struct node *address;
typedef struct node{
	
	int info;
	int index;
	int support;
	address fs;
	address nb;
	address pr;
	
}nodeTrie;

int idItem(char* item);

address make_node(int id,int idIndex);

address find_index(address root, int index);

int totalItem(char* arr[]);

address creat_trie(char* arr[]);

void sortTransaksi(char** transaksi);

void print_trie(address node, int level);

int find_level(address root, address node);

void updateTrie(address root, address trans, int Total, int Total2);

void printMinimum(address root, int total ,int minimum);


#endif
