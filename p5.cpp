#include <iostream>
using namespace std;

void reflejarMatriz(int matriz[6][6], int n){
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n / 2; j++){
            temp = matriz[i][j];
            matriz[i][j] = matriz[i][n - j - 1];
            matriz[i][n - j - 1] = temp;
        }
    }
}

void mostrarMatriz(int matriz[6][6]){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int matriz[6][6] = {
    {1, 2, 3, 4, 5, 6},
    {7, 8, 9, 10, 11, 12},
    {13, 14, 15, 16, 17, 18},
    {19, 20, 21, 22, 23, 24},
    {25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36}
    };

    reflejarMatriz(matriz, 6);
    cout << "Matriz reflejada horizontalmente:" << endl;
    mostrarMatriz(matriz);

    return 0;
}