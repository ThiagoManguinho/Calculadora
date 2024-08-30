#include <stdio.h>
#include <string.h>

void convBinario (int valor){
    int count = 0;
    int Binario[16] = {0};

    printf("Convertendo para binario...\n");
    while (valor > 0){
        Binario[count] = valor%2;
        printf("%d / 2 = %d, resto = %d\n", valor, valor/2, Binario[count]);
        valor = valor/2;
        count++;
    }    

    printf("Resultado: ");
    for (int i = 15; i>=0; i--){
        printf("%d", Binario[i]);
    }
    printf("\n");
}

void convOctagonal (int valor){
    int count=0;
    int Octagonal[16] = {0};

    printf("\nConvertendo para octagonal...\n");
    while (valor > 0){
        Octagonal[count] = valor%8;
        printf ("%d / 8 = %d, resto = %d\n", valor, valor/8, Octagonal[count]);
        valor = valor/8;
        count++;
    }

    printf("Resultado: ");
    for (int i=15; i>=0; i--){
        printf("%d", Octagonal[i]);
    }
    printf("\n");
}

void convHexadecimal (int valor){
    int count=0;
    char Hexadecimal[16] = {0};

    printf("\nConvertendo para hexadecimal...\n");
    while (valor > 0){

        int resto = valor%16;
        if (resto < 10) {
            Hexadecimal[count] = 48 + resto;
        } else {
            Hexadecimal[count] = 55 + resto;
        }
        printf ("%d / 16 = %d, resto = %d (%c)\n", valor, valor/16, resto, Hexadecimal[count]);
        valor = valor/16;
        count++;
    }

    printf("Resultado: ");
    for (int i=15; i>=0; i--){
        printf("%c", Hexadecimal[i]);
    }
    printf("\n");
}

void convBCD (int valor){
    char Bsc[16][5] = {0};
    int count = 0;

    printf("\nConvertendo para BSC...\n");
    while (valor > 0){
        int elemento = valor%10;

        if (elemento == 0){
            printf("Para o digito %d sera 0000\n", elemento);
            sprintf(Bsc[count], "0000");
        }
        else if (elemento == 1){
            printf("Para o digito %d sera 0001\n", elemento);
            sprintf(Bsc[count], "0001");
        }
        else if (elemento == 2){
            printf("Para o digito %d sera 0010\n", elemento);
            sprintf(Bsc[count], "0010");
        }
        else if (elemento == 3){
            printf("Para o digito %d sera 0011\n", elemento);
            sprintf(Bsc[count], "0011");
        }
        else if (elemento == 4){
            printf("Para o digito %d sera 0100\n", elemento);
            sprintf(Bsc[count], "0100");
        }
        else if (elemento == 5){
            printf("Para o digito %d sera 0101\n", elemento);
            sprintf(Bsc[count], "0101");
        }
        else if (elemento == 6){
            printf("Para o digito %d sera 0110\n", elemento);
            sprintf(Bsc[count], "0110");
        }
        else if (elemento == 7){
            printf("Para o digito %d sera 0111\n", elemento);
            sprintf(Bsc[count], "0111");
        }
        else if (elemento == 8){
            printf("Para o digito %d sera 1000\n", elemento);
            sprintf(Bsc[count], "1000");
        }
        else if (elemento == 9){
            printf("Para o digito %d sera 1001\n", elemento);
            sprintf(Bsc[count], "1001");
        }

        valor = valor/10;
        count++;
    }

    printf("Resultado:\n");
    for (int i=count-1; i>=0; i--){
        printf ("%s ", Bsc[i]);
    }
}

int main (void){
    int valor;
    printf ("Digite o valor a ser convertido: ");
    scanf("%d", &valor);

    convBinario (valor);
    convOctagonal (valor);
    convHexadecimal (valor);
    convBCD (valor);
}