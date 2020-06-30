/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hp
 *
 * Created on 29 de junio de 2020, 09:46 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int validarNumeros(char cadena[]) {
    for (int i = 0; i < strlen(cadena) - 1; i++) {
        if (!isdigit(cadena[i])) {
            return 0;
        }
    }
    return 1;
}

bool validateSex(char gender) {

    if ((gender == 'F' || gender == 'f') || (gender == 'M' || gender == 'm')) {
        return true;
    } else {
        return false;
    }
}

int pruebaXO(char cadena[]) {
    int i, aux = 0;
    for (i = 0; i < strlen(cadena) - 1; i++) {
        if ((cadena[i] == 'X' || cadena[i] == 'O') || (cadena[i] == 'O' || cadena[i] == 'X')) {
            aux = 0;
        } else {
            aux = 1;
            break;
        }
    }
    return aux;
}

void egolatra(char cadena[]) {
    int numero = atoi(cadena), i = 0, auxNum = 0, potencia = strlen(cadena) - 1;
    int numCadena[potencia];

    for (i; i < strlen(cadena) - 1; i++) {
        numCadena[i] = cadena[i] - '0';
        auxNum += pow(numCadena[i], potencia);
    }
    if (auxNum == numero) {
        printf("El numero %d SI es egolatra\n", numero);
    } else {
        printf("El numero %d NO es egolatra\n", numero);
    }
}

void primoDesendente(char cadena[]) {
    int i = atoi(cadena), j;
    for (i; i >= 1; i--) {
        bool aux = false;
        j = i;
        while (aux == false && j >= 1) {
            if (j == 1) {
                j = j + 1;
            }
            j--;
            if ((i % j) == 0) {
                aux = true;
            }
            if (j == 1 || i == 1) {
                printf("%d, ", i);
                aux == true;
            }
        }
    }
    printf("\n");
}

int magicNumber(char chain[]) {

    int higher = 0, less = 0, subtraction = 0, aux = 0;
    int tam = strlen(chain) - 1;
    char numberLess[tam], numberHigher[tam];

    //Ordenar el arreglo de mayor a menor por método burbuja 

    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (chain[i] < chain[j]) {
                aux = chain[i];
                chain[i] = chain[j];
                chain[j] = aux;
            }
        }
        numberHigher[i] = chain[i];
    }
    higher = atoi(numberHigher);

    //Ordenar el arreglo de menor a mayor por método burbuja

    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (chain[i] > chain[j]) {
                aux = chain[i];
                chain[i] = chain[j];
                chain[j] = aux;
            }
        }
        numberLess[i] = chain[i];
    }
    less = atoi(numberLess);

    subtraction = higher - less;

    return subtraction;
}

double IMC(char weight[], char height[]) {

    int weightBody = atoi(weight);
    int heigh = atoi(height);
    double stature = ((double) heigh / 100);

    return weightBody / pow(stature, 2);
}

char digits[2];

char* conversionToDigit(int number) {

    int i = 0;
    while (number > 0) {
        int value = number % 10;
        digits[i] = value + '0';
        number = number / 10;
        i++;
    }
    return digits;
}

char numbers[2];

char* sumDigits(char digitException[], char numberStart[], char numberEnd[]) {

    int numbersExceptions = 0;
    int sumDigit = 0, aux = 0;

    int number = atoi(digitException);
    
    for (int i = strlen(numberStart); i <= strlen(numberEnd); i++) {
        for (int j = 0; j <= strlen(conversionToDigit(i)) - 1; j++) {

            char numChar = conversionToDigit(i)[j];
            aux = numChar - '0';

            if (aux == number) {
                numbersExceptions += 1;
            } else {
                sumDigit += aux;
            }
        }
    }

    numbers[0] = sumDigit;
    numbers[1] = numbersExceptions;

    return numbers;
}

void cadenaPuntaje(char cadena[]) {
    int i = 0, suma = 0, aux = 0;
    for (i; i < strlen(cadena); i++) {
        if (cadena[i] == 'O') {
            suma++;
        } else {
            suma = 0;
        }
        aux = suma + aux;
    }
    printf("Su puntaje es %d \n", aux);
}

