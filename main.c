#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    // armarios
    unsigned char armarios = 0b00100100;
    unsigned char auxArmario;
    int aleatorio;

    // escolher armario aleatorioamente
    // escolher um numero aleatorio entre 1 e 8;
    srand((unsigned)time(NULL));
    aleatorio = rand() % 7;
    printf("%d \n", aleatorio);

    // pegando o bit da posição sorteada
    auxArmario = armarios >> aleatorio;
    auxArmario = auxArmario << 7;
    auxArmario = auxArmario >> 7;

    // veriricando se o bit já está ocupado
    if(auxArmario && 1){
        printf("Armario na posição %d está ocupado \n", aleatorio);
    } else{
          // trocando o bit na posição correta caso a posição não esteja
        auxArmario = 0b000000001;
        auxArmario = auxArmario << aleatorio;
        armarios = armarios | auxArmario;
        printf("%d", armarios);
    }
    
        // switch (aleatorio)
        // {
        // case 1:
        //     // se for um numero impar o ultimo bit estará ocupada
        //     if(armarios % 2){
        //         printf("%d", armarios);
        //     }
        //     break;
        // case 2:
        //     // verificando se o bit na posição 2 está ocupado
        //     // vou mover o duas devezes até o bit da posição 2 ( que no casa vai ser o armario 2);
        //     auxArmario  = armarios >> 2;
        //     if(auxArmario % 2){
        //         printf("%d \n", auxArmario);
        //     }   
        //     break;
        
        // case 3:
        //      // verificando se o bit na posição 2 está ocupado
        //     // vou mover o duas devezes até o bit da posição 2 ( que no casa vai ser o armario 2);
        //     auxArmario  = armarios >> 2;
        //     if(auxArmario % 2){
        //         printf("%d \n", auxArmario);
        //     }   
        //     break;
        // default:
        //     break;
        // }

    return 0;
}