#include <stdio.h>

// PROTÓTIPO
void mostrar_abacaxi();


int abacaxi = 100;

int main()
{
    printf("Quanto gosta de abacaxi: %i\n", abacaxi);

    mostrar_abacaxi(abacaxi);

    return 0;
}

// INTEGRAÇÃO
void mostrar_abacaxi()
{
    int abacaxi = 3;
    abacaxi++;
    printf("Quanto gosta de abacaxi (dentro do mostra): %i\n", abacaxi);
}

