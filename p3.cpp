#include <iostream>
using namespace std;

int sumaDiagonales(int matriz[4][4]){
    int suma = 0;
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j ++){
            if (i == j){
                suma += matriz[i][j];
            }
            if (i + j == 3){
                suma += matriz[i][j];
            }
        }
    }
    return suma;
}

int main(){

    int suma;

    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    suma = sumaDiagonales(matriz);

    cout << "La suma de los elementos de las 2 diagonales son: " << suma << endl;

    return 0;
}