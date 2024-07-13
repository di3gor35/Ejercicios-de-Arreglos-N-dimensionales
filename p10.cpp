#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void crearMatriz(int matriz[10][10]){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = rand() % 2;
        }
    }
}

int calcularNumeroMinas(int matriz[10][10], int fila, int columna){
    int minas = 0;
    for (int i = fila - 1; i <= fila + 1; i++){
        for (int j = columna - 1; j <= columna + 1; j++){
            if (i == fila && j == columna){
                continue;
            }
            if (i >= 0 && i < 10 && j >= 0 && j < 10){
                minas += matriz[i][j];
            }
        }
    }
    return minas;
}

void mostrarNumeroMinas(int matriz[10][10]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < 10; j++){
            cout << calcularNumeroMinas(matriz, i, j) << " ";
        }
        cout << endl;
    }
}

int main(){
    srand(time(0));
    int matriz[10][10];

    crearMatriz(matriz);
    mostrarNumeroMinas(matriz);
    return 0;
}