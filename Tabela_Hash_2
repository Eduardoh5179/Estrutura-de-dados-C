#include <stdio.h>
#include <stdlib.h>
#define TAM 11

typedef struct{
    int chave;
    struct hash *prox;
}hash;

hash *tabela[TAM];

int fhash(int chave){
    return chave % TAM;
}

void insert(int chave){
    int pos;
    pos = fhash(chave);
    hash *novo = (hash*)malloc(sizeof(hash));
    if(novo == NULL){
        printf("erro ao alocar");
        return;
    }
    novo -> chave = chave;
    novo -> prox = tabela[pos];
    tabela[pos] = novo;
}

void imprimir(){
    for (int i = 0; i < TAM; i++) {
        printf("posicao %d: ",i);
        hash *atual = tabela[i];
        while(atual != NULL){
            printf("%d -> ",atual->chave);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
}

hash* buscar(int chave){
    int pos = fhash(chave);
    hash *atual = tabela[pos];
    
    while(atual != NULL){
        if(atual -> chave == chave){
            printf("chave %d encontrada na posicao %d \n",chave,pos);
            return atual;
        }
        atual = atual->prox;
    }
    printf("chave %d nao encontrada. \n",chave);
}

int main()
{
    insert(5);
    insert(10);
    insert(44);
    imprimir();
    buscar(5);
}
