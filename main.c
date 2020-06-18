#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void egolatra(char cadena[]){
    int numero=atoi(cadena), i=0, auxNum=0, potencia=strlen(cadena)-1;
    int numCadena[potencia];

    for(i; i<strlen(cadena)-1; i++){
        numCadena[i]=cadena[i]-'0';
        auxNum+=pow(numCadena[i], potencia);
    }
    if(auxNum==numero){
        printf("El numero %d SI es egolatra\n",numero);
    }else{
        printf("El numero %d NO es egolatra\n", numero);
    }
}

void primoDesendente(int num){
    int i=num, j;
    for(i; i>=1; i--){
        bool aux=false;
        j=i;
        while(aux==false && j>=1){
            if(j==1){
                j=j+1;
            }
            j--;
            if((i%j)==0){
                aux=true;
            }
            if(j==1 || i==1){
                printf("%d, ",i);
                aux==true;
            }
        }
    }
    printf("\n");
}
void cadenaPuntaje(char cadena[]){
    int i=0, suma=0, aux=0;
    for(i; i<strlen(cadena); i++){
        if(cadena[i]=='O'){
            suma++;
        }else{
            suma=0;
        }
        aux=suma+aux;
    }
    printf("Su puntaje es %d \n",aux);
}


void menu(){
    int num, opcion;
    char cadena[30];
    do{
        printf("Digite una opcion\n1) Primos desendentes\n2) Numero Egolatra\n7) Puntaje dados por X y O\n8) Salir \nOpcion:");
        scanf("%d",& opcion);
        fflush(stdin);
        switch(opcion){
            case 1:
                printf("Digite el numero para ver los numeros primos desde n hasta 1\nNumero: ");
                scanf("%d",& num);
                primoDesendente(num);
                break;
            case 2:
                printf("Digite un numero para verificar si es o no egolatra\nNumero: ");
                fgets(cadena,30,stdin);
                egolatra(cadena);
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                printf("Digite una cadena compuesta por X y O (de la forma XOXXOOOXO) para calcular el puntaje\nCadena: ");
                fgets(cadena,30, stdin);
                cadenaPuntaje(cadena);
                break;
            case 8:
                printf("Adios");
                break;

            default:
                printf("Valor no valido\n");

        }
    }while(opcion!=8);
}


int main(int argc, char *argv[]) {
    menu();
    return 0;
}