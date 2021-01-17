#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"

node* newNode(char c)
{
	node *root = NULL;
	root = (node*)malloc(sizeof(node));
	if (root)
	{
		root->letter = c;
		root->count = 0;
		root->numchildren = 0;
		for (int i = 0; i < NUM_LETTERS; i++)
		{
			root->children[i] = NULL;
		}
	}
	return root;
}
char buildWord(node *root,char c)
{
	int i;
	node *temp = root;
	while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{ 
		c=tolower(c);
		 i = (int)(c - 'a');
		if (temp->children[i]== NULL)
		{
			temp->children[i] = newNode(c);
			temp->count++;
			temp->numchildren++;
		}
		temp = temp->children[i];
		
		c= getc(stdin);
	}
	temp->count++;
	return c;
}

void buildTrie(node *root)
{
	
	char c= getc(stdin);
	
	while (c != EOF)
	{ 
		
		c=buildWord(root, c);
		if(c != EOF )
			c = getc(stdin);
	}
	return ;
}