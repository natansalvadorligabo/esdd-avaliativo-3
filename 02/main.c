#include "queue.h"
#include <time.h>

int chamadoCaixa();

int main(){
    int option, conta = 1, numeroCaixa, cliente;

    Queue normal;      
    Queue prioritaria;

    init(&normal);
    init(&prioritaria);

    do{
        printf("1 - Pegar ficha normal\n2 - Pegar ficha prioritária\n3 - Caixa\n0 - Sair\nEscolha sua opção (0-3): ");
        scanf("%d", &option);
        switch (option){
        case 0:
            printf("Encerrando o sistema...\n");
            break;
        case 1:
            enqueue(normal, conta);
            conta++;
            break;
        case 2:
            enqueue(prioritaria, conta);
            conta++;
            break;
        case 3:
            numeroCaixa = chamadoCaixa();

            if(numeroCaixa == 1 || numeroCaixa == 2 || numeroCaixa == 3){
                if (!is_empty(prioritaria)){
                    cliente = dequeue(prioritaria);
                }else{
                    cliente = dequeue(normal);
                }
            } else if (!is_empty(normal)){
                cliente = dequeue(normal);
            } 
            printf("\nCaixa: %d - Cliente: %d\n\n", numeroCaixa, cliente);

            break;
        default:
            printf("Opção inválida. Tente novamente!\n");
            break;
        }
    } while (option != 0);

    return 0;
}

int chamadoCaixa(){
    srand((unsigned)time(NULL));

    int numeroCaixa = (rand() % 10) + 1;

    return numeroCaixa;
}