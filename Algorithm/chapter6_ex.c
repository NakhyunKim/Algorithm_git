/* File name : ex.c
 * Describe : Pick m number in n
 * Date : 2016 08 08
 * Name : Nak
 * Input : m n (number)
 * Output : All case m of n
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k;
int pick_num;
int num;

void pick(int smallest, int end_num, int toPick, int *all_case)
{
    int i, j;

    if(toPick == 0){
        for(j = 0; j < pick_num; j++)
            printf("%d ", all_case[j]);
		printf("\n");
        return;
    } //toPick reach to 0

    for(i = smallest; i < end_num; i++){
		all_case[k++] = i+1;
        pick(i+1, end_num, toPick-1, all_case);
		k--;
    }
}

int main(int argc, char **argv)
{
    int total_num;
    int *all_case;
    int i, j;

    total_num = atoi(argv[2]);
    pick_num = atoi(argv[1]);

	all_case = (int*)malloc(sizeof(int) * pick_num);
	pick(0, total_num, pick_num, all_case);
	return 0;
}
