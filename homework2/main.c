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
    //чтение первого массива
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
    matrixA.ind=matrixA.not_null;
    fclose(file1);

    //Чтение втого массива
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
    matrixB.ind=matrixB.not_null;
    fclose(file2);

     if(matrixA.M!=matrixB.N)
     {
        printf("Fold impossible");
        return 0;
     }
     else
     {
        multiplication(&matrixA,&matrixB,&matrixC);//умножение
     }
     //вывод результата работы программы
     int i=0;
     int j=0;
     for(i=0; i<matrixC.N;i++)
     {
        for(j=0;j<matrixC.M;j++)
        {
            printf( "%f ",get_elem(&matrixC,i,j));
        }
        printf("\n");
     }

    free(matrixA.arr);
    free(matrixB.arr);
    free(matrixC.arr);
    return 0;
}

void multiplication(struct matrix *matrixA,struct matrix *matrixB, struct matrix *matrixC)
{   //установка размеров 3 массива
    matrixC->N=matrixA->N;
    matrixC->M=matrixB->M;
    matrixC->not_null=matrixC->N*matrixC->M;
    matrixC->arr =malloc(matrixB->not_null*sizeof(struct element));
    //умножение 3 массива
    int i=0;
    int j=0;
    int k=0;
    for(i=0; i<matrixC->N;i++)
    {
        for( j=0;j<matrixC->M;j++)
        {
            float temp=0;
            for(k=0; k<matrixA->M;k++)
            {
                temp = temp + get_elem(matrixA, i, k) * get_elem(matrixB, k, j);
            }
            set_elem(matrixC,i,j,temp);//установка нового элемнта в 3 массив
        }
    }
}


float get_elem(struct matrix *matrixX, int row, int col)//поиск нужного элемента
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

void set_elem(struct matrix *matrixX,int row,int col, float elem)//установка значения нужного эллемента
{
    matrixX->arr[matrixX->ind].i=row;
    matrixX->arr[matrixX->ind].j=col;
    matrixX->arr[matrixX->ind].val=elem;
    matrixX->ind++;
}
