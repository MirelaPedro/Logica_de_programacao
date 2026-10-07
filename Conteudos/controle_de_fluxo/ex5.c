#include <stdio.h>

int main(){
    int segundos, horas, minutos;

    printf("Segundos: ");
    scanf("%i", &segundos);

    //Verificando se não há maios de 24 horas
    if(segundos >= 86400){
        printf("Um dia não pode ter mais de 24 hrs\n");
        return 0;
    }

    minutos = segundos/60;
    segundos = segundos%60; //Pegando os segundos que sobram do dia

    horas = minutos/60;
    minutos = minutos%60; //Pegando os minutos que sobram


    printf("%i:%i:%i", horas, minutos, segundos);    
    printf("\n");

    return 0;
}