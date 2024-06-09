#include <iostream>
#include <string>

using namespace std;

class Utils {
    public:
        Utils() {}

        void menuPrincipal() {
            cout << endl << "Selecione: " << endl;
            cout << "0- Sair " << endl;
            cout << "1- Cadastrar nota: " << endl;
            cout << "2- Consultar notas: " << endl;
            cout << "3- Cadastrar falta: " << endl;
            cout << "4- Consultar faltas: " << endl;
        }

        void menuNotas() {
            cout << endl << "Selecione qual nota deseja registrar: " << endl;
            cout << "0- Voltar " << endl;
            cout << "1- N1: " << endl;
            cout << "2- N2: " << endl;
            cout << "3- N3: " << endl;
            cout << "4- Salvar " << endl;
        }

        bool isBissexto(int ano) {
            return ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));
        }

        bool isValidDate(string date) {
            if (date.length() != 10)
                return false;

            if (date[2] != '/' || date[5] != '/')
                return false;

            int dia, mes, ano;
            try {
                dia = stoi(date.substr(0, 2));
                mes = stoi(date.substr(3, 5));
                ano = stoi(date.substr(6, 10));
            } catch (...) {
                return false;
            }

            if (mes < 1 || mes > 12)
                return false;

            if (dia < 1)
                return false;

            if (mes == 2) {
                if (isBissexto(ano)) {
                    if (dia > 29)
                        return false;
                } else {
                    if (dia > 28)
                        return false;
                }
            } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
                if (dia > 30)
                    return false;
            } else {
                if (dia > 31)
                    return false;
            }

            return true;
        }
};
