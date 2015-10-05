#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>

struct element {
		int i;
		int j;
		float val;
	};

struct matrix{
        int N;
        int M;
        int not_null;
        struct  element *arr;
        int ind;
};


float get_elem(struct matrix *matrixX, int row, int col);
void set_elem(struct matrix *matrixX,int row,int col, float elem);
void multiplication(struct matrix *matrixA,struct matrix *matrixB, struct matrix *matrixC);

int main(int argc, char *argv[])
{
    struct matrix matrixA;
	struct matrix matrixB;
    struct matrix matrixC;
    matrixA.ind=0;
    matrixB.ind=0;
    matrixC.ind=0;

    FILE *file1 = fopen(argv[1],"r");

    if(file1 == 0)	{
        printf("Can not open file '%s'",argv[1]);
        return 0;
    }

    fscanf (file1, "%d%d%d", &matrixA.N,&matrixA.M,&matrixA.not_null);
    matrixA.arr =malloc(matrixA.not_null*sizeof(struct element));

    int index=0;
    while ((fscanf (file1, "%d%d%f", &matrixA.arr[index].i,&matrixA.arr[index].j,&matrixA.arr[index].val)) != EOF) {

		index++;
    }

    fclose(file1);



    FILE *file2 = fopen(argv[2],"r");
    if(file2 == 0)	{
        printf("Can not open file '%s'",argv[2]);
        return 0;
    }

    fscanf (file2, "%d%d%d", &matrixB.N,&matrixB.M,&matrixB.not_null);
    matrixB.arr =malloc(matrixB.not_null*sizeof(struct element));

    index=0;
    while ((fscanf (file2, "%d%d%f", &matrixB.arr[index].i,&matrixB.arr[index].j,&matrixB.arr[index].val)) != EOF) {

		index++;
    }

    fclose(file2);
    matrixA.ind=matrixA.not_null;
    matrixB.ind=matrixB.not_null;


     if(matrixA.M!=matrixB.N)
     {
     printf("Fold impossible");
     return 0;
     }
     else
     {
        //printf("Hello world! 12\n");
      multiplication(&matrixA,&matrixB,&matrixC);
     }
        //printf("Hello world! 13\n");
     int i=0;
     int j=0;

    printf( "\n 000000000000000000 \n");
    printf( "%d \n",matrixC.N);
    printf( "%d \n",matrixC.M);
    printf( "\n 11111111111111111111 \n");

     for(i=0; i<matrixA.N;i++)
        {
        //printf("Hello world! 17\n");
            for(j=0;j<matrixA.M;j++)
            {
           //printf("Hello world! 18\n");
               printf( "%f ",get_elem(&matrixA,i,j));
            }
        }

        printf( "\n 222222222222222 \n");
         for(i=0; i<matrixB.N;i++)
        {
        //printf("Hello world! 17\n");
            for(j=0;j<matrixB.M;j++)
            {
           //printf("Hello world! 18\n");
               printf( "%f ",get_elem(&matrixB,i,j));
            }
        }


 printf( "\n 3333333333333333333 \n");
     for(i=0; i<matrixC.N;i++)
        {
        //printf("Hello world! 17\n");
            for(j=0;j<matrixC.M;j++)
            {
           //printf("Hello world! 18\n");
               printf( "%f ",get_elem(&matrixC,i,j));
            }
        }


    free(matrixA.arr);
    free(matrixB.arr);
    free(matrixC.arr);
    //printf("Hello world!\n");
     return 0;
}

void multiplication(struct matrix *matrixA,struct matrix *matrixB, struct matrix *matrixC)
{      // printf("Hello world! 14\n");
        matrixC->N=matrixA->N;
        matrixC->M=matrixB->M;
        matrixC->not_null=matrixC->N*matrixC->M;
        matrixC->arr =malloc(matrixB->not_null*sizeof(struct element));
        int i=0;
        int j=0;
        int k=0;
        //printf("Hello world! 15\n");
        for(i=0; i<matrixC->N;i++)
        {
            for( j=0;j<matrixC->M;j++)
            {   //printf("Hello world!16\n");
                float temp=0;
                for(k=0; k<matrixA->M;k++)
                {
                temp = temp + get_elem(matrixA, i, k) * get_elem(matrixB, k, j);

                }
                set_elem(matrixC,i,j,temp);
            }
        }

}


float get_elem(struct matrix *matrixX, int row, int col)
{
int k=0;
int t=0;
 for(k=0; k<matrixX->ind;k++)
    {
        if((row==matrixX->arr[k].i)&&(col==matrixX->arr[k].j))
        {
            return matrixX->arr[k].val;
        }
    }
    return 0;
}

void set_elem(struct matrix *matrixX,int row,int col, float elem)
{
    matrixX->arr[matrixX->ind].i=row;
    matrixX->arr[matrixX->ind].j=col;
    matrixX->arr[matrixX->ind].val=elem;
    matrixX->ind++;
}
