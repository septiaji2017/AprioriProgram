#ifndef APR_H
#define APR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN_SUPPORT 2
#define MIN_CONFIDENCE 0.6

typedef struct TrieNode {
    char* item;
    int support;
    struct TrieNode* child;
    struct TrieNode* sibling;
} TrieNode;

TrieNode* createTrie();

struct TrieNode *createTrieNode(char* item);

struct TrieNode *getChildNode(struct TrieNode *node, char* item);

void addChildNode(struct TrieNode *parent, struct TrieNode *child);

void readTransaction(struct TrieNode *root, char *transaction);

void printTrie(struct TrieNode *node, int level);

void generateFrequentItemsetsFromNode(struct TrieNode* current, struct TrieNode* node, int minSupport);

void generateFrequentItemsets(struct TrieNode* root, int minSupport);

#endif
