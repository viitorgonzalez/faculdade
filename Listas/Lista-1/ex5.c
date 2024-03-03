#include <stdio.h>
#include "ex5library.c" // To avoid using 'gcc .\ex5.c .\ex5library.c' to compile
#include "ex5library.h"

#define MAX_PROPERTIES 10

int main() {
    Property properties[MAX_PROPERTIES];
    int numProperties = 0, 
        switchChoice = 0, 
        counter = 0,
        value = 0,
        average = 0;

    do {
        printf("\nOpções:\n");
        printf("\n0- Sair");
        printf("\n1- Cadastrar");
        printf("\n2- Mostrar imóveis");
        printf("\n3- Quantidadade de imóveis alugados");
        printf("\n4- Quantidadade de imóveis vendidos");
        printf("\n5- Mostrar imóveis com preço acima do valor a ser digitado");
        printf("\n6- Mostrar imóveis com metragem acima do valor a ser digitado");
        printf("\n7- Mostrar imóveis disponíveis para compra ou aluguel");
        printf("\n8- Mostrar média dos valores das propriedades disponíveis");
        printf("\n9- Quantidade de imóveis com cômodos acima do valor a ser digitado\n");
        printf("\n-> ");

        scanf("%d", &switchChoice);
        getchar();

        switch (switchChoice) {
            case 0:
                printf("\nSaindo...");
                break;

            case 1:
                if(numProperties >= MAX_PROPERTIES) {
                    printf("\nMáximo de propriedades atingido.");
                    break;
                }
                registerProperty(&properties[numProperties]);  
                numProperties++;                  

                break;

            case 2:
                for(int i = 0; i < numProperties; i++) {
                    printf("\nPropriedade %d:\n", i + 1);
                    printProperty(&properties[i]);
                    printf("\n");
                }
                break;
            
            case 3: 
                counter = 0;
                for(int i = 0; i < numProperties; i++) {
                    counter += countRentedProperties(&properties[i]);
                }
                    printf("\nExistem %d imóveis alugados.", counter);
                break;

            case 4:
                counter = 0;
                for(int i = 0; i < numProperties; i++) {
                    counter += countSoldProperties(&properties[i]);
                }
                    printf("\nExistem %d imóveis vendidos.", counter);
                break;

            case 5:
                value = 0;

                printf("\nDigite o valor para que seja impresso os imóveis com valores superiores: ");
                scanf("%d", &value);
                getchar();

                for(int i = 0; i < numProperties; i++) {
                    PropertiesAboveValue(&properties[i], value);
                }
                break;

            case 6:
                value = 0;

                printf("\nDigite o valor para que seja impresso os imóveis com valores superiores (metros): ");
                scanf("%d", &value);
                getchar();

                for(int i = 0; i < numProperties; i++) {
                    propertiesWithSquareFootageAbove(&properties[i], value);
                }
                break;

            case 7:
                for(int i = 0; i < numProperties; i++) {
                    availableProperties(&properties[i]);
                }
                break;

            case 8:
                average = 0;
                counter = 0;

                for(int i = 0; i < numProperties; i++) {
                    if(averageAvailableProperties(&properties[i])) {
                        average += averageAvailableProperties(&properties[i]);
                        counter++;
                    }
                }
                printf("\nMédia: %d", average / counter);
                break;

            case 9:
                value = 0;
                counter = 0;

                printf("\nDigite o valor para que seja impresso os imóveis com valores superiores: ");
                scanf("%d", &value);
                getchar();

                for(int i = 0; i < numProperties; i++) {
                    counter += countPropertiesWithNumberOfRooms(&properties[i], value);
                }
                printf("Existem %d imóveis com mais do que %d cômodos.", counter, value);
                break;

            default:
                printf("Opção inválida.\n");
        }        
    } while (switchChoice != 0);
    
    return 0;
}
