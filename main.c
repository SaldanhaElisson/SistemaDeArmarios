#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned char resultado;
// monstrando na tela um numero em forma binaria
void imprimirBinario(int n){
        int r = 0;
         for(int i = 7; i >= 0; i--) {
            // Executa a operação shift right até a 
            // última posição da direita para cada bit.
            r = n  >> i;
                
            // Por meio do "e" lógico ele compara se o valor 
            // na posição mais à direita é 1 ou 0 
            // e imprime na tela até reproduzir o número binário.
            if(r & 1) {
                printf("1");
            } else {
                printf("0");
            }
        }
          printf(", ");   
}

// pegando o bit da posição sorteado
unsigned char pegandoBit(int aleatorio,  unsigned char armarios, int segundaVez){
    unsigned char armarioElemento;
    armarioElemento = armarios >> aleatorio;
    armarioElemento = armarioElemento << 7;
    armarioElemento = armarioElemento >> 7;
  
    
    if(segundaVez){
         taOcupado(armarioElemento, armarios, aleatorio);
         return 0;
    }

   return armarioElemento;
}


unsigned char DesacupandoOuOcupando( unsigned char armarios, int aleatorio, unsigned char Desacupar){
        unsigned char armarioElemento;
       // trocando o bit na posição correta caso a posição não esteja
        armarioElemento = 0b00000001;
        armarioElemento = armarioElemento << aleatorio;

        //se a pessoa digitar que quer desocupar o armario em uma posição
        if(Desacupar){
            // verificando se o armario ja está desocupado 
            if(!(pegandoBit(aleatorio, armarios, 0))){
                
                printf("Armario ja está desocupado: \n");
                printf(" \n");
                resultado = armarios;
                return armarios;
            };
            
            printf("O armario %d  foi desacupado: \n", aleatorio);
            armarios = armarios ^ armarioElemento;
            imprimirBinario(armarios);
            resultado = armarios;

            return armarios;
        }

        // ocupar armario em uma posição
        armarios = armarios | armarioElemento;
   
        imprimirBinario(armarios);
        printf(" \nO seu armario está na posição %d nos numeros acima", aleatorio);
        printf("\n");

        resultado = armarios;
        return armarios;
    
}

// verificando se Ta ocupado
 void taOcupado(  unsigned char armarioElemento, unsigned char armarios, int aleatorio ){
    unsigned char armariosResultado;
     if(!(armarioElemento && 1)){
          armariosResultado = DesacupandoOuOcupando(armarios, aleatorio, 0);
    } else{
        // se tiver está ocupado ele vai somar + 1 para pegar o proxuimo elemento

        // ele vai vasculhar os elementos depois do numero sorteado
        // se não encontrar nada nehum armario vago depois dos numeros sorteado
        // ele vai voltar pro inicio e começar a vasculhar até achar um armario que esteja vago;
        aleatorio = aleatorio < 7 ? aleatorio: -1;
        pegandoBit(aleatorio+1, armarios, 1);
    }
    
}

int main(){
    // armarios
    unsigned char armarios = 0b01111111;
    int comando;
    unsigned char auxArmario;
    int armario;

    for( ; ; ){

          if(armarios == 255){
            printf("Todos os armarios estão ocupado: \n");
    
            printf("Digite que posição você quer desacupar: \n");
            armario = getchar();
            scanf("%d", &armario);

            DesacupandoOuOcupando(armarios, (int)armario, 2);
            armarios = resultado;
            continue;
        }
     
        printf("\n");
        printf("SISTEMA DE ARMARIOS: \n ");
        printf(" \n");
        printf("O que você quer fazer ?: \n");
        printf("Digite [1] para ocupar um armario \n");
        printf("Digite [2] para ocupar um armario \n");
        printf("Digite [3] para sair do programa\n");
        scanf("%d", &comando);
        
      

        // desacupando um armario 
        if(comando == 2){
            printf("Digite que posição você quer desacupar: \n");
            armario = getchar();
            scanf("%d", &armario);

            DesacupandoOuOcupando(armarios, (int)armario, 2);
            armarios = resultado;
            continue;
        } else if( comando > 7){
            printf("Somente temos os  armarios de 0 até 7: \n");
            printf("O armario digitado não existe \n");
            continue;
        } else if( comando == 3){
            break;
        }

        // escolher armario aleatorioamente
        // escolher um numero armario aleatorio;
        srand((unsigned)time(NULL));
        armario = rand() % 7;
        printf("\n");

        // // pegando o bit da posição sorteada
        auxArmario = pegandoBit(armario, armarios, 0);
        taOcupado(auxArmario, armarios, armario);
        printf("\n");
        armarios = resultado;
    }
        
        
    return 0;
}