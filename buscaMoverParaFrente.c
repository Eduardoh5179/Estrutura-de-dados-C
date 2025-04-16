#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int arr[TAM];

void printArr(){
    int i;
    for(i=0;i<TAM;i++){
        printf(" %d ",arr[i]);
    }
}

int buscaMoverParaFrente(int chave){
    for (int i = 0; i < TAM; i++) {
        if(arr[i] == chave){
            if(i != 0){
                int temp = arr[i];
                arr[i] = arr[0];
                arr[0] = temp;
            }
            printf("\nchave encontrada %d encontrada e movida para a posição 0\n",chave);
            return 0;
        }
    }
    printf("chave nao encontrada");
    return -1;
}


int main()
{
    for (int i = 0; i < TAM; i++) {
        arr[i] = i*2;
    }
    buscaMoverParaFrente(8);
    printArr();
}
