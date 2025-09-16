#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
    int main () {
    string palavra;
  cout << " Bem Vindo a forca " << endl;
  cout << " Digite a palavra secreta: ";
  cin >> palavra;

system ("cls");

    int qntdel = palavra.length ();
    cout << " A palavra tem " << qntdel << " letras " << endl;

   
        string chute; // armazena palavra 
        int acertos = 0; // conta acertos  
        cout << " Vamos começar o jogo " << endl;
         while  (true) { // começa o loop
        cout << " Digite uma letra: ";
        cin >> chute;
       chute[0] = tolower(chute[0]);
        bool tem = false; // variavel de controle
        for (int i=0; i < qntdel; i++) { // verifica letra por letra
            if (chute[0] == palavra[i]) {
                tem = true; // se a letra estiver na palavra
                acertos++; // conta o acerto
            }
         }  // loop for, verifica letra por letra
         if (tem) {

cout << " Acertou uma letra! " << endl;
cout << " Você já acertou " << acertos << " letras. " <<endl;
if (qntdel - acertos > 0) {
cout << " Ainda restam: " << qntdel - acertos << " letras "<< endl; 
 } } else {
cout << " Errou! Tente novamente " << endl;
cout << " Você já acertou " << acertos << " letras " << "Ainda restam:" << qntdel - acertos <<endl; 
                 }
        if (acertos == qntdel) { // se acertar todas as letras
            cout << " Parabéns! Você ganhou! A palavra era " << palavra << endl;
            break; // sai do loop
                 
            }
    




            
        } 
        system ("pause");
        return 0;

    }