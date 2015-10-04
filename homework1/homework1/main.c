#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



void swap (int *x, int *y){
     int z = *x;
     *x = *y;
     *y = z;
}

int main(int argc, char *argv[])
{
    int *a;  // указатель на массив

    FILE *file1 = fopen(argv[1],"r+");
    if(file1 == 0)
	{
        printf("не могу открыть файл '%s'",argv[1]);
        return 0;
	}

    int count=0;
    int temp;

    while ((fscanf (file1, "%d", &temp)) != EOF) {
		count++;
	}

	a = (int*) malloc(count*sizeof(int));
	rewind (file1);
	int index1=0;

	while ((fscanf (file1, "%d", &a[index1])) != EOF) {
		index1++;
	}


    int nullindex=0;
    int minusindex=0;
    int i;

    for(i=1;i<count;i++)
    {
    if(a[i]==0)
        {
            swap(&a[i], &a[nullindex]);
            nullindex++;
            i--;
        }
        else
        {
            if(a[i]<0)
            {
                swap(&a[i], &a[minusindex]);
                minusindex++;
                i--;
            }
        }


    }


    FILE *file2 = fopen(argv[1],"w+");
    if(file2 == 0)
	{
        printf("не могу открыть файл '%s'",argv[1]);
        return 0;
	}

	for(i=0;i<count;i++)
    {
        fprintf(file2,"%d \n", a[i]);
    }


    fclose(file1);
    fclose(file2);
    free(a);
    return 0;

}
