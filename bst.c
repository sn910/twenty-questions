#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bst.h"

char* my_strdup(char* s) {
    size_t len = strlen(s) + 1;
    char* dup = malloc(len);
    if (dup == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(dup, s);
    return dup;
}

struct node* create_node(int key, char* question, char* answer) { // creates nodes for the bst
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->question = my_strdup(question);
    newNode->answer = my_strdup(answer);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int key, char* question, char* answer) { // inserts the nodes in the bst
    if (root == NULL) {
        return create_node(key, question, answer);
    }
    if (key < root->key) {
        root->left = insert(root->left, key, question, answer);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key, question, answer);
    }
    return root;
}


void free_tree(struct node* root) { // frees memory allocated for the bst
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root->question);
        free(root->answer);
        free(root);
    }
}
