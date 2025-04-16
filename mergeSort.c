#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 10

int arr[TAM];

int randomArr(){
    int i;
    srand(97);
    for(i=0;i<TAM;i++){
        arr[i] = rand() % (TAM * 10);
    }
    
    return arr[TAM];
}

void printArr(){
    int i;
    for(i=0;i<TAM;i++){
        printf(" %d ",arr[i]);
    }
}

void merge(int X[], int inicio, int fim, int meio){
    int aux[TAM];
    int i = inicio;
    int j = meio + 1;
    int k = inicio;
    
    while(i <= meio && j<=fim){
        if(X[i] <= X[j]){
            aux[k++] = X[i++];
        } else{
            aux[k++] = X[j++];
        }
    }
    
    while (i <= meio) {
        aux[k++] = X[i++];
    }
    while (j<=fim) {
        aux[k++] = X[j++];
    }
    for (i = inicio; i <= fim; i++) {
        X[i] = aux[i];
    }
}

int mergeSort(int X[],int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio+fim)/2;
        mergeSort(X,inicio,meio);
        mergeSort(X,meio+1,fim);
        merge(X,inicio,fim,meio);
    }
}

int main()
{
    randomArr();
    mergeSort(arr,0,TAM-1);
    printArr();
}
