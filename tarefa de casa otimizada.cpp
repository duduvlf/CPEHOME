#include <iostream>
#include <stdlib.h>
// EDUARDO AUGUSTO - RA 252003471 - TAREFA DE CASA 01
using namespace std;

int main() {    

    // Exercício 01 
    int numeros[5]; // criei 5 variáveis inteiras

    cout << "digite 5 números inteiros entre 0 a 25 (0=A, 25=Z): " << endl; //mostra a mensagem na tela
   for ( int i = 0; i < 5; i++ ) { // laço de repetição para ler os 5 números
   cin >> numeros[i]; // aqui o usuário digita os números
   }
for ( int i = 0; i < 5; i++ ) {
if ( numeros[i] < 0 || numeros[i] > 25 )  { 
  cout << "número inválido" << endl;
  system("pause");
  return 1; 
}
} 
 cout << "As letras correspondentes são: ";
    for (int i = 0; i < 5; i++) {
        cout << char('A' + numeros[i]);
        if (i < 4) cout << ", ";
    }
    cout << endl;
     
// Exercício 02
char letra[5]; { // criei 5 variáveis do tipo char para armazenar as letras
int deslocamento; {

cout << "Digite uma sequencia de 5 letras: " << endl;
for ( int i = 0; i < 5; i++ ) { // laço de repetição para ler as 5 letras
cin >> letra[i]; // aqui o usuário digita as letras
}
cout << "Digite o valor do deslocamento (1 a 7): " << endl;
cin >> deslocamento;
if (deslocamento < 1 || deslocamento > 7) { // condição para verificar se o deslocamento está entre 1 e 7
    cout << "Valor de deslocamento inválido." << endl;
    system("pause");
    return 1; // aqui o programa termina com erro, pois foi digitado um número fora das condições
    } else {
    cout << "Codigo Criptografado: ";
for (int i = 0; i < 5; i++) {
    cout << char('A' + ((toupper(letra[i]) - 'A' + deslocamento) % 26));
} 
   cout << endl; 

        // o toupper é para converter letras minúsculas em maiúsculas 
    // "toupper(letra1) - 'A' " converte a letra em um número entre 0 e 25 
    // o + deslocamento é para aplicar o deslocamento
    // o % 26 é para garantir que o resultado fique entre 0 e 25
    // 
    }
    {
        cout << "para ver o código descriptografado:" << endl;
        system("pause");
    cout << "Codigo Descriptografado: ";
    for (int i = 0; i < 5; i++) {

    cout << char('A' + ((toupper(letra[i] + deslocamento) - 'A' - deslocamento + 26) % 26)) ; 
    }
    cout << endl;
       // o +26 é para evitar números negativos no cálculo do módulo
       // "toupper(letra1 + deslocamento) - 'A' " converte a letra em um número entre 0 e 25
       // o - deslocamento é para aplicar o deslocamento inverso

        
         }}
system("pause");
return 0;
}
}