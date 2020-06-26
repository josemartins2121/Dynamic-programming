#include <stdio.h>
#define MAXSIZE 101
unsigned long int count = 0;

unsigned long int fib1(unsigned long int N)
{
    //printf("F(%lu)\n", N);
    count++;
    if (!N || N == 1)
        return N;
    else
        return fib1(N - 1) + fib1(N - 2);
}

unsigned long int fib2(unsigned long int N,unsigned long int aux[])
{
    //printf("F(%lu)\n", N);
    count++;
    if(aux[N]==-1)aux[N]=fib2(N-1,aux)+fib2(N-2,aux);
    return aux[N];
}

int main()
{

    unsigned long int N;

    printf("Fib(non dynamic) N?");
    scanf("%lu", &N);
    if (N > 0)
    {
        printf("O número de fibonacci de ordem %lu é : %lu\n", N, fib1(N));
        printf("Foi executado %lu vezes\n", count);
    }
    count=0;

    unsigned long int aux[MAXSIZE];
    for(unsigned long int i=0;i<MAXSIZE;i++){
        aux[i]=-1;
    }
    aux[0]=0;
    aux[1]=1;

    printf("Fib (dynamic) N?");
    scanf("%lu", &N);
    if (N > 0)
    {
        printf("O número de fibonacci de ordem %lu é : %lu\n", N, fib2(N,aux));
        printf("Foi executado %lu vezes\n", count);
    }

}