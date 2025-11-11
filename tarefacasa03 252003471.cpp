// Eduardo Augusto - 252003471

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
int opcao;

cout << "Digite o tamanho da matriz (N x N): ";
cout << "A matriz deve entre 1 e 10" << endl;
int n;
int linha, coluna;
n = linha = coluna = 0;
cin >> n;
 for (linha = 1; linha <= n; linha++) {
    for (coluna = 1; coluna <= n; coluna++) { // o for percorre as colunas e as linhas da matriz, para ler os valores
        cout << char(176) << char(176); // Preto "░░"
        cout << char(219) << char(219); // Branco "██"    ,,  os caracteres sao representados por seus codigos 
    }
    cout << endl;
 }
 system("pause");
 while (true) {

 cout << "=================MENU================" << endl;
 cout << "1 - Inverter as cores" << endl;
 cout << "2 - Mostrar matriz transposta" << endl;
 cout << "3 - Contar pixels" << endl; 
 cout << "4 - Desenhar uma moldura:" << endl;
 cout << "5 - Sair" << endl;
 cout << "====================================" << endl;
    cin >> opcao;
    switch (opcao) {
        case 1:
            cout << "Inverter as cores selecionado." << endl;
             for (linha = 1; linha <= n; linha++) {
    for (coluna = 1; coluna <= n; coluna++) {
        cout << char(219) << char(219); // Branco "██"
        cout << char(176) << char(176); // Preto "░░"
    }
    cout << endl;
 }
            break;
        case 2:
            cout << "Mostrar matriz transposta selecionado." << endl;
            for (coluna = 1; coluna <= n; coluna++) {
    for (linha = 1; linha <= n; linha++) {
        cout << char(176) << char(176); // Preto "░░"
        cout << char(219) << char(219); // Branco "██"
    }
    cout << endl;
 }
            break;
        case 3:
            cout << "Contar pixels selecionado." << endl;
            cout << "Total de pixels: " << n * n << endl;
            cout << "Pixels pretos: " << (n * n) / 2 << endl;
            cout << "Pixels brancos: " << (n * n) / 2 << endl;
            break;
        case 4:
            cout << "Desenhar uma moldura selecionado." << endl;
            for (linha = 1; linha <= n; linha++) {
    for (coluna = 1; coluna <= n; coluna++) {
        if (linha == 1 || linha == n || coluna == 1 || coluna == n) {
            cout << char(219) << char(176); // Branco "██" // borda externa
        } else {
            cout << char(176) << char(219); // Preto "░░" // preenchimento interno
        }
    } 
    cout << endl;
    }
            break;
        case 5:
            cout << "Saindo do programa." << endl;
            return 0;
        default: // caso o usuario digite um numero invalido
            cout << "Opção inválida. Tente novamente." << endl;
            continue;
    }
    system ("pause");
    system("cls");
    }
    return 0;

}