#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int calcularEstadoArbol(int matriz[10][10], int fila, int columna){
    for (int i = fila - 1; i <= fila + 1; i++){
        for (int j = columna - 1; j <= columna + 1; j++){
            if (i >= 0 && i < 10 && j >= 0 && j < 10){
                if (matriz[i][j] == 1){
                    return 1;
                }
            }
        }
    }
    return 0;
}

void copiarMatriz(int matriz[10][10], int matriz2[10][10]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matriz2[i][j] = matriz[i][j];
        }
    }
}

void actualizarEstadoArbol(int matriz[10][10], int matriz2[10][10]){
    copiarMatriz(matriz, matriz2);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (matriz2[i][j] == 0){
                matriz2[i][j] = calcularEstadoArbol(matriz, i, j);
            } else if (matriz[i][j] == 1){
                matriz2[i][j] = 2;
            }
        }
    }
}

void mostrarBosques(int matriz[10][10], int matriz2[10][10]){
    cout << "Bosque inicial:\t\tBosque despues:" << endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\t";
        for (int k = 0; k < 10; k++){
            cout << matriz2[i][k] << " ";
        }
        cout << endl;
    }
}

void menu(int matriz[10][10], int matriz2[10][10]){
    int opcion;
    do {
        cout << "1. Iniciar simulacion" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion){
            case 1:
                cout << "Iniciando simulacion..." << endl;
                actualizarEstadoArbol(matriz, matriz2);
                mostrarBosques(matriz, matriz2);
                copiarMatriz(matriz2, matriz);
                break;
            case 2:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        cout << endl;
    
    } while (opcion != 2);
}

int main(){
    srand(time(0));
    int matriz[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 2, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int matriz2[10][10];
 
    menu(matriz, matriz2);

    return 0;
}