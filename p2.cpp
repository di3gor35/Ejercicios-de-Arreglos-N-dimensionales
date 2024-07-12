#include <iostream>

using namespace std;

void buscarValorMatriz(int matriz[3][3], int posiciones[9][2], int valor, int &k){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(matriz[i][j] == valor){
                posiciones[k][0] = i;
                posiciones[k][1] = j;
                k++;
            }
        }
    }
}

void mostrarPosiciones(int posiciones[9][2], int valor, int k){
    if (k > 0){
        cout << "El valor " << valor << " se encuentra en las posiciones: " << endl;
        for (int i = 0; i < k; i++){
            cout << "Fila " << posiciones[i][0] << ", Columna " << posiciones[i][1] << endl;
        }
    } else {
        cout << "El valor no se encuentra en la matriz" << endl;
    }
}

int main(){
    int valor;
    int k = 0;
    int posiciones[9][2];

    int matriz[3][3] = {
        {1, 2, 3},
        {3, 2, 1},
        {4, 2, 3}
    };

    cout << "Ingrese el numero a buscar: ", cin >> valor;
    buscarValorMatriz(matriz, posiciones, valor, k);
    mostrarPosiciones(posiciones, valor, k);
    return 0;
}