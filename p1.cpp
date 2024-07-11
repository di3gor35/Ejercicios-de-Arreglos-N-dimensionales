#include <iostream>

using namespace std;

void multiplicarMatrices(int matriz1[3][3], int matriz2[3][3], int resultado[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            resultado[i][j] = 0;
            for(int k = 0; k < 3; k++){
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void mostrarEnConsola(int matriz1[3][3], int matriz2[3][3], int resultado[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << matriz1[i][j] << " ";
        }
        if (i == 1){
            cout << " *  ";
        } else {
            cout << "    ";
        }
        for(int j = 0; j < 3; j++){
            cout << matriz2[i][j] << " ";
        }
        if (i == 1){
            cout << " =  ";
        } else {
            cout << "    ";
        }
        for(int j = 0; j < 3; j++){
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int matriz1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matriz2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int resultado[3][3];

    multiplicarMatrices(matriz1, matriz2, resultado);

    mostrarEnConsola(matriz1, matriz2, resultado);

    return 0;
}