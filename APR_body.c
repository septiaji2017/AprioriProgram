#include "APR.h"

TrieNode* createTrie() {
    TrieNode* root = (TrieNode*) malloc(sizeof(TrieNode));
    root->item = NULL;
    root->support = 0;
    root->child = NULL;
    root->sibling = NULL;
    return root;
}

struct TrieNode *createTrieNode(char* item) {
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->item = item;
    node->support = 0;
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

struct TrieNode *getChildNode(struct TrieNode *node, char* item) {
    struct TrieNode *child = node->child;
    while (child != NULL && strcmp(child->item, item) != 0) {
        child = child->sibling;
    }
    return child;
}

void addChildNode(struct TrieNode *parent, struct TrieNode *child) {
    child->sibling = parent->child;
    parent->child = child;
}

void readTransaction(struct TrieNode *root, char *transaction) {
    char *token = strtok(transaction, " ");

    while (token != NULL) {
  		struct TrieNode *current = root;
        struct TrieNode *child = getChildNode(current, token);
        if (child == NULL) {
            child = createTrieNode(token);
            addChildNode(current, child);
        }
        child->support++;
        current = child;
        token = strtok(NULL, " ");
    }
}

void printTrie(struct TrieNode *node, int level) {
    if (node == NULL) {
        return;
    }
    if (level > 0) {
        printf("%s (%d)\n", node->item, node->support);
    }
    printTrie(node->child, level + 1);
    printTrie(node->sibling, level);
}
