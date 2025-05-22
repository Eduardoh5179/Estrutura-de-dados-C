#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado,bal;
    struct no *esq;
    struct no *dir;
};

struct no *raiz_avl = NULL;

struct no *cria_no(int valor){
    struct no *aux = malloc(sizeof(struct no));
    aux->dado=valor;
    aux->dir=NULL;
    aux->esq=NULL;
    aux->bal=0;
    return aux;
}

void esquerda(struct no *p){
    struct no *q, *hold;
    p=q->dir;
    hold=q->esq;
    q->esq=p;
    p->dir=hold;
}

void direita(struct no *p){
    struct no *q,*hold;
    q=p->esq;
    hold=q->dir;
    q->dir=p;
    p->esq=hold;
}

void insere_bal(int chave){
    struct no *pp = NULL, *p=raiz_avl;
    struct no *pnovo=NULL, *anovo=raiz_avl,*q,*filho;
    int imbal;
    if(p==NULL){
        raiz_avl = cria_no(chave);
        return;
    }
    
    while(p!=NULL){
        if(chave<p->dado){
            q=p->esq;
        }else{
            q=p->dir;
        }
        if(q!=NULL){
            if(q->bal!=0){
                pnovo=p;
                anovo=q;
            }
        }
    pp=p;
    p=q;
    }
    q=cria_no(chave);
    if(chave<pp->dado){
        pp->esq=q;
    }else{
        pp->dir=q;
    }
    if(chave<anovo->dado){
        filho=anovo->esq;
    }else{
        filho=anovo->dir;
    }
    p=filho;
    while(p!=q){
        if(chave<p->dado){
            p->bal=1;
            p=p->esq;
        }else{
            p->bal-1;
            p=p->dir;
        }
    }
    if(chave < anovo->dado){
        imbal=1;
    } else{
        imbal=-1;
    }
    if(anovo->bal==0){
        printf("sem desbalanceamento\n");
        anovo->bal=imbal;
        return;
    }
    if(anovo->bal != imbal){
        printf("sem desbalanceamento\n");
        anovo->bal=0;
        return;
    }
    if(filho->bal==imbal){
        p=filho;
        if(imbal==1){
            printf("desbalanceamento simples direita\n");
            direita(anovo);
        }else{
            printf("desbalalnceamento simples a esquerda");
            esquerda(anovo);
        }
        anovo->bal=0;
        filho->bal=0;
    } else{
        if(imbal==1){
            printf("desbalalnceamento duplo a esq/direita\n");
            p=filho->dir;
            esquerda(filho);
            anovo->esq=p;
            direita(anovo);
        } else{
            printf("desbalanceamento duplo a direita/esq\n");
            p=filho->esq;
            direita(filho);
            anovo->dir=p;
        }
        if(p->bal==0){
            anovo->bal=0;
            filho->bal=0;
        }else{
            if(p->bal==imbal){
                anovo->bal=-imbal;
                filho->bal=0;
            }
            else{
                anovo->bal=0;
                filho->bal=imbal;
            }
        }
        p->bal=0;
    }
    if(pnovo=NULL){
        raiz_avl=p;
    }
    else if(anovo==pnovo->dir){
        pnovo->dir=p;
    }
    else{
        pnovo->esq=p;
    }
    return;
}

void em_ordem(struct no *raiz){
    if(raiz!=NULL){
        printf("%d ",raiz->dado);
        em_ordem(raiz->esq);
        em_ordem(raiz->dir);
    }
}

int main()
{
    insere_bal(20);
    insere_bal(10);
    insere_bal(30);
    insere_bal(5);
    insere_bal(15);
    insere_bal(40);
    insere_bal(33);
    insere_bal(8);

    
    printf("em ordem: ");
    em_ordem(raiz_avl);
    printf("\n");
}
