/*
5_1. Первые k элементов длинной последовательности.

Дана очень длинная последовательность целых чисел длины n. Требуется вывести в
отсортированном виде её первые k элементов. Последовательность может не помещаться в память.
Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.


9 4
3 7 4 5 6 1 15 4 2

 1 2 3 4
 */

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

template<class T>
void merge(T a[], long left, long split, long rigth) {
    long pos1=left; //позиция чтения из левой части
    long pos2=split+1; //позиция чтения из правой части
    long pos3=0;    // текущая позиция в temp
    T *temp = new T[rigth-left+1];

    // идет слияние, пока есть хоть один элемент в каждой последовательности
    while (pos1 <= split && pos2 <= rigth) {
        if (a[pos1] < a[pos2])
            temp[pos3++] = a[pos1++];
        else
            temp[pos3++] = a[pos2++];
    }

    // копирование остатков в конец буфера
    while (pos2 <= rigth)
        temp[pos3++] = a[pos2++];
    while (pos1 <= split)
        temp[pos3++] = a[pos1++];

    for (pos3 = 0; pos3 < rigth-left+1; pos3++)
        a[left+pos3] = temp[pos3];

    delete [] temp;
}

template<class T>
void mergeSort(T a[], long left, long rigth) {
    long split;                   // индекс, по которому делим массив

    if (left < rigth) {
        split = (left + rigth)/2;
        mergeSort(a, left, split);
        mergeSort(a, split+1, rigth);
        merge(a, left, split, rigth);    //результаты в общий массив
    }
}

template<class T>
int reader(T a[], int k, long n)
{
    int to=k*2;
    //проверяем читаем ли мы весь буфер
    if(n<k) to=k+n;
    for (int i = k; i <to; ++i)
        cin>>a[i];

    mergeSort(a,0,to-1);

    return to-k;
}

int main() {
    int n,k;
    cin>>n>>k;

    int* mass =new int [k*2];
    //чтение первой половины буфера
    for (int i = 0; i <k; ++i)
        cin>>mass[i];
    n-=k;

    //чтение второй половины буфера
    while(n>0)
       n-=reader(mass,k,n);

    for (int i = 0; i < k; ++i)
        cout<<mass[i]<<" ";

    return 0;
}