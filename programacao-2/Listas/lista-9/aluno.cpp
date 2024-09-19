#include "pessoa.cpp"

class Aluno:public Pessoa{
    private:
        int numMatricula;
        string endereco;
    public:
        void imprimirAluno(){
            cout<<getNome<<endl;
            cout<<getCpf<<endl;
            cout<<numMatricula<<endl;
            cout<<endereco<<endl;
        }
    int getNumMatricula(){
        return numMatricula;
    }
    void setNumMatricula(int numMatricula){
        this->numMatricula=numMatricula;
    }
    string endereco(){
        return endereco;
    }
    void setEndereco(string endereco){
        this->endereco = endereco;
    }
};