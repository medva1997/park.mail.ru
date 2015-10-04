#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define n 1000

int main(int argc, char *argv[])
{

    FILE *file1 = fopen(argv[1],"r");
    if(file1 == 0)	{
        printf("не могу открыть файл '%s'",argv[1]);
        return 0;
	}

	//создаем временный файл
	FILE *file2 = fopen("tempfile1.txt","w+");
    if(file2 == 0)	{
        printf("не могу открыть файл '%s'","tempfile1.txt");
        return 0;
	}
	FILE *file3 = fopen("tempfile2.txt","w+");
    if(file2 == 0)	{
        printf("не могу открыть файл '%s'","tempfile2.txt");
        return 0;
	}

	int temp;
	int zirocounter=0;//количество нулей
	while ((fscanf (file1, "%d", &temp)) != EOF) {
		if(temp==0)		{
            zirocounter++;
		}
		if(temp<0)		{
            fprintf(file2,"%d \n",temp);
		}
		if(temp>0)		{
            fprintf(file3,"%d \n",temp);
		}
	}

	fclose(file1);
    //открываем основной фал на перезапись
    FILE *file4 = fopen(argv[1],"w+");
    if(file1 == 0)	{
        printf("не могу открыть файл '%s'",argv[1]);
        return 0;
	}

    int i;
	for(i=0;i<zirocounter;i++){fprintf(file4,"%d \n", 0);}

    rewind (file2);
    rewind (file3);
	while ((fscanf (file2, "%d", &temp)) != EOF) {
            fprintf(file4,"%d \n", temp);
		}
    while ((fscanf (file3, "%d", &temp)) != EOF) {
            fprintf(file4,"%d \n", temp);
		}

    return 0;
}
