#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {    

    // Exercício 01 
    int numeros1, numeros2, numeros3, numeros4, numeros5; { // criei 5 variáveis inteiras

    cout << "digite 5 números inteiros entre 0 a 25 (0=A, 25=Z): " << endl; //mostra a mensagem na tela
    cin >> numeros1 >> numeros2 >> numeros3 >> numeros4 >> numeros5; // aqui o usuário digita os números

if ( numeros1 < 0 || numeros1 > 25 || numeros2 < 0 || numeros2 > 25 || numeros3 < 0 || numeros3 > 25 || numeros4 < 0 || numeros4 > 25 || numeros5 < 0 || numeros5 > 25 ) { // condição para verificar se os números estão entre 0 e 25
  cout << "número inválido" << endl;
  system("pause");
  return 1; // aqui o programa termina com erro, pois foi digitado um número dentro das condições
} else { // se os números estiverem dentro das condições, o programa continua
    cout << "as letras correspondentes são: ";
cout << char(('A' + numeros1)) << ","
     << char(('A' + numeros2))<< ","
     << char(('A' + numeros3)) << ","
     << char(('A' + numeros4)) << ","
     << char(('A' + numeros5))  << endl; // utilizar o char para converter o número em caractere 
     // 'A' + numero converte o número em letra (0=A, 1=B, 2=C, ..., 25=Z)
     // 'A' é o valor ASCII da letra A, que é 65 e deixa o valor do número entre 0 e 25
     }
}
// Exercício 02
char letra1, letra2, letra3, letra4, letra5; { // criei 5 variáveis do tipo char para armazenar as letras
int deslocamento; {

cout << "Digite uma sequencia de 5 letras: " << endl;
cin >> letra1 >> letra2 >> letra3 >> letra4 >> letra5;
cout << "Digite o valor do deslocamento (1 a 7): " << endl;
cin >> deslocamento;
if (deslocamento < 1 || deslocamento > 7) { // condição para verificar se o deslocamento está entre 1 e 7
    cout << "Valor de deslocamento inválido." << endl;
    system("pause");
    return 1; // aqui o programa termina com erro, pois foi digitado um número fora das condições
    } else {
    cout << "Codigo Criptografado: ";
    cout << char('A' + ((toupper(letra1) - 'A' + deslocamento) % 26)) << ","
       << char('A' + ((toupper(letra2) - 'A' + deslocamento) % 26)) << ","
         << char('A' + ((toupper(letra3) - 'A' + deslocamento) % 26)) << ","
        << char('A' + ((toupper(letra4) - 'A' + deslocamento) % 26)) << ","
        << char('A' + ((toupper(letra5) - 'A' + deslocamento) % 26)) << endl; 
        // o toupper é para converter letras minúsculas em maiúsculas 
    // "toupper(letra1) - 'A' " converte a letra em um número entre 0 e 25 
    // o + deslocamento é para aplicar o deslocamento
    // o % 26 é para garantir que o resultado fique entre 0 e 25
    // 

        cout << "para ver o código descriptografado:" << endl;
        system("pause");
    cout << "Codigo Descriptografado: ";
    cout << char('A' + ((toupper(letra1 + deslocamento) - 'A' - deslocamento + 26) % 26))
       << char('A' + ((toupper(letra2 + deslocamento) - 'A' - deslocamento + 26) % 26)) 
        << char('A' + ((toupper(letra3 + deslocamento) - 'A' - deslocamento + 26) % 26)) 
       << char('A' + ((toupper(letra4 + deslocamento) - 'A' - deslocamento + 26) % 26))
       << char('A' + ((toupper(letra5 + deslocamento) - 'A' - deslocamento + 26) % 26)) << endl; 
       // o +26 é para evitar números negativos no cálculo do módulo
       // "toupper(letra1 + deslocamento) - 'A' " converte a letra em um número entre 0 e 25
       // o - deslocamento é para aplicar o deslocamento inverso

        
         }}}
system("pause");
return 0;
}