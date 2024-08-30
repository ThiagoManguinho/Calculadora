#include <stdio.h>

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

    printf("Resultado: ");
    for (int i=count-1; i>=0; i--){
        printf ("%s ", Bsc[i]);
    }
}

void complementoA2 (int valor){
    int Comple2[16] = {0};
    int count = 0;

    while (valor > 0){
        Comple2[count] = valor%2;
        valor = valor / 2;
        count++;
    }
    printf("\nBinario normal: ");
    for (int i = 15; i>=0; i--){
        printf("%d", Comple2[i]);
    }

    int posicaoUm;
    for (int i = 15; i>=0; i--){
        if (Comple2[i] == 1){
            posicaoUm = i;
        }
    }
    
    for (int i = 15; i>posicaoUm; i--){
        if (Comple2[i] == 0){
            Comple2[i] = 1;
        }
        else if (Comple2[i] == 1){
            Comple2[i] = 0;
        } 
    }  

    printf("\nComplemento a 2: ");
    for (int i = 15; i>=0; i--){
        printf("%d", Comple2[i]);
    }
    printf("\n");
}

void TransformandoFloat (float valor){

    int auxValor = (int)valor;
    float DpsVirgula =  valor - auxValor;
    
    printf("Valor depois da virgula: %f\n", DpsVirgula);
    int DpsVirgulaBinario[23] = {0};
    int count = 0;

    while (DpsVirgula != 0 && count <23){
        DpsVirgula = DpsVirgula * 2;
        int INTresultado = (int)DpsVirgula;
        DpsVirgulaBinario[count] = INTresultado;
        DpsVirgula = DpsVirgula - INTresultado;
        count++;
    }

    printf("Valor fracionario da virgula em binario: ");
    for (int i=0; i<count; i++){
        printf("%d", DpsVirgulaBinario[i]);
    }
    printf("\n");



    int valorAntesVIG = (int)valor;
    if (valorAntesVIG < 0){
        valorAntesVIG =  valorAntesVIG * (-1);
    }
    printf("\nValor antes da virgula: %d", valorAntesVIG);;
    int Binario[23] = {0};
    int count2 = 0;
    while (valorAntesVIG > 0){
        Binario[count2] = valorAntesVIG%2;
        valorAntesVIG = valorAntesVIG / 2;
        count2++;
    }
    
    printf("\nValor antes da virgula em binario: ");
    for (int i = 22; i>=0; i--){
        printf("%d", Binario[i]);
    }
    printf("\n");



    int bitSinal;
    if (auxValor > 0){
        bitSinal = 0;
        printf("\nValor positivo, logo bit de sinal sera %d", bitSinal);
    }
    else{
        bitSinal = 1;
        printf("\nValor negativo, logo bit de sinal sera %d", bitSinal);
    }
    printf("\n");



    int expoente = count2 - 1;
    printf ("\nExpoente sem somar com 127: %d", expoente);

    int expoenteCom127 = expoente + 127;
    printf ("\nExpoente com 127 somado: %d", expoenteCom127);

    int BinarioExp[8] = {0};
    int countExp = 0;
    while (expoenteCom127 > 0){
        BinarioExp[countExp] = expoenteCom127%2;
        expoenteCom127 = expoenteCom127 / 2;
        countExp++;
    }
    printf("\nExpoente em binario: ");
    for (int i=7; i>=0; i--){
        printf("%d", BinarioExp[i]);
    }
}

void TransformandoDouble (float valor){

    int auxValor = (int)valor;
    double DpsVirgula =  valor - auxValor;
    
    printf("Valor depois da virgula: %f\n", DpsVirgula);
    int DpsVirgulaBinario[52] = {0};
    int count = 0;

    while (DpsVirgula != 0 && count <52){
        DpsVirgula = DpsVirgula * 2;
        int INTresultado = (int)DpsVirgula;
        DpsVirgulaBinario[count] = INTresultado;
        DpsVirgula = DpsVirgula - INTresultado;
        count++;
    }

    printf("Valor fracionario da virgula em binario: ");
    for (int i=0; i<count; i++){
        printf("%d", DpsVirgulaBinario[i]);
    }
    printf("\n");



    int valorAntesVIG = (int)valor;
    if (valorAntesVIG < 0){
        valorAntesVIG =  valorAntesVIG * (-1);
    }
    printf("\nValor antes da virgula: %d", valorAntesVIG);;
    int Binario[52] = {0};
    int count2 = 0;
    while (valorAntesVIG > 0){
        Binario[count2] = valorAntesVIG%2;
        valorAntesVIG = valorAntesVIG / 2;
        count2++;
    }
    
    printf("\nValor antes da virgula em binario: ");
    for (int i = 51; i>=0; i--){
        printf("%d", Binario[i]);
    }
    printf("\n");



    int bitSinal;
    if (auxValor > 0){
        bitSinal = 0;
        printf("\nValor positivo, logo bit de sinal sera %d", bitSinal);
    }
    else{
        bitSinal = 1;
        printf("\nValor negativo, logo bit de sinal sera %d", bitSinal);
    }
    printf("\n");



    int expoente = count2 - 1;
    printf ("\nExpoente sem somar com 1023: %d", expoente);

    int expoenteCom127 = expoente + 1023;
    printf ("\nExpoente com 1023 somado: %d", expoenteCom127);

    int BinarioExp[11] = {0};
    int countExp = 0;
    while (expoenteCom127 > 0){
        BinarioExp[countExp] = expoenteCom127%2;
        expoenteCom127 = expoenteCom127 / 2;
        countExp++;
    }
    printf("\nExpoente em binario: ");
    for (int i=10; i>=0; i--){
        printf("%d", BinarioExp[i]);
    }
}


int main (void){
    int valor, escolha;
    float valorF;

    printf("Faca a sua escolha\n");
    printf("(1) Converter o valor em base [2, 8 16, BSC] e Complemento a 2\n");
    printf("(2) Convertendo valor em float e double\nEscolha: ");
    scanf ("%d", &escolha);

    if (escolha == 1){
        printf ("Digite o valor desejado: ");
        scanf ("%d", &valor);
        printf ("-==-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
        convBinario (valor);
        convOctagonal (valor);
        convHexadecimal (valor);
        convBCD (valor);

        printf("\n");
        complementoA2 (valor);
        printf ("-==-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
    }
    else {
        printf ("Digite o valor desejado: ");
        scanf ("%f", &valorF);
        printf ("-==-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
        TransformandoFloat (valorF);
        printf ("\n-==-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
        TransformandoDouble (valorF);
    }   
}