#include <iostream>

int main() {
  using namespace std;

  int tam = 0, count = 0;

  cout  << "Digite o tamanho do vetor" << endl;
  cin >> tam;

  int *arr = new int[tam];

  cout << "Digite o vetor:" << endl;
  for(int i = 0; i < tam; i++) {
    cin >> arr[i];
  }

  cout << "Soma:" << endl;
  for(int i = 0; i < tam; i++) {
    cout << arr[i] << endl;
    count += ((arr[i] % 2) != 0) ? arr[i] : 0;
  }

  cout << count;

  return 0;
}
