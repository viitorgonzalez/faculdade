#include <iostream>
#include <string>

int main() {

  int count = 1;
  std::string text;

  std::cout << "Digite uma frase:" << std::endl;
  std::getline(std::cin, text);

  for(int i = 0; i < text.size(); i++) {
    count += (text[i] == ' ') ? 1 : 0;
  }

  std::cout << count;

  return 0;
}
