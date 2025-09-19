#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main () {
    string palavra;
    cout << " Bem Vindo ao verificador de palindromos " << endl;
    while (true) {
    cout << " Digite a palavra: ";
    cin >> palavra;
    int tamanho = palavra.length();
    bool palindromo = true;

    for (int i = 0; i < tamanho / 2; i++) {
        if (palavra[i] != palavra[tamanho - 1 - i]) {
            palindromo = false;
            break;
        }
    }

    if (palindromo) {
        cout << " A palavra " << palavra << " é um palindromo " << endl;
    } else {
        cout << " A palavra " << palavra << " não é um palindromo " << endl;
    }
    cout << " Deseja verificar outra palavra? (s/n): ";
    char resposta;
    cin >> resposta;
    if (resposta == 'n' || resposta == 'N') {
        break;
    }
    continue;
    }
    
    system("pause");
    return 0;
}