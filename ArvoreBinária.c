#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    char RA[8];
    struct Aluno* esquerda;
    struct Aluno* direita;

} Aluno;

Aluno* raiz = NULL;

Aluno* criar_aluno(char nome[50], int idade, char RA[8]){
    Aluno* dado = (Aluno*) malloc(sizeof(Aluno));

    if(dado != NULL){
        strcpy(dado->nome, nome);
        dado->idade = idade;
        strcpy(dado->RA, RA);
        dado->esquerda = NULL;
        dado->direita = NULL;
    }
    return dado;
}

void inserir(Aluno* dado){
    if(raiz == NULL){
        raiz = dado;
        return;
    }

    Aluno* atual = raiz;
    while(1){
        if(strcmp(dado->nome, atual->nome) < 0){
            if(atual->esquerda == NULL){
                atual->esquerda = dado;
                return;
            }else{
                atual = atual->esquerda;
            }
        }else{
              if(atual->direita == NULL){
                atual->direita = dado;
                return;
            }else{
                atual = atual->direita;
            }
        }
    }
}


Aluno* buscar_aluno(char nome[50]){
    Aluno* atual = raiz;
    if(strcmp(nome, atual->nome) == 0){
        return atual;
    }
    while(atual != NULL && strcmp(nome, atual->nome) != 0){
        if(strcmp(nome, atual->nome) < 0){
            atual = atual->esquerda;
        }else{
            atual = atual->direita;
        }
    }
    return atual;

}

void imprimir_Ordem(Aluno* dado){
    if(dado != NULL){
        imprimir_Ordem(dado->esquerda);
        printf("%s\n", dado->nome);
        imprimir_Ordem(dado->direita);
    }

}

Aluno remover_folha(Aluno* dado){
    Aluno resultado = *dado;
    free(dado);
    return resultado;
}


Aluno remover_um_filho(Aluno* atual){
    Aluno* anterior = raiz;
    
    while(1){
        if(strcmp(atual->nome, anterior->nome) < 0){
            if(anterior->esquerda == atual){
                Aluno resultado = *atual;
                if(atual->esquerda != NULL){
                    anterior->esquerda = atual->esquerda;
                    free(atual);
                    return resultado;
                }else{
                    anterior->esquerda = atual->direita;
                    free(atual);
                    return resultado;
                }
                
            }else{
                anterior = anterior->esquerda;
            }
            
        }else{
            if(anterior->direita == atual){
                Aluno resultado = *atual;
                if(atual->esquerda != NULL){
                    anterior->direita = atual->esquerda;
                    free(atual);
                    return resultado;
                }else{
                    anterior->direita = atual->direita;
                    free(atual);
                    return resultado;
                }
            }else{
                anterior = anterior->direita;
            }
        }
        
    }
}

Aluno remover(Aluno* dado){
    if(dado == NULL){
        printf("O aluno nao esta presente na arvore");
        return;
    }
    if(dado->esquerda == NULL && dado->direita == NULL){
        Aluno resultado = remover_folha(dado);
        return resultado;
    }
    
    else{
        Aluno resultado = remover_um_filho(dado);
        return resultado;
    }
}


int main(){
    Aluno* dado = criar_aluno("Milena", 23, "20820826");
    inserir(dado);
    dado = criar_aluno("William", 32, "20820826");
    inserir(dado);
    dado = criar_aluno("Adriano", 30, "20825026");
    inserir(dado);
    dado = criar_aluno("Cleison", 25, "20825026");
    inserir(dado);
    
    
    Aluno* atual = buscar_aluno("Adriano");
    Aluno removido = remover(atual);
    
    printf("O aluno %s foi removido", removido.nome);
    //imprimir_Ordem(raiz);
    //Aluno* resultado_busca = buscar_aluno("Flávia");
    //printf("O aluno %s esta presente na arvore.", resultado_busca->nome);
}
