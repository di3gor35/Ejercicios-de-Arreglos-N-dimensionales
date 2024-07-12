#include <iostream>
using namespace std;

void encontrarValoresMinMax(int matriz[4][4], int posiciones[2][3], int n){
    int valmax = matriz[0][0], valmin = matriz[0][0];
    posiciones[0][0] = valmax;
    posiciones[1][0] = valmin;
    posiciones[0][1] = posiciones[0][2] = 0;
    posiciones[1][1] = posiciones[1][2] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (matriz[i][j] > valmax){
                valmax = matriz[i][j];
                posiciones[0][0] = valmax;
                posiciones[0][1] = i;
                posiciones[0][2] = j;
            }
            if (matriz[i][j] < valmin){
                valmin = matriz[i][j];
                posiciones[1][0] = valmin;
                posiciones[1][1] = i;
                posiciones[1][2] = j;
            }
        }
    }
}

void mostrarPosiciones(int posiciones[2][3]){
    cout << "El valor maximo es " << posiciones[0][0] << " y su posicion es:" << endl;
    cout << "Fila: " << posiciones[0][1] << ", Columna: " << posiciones[0][2] << endl;
    cout << "El valor minimo es " << posiciones[1][0] << " y su posicion es:" << endl;
    cout << "Fila: " << posiciones[1][1] << ", Columna: " << posiciones[1][2] << endl;
}

int main(){
    int posiciones[2][3];
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    encontrarValoresMinMax(matriz, posiciones, 4);
    mostrarPosiciones(posiciones);

    return 0;
}