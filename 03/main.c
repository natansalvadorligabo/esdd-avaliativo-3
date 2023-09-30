#include "queue.h"

int main(int argc, char const *argv[]){
    Queue caverna;
    Queue auxiliar;
    
    char sobrevivente;
    char nome;
    int size = QUEUE_MAX_SIZE;

    init(&caverna);
    init(&auxiliar);

    while(!is_full(caverna)){
        printf("Digite um nome para colocar na caverna: ");
        scanf("%c", &nome);
        getchar();
        enqueue(caverna, nome);
    }

    while(size > 1){
        for(int i = 0; i < 3; i++){
            enqueue(caverna, dequeue(caverna));
        }
        dequeue(caverna);
        size--;
    }

    printf("\nSobrevivente: %c\n", dequeue(caverna));
    
    return 0;
}