#include <iostream>

const int TAM = 50;

int main() {
  using namespace std;

  int arr[TAM], countPar = 0, countCinco = 0;

  cout << "Digite um vetor de insteiros positivos:" << endl;
  for(int i = 0; i < TAM; i++) {
    cin >> arr[i];
  }

  for(int i = 0; i < TAM; i++) {
    countPar += ((arr[i] % 2 == 0)) ? 1 : 0;
    countCinco += ((arr[i] % 5 == 0)) ? 1 : 0;

  }

  cout << countPar << endl;
  cout << countCinco;

  return 0;
}
