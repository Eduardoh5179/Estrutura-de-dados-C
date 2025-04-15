#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int arr[TAM];

int randomArr(){
    int i;
    srand(499);
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

void insertionSort(){
    for (int i = 1; i < TAM; i++) {
        int ponteiro = arr[i];
        int j = i-1;
        int x = 0;
        
        while(x == 0 && j>=0){
            if(arr[j] > ponteiro){
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
                j--;
            } else{
                x = 1;
            }
        }
    }
}

int main()
{
    randomArr();
    insertionSort();
    printArr();
}
