#include <iostream>

using namespace std;

void imprimirEspiral(int matriz[5][5], int tam) {
    int fila_inicio = 0, fila_fin = tam - 1;
    int columna_inicio = 0, columna_fin = tam - 1;

    while (fila_inicio <= fila_fin && columna_inicio <= columna_fin) {

        for (int i = columna_inicio; i <= columna_fin; ++i) {
            cout << matriz[fila_inicio][i] << " ";
        }
        fila_inicio++;

        for (int i = fila_inicio; i <= fila_fin; ++i) {
            cout << matriz[i][columna_fin] << " ";
        }
        columna_fin--;


        if (fila_inicio <= fila_fin) {
            for (int i = columna_fin; i >= columna_inicio; --i) {
                cout << matriz[fila_fin][i] << " ";
            }
            fila_fin--;
        }


        if (columna_inicio <= columna_fin) {
            for (int i = fila_fin; i >= fila_inicio; --i) {
                cout << matriz[i][columna_inicio] << " ";
            }
            columna_inicio++;
        }
    }
    cout << endl;
}

int main() {
    int matriz[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };


    cout << "Recorrido en espiral: " << endl;
    imprimirEspiral(matriz, 5);

    return 0;
}
