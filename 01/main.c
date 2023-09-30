#include "queue.h"

int main(){
    int number, i;
    
    Queue fila;
    Queue filaAux;

    init(&fila);
    init(&filaAux);

    for (i = 0; i < QUEUE_MAX_SIZE; i++){
        printf("Enter a number: ");
        scanf("%d", &number);
        enqueue(fila, number);
    }

    i = 1;
    while(!is_empty(fila)){
        number = dequeue(fila);
        if(number % 2 != 0 || number == 0){
            printf("Position: %d - Number: %d\n", i, number);
            enqueue(filaAux, number);
            i++;
        }
    }
    
    while (!is_empty(filaAux)){
        enqueue(fila, dequeue(filaAux));
    }

    return 0;
}