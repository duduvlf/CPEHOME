// a ideia é fazer uma calculadora que mostre se o número é par ou ímpar
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

int x;
char opcao;

    do {
cout << "Escolha um número : " "\n";
 cin >> x;


// O operador módulo (%) em C++ retorna o resto da divisão entre dois números inteiros.


    if (x % 2 == 0) {
        cout << x << " é par\n";
    } else {
        cout << x << " é ímpar\n";
    }
     cout << "Deseja testar outro número? (s/n): ";
        cin >> opcao;
    } while (opcao == 's' || opcao == 'S');


system("pause");
    return 0;

    }
// char opcao; cria uma variável para guardar a escolha do usuário.
//do { ... } while (...); repete o bloco enquanto a condição for verdadeira.