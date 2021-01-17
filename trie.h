#pragma once
#define WORD 30
#define NUM_LETTERS ((int)26)
typedef enum { FALSE = 0, TRUE = 1 } boolean;

typedef struct node {
	char letter;
	long unsigned int count;
	long unsigned int numchildren;
	struct node* children[NUM_LETTERS];
	
} node;

void buildTrie(node* root);
char buildWord(node* root, char c);
node* newNode(char c);

