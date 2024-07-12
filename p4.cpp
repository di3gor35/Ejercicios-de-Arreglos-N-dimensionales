#include <iostream>
using namespace std;

void validarFilas(int &fila1, int &fila2){
    bool valido = true;
    int aux;
    cout << "Ingrese la primera fila a intercambiar: ", cin >> fila1;
    cout << "Ingrese la segunda fila a intercambiar: ", cin >> fila2;
    do {
        if (fila1 == fila2){
            cout << "Ingrese filas diferentes" << endl;
            cout << "Ingrese la primera fila a intercambiar: ", cin >> fila1;
            cout << "Ingrese la segunda fila a intercambiar: ", cin >> fila2;
            valido = false;
        } else if (fila1 > fila2){
            aux = fila1;
            fila1 = fila2;
            fila2 = aux;
            valido = true;
        } else {
            valido = true;
        }
    } while (valido == false);
}

void intercambiarFilas(int matriz[4][4], int fila1, int fila2){
    int aux;
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 4; j++){
            aux = matriz[fila1][j];
            matriz[fila1][j] = matriz[fila2][j];
            matriz[fila2][j] = aux;
        }
    }
}

void mostrarMatriz(int matriz[4][4]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int fila1, fila2;
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    validarFilas(fila1, fila2);
    intercambiarFilas(matriz, fila1, fila2);

    cout << "Matriz con filas intercambiadas:" << endl;
    mostrarMatriz(matriz);

    return 0;
}