// Eduardo Augusto - 252003471
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



const int MAX_TAM = 10;

int main() {
    int opcao;
    srand (time(NULL));
    
    cout << "Digite o tamanho da matriz (N x N): ";
    cout << "A matriz deve entre 1 e 10" << endl;
    
    int n;
    int linha, coluna;
    // n = linha = coluna = 0; // Esta linha não é estritamente necessária
    
    char preto = char(176); // caractere para representar pixel preto
    char branco = char(219); // caractere para representar pixel branco
    int qntdepreto = 0;
    int qntdebranco = 0;
    
    cin >> n;

   
    while (n < 1 || n > MAX_TAM) {
        cout << "Tamanho invalido. Digite um valor entre 1 e " << MAX_TAM << ": ";
        cin >> n;
    }

 
    int matriz[MAX_TAM][MAX_TAM]; 

   
    // Seu código original só preenchia a posição [0][0]
    for (linha = 0; linha < n; linha++) {
        for (coluna = 0; coluna < n; coluna++) {
            matriz[linha][coluna] = rand() % 2;
        }
    }



    while (true) {
       
        for (int linha = 0; linha < n; linha++) {
            for (int coluna = 0; coluna < n; coluna++) {
                if (matriz[linha][coluna] == 0) {
                    cout << preto << preto;
                } else {
                    cout << branco << branco;
                }
            }
            cout << endl;
        }

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
                cout << "Invertendo as cores..." << endl;
               
                
                for (linha = 0; linha < n; linha++) {
                    for (coluna = 0; coluna < n; coluna++) {
                        if (matriz[linha][coluna] == 0) {
                            matriz[linha][coluna] = 1; // Muda para branco
                        } else {
                            matriz[linha][coluna] = 0; // Muda para preto
                        }
                    }
                }
                cout << "Cores invertidas." << endl;
                break;
            case 2:
                cout << "Mostrar matriz transposta selecionado." << endl;
               
                // Para imprimir a transposta, mantemos os loops (linha, coluna)
                // mas acessamos a matriz como [coluna][linha]
                for (linha = 0; linha < n; linha++) {
                    for (coluna = 0; coluna < n; coluna++) {
                        if (matriz[coluna][linha] == 0) { 
                            cout << preto << preto;
                        } else {
                            cout << branco << branco;
                        }
                    }
                    cout << endl;
                }
                break;
            case 3:
              
                cout << "Contar pixels selecionado." << endl;
                cout << "Total de pixels: " << n * n << endl;
                qntdepreto = qntdebranco = 0;    
                for (linha = 0; linha < n; linha++) {
                    for (coluna = 0; coluna < n; coluna++) {
                        if (matriz[linha][coluna] == 0) qntdepreto++;
                        else qntdebranco++;
                    }
                }
                cout << "Pixels pretos: " << qntdepreto << endl;
                cout << "Pixels brancos: " << qntdebranco << endl;
                break;
            case 4:
                cout << "Desenhando moldura..." << endl;
                
              
                // do loop 'while' vai desenhar o resultado.
                for (linha = 0; linha < n; linha++) {
                    for (coluna = 0; coluna < n; coluna++) {
                        // Verifica se a célula está na borda
                        if (linha == 0 || linha == n - 1 || coluna == 0 || coluna == n - 1) {
                            matriz[linha][coluna] = 1; // 1 = branco
                        }
                    }
                }
                cout << "Moldura desenhada." << endl;
                break;
            case 5:
                cout << "Saindo do programa." << endl;
                return 0;
            default: // caso o usuario digite um numero invalido
                cout << "Opção inválida. Tente novamente." << endl;
        
                break; // 'break' é o padrão
        }
        system("pause");
        system("cls");
    }
    return 0;
}