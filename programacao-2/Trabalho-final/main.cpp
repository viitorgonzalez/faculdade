#include "CadastroNota.cpp"
#include "CadastroFalta.cpp"

#include "Utils.cpp"

#include <fstream>

int main() {
    Utils utils;

    Aluno aluno[3] = {
        {"André", 0},
        {"Diogo", 1},
        {"Vítor", 2}
    };

    Disciplina disciplina[1] = {
        {"Programação 2", "Ciência da Computação"},
    };

    Nota turmaNotas[3] = {
        {aluno[0], disciplina[0]},
        {aluno[1], disciplina[0]},
        {aluno[2], disciplina[0]}
    };

    Falta turmaFaltas[3] = {
        {aluno[0], disciplina[0]},
        {aluno[1], disciplina[0]},
        {aluno[2], disciplina[0]}
    };

    int opPrincipal, opNotas;
    float n = 0;
    string dataFalta;
    int contFaltas = 0;

    int matriculaAluno;
    string nomeAluno;

    ifstream arquivoL;
    ofstream arquivoE;

    string linha = "";

    do {
        utils.menuPrincipal();
        cin >> opPrincipal;

        switch (opPrincipal) {
            case 1:
                cout << "Digite a matrícula do aluno:" << endl;
                cin >> matriculaAluno;

                do {
                    utils.menuNotas();
                    cin >> opNotas;

                    switch (opNotas) {
                        case 1: 
                            cout << "Digite a nota: " << endl;
                            cin >> n;

                            if((n < 0) || (n > 10)) {
                                cout << endl << "Nota inválida." << endl;
                                break;
                            }

                            turmaNotas[matriculaAluno].setN1(n);
                            n = 0;
                            break;

                        case 2: 
                            cout << "Digite a nota: " << endl;
                            cin >> n;

                            if((n < 0) || (n > 10)) {
                                cout << endl << "Nota inválida." << endl;
                                break;
                            }

                            turmaNotas[matriculaAluno].setN2(n);
                            n = 0;
                            break;
                            
                        case 3: 
                            cout << "Digite a nota: " << endl;
                            cin >> n;

                            if((n < 0) || (n > 10)) {
                                cout << endl << "Nota inválida." << endl;
                                break;
                            }

                            turmaNotas[matriculaAluno].setN3(n);
                            n = 0;
                            break;

                        case 4: 
                            nomeAluno = turmaNotas[matriculaAluno].getAluno().getNome();
                            arquivoE.open((nomeAluno + "-Notas" + ".csv").c_str(), ios::out);
                            if (arquivoE.is_open()) {
                                arquivoE << 
                                    turmaNotas[matriculaAluno].getAluno().getNome() << "," <<
                                    turmaNotas[matriculaAluno].getAluno().getMatricula() << "," <<
                                    turmaNotas[matriculaAluno].getDisciplina().getMateria() << "," <<
                                    turmaNotas[matriculaAluno].getDisciplina().getCurso() << "," <<
                                    turmaNotas[matriculaAluno].getN1() << "," <<
                                    turmaNotas[matriculaAluno].getN2() << "," <<
                                    turmaNotas[matriculaAluno].getN3() << "\n";
                            }
                            arquivoE.close();
                            break;
                        
                        case 0: 
                            cout << "Voltando.." << endl;
                            continue;

                        default:
                            cout << "Opção inválida! Escolha uma opção válida." << endl;
                            break;
                    }
                } while (opNotas != 0);
                break;

            case 2: 
                cout << endl << "Digite a matrícula do aluno:" << endl;
                cin >> matriculaAluno;

                nomeAluno = turmaNotas[matriculaAluno].getAluno().getNome();

                arquivoL.open((nomeAluno + "-Notas" + ".csv").c_str(), ios::in);
                
                if (arquivoL.good()) {
                    while (getline(arquivoL, linha)) {
                        cout << endl << linha << endl;
                    }
                    arquivoL.close();
                } else {
                    cout << endl << "O arquivo \"" << nomeAluno + "-Notas" + ".csv" << "\" não existe." << endl;
                }
                break;

            case 3:
                cout << "Digite a matrícula do aluno:" << endl;
                cin >> matriculaAluno;

                cout << "Digite a data da falta (DD/MM/AAAA):" << endl;
                cin >> dataFalta;

                if (!utils.isValidDate(dataFalta)) {
                    cout << "Data inválida!" << endl;
                    break;
                }

                turmaFaltas[matriculaAluno].getData()[contFaltas] = dataFalta;
                contFaltas++;
                nomeAluno = turmaFaltas[matriculaAluno].getAluno().getNome();  

                arquivoE.open((nomeAluno + "-Faltas" + ".csv").c_str(), ios::out);
                if(arquivoE.is_open()) {
                    arquivoE << 
                        turmaFaltas[matriculaAluno].getAluno().getNome() << "," <<
                        turmaFaltas[matriculaAluno].getAluno().getMatricula() << "," <<
                        turmaFaltas[matriculaAluno].getDisciplina().getMateria() << "," <<
                        turmaFaltas[matriculaAluno].getDisciplina().getCurso() << ",";
                }
                        
                if(arquivoE.is_open()) {
                    for(int i = 0; i < 10; i++) {
                        if(turmaFaltas[matriculaAluno].getData()[i] != "") {
                            arquivoE << turmaFaltas[matriculaAluno].getData()[i] << ",";
                        }
                    }
                }

                arquivoE.close();
                break;

            case 4:
                cout << "Digite a matrícula do aluno:" << endl;
                cin >> matriculaAluno;

                nomeAluno = turmaFaltas[matriculaAluno].getAluno().getNome();
               arquivoL.open((nomeAluno + "-Faltas" + ".csv").c_str(), ios::in);
                
                if (arquivoL.good()) {
                    while (getline(arquivoL, linha)) {
                        cout << endl << linha << endl;
                    }
                    arquivoL.close();
                } else {
                    cout << endl << "O arquivo \"" << nomeAluno + "-Faltas" + ".csv" << "\" não existe." << endl;
                }
                break;

            case 0: 
                cout << "Saindo...";
                return 1;
                
            default:
                cout << "Opção inválida! Escolha uma opção válida." << endl;
        }
    } while (opPrincipal != 0);

    return 0;
}
