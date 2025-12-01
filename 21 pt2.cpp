#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <algorithm> 
#include <string>

using namespace std;

struct Carta {
    string nome;  
    string naipe;  
    int valor;    
};

void imprimirBaralho(Carta deck[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "[" << deck[i].nome << "--" << deck[i].naipe << "]";
        if ((i + 1) % 13 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

void embaralhar(Carta deck[], int tamanho) {
    for (int i = 0; i < 1000; i++) {
        int pos1 = rand() % tamanho; 
        int pos2 = rand() % tamanho; 
        swap(deck[pos1], deck[pos2]);
    }
}

// CORREÇÃO: Removi as variáveis globais daqui!

int main() { 
    srand(time(NULL));
    
    // CORREÇÃO: Movi elas para cá (Variáveis Locais)
    int opcao = 0;
    int indice = 0; 
    
    Carta baralho[52];
    
    string naipes[] = {"Ouros", "Espadas", "Copas", "Paus"};
    string nomes[]  = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei", "As"};
    int valores[]   = { 2,   3,   4,   5,   6,   7,   8,   9,   10,    10,     10,    10,    11 };
    
    cout << "Criando um baralho de 52 cartas..." << endl;
    system("pause");
    
    for (int n = 0; n < 4; n++) { 
        for (int v = 0; v < 13; v++) { 
            baralho[indice].naipe = naipes[n];
            baralho[indice].nome = nomes[v]; 
            baralho[indice].valor = valores[v];
            indice++; 
        }
    }
    cout << "---Baralho---" << endl;
    imprimirBaralho(baralho, 52);                                     
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
            
            case 1: { 
                
                bool estorou = false;
                cout << "Iniciando o jogo..." << endl;
                int soma = 0;
                int numdeAses = 0;
                int numdeAsesDeeler = 0;
                
                indice = 0; // Reseta o índice para o começo do baralho
                
                Carta carta1 = baralho[indice];
                indice++;
                
                system("pause");
                system ("cls");
                cout << "---------------------------------" << endl;
                cout << "Sua primeira carta: " << carta1.nome << " de " << carta1.naipe << endl;
                if (carta1.valor == 11) {
                    numdeAses++;
                }
                soma += carta1.valor;
                
                Carta carta2 = baralho[indice];
                indice++;
                cout << "Sua segunda carta: " << carta2.nome << " de " << carta2.naipe << endl;
                soma += carta2.valor;
                if (carta2.valor == 11) {
                    numdeAses++;
                }
                if (soma == 22) {
                    soma = 12;
                    numdeAses--;
                }
                cout << "Sua soma atual e: " << soma << endl;
                cout << "---------------------------------" << endl;
                
                Carta cartadodeeler1 = baralho[indice];
                cout << " Carta do Deeler: " << cartadodeeler1.nome << " de " << cartadodeeler1.naipe << endl;
                indice++;
                if (cartadodeeler1.valor == 11) {
                    numdeAsesDeeler++;
                }
                cout << "---------------------------------" << endl;
                system("pause");
                
                while (true) {
                    cout << "Deseja mais uma carta?" << endl << "(1) Sim (2) Nao): ";
                    int escolha;
                    cin >> escolha;

                    if (escolha == 1) {
                        Carta novacarta = baralho[indice];
                        indice++;
                        cout << "Carta retirada: " << novacarta.nome << " de " << novacarta.naipe << endl;
                        soma += novacarta.valor;
                        cout << "Sua soma atual e: " << soma << endl;
                        
                        if (novacarta.valor == 11) {
                            numdeAses++;
                        }
                        
                        // Loop para corrigir ases caso estoure
                        if (soma > 21 && numdeAses > 0) {
                            soma -= 10;
                            numdeAses--;
                            cout << "Voce tinha um A. Ele agora vale 1 ponto. Sua nova soma e: " << soma << endl;
                            if (soma <= 21) {
                                estorou = false;
                            }
                        }
                        system("pause");
                        
                        if (soma > 21) {
                            cout << "Voce estourou! Sua soma ultrapassou 21. Voce perdeu!" << endl;
                            estorou = true;
                            break;
                        } 
                    }
                    else if (escolha == 2) {
                        cout << "Sua soma final e: " << soma << endl;
                        system("pause");
                        cout << "Vez do Deeler." << endl;
                        system("pause");
                        
                        int somaDeeler = 0;
                        somaDeeler += cartadodeeler1.valor;
                        // Nota: O índice já foi incrementado quando mostramos a primeira carta do dealer
                        cout << "Soma do Deeler: " << somaDeeler << endl;
                        
                        while (somaDeeler < 17) {
                            cout << "Deeler puxa mais uma carta." << endl;
                            Carta cartadodeeler = baralho[indice];
                            indice++;
                            system("pause");
                            cout << "Carta retirada: " << cartadodeeler.nome << " de " << cartadodeeler.naipe << endl;
                            somaDeeler += cartadodeeler.valor;
                            if (cartadodeeler.valor == 11) {
                                numdeAsesDeeler++;
                            }
                            cout << "Soma do Deeler: " << somaDeeler << endl;
                            if (somaDeeler > 21 && numdeAsesDeeler > 0) {
                                somaDeeler -= 10; 
                                numdeAsesDeeler--;
                                cout << "Deeler tinha um A. Ele agora vale 1 ponto. Nova soma do Deeler e: " << somaDeeler << endl;
                            }
                        }
                        
                        // Verifica quem ganhou
                        if (somaDeeler > 21) {
                            cout << "Deeler estourou! Voce ganhou!" << endl;
                            estorou = true;
                        } else if (somaDeeler >= soma && somaDeeler <= 21) {
                            cout << "Deeler venceu! Voce perdeu!" << endl;
                        } else {
                            cout << "Voce venceu o Deeler! Parabens!" << endl;
                        }
                        system("pause");
                        break; 
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
                return 0; 
                
            default:
                cout << "Opcao invalida! Por favor, escolha 1, 2 ou 3." << endl;
                break;
        }
    }
    system("pause");
    return 0;
}