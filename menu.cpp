#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>
using namespace std;
int main(){

setlocale(LC_ALL, "");
int i=0;
string nomedoproduto[50];
long long int codigo[50];
int opcao;
int procurarproduto;
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
            cout << "Para Cadastrar Produto, insira os detalhes do produto." << endl;
            cout << "Digite o código do produto: ";
            cin.ignore(); // Limpa o buffer do cin
            cin >> codigo[i];
            cout << "Digite o nome do produto: ";
            cin.ignore();
            getline(cin, nomedoproduto[i]);
            cout << "Produto cadastrado com sucesso!" << endl;
            i++;
            break;
case 2:
            cout << "Para Procurar um Item, insira o codigo do produto." << endl;
            cout << "Digite o codigo do produto: ";
            cin >> procurarproduto;

            bool encontrado = false; 

            // 2. Loop para percorrer TODOS os produtos já cadastrados (de 0 até i-1).
            for (int k = 0; k < i; k++) {
                // 3. Compara o código procurado com o código na posição ATUAL do loop.
                if (procurarproduto == codigo[k]) {
                    cout << "------------------------------------" << endl;
                    cout << "Produto encontrado!" << endl;
                    cout << "Código: " << codigo[k] << endl;
                    cout << "Nome: " << nomedoproduto[k] << endl;
                    cout << "------------------------------------" << endl;
                    
                    encontrado = true;
                    break; 
                }
            }
            if (!encontrado) { // Se 'encontrado' ainda for 'false'
                cout << "Produto não encontrado." << endl;
            }
            break;
case 3:
            cout << "Esses são os produtos cadastrados:" << endl;
            for (int j = 0; j < i; j++) {
                cout << "Código: " << codigo[j] << ", Nome: " << nomedoproduto[j] << endl;
            }
            break;
 case 0:
            cout << "Saindo..." << endl;
            return 0;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
    }
    system("pause");
    system("cls");


} return 0;
}