void menu() {

    int number, opcion;
    char chain[30], gender, height[10], weight[10];
    char startNumber [10];
    char endNumber [10];
    char digitException [10];

    do {
        printf("Digite una opción: \n1) Primos descendentes\n2) Número Egolatra \n3) Número mágico \n4) Indice de masa corporal (IMC) \n5) Suma de digitos \n7) Puntaje dados por X y O \n8) Salir \n\n Opcion:  ");
        scanf("%d", & opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                printf("Digite el número para ver los números primos desde n hasta 1\n Número: ");
                fgets(chain, 30, stdin);
                if (validarNumeros(chain) != 0) {
                    primoDesendente(chain);
                } else {
                    printf("Error al digitar el número\n");
                }
                break;
            case 2:
                printf("Digite un número para verificar si es o no egolatra \n Número: ");
                fgets(chain, 30, stdin);
                if (validarNumeros(chain) != 0) {
                    egolatra(chain);
                } else {
                    printf("Error al digitar el número\n");
                }

                break;
            case 3:

                fflush(stdin);
                printf("Ingrese un número de mínimo 3 digitos, para comprobar si es un número mágico: ");
                fgets(chain, 30, stdin);
                fflush(stdin);

                number = atoi(chain);

                if (validarNumeros(chain) != 0) {
                    printf("El número %d %s \n", number, magicNumber(chain) == number ? " es un número mágico \n" : " no es número magico \n");
                }
                break;

            case 4:

                printf("Para hacer el calculo de IMC ingrese: \n ");

                printf("Ingrese su estatura en cm (Ejemplo: 170): ");
                fgets(height, 15, stdin);

                if (validarNumeros(height) != 0) {

                    printf("Ingrese su peso en kg:");
                    fgets(weight, 10, stdin);

                    if (validarNumeros(weight) != 0) {

                        printf("Ingrese su género F si es mujer o M si es hombre: ");
                        scanf("%c", &gender);
                        if (validateSex(gender)) {

                            if (gender == 'F' || gender == 'f') {
                                if (IMC(weight, height) < 16) {
                                    printf("Su IMC por es % .1f y su diagnóstico es desnutrición \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 16 || IMC(weight, height) == 20) {
                                    printf("Su IMC es %.2f y su diagnóstico es bajo peso \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 20 || IMC(weight, height) == 24) {
                                    printf("Su IMC es %.2f y su diagnóstico es normal \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 24 || IMC(weight, height) == 29) {
                                    printf("Su IMC es %.2f y su diagnóstico es sobrepeso \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 29 || IMC(weight, height) == 34) {
                                    printf("Su IMC es %.2f y su diagnóstico es obesidad \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 34 || IMC(weight, height) == 39) {
                                    printf("Su IMC es %.2f y su diagnóstico es obesidad marcada \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 39) {
                                    printf("Su IMC es %.2f y su diagnóstico es obesidad morbida \n", IMC(weight, height));
                                }
                            } else if (gender == 'M' || gender == 'm') {
                                if (IMC(weight, height) < 17) {
                                    printf("Su IMC es %.2f y su diagnóstico es desnutrición: \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 17 || IMC(weight, height) == 20) {
                                    printf("Su IMC es %.2f y su diagnóstico es bajo peso: \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 20 || IMC(weight, height) == 25) {
                                    printf("Su IMC es %.2f y su diagnóstico es normal: \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 25 || IMC(weight, height) == 30) {
                                    printf("Su IMC es %.2f y su diagnóstico es sobrepeso: \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 30 || IMC(weight, height) == 35) {
                                    printf("Su IMC es %.2f y su diagnóstico es obesidad: \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 35 || IMC(weight, height) == 40) {
                                    printf("Su IMC es %.2f y su diagnóstico es obesidad marcada: \n", IMC(weight, height));
                                } else if (IMC(weight, height) > 40) {
                                    printf("Su IMC es %.2f y su diagnóstico es obesidad morbida: \n", IMC(weight, height));
                                }
                            }
                        } else {
                            printf("Error al digitar la letra \n");
                        }
                    } else {
                        printf("Error al digitar el número \n");
                    }
                } else {
                    printf("Error al digitar el número \n");
                }

                break;

            case 5:

                printf("Por favor digita el primer numero del intervalo inicial \n");
                fgets(startNumber, 10, stdin);

                if (validarNumeros(startNumber) != 0) {

                    printf("Por favor digita el segundo numero del intervalo para completarlo \n");
                    fgets(endNumber, 10, stdin);

                    if (validarNumeros(endNumber) != 0) {

                        printf("Por favor digita el valor del digito que quieres que no se sume \n");
                        fgets(digitException, 10, stdin);

                        if (validarNumeros(digitException) != 0) {

                            printf("\n La suma de los digitos en el intervalo [%c,%c] sin tener en cuenta el número %c \n\n", startNumber, endNumber, digitException);
                            printf("La suma de digitos diferentes a %c es: %d \n", digitException, sumDigits(digitException, startNumber, endNumber)[0]);
                            printf("La cantidad de números que no se tuvieron en cuenta fueron: %d \n", sumDigits(digitException, startNumber, endNumber)[1]);
                        } else {
                            printf("Error al digitar el número \n");
                        }
                    } else {
                        printf("Error al digitar el número \n");
                    }
                } else {
                    printf("Error al digitar el número \n");
                }

                break;

            case 6:

                break;
            case 7:
                printf("Digite una cadena compuesta por X y O (de la forma XOXXOOOXO) para calcular el puntaje\nCadena: ");
                fgets(chain, 30, stdin);
                fflush(stdin);
                if (pruebaXO(chain) != 0) {
                    printf("Error al digitar la cadena\n");
                } else {
                    cadenaPuntaje(chain);
                }

                break;
            case 8:
                printf("Adios");
                break;

            default:
                printf("Valor no valido\n");

        }
    } while (opcion != 8);
}

int main(int argc, char *argv[]) {
    menu();
    return 0;
}

