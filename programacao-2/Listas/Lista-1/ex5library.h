#ifndef EX5LIBRARY_H
#define EX5LIBRARY_H

typedef struct {
    char propertyAddress[50];
    int propertyValue;
    int rentValue;
    int roomsNumber;
    float squareFootage;
    char status[11];
} Property;

void registerProperty(Property *prop);

void printProperty(Property *prop);

int countRentedProperties(Property *prop);

int countSoldProperties(Property *prop);

void PropertiesAboveValue(Property *prop, float value);

void propertiesWithSquareFootageAbove(Property *prop, float meters);

void availableProperties(Property *prop);

float averageAvailableProperties(Property *prop);

int countPropertiesWithNumberOfRooms(Property *prop, int rooms);

#endif