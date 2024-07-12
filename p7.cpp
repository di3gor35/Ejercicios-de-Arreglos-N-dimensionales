#include <iostream>
using namespace std;

void rotarMatriz(int matriz[4][4]){
    int aux[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            aux[i][j] = matriz[i][j];
        }
    }
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matriz[i][j] = aux[3-j][i];
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
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotarMatriz(matriz);
    cout << "Matriz rotada 90 grados en sentido horario: " << endl;
    mostrarMatriz(matriz);
    return 0; 
}