#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct aluno{
    char nome[50];
    int idade;
    char RA[8];
    struct aluno* proximo;
    /*ponteiro que aponta pro hexadecimal do local da memoria RAM do proximo item da lista*/
}aluno;


aluno* raiz;

/*"metodo criador" do struct aluno*/
aluno* criar_aluno(char nome[50], int idade, char RA[9]){
    aluno* dado = (aluno*) malloc(sizeof(aluno));
    
    if (dado != NULL)
    {
    /*usa strcpy por ser string*/
    strcpy(dado->nome, nome);
    /*acessa o campo idade com os parametros passados*/
    dado ->idade = idade;
    strcpy(dado->RA, RA);
    dado->proximo= NULL;
        
    }  
    return dado;  
}

bool esta_vazia(){
    return raiz == NULL;
}
void inserir_final_lista(aluno* dado){
    aluno* atual = raiz;
    while (atual->proximo != NULL)
    {
        atual=atual->proximo;
    }
    atual->proximo = dado;
    

}
void inserir_lista_vazia(aluno* dado){
    /*coloca o dado como a raiz da lista*/
    raiz = dado;
    return;
}

void inserir(aluno* dado){
    if(esta_vazia()){
        inserir_lista_vazia(dado);
        return;
    }
    inserir_final_lista(dado);
    return;


}



void inserir_exato(aluno*dado, int indice){
    aluno* atual = raiz;
    int contador = 0;

    while (contador < (indice - 1)){
        atual=atual->proximo;
        contador++;
    }
    dado->proximo=atual->proximo;
    atual->proximo = dado;
    
}  


void imprimir_lista(){
    aluno* atual = raiz;
    if (esta_vazia())
    {
        printf("\nA lista esta vazia..");
        return;
    }
    while (atual != NULL)
    {
        printf("Nome: %s\nidade: %d\n", atual->nome, atual->idade);
        atual= atual->proximo;
    }
        printf("fim lista\n");
    
}

aluno remover(){
    aluno retorno;
    if (esta_vazia())
    {
        printf("\nA lista esta vazia");
        return retorno;
    }
    
    aluno* atual = raiz->proximo;
    aluno* anterior = raiz;

    while (atual->proximo!=NULL)
    {
        anterior = anterior->proximo;
        atual = atual->proximo;
    }
    retorno = *atual;
    anterior->proximo= NULL;
    free(atual);
    
    return retorno;
}

int main(){


    aluno* dado = criar_aluno("Jorgin", 17, "00000001");
    aluno* dado1 = criar_aluno("Jorgina", 16, "00000001");
    aluno* dado2 = criar_aluno("Jorgino", 15, "00000001");
    aluno* dado3 = criar_aluno("Jorgine", 18, "00000001");
    

    inserir(dado);
    inserir(dado1);
    inserir(dado2);
    inserir(dado3);
    imprimir_lista();
    aluno removido = remover();
    printf("\nNome do aluno removido: %s\n", removido.nome);
    
    imprimir_lista();

}