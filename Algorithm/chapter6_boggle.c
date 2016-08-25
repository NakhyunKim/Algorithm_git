/* File name : ex.c
 * Describe : Boggle example
 * Date : 2016 08 16
 * Name : Nak
 */

#include <stdio.h>
#include <string.h>

#define MAX 50

int top2 = 0;
char stack[MAX];
char puzzle[5][5] ={ {'U', 'R', 'L', 'P', 'M'},
	  				 {'X', 'P', 'R', 'E', 'T'},
			  	     {'G', 'I', 'A', 'E', 'T'},
 			  		 {'X', 'T', 'N', 'Z', 'Y'},
	  				 {'X', 'O', 'Q', 'R', 'S'}
				   };
struct xy {
	int x;
	int y;
};
struct xy position[MAX];

void push(int x, int y)
{
	if(top2 == MAX)
		return;
	top2++;
	position[top2].x = x;
	position[top2].y = y;
}

void pop()
{
	if(top2 == 0)
		return;
	top2--;
}

int hasWord(char *word, int index, int len, int x, int y)
{
	int i;
	int x_direc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int y_direc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
 
	int next_x, next_y;


	if(x < 0 || y < 0)
		return 0;
	if(index == len)
		return 1;
	if(word[index] != puzzle[x][y])
		return 0;
	
	push(x, y);
	for(i = 0; i < 8; i++)
	{
		next_x = x, next_y = y;

		next_x += x_direc[i];
		next_y += y_direc[i];

		if(hasWord(word, index+1, len, next_x, next_y))
			return 1;
	}
}	

int main(void)
{
	int i, j, k;
	char *find = "REPEAT";
	int len;

	len = strlen(find);
	printf("%d\n", len);
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(hasWord(find, 0, len, i, j)){
				for(;top2>0;){
					printf("%c x:%d y:%d\n",puzzle[position[top2].x][position[top2].y], position[top2].x, position[top2].y); 
					pop();
				}
			}
		}
	}
}
