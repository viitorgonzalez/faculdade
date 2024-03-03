#include "ex5library.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void registerProperty(Property *prop) {
    printf("\nDigite o endereço do imóvel: ");
    fgets(prop->propertyAddress, sizeof(prop->propertyAddress), stdin);
    prop->propertyAddress[strcspn(prop->propertyAddress, "\n")] = '\0';

    printf("\nDigite o valor do imóvel: ");
    scanf("%d", &prop->propertyValue);
    getchar();

    printf("\nDigite o valor de aluguel do imóvel: ");
    scanf("%d", &prop->rentValue);
    getchar();

    printf("\nDigite a quantidade de cômodos existentes no imóvel: ");
    scanf("%d", &prop->roomsNumber);
    getchar();

    printf("\nDigite a metragem quadrada do imóvel(metros): ");
    scanf("%f", &prop->squareFootage);
    getchar();

    printf("\nDigite o status do imóvel(Alugado, Vendido ou Disponível): ");
    fgets(prop->status, sizeof(prop->status), stdin);
    prop->status[strcspn(prop->status, "\n")] = '\0'; 
}

void printProperty(Property *prop) {
    printf("\nEndereço: %s", prop->propertyAddress);
    printf("\nValor: %d", prop->propertyValue);
    printf("\nValor do aluguel: %d", prop->rentValue);
    printf("\nQuantidade de cômodos: %d", prop->roomsNumber);
    printf("\nMetragem quadrada: %.2f", prop->squareFootage);
    printf("\nStatus: %s\n", prop->status);
}

int countRentedProperties(Property *prop) {
    for (int i = 0; prop->status[i]; i++) {
        prop->status[i] = tolower(prop->status[i]);
    }
    return (strcmp(prop->status, "alugado") == 0) ? 1 : 0;
}

int countSoldProperties(Property *prop) {
    for (int i = 0; prop->status[i]; i++) {
        prop->status[i] = tolower(prop->status[i]);
    }
    return (strcmp(prop->status, "vendido") == 0) ? 1 : 0;
}

void PropertiesAboveValue(Property *prop, float value) {
    if(value < prop->propertyValue)
        printProperty(prop);
}

void propertiesWithSquareFootageAbove(Property *prop, float meters) {
    if(meters < prop->squareFootage)
        printProperty(prop);
}

void availableProperties(Property *prop) {
    for (int i = 0; prop->status[i]; i++) {
        prop->status[i] = tolower(prop->status[i]);
    }

    if(strcmp(prop->status, "disponivel") == 0 || strcmp(prop->status, "disponível") == 0) {
        printProperty(prop);
    }
}

float averageAvailableProperties(Property *prop) {
    return (strcmp(prop->status, "disponivel") == 0 || strcmp(prop->status, "disponível") == 0) ? prop->rentValue : 0;
}

int countPropertiesWithNumberOfRooms(Property *prop, int rooms) {
    return (rooms < prop->roomsNumber) ? 1 : 0;
}