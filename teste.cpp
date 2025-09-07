#include <iostream>
#include <cstdlib>

using namespace std; 

int main (){

    int x,y,z;

cout << "Determine um numero:" "\n";
cin >> x;
cout << "Determine outro numero: " "\n";
cin >> y;

cout << "A soma deles:" << x+y << "\n";

cout << "determine: \n";
cin >> z;

if ( z % 2 == 0) {

    cout << z << " e par ";

} else {

cout << z << " e impar ";

}


system ("pause");
return 0;



}