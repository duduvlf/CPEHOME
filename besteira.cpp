#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main () {
     srand (time(NULL));
    int n, opcao;

    cout<< "digite um numero n para matriz NxN"<<endl;
    cin>>n;

     while(n<1 || n>10){  //para criar a condicao se o numero for maior 
     cout << "numero invalido! Digite novamente "<<endl;
 }
 int matriz[11][11]; // criar uma matriz maior para n precisar criar armazenamento desnecessario
    for (int i=0; i<n; i++)
     for(int j=0; j<n; j++)
     matriz[i][j]= rand() %2; // o rand() gerara numeros aleatorios grandes em que somente sera divisivel por 2 e tera como resto 0 ou 1

     char branco= char(176);
     char preto= char(219);

     while(true){
    //mostrar a matriz no programa 
    for (int i=0; i<n ; i++){ 
      for (int j=0;j<n; j++){
        if(matriz[i][j]==0){
            cout<< preto << preto;
        }else{
            cout<< branco << branco;
        }
      }
      cout<< endl; 
    }
    cout<<"\n MENU \n"<<endl;
    cout<< "1- inverter as cores\n";
    cout<<"2- Mostrar a matriz transposta\n";
    cout<<"3- contar pixels \n";
    cout<< "4-adicionar borda\n";
    cout<<"5-sair\n"; 
       cin>>opcao;

       switch(opcao){
          case 1:
           {for(int i=0; i<n; i++)
           for (int j=0;j<n;j++)
           if (matriz[i][j] == 0) {
               matriz[i][j] = 1;
           }else {
               matriz[i][j] = 0;
           }
           break;
       }
        case 2:
        {



        }
     }




}
return 0;
}