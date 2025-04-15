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

void selectionSort(){
    int i,j;
    for (i = 0; i <= TAM-1; i++) {
        int x = i;
        for(j = i+1;j<TAM;j++){
            if(arr[x]>arr[j]){
                x = j;
            }
        } 
        int y = arr[i];
        arr[i] = arr[x];
        arr[x] = y;
    }
}

int main()
{
    randomArr();
    selectionSort();
    printArr();
}
