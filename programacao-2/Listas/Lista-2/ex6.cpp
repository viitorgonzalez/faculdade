#include <iostream>

using namespace std;

int tipoTriangulo(int a, int b, int c) {
    if((a + b < c) || (b + c < a) || a + c < b) 
        return 0;

    if((a == b) && (b ==c)) 
        return 1;

    if((a == b) || (a ==c) || (b == c))
        return 2;

    return 3;
}

int main() {
    float a = 0, b = 0, c = 0;
    int choice = 0;

    do {

        cout << "Digite o valor do lado: " << endl;
        cin >> a;

        cout << "Digite o valor do lado: " << endl;
        cin >> b;

        cout << "Digite o valor do lado: " << endl;
        cin >> c;

        cout << "Resultado: " << tipoTriangulo(a, b, c);

        cout << endl << "Digite (-1) caso queira sair ou qualquer outro número para continuar: " << endl;
        cin >> choice;

    } while (choice != -1);



    return 0;
}
