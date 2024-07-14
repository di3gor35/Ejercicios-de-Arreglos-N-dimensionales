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

int calcularVecinosVivos(int matriz[10][10], int fila, int columna){
    int vivos = 0;
    for (int i = fila - 1; i <= fila + 1; i++){
        for (int j = columna - 1; j <= columna + 1; j++){
            if (i == fila && j == columna){
                continue;
            }
            if (i >= 0 && i < 10 && j >= 0 && j < 10){
                vivos += matriz[i][j];
            }
        }
    }
    return vivos;
}


void copiarMatriz(int matriz[10][10], int matriz2[10][10]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matriz2[i][j] = matriz[i][j];
        }
    }
}

void actualizarEstadoCeldas(int matriz[10][10], int matriz2[10][10]){
    int vivos;
    copiarMatriz(matriz, matriz2);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            vivos = calcularVecinosVivos(matriz, i, j);
            if (matriz[i][j] == 1 && (vivos < 2 || vivos > 3)){
                matriz2[i][j] = 0;
            } else if (matriz[i][j] == 0 && vivos == 3){
                matriz2[i][j] = 1;
            } 
        }
    }
}

void mostrarTablero(int matriz[10][10], int matriz2[10][10]){
    cout << "Tablero inicial:\tTablero despues:" << endl;
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
        cout << "1. Iniciar nueva simulacion" << endl;
        cout << "2. Nueva generacion" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion){
            case 1:
                cout << "Iniciando simulacion..." << endl;
                crearMatriz(matriz);
                actualizarEstadoCeldas(matriz, matriz2);
                mostrarTablero(matriz, matriz2);
                
                break;
            case 2:
                cout << "Cambiando a nueva generacion..." << endl;
                copiarMatriz(matriz2, matriz);
                actualizarEstadoCeldas(matriz, matriz2);
                mostrarTablero(matriz, matriz2);
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        cout << endl;
    
    } while (opcion != 3);
}

int main(){
    int matriz[10][10];
    int matriz2[10][10];

    srand(time(0));
    menu(matriz, matriz2);
    return 0;
}