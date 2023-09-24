#include <iostream>
#include <math.h>
#define numero 18446744073709551615;
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
/*
void encender(unsigned long long int LED){
        digitalWrite(8, LOW);
        shiftOut(7,9,MSBFIRST,LED>>56);
        shiftOut(7,9,MSBFIRST,LED>>48);
        shiftOut(7,9,MSBFIRST,LED>>40);
        shiftOut(7,9,MSBFIRST,LED>>32);
        shiftOut(7,9,MSBFIRST,LED>>24);
        shiftOut(7,9,MSBFIRST,LED>>16);
        shiftOut(7,9,MSBFIRST,LED>>8);
        shiftOut(7,9,MSBFIRST,LED);
        digitalWrite(8,HIGH);

}

void Verificacion(int frecuencia){
        unsigned long long int num = 0;
        digitalWrite(8, LOW);
        shiftOut(7,9,MSBFIRST,total>>56);
        shiftOut(7,9,MSBFIRST,total>>48);
        shiftOut(7,9,MSBFIRST,total>>40);
        shiftOut(7,9,MSBFIRST,total>>32);
        shiftOut(7,9,MSBFIRST,total>>24);
        shiftOut(7,9,MSBFIRST,total>>16);
        shiftOut(7,9,MSBFIRST,total>>8);
        shiftOut(7,9,MSBFIRST,total);
        digitalWrite(8, HIGH);
        delay(frecuencia);

        encender(num);
        delay(frecuencia);

}
*/
int main()
{

    int **matriz;
    int **matriz1;

     //   unsigned long long int patron1;  //18446744073709551615;

    matriz= creamatriz1(8,8);
    matriz1= RellenarMatriz(matriz);
    imprimir_matriz(matriz1,8,8);
    int a, opcion;
    while (a==0){
        cout<< "Seleccione un opcion"<< endl;
        cout<< "1. Verificar funcionamiento"<<endl<<"2. Mostrar imagen "<<endl<<"3. Forma Alternada";
    cin>> opcion;
        switch(opcion)
    {
    case 1 :
                a=1;
    break;


    case 2:
        a = 1;
    break;

    case 3 :
    a= 0;
    break;
    }

    }



    return 0;
}
