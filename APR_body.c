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
    char *token = strtok(transaction, " \n");

    while (token != NULL) {
  		struct TrieNode *current = root;
        struct TrieNode *child = getChildNode(current, token);
        if (child == NULL) {
            child = createTrieNode(token);
            addChildNode(current, child);
        }
        child->support++;
        current = child;
        token = strtok(NULL, " \n");
    }
}

void generateFrequentItemsetsFromNode(struct TrieNode* current, struct TrieNode* node, int minSupport) {
    for (struct TrieNode* child1 = node->sibling; child1 != NULL; child1 = child1->sibling) {
        if (child1->support >= minSupport) {
            char* itemset = (char*) malloc(1024 * sizeof(char));
            itemset[0] = '\0';
            strcat(itemset, current->item);
            strcat(itemset, " ");
            strcat(itemset, child1->item);
            printf("{ %s } : %d\n", itemset, child1->support);
            generateFrequentItemsetsFromNode(current, child1, minSupport);
            free(itemset);
        }
    }
    if (current->child != NULL) {
        generateFrequentItemsetsFromNode(current->child, current->child, minSupport);
    }
}

void generateFrequentItemsets(struct TrieNode* root, int minSupport) {
    for (struct TrieNode* child = root->child; child != NULL; child = child->sibling) {
        if (child->support >= minSupport) {
            printf("{ %s } : %d\n", child->item, child->support);
            generateFrequentItemsetsFromNode(child, child, minSupport);
        }
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