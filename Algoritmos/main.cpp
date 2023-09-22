#include <iostream>
#include <math.h>
using namespace std;
int** creamatriz1 (int filas, int columnas){
    int ** matriz =  new int* [filas];

    for (int i = 0;i<filas;i++){
        matriz[i]= new int [columnas];
    }
    return matriz;
}

int** RellenarMatriz(int** matriz){
    int contador = 0;
    for (int i = 0; i<8 ; i++){
        for ( int u = 0; u<8; u++){
                matriz[i][u]= contador;
                contador++;
            }
        }

return matriz;
   }
void imprimir_matriz(int** matriz, int filas, int columnas){
    for (int i = 0; i<filas; i++){
        for (int u = 0; u<columnas; u++ ){
                cout<< matriz[i][u]<< " ";
        }
        cout<< endl;
        }
}

unsigned long long  int  Verificar(int** matriz){
        unsigned long long int suma = 0 ;
        for (int i = 0; i<8; i++){
            for (int u = 0; u<8; u++ ){
                suma = suma + pow(2,matriz[i][u]);

        }
        }
        return suma;
}


int main()
{
    /*
    int **matriz;
    int **matriz1;
*/
        unsigned long long int patron1;  //18446744073709551615;
    /*
    matriz= creamatriz1(8,8);
    matriz1= RellenarMatriz(matriz);
    imprimir_matriz(matriz1,8,8);
    patron1= Verificar(matriz1);
*/
    for (int i= 5; i<64; i++){
        patron1 = patron1 + pow(2,i);
    }
    cout<< patron1;


    return 0;
}
