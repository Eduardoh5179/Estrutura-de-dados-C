#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int arr[TAM + 1];

void printArr(){
    int i;
    for(i=0;i<TAM;i++){
        printf(" %d ",arr[i]);
    }
}

int buscaSeqSentinela(int chave){
    int i = 0;
    
    arr[TAM] = chave;
    
    while(arr[i] != chave){
        i++;
    }
    
    if(i < TAM){
        printf("Chave %d encontrada na posição %d\n",chave,i);
        return i; 
    } else{
        printf("Chave %d nao encontrada\n",chave);
        return - 1;
    }
}


int main()
{
    for (int i = 0; i < TAM; i++) {
        arr[i] = i*2;
    }
    buscaSeqSentinela(8);
}
