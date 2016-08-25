/* File name : quad_tree.c
 * Describe : quad_tree reverse
 * Date : 2016 08 17
 * Name : Nak
 * Input : 4
		   w
		   xbwwb
		   xbwxwbbwb
		   xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
 * Output : w
			xwbbw
			xxbwwbbbw
			xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define SMAX 50

struct Data{
	char in;
	struct Data *point[4];
};

int top;
typedef struct Data Data;
Data *d;
int index1;
int index2;
int stack[SMAX];

void Input_Data(char *in);
void reverse(Data out);

void push(int i)
{
	if(top == SMAX)
		return;
	stack[top++] = i;
}

int pop()
{
	if(top == 0)
		return;
	return stack[--top];
}

int main(void)
{
	char **input;
	char **output;
	int num;
	int i, j, k, len;

	printf("case num : ");
	scanf("%d", &num);

	input = (char**)malloc(sizeof(char*) * num);
	for(i = 0; i < num; i++)
		input[i] = (char*)malloc(sizeof(char) * MAX);

	printf("Input string\n");
	for(i = 0; i < num; i++) 
		scanf("%s", input[i]);
		
	output = (char**)malloc(sizeof(char*) * num);
	for(i = 0; i < num; i++)
		output[i] = (char*)malloc(sizeof(char*) * strlen(input[i]));

	for(i = 0; i < num; i++){
		len = strlen(input[i]);
		d = (Data*)malloc(sizeof(Data) * len);
        memset(d, 0, sizeof(d));
		top = 0;
		index1 = 0;
		index2 = 0;

		for(j = 0; j < len; j++){
			d[j].in = input[i][j];
            //printf("d[%d].in : %c input[%d][%d] : %c\n", j, d[j].in, i, j, input[i][j]);
        }

		Input_Data(input[i]);

		reverse(d[0]);
		printf("\n");

	}

	for(i = 0; i < num; i++)
		free(output[i]);
	free(output);

	for(i = 0; i < num; i++)
		free(input[i]);
	free(input);
	free(d);
}

void Input_Data(char *in)
{
	int i;

	for(i = 1; i <= 4; i++) {
		d[index2].point[i-1] = &d[index1+1];
        //printf("%c ",d[index1].point[i-1]->in);
		index1++;
		if(d[index1].in == 'x')
		{
			push(index2);
			index2 = index1;
			Input_Data(in);
			index2 = pop();
		}
	}
}

void reverse(Data out)
{
	int i;
	printf("%c", out.in);

	if(out.point[2]->in == 'x')
		reverse(*out.point[2]);
	else printf("%c", out.point[2]->in);

	if(out.point[3]->in == 'x')
		reverse(*out.point[3]);
	else printf("%c", out.point[3]->in);

	if(out.point[0]->in == 'x')
		reverse(*out.point[0]);
	else printf("%c", out.point[0]->in);

	if(out.point[1]->in == 'x')
		reverse(*out.point[1]);
	else printf("%c", out.point[1]->in);
}