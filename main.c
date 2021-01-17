#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include  "trie.h"

void Word(node *n,char *word,int j, bool rev)
{
	
	if (n->numchildren == 0)
	{
		printf("%s %lu \n", word, n->count);
		free(n);
		return;
	}
	
	if ((!rev) && (n->numchildren < n->count))
	{
		if (word[0] != '\0')
		{
			n->count = n->count - n->numchildren;
			printf("%s %lu \n", word, n->count);
		}
		
	}
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		int calced_i = i;
		if (rev)
			calced_i = NUM_LETTERS - i - 1;
		if (n->children[calced_i] != NULL) {
			word[j] = n->children[calced_i]->letter; j++;
			Word(n->children[calced_i], word, j,rev);
			word[j] = '\0';
			j--;

		}				
	}

	if ((rev)&&(n->numchildren < n->count))
	{
		word[j] = '\0';
		if (word[0] != '\0') 
		{
			n->count = n->count - n->numchildren;
			printf("%s %lu \n", word, n->count);
		}

	}

	free(n);
	
	 
}

int main(int argc, char** argv) {
	
	bool reverse = (argc > 1) && argv[1][0] == 'r';
	node* head = newNode('\0');
	buildTrie(head);
	char word[WORD] = { '\0' };
	Word(head, word, 0,reverse);
}
