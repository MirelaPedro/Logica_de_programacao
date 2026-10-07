#include <stdio.h>

#define STRING 100

int main(){
    char var_string[STRING];
    int index = 0;
    
    do{
        scanf("%c", &var_string[index]);
        getchar();

        index++;

    } while(var_string[index-1] != '\n'); //o \n representa o enter no c

    var_string[index-1] = '\0';
    
    printf("%s\n", var_string);
    return 0;
}

//String é um vetor especial de caracters
/*for (int i = 0; i < index; i++){
    printf("%c", var_string[i]);
}*/
