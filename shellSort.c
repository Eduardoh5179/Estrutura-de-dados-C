#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 10

int arr[TAM];

int randomArr(){
    int i;
    srand(97);
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

int shellSort(){
    int i,j,aux;
    float k = (log(TAM + 1)/log(3));
    int K = floor(k+0.5);
    int h = ((pow(3,k)-1)/2);

    while(h>0){
        for(i = h; i < TAM;i++){
            aux = arr[i];
            j = i;
                while(j>=h && arr[j - h] > aux){
                        arr[j] = arr[j-h];
                        j = j - h;
                }
                arr[j] = aux;
            }
        h = (h-1)/3;
        }
    }



int main()
{
    randomArr();
    shellSort();
    printArr();
}
