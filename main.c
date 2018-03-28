#include <stdio.h>
#include <stdlib.h>
#include "sha-256.h"

int main() {
    int i,ch;
    char string[3000]={'\0'};
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("inputFile.txt", "rb");

    if(inputFile == NULL){
        printf("Deu ruim");
        return 1;
    }
    i = 0;
    while (i < sizeof(string)-1 && EOF !=(ch=fgetc(inputFile))){
        string[i++] = ch;
    }
    printf("inputFile:\n%s", string);

    fclose(inputFile);

    outputFile = fopen("outputFile.txt", "wb");
    int result = fputs(string, outputFile);
    if(result == EOF){
        printf("Deu ruim");
        return 1;
    }

    fclose(outputFile);

  return 0;
}
