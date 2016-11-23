/*
3_2. ​Дан массив целых чисел А[0..n­1]. Известно, что на интервале [0, m] значения массива строго

        возрастают, а на интервале [m, n­1] строго убывают. Найти m за O(log m).

2 ≤ n ≤ 10000.
 */
#include <iostream>
// поиск на отрезке
int binsearch(int *array,int n, int l, int r)
{
    int m=0;
    if (r>=n)
        r=n-1;

    while(l<r)
    {
        m=(l + r) / 2;

        if (array[r-1]<array[r])
        {
            return r;
        }

        if(l==1)
        {
            if (array[l - 1] > array[l])
            {
                return l - 1;
            }
        }

        if((array[m-1]<array[m])&&(array[m]>array[m+1]))
        {
            return m;
        }
        else
        {
            if((array[m-1]>array[m])&&(array[m]>array[m+1]))
                r=m-1;
            else
                l=m+1;
        }
    }

    return r;
}
//вычисляем 2^i
int pow(int i)
{
    return 1<<i;
}


int search_by_pow(int *array,int n)
{
    int m=0;
    //проходимся по степеням двойки пока в 2^i не появится уменьшение
    for (int i=0; m<n; i++)
    {
        m=pow(i);
        if((array[m-1]>array[m])&&(array[m]>array[m+1]))
            break;
    }
    //поиск на отрезке m/2,m
    return binsearch(array,n,m/2,m);
}

int main() {

    int n=0;
    std::cin >>n;
    int *A=new int[n];
    for(int i=0; i<n;i++)
    {
        std::cin>>A[i];
    }
    std::cout<<search_by_pow(A,n)<<std::endl;

    delete [] A;
    return 0;
}