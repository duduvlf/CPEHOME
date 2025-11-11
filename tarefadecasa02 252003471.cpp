// tarefadecasa02 252003471.cpp
// Nome: Eduardo Augusto
// RA: 252003471

#include <iostream>
#include <cstdlib>
using namespace std;
    // função que verifica se é possível conectar dois picos sem que haja nenhum pico intermediário que atrapalhe
// a conexão, ou seja, se a inclinação da reta que liga os dois picos é maior que a inclinação da reta que liga o pico inicial com os picos intermediários
// formula: m = (y2 - y1) / (x2 - x1)
bool feelsgood(int i, int a, int alturas[]) {
       float m = (float)(alturas[a] - alturas[i]) / (a - i); 
           for (int k = i + 1; k < a; k++) {
           float m_nu = (float)(alturas[k] - alturas[i]) / (k - i); //  inclinação da reta para verificar os picos
           if (m_nu >= m) return false; // algum pico atrapalha
                                         }
    return true;
}


int main() {

    int n;
    cout << "Escolha o numero de picos: "; 
    cin >> n;

    int altura[1000]; // limite de picos
    for (int i = 0; i < n; i++) cin >> altura[i];

    int cabos = 0; 
    int presente = 0; 

    // enquanto não chegar no último pico
    while (presente < n - 1) {
        int proximo = presente + 1;
        // procura o próximo pico que pode ser conectado ao atual
        // se não houver, o próximo pico será o último
        for (int a = presente + 1; a < n; a++) {
            if (feelsgood(presente, a, altura)) {
                proximo = a;
            }
        }
        cout << "Conectando pico " << presente << " com pico " << proximo << endl;
        cabos++;
        presente = proximo;
    }

    cout << "Numero minimo de cabos: " << cabos << endl;
system("pause");
    return 0;
}

