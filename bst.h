#pragma once
#ifndef bst_h
#define bst_h
#include <stdio.h>
#include <string.h>

struct node // creates base for node
{
	int data;
	char* question;
	char* answer;
	struct node* left;
	struct node* right;
	int key;
};

char* my_strdup(char* s);
struct node* create_node(int key, char* question, char* answer);
struct node* insert(struct node* root, int key, char* question, char* answer);
void free_tree(struct node* root);

#endif 
