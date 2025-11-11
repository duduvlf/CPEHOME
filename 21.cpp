#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>    

using namespace std;
int main(){
srand((time(0)));
int numeroaleatorio = 0;
int J, K, Q = 10;
int A = 1;
int resposta;
int rodadas = 1;
int soma = 0; // alt + setinha p cima ou p baixo
cout << "Bem-vindo ao jogo do 21!" << endl;
while (resposta != 2){
    
cout << "Rodada " << rodadas << endl;
cout << "Apostar o" << rodadas<< "° número: " << endl; // trocar o "primeiro número" pelo número de rodadas
cout << "1- Sim ou 2-Não?" << endl;
cin >> resposta;
switch (resposta) {
    case 1:
    numeroaleatorio = rand() % 10 + 1;
    if (numeroaleatorio == 10 || numeroaleatorio == 1){
        int n = rand () % 4 + 1;
        if (n == 0) {
            numeroaleatorio = J;
        } else if (n == 1) {
            numeroaleatorio = K;
        } else if (n == 2) {
            numeroaleatorio = Q;
        } else {
            numeroaleatorio = 10;
        }
        if (numeroaleatorio == 1){
            numeroaleatorio = A;
        }
    }
    soma += numeroaleatorio;
    cout << "Número sorteado: " << numeroaleatorio << endl;
    cout << "Soma atual: " << soma << endl;
    if (soma > 21){
        cout << "Você perdeu! Sua soma ultrapassou 21." << endl;
        break;
    }
    else if (soma == 21){
        cout << "Parabéns! Você ganhou!" << endl;
        break;
    }
    cout << "----------------------------------" << endl;
    cout << "deseja jogar novamente?" << endl;
    cout << "1- Sim ou 2-Não?" << endl;
    cin >> resposta;
    break;
  case 2: 
  cout << "acabou" << endl;
  break;
}
rodadas++;
}
system("pause");
return 0;
}