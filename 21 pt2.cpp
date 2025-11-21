#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <algorithm> 

using namespace std;

void imprimirBaralho(int deck[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << deck[i] << " ";
        if ((i + 1) % 13 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

void embaralhar(int deck[], int tamanho) {
    for (int i = 0; i < 1000; i++) {
        int pos1 = rand() % tamanho; 
        int pos2 = rand() % tamanho; 
        swap(deck[pos1], deck[pos2]);
    }
}

int opcao = 0;

int main() { 
    bool estorou = false;
    srand(time(NULL));

    int baralho[52];
    int indice = 0; 

    cout << "Criando um baralho de 52 cartas..." << endl;
    system("pause");

    for (int naipe = 0; naipe < 4; naipe++) {
        for (int valor = 2; valor <= 10; valor++) {
            baralho[indice] = valor;
            indice++; 
        }
        baralho[indice++] = 10; 
        baralho[indice++] = 10; 
        baralho[indice++] = 10; 
        baralho[indice++] = 11;
    }

    cout << "---Baralho---" << endl;
    imprimirBaralho(baralho, 52);                                      // Tem que fazer com A valendo 1 também
    system("pause");

    cout << "Embaralhando..." << endl;
    embaralhar(baralho, 52);
    cout << "--- Baralho Embaralhado ---" << endl;
    system("pause");
    while (true) {
        embaralhar(baralho, 52);
        cout << "---------------------------------" << endl;
        cout << "Bem Vindo ao Blackjack!" << endl;
        cout << " 1- Jogar" << endl;
        cout << " 2- Ver regras do jogo" << endl;
        cout << " 3- Sair" << endl;
        cout << "---------------------------------" << endl;
        cin >> opcao;
        
        switch (opcao) {
            
            case 1: { // Abri chave aqui para isolar as variáveis do jogo
                
                cout << "Iniciando o jogo..." << endl;
                int soma = 0;
                indice = 0; 
                
                int carta1 = baralho[indice];
                indice++;
                system("pause");
                system ("cls");
                cout << "Sua primeira carta: " << carta1 << endl;
                soma += carta1;
                
                int carta2 = baralho[indice];
                indice++;
                cout << "Segunda carta: " << carta2 << endl;
                soma += carta2;
                
                cout << "Sua soma atual e: " << soma << endl;
                cout << "---------------------------------" << endl;
                
                int cartadodeeler1 = baralho[indice + 1];
                cout << " Carta do Deeler: " << cartadodeeler1 << endl;
                indice++;
                cout << "---------------------------------" << endl;
                system("pause");
                while (true) {
                    cout << "Deseja mais uma carta?" << endl << "(1) Sim (2) Nao): ";
                    int escolha;
                    cin >> escolha;

                    if (escolha == 1) {
                        int novacarta = baralho[indice];
                        indice++;
                        cout << "Carta retirada: " << novacarta << endl;
                        soma += novacarta;
                        cout << "Sua soma atual e: " << soma << endl;
                        
                        if (soma > 21) {
                            cout << "Voce estourou! Sua soma ultrapassou 21. Voce perdeu!" << endl;
                            estorou = true;
                            break;
                        } else if (soma == 21) {
                            cout << "Parabens! Voce fez 21! Voce ganhou!" << endl;
                            break; // Se fez 21, para de pedir carta
                        } 
                    }
                    
                    if (escolha == 2) {
                        cout << "Sua soma final e: " << soma << endl;
                        system("pause");
                        cout << "Vez do Deeler." << endl;
                        system("pause");
                        int somaDeeler = 0;
                        somaDeeler += cartadodeeler1;
                        indice++;
                        cout << "Soma do Deeler: " << somaDeeler << endl;
                        
                        while (somaDeeler < 17) {
                            cout << "Deeler puxa mais uma carta." << endl;
                            int cartadodeeler = baralho[indice];
                            indice++;
                            system("pause");
                            cout << "Carta retirada: " << cartadodeeler << endl;
                            somaDeeler += cartadodeeler;
                            cout << "Soma do Deeler: " << somaDeeler << endl;
                        }
                        
                        // Verifica quem ganhou depois que o Dealer parou
                        if (somaDeeler > 21) {
                            cout << "Deeler estourou! Voce ganhou!" << endl;
                            estorou = true;
                        } else if (somaDeeler >= soma && somaDeeler <= 21) {
                            cout << "Deeler venceu! Voce perdeu!" << endl;
                        } else {
                            cout << "Voce venceu o Deeler! Parabens!" << endl;
                        }
                        system("pause");
                        break; // Sai do while(true) de pedir cartas porque o jogo acabou
                    }
                } 
                
                break; 
            } 
            case 2:
                cout << "Regras do Blackjack:" << endl;
                cout << "1. O objetivo e chegar o mais proximo possivel de 21 sem ultrapassar." << endl;
                cout << "2. Cartas de 2 a 10 valem seu valor nominal." << endl;
                cout << "3. J, Q, K valem 10 pontos cada." << endl;
                cout << "4. A pode valer 1 ou 11, dependendo do que for melhor para o jogador." << endl;
                cout << "5. O Deeler deve puxar cartas ate atingir pelo menos 17 pontos." << endl;
                cout << "6. Se voce ultrapassar 21 pontos, voce perde automaticamente." << endl;
                cout << "7. Se o Deeler ultrapassar 21 pontos, voce vence automaticamente." << endl;
                cout << "8. Se ambos tiverem a mesma pontuacao, o Deeler vence." << endl;
                break;

            case 3:
                cout << "Obrigado por jogar! Ate a proxima!" << endl;
                return 0; // Encerra o programa
                
            default:
                cout << "Opcao invalida! Por favor, escolha 1, 2 ou 3." << endl;
                break;
        }
    }
    system("pause");
    return 0;
}