#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// pegando o bit da posição sorteado
void pegandoBit(unsigned char aleatorio,  unsigned char armarios){
    unsigned char armarioElemento;
    armarioElemento = armarios >> aleatorio;
    armarioElemento = armarioElemento << 7;
    armarioElemento = armarioElemento >> 7;

   taOcupado(armarioElemento, armarios, aleatorio);
}

// verificando se Ta ocupado
int taOcupado( unsigned char armarioElemento, unsigned char armarios, unsigned char aleatorio ){
    // não está ocupado
    printf("entrei aqui \n");
     if(!(armarioElemento && 1)){
        // trocando o bit na posição correta caso a posição não esteja
        armarioElemento = 0b000000001;
        armarioElemento = armarioElemento << aleatorio;
        armarios = armarios | armarioElemento;
        printf("%d", armarios);  
        return armarios;
    } else{
        // se tiver está ocupado ele vai somar + 1 para pegar o proxuimo elemento

        // ele vai vasculhar os elementos depois do numero sorteado
        // se não encontrar nada nehum armario vago depois dos numeros sorteado
        // ele vai voltar pro inicio e começar a vasculhar até achar um armario que esteja vago;
        aleatorio = (aleatorio+1) > 7 ? (aleatorio + 1): - (-aleatorio + 1);
        pegandoBit(aleatorio, armarios);
    }
}

int main(){
    // armarios
    unsigned char armarios = 0b00010000;
    unsigned char auxArmario;
    unsigned char aleatorio;

    if(armarios == 255){
        printf("Todos os armarios estão ocupado: \n");
        return 0;
    }
  
    // escolher armario aleatorioamente
    // escolher um numero aleatorio entre 1 e 8;
    srand((unsigned)time(NULL));
    aleatorio = rand() % 7;
    printf("%d \n", aleatorio);

    // pegando o bit da posição sorteada
    pegandoBit(aleatorio, armarios);


      
    return 0;
}