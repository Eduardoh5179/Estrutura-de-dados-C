#include <stdio.h>
#include <stdlib.h>
#define TAM 11

int arr[TAM];

void start(){
    for (int i = 0; i < TAM; i++) {
        arr[i] = -1;
    }
}

int fhash(int key){
    return key % TAM;
}

void insert(int key){
    int pos = fhash(key);
    int count = 0;
    
    while(arr[pos] != -1 && count < TAM){
        pos = (pos+1) % TAM;
        count++;
    }
    
    if(count == TAM){
        printf("tabela cheia\n");
    }
    else{
        arr[pos] = key;
    }
}

void print(){
    for (int i = 0; i < TAM; i++) {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

int buscar(int chave){
    int pos = fhash(chave);
    int count = 0;
    
    while(arr[pos] != -1 && count < TAM){
        if(arr[pos] == chave){
            printf("chave %d encontrada na posicao %d\n", chave,pos);
            return;
        }
        
        pos = (pos+1) % TAM;
        count++;
    }
    printf("chave %d nao encontrada",chave);
}

int main()
{
    start();
    insert(33);
    insert(26);
    insert(58);
    print();
    buscar(58);
}
