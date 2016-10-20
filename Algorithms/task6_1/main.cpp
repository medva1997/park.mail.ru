//6_1.​ Высокая пирамида. ​Каждый вышележащий слой пирамиды должен быть не больше нижележащего.
//N ≤ 200.

#include <iostream>

long int P2(int n, int k,long int **A) {

    if((n>0)&&(k>0)&&(A[n][k]!=-1))
        return A[n][k];
    else
    {
        if(n<0)
            return 0;

        if(k<=0)
            return 0;

        if (n==0)
            return 1;
        else {
            A[n][k] = P2(n - k, k, A) + P2(n, k - 1, A);
            return A[n][k];
        }
    }
}
long int Search(int n)
{
    n++;
    long int **a = new long int*[n];
    for(int i = 0; i < n; ++i) {
        a[i] = new long int[n];
        for (int j = 0; j <n ; ++j) {
            a[i][j] = -1;
        }
    }

    long int rez=P2(n-1,n-1,a);

    for(int i = 0; i < n; ++i) {
        delete [] a[i];
    }
    delete [] a;

    return  rez;


}


int main() {
    int n=0;
    std::cin>>n;

    std::cout << Search(n) << std::endl;


    return 0;
}