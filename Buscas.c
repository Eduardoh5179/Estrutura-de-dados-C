#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int arr[TAM];


void inicializar(){
    for (int i = 0; i < TAM; i++) {
        arr[i] = i; 
    }
}

void print(){
    for (int i = 0; i < TAM; i++) {
        printf(" %d ", arr[i]);
    }
}

int buscaSeq(int chave){
    for (int i = 0; i < TAM; i++) {
        if(arr[i] == chave){
            printf("\nnumero encontrado: %d ",chave);
            return arr[i];
        }
    }
    printf("\nnada encontrado");
    return -1;
}

int buscaB(int chave){
    int primeiro = 0, ultimo = TAM-1,meio;
    
    while(primeiro<=ultimo){
        meio = (primeiro + ultimo)/2;
        if(chave == arr[meio]){
            printf("\nnumero encontrado %d",arr[meio]);
            return arr[meio];
        }
        if(chave < arr[meio]){
            ultimo = meio - 1;
        } else{
            primeiro = meio + 1;
        }
        
    }
        printf("\nnumero nao encontrado");
        return -1;
}


int main()
{
    inicializar();
    print();
    buscaSeq(5);
    buscaB(5);
}
