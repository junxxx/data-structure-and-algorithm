#include <stdio.h>
#define SIZE  10
int sort(int vals[SIZE]);

int main()
{
        int group[SIZE] = {1,2,2,53,4,45,32,12,31,9};

        int i;
	for (i=0;i<SIZE;i++)
		printf("%4d",group[i]);
 	
	sort(group);
	
	for (i=0;i<SIZE;i++)
		printf("%4d",group[i]);

}
	int sort(int vals[SIZE])	//sort the number in decreasing order
	{
		int i,j,tem; 
		for (i = 0; i < SIZE; i++)
		{
			for ( j = 0; j < SIZE - i; j++)
			{
				if (vals[i]>= vals[i+1])
				{
					vals[tem] = vals[i];
					vals[i] = vals[i+1];
					vals[i+1] = vals[tem];
				}		
			}
		}
		return (vals[SIZE]);
	}

