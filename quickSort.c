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

int troca(int X[], int i, int r){
    int aux = X[i];
    X[i] = X[r];
    X[r] = aux;
}

int particao(int X[], int p,int r){
    int pivo,i,j;
    pivo = X[(p+r)/2];
    i=p-1;
    j=r+1;
    
    while(1){
        do{
            j--;
        } while(X[j] > pivo);
        
        do{
            i++;
        } while (X[i] < pivo);
        
        if(i<j){
            troca(X,i,j);
        } else{
            return j;
        }
    }
    
}

int quickSort(int X[], int p, int r){
    if(p<r){
        int q = particao(X,p,r);
        quickSort(X,p,q);
        quickSort(X,q+1,r);
    }
}

int main()
{
    randomArr();
    quickSort(arr,0,TAM-1);
    printArr();
}
