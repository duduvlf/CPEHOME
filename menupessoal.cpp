#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>
using namespace std;
long long int codigo[50];
string nomedoproduto[50];
int pesquisarproduto;
int i=0;

int cadastrarproduto() {
    cout << "Para cadastrar o produto, digite seu código." << endl;
    cin >> codigo[i];
    cout << "Para cadastrar o produto, digite seu nome." << endl;
    getline (cin >> ws, nomedoproduto[i]);
    cout << "Produto cadastrado com sucesso!" << endl;
    i++;
}

int procurarproduto() {
    cout << "Digite o código do produto" << endl;
    cin >> pesquisarproduto;
    bool encontrado = false;
    for (int k = 0; k < i; k++) {
        if (pesquisarproduto == codigo[k]) {
            cout << "------------------------------------" << endl;
            cout << "Produto encontrado!" << endl;
            cout << "Código: " << codigo[k] << endl;
            cout << "Nome: " << nomedoproduto[k] << endl;
            cout << "------------------------------------" << endl;

            encontrado = true;
            break;
        } } if (!encontrado) {
            cout << "Produto não encontrado." << endl;
            
        }
    return 0;

}
int listarprodutos() {
    for (int j=0; j<i; j++) {


cout << "------------------------------------" << endl;
cout << "Código: " << codigo[j] << endl;
cout << "Nome: " << nomedoproduto[j] << endl;
cout << "------------------------------------" << endl;

    }
    return 0;

}

int main(){
    setlocale(LC_ALL, "");
    int opcao;

    while (true){
        cout << "================MENU================" << endl;
        cout << "1 - Cadastrar Produto" << endl;
        cout << "2 - Procurar Produto" << endl;
        cout << "3 - Listar Produtos" << endl;
        cout << "0 - Sair" << endl;
        cout << "====================================" << endl;
        cin >> opcao;

        switch (opcao) {
        case 1:
            cadastrarproduto();
            break;
        case 2:
            procurarproduto();
            break;
        case 3:
            listarprodutos();
            break;
        case 0:
            cout << "Saindo do programa." << endl;
            return 0;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
           return 0;
        }
    system("pause");
    system("cls");
    }
    return 0;
}