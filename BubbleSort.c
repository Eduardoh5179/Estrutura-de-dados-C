#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int arr[TAM];

int randomArr(){
    int i;
    srand(33);
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

void bubbleSort(){
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM - 1; j++) {
            if(arr[j]>arr[j+1]){
                int x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = x;
            }
        }
    }
}

void bubbleSort2(){
    int i,j;
    for (i = 1; i <= TAM-1; i++) {
        for (j=TAM-1; j>=i; j--) {
            if(arr[j]<arr[j-1]){
                int x = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = x;
            }
        }
    }
}

void bubbleSort3(){
    int n = 1, troca = 1, x;
    
    while(n<=TAM && troca == 1){
        troca = 0;
        
        for(int i = 0;i<TAM-1;i++){
            if(arr[i] > arr[i+1]){
                x = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = x;
                troca = 1;
            }
        }
    }
}

int main()
{
    randomArr();
    bubbleSort();
    printArr();
}
