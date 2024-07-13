#include <iostream>

using namespace std;

void imprimirCuadradoLatino(int n){
    int matriz[n][n];
    int matriz2[n];
    int con;
    int con2;

    for (int j = 0; j < n; j++){
            matriz2[j] = j+1;
        }
    cout << "Cuadrado latino de orden " << n << ":" << endl;
    for (int i = 0; i < n; i++){
        con = 0;
        con2 = 0;
        for (int k = 0; k < n; k++){
            matriz[i][k] = (i>k) ? matriz2[n-i+con2++]:matriz2[con++];
            cout << matriz[i][k] << " ";
        }
        cout << endl;
    }

}

int main(){
    int n;
    cout << "Introduzca el orden de la matriz cuadrada: ", cin >> n;
    
    imprimirCuadradoLatino(n);
    return 0;
}