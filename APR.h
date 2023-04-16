#ifndef APR_H
#define APR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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


#endif
