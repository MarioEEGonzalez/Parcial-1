// C++ code
//
#include <math.h>
int opcion;
#define total 255

int* arreglo ( int columnas){
    int * arreglo =  new int [columnas];

    for (int i = 0;i<columnas;i++){
        arreglo[i] = i;
    }
    return arreglo;
}

// RELLENA UNA MATRIZ CON NUMEROS DEL 0 AL 63
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



//  ENCIENDE EL LOS LEDS QUE CORRESPONDE AL NUMERO EN DECIMAL
void encender( unsigned long  long int  LED1){
    digitalWrite(8, LOW);
    shiftOut(7,9,MSBFIRST,LED1>>56);
    shiftOut(7,9,MSBFIRST,LED1>>48);
    shiftOut(7,9,MSBFIRST,LED1>>40);
    shiftOut(7,9,MSBFIRST,LED1>>32);
    shiftOut(7,9,MSBFIRST,LED1>>24);
    shiftOut(7,9,MSBFIRST,LED1>>16);
    shiftOut(7,9,MSBFIRST,LED1>>8);
    shiftOut(7,9,MSBFIRST,LED1);
    digitalWrite(8, HIGH);
}

// FUNCION VERIFICACION PERMITE ENCENDER Y APAGAR LOS LEDS
void Verificacion(int frecuencia){
    unsigned long long int num = 0;
    digitalWrite(8, LOW);
    for (int i = 0; i<8;i++){
        shiftOut(7,9,MSBFIRST,total);
    }
    digitalWrite(8, HIGH);
    delay(frecuencia);

    encender(num);
    delay(frecuencia);
}

//PERMITE LEER UN DATO POR EL PUERTO SERIAL
int leerDato( ){
    int variable;
    while(Serial.available()== 0){

    }
    variable = Serial.parseInt();
    return variable;

}

//PERMITE VERIFICAR EL FUNCIONAMIENTO DE LOS LEDS CON UNA FRECUENCIA Y CANTIDAD LEIDAS
void verificar_funcionamiento(){
    int z=0;
    int freq, cant;
    Serial.println("Ingrese la frecuencia de encendido");
    freq=  leerDato();
    Serial.println("Ingrese la cantidada de veces de repeticion");
    cant = leerDato();
    while(z<cant){
        Verificacion(freq);
        z=z+1;
    }

}


//IMPRIME EL PATRON #1
void imprimirPatron1( ) {

    int suma = 0;
    int *arreglo1;
    arreglo1= arreglo(8);




    for (int i = 0; i < 8; i++) {
        suma = 1;
        suma= suma + pow(2,arreglo1[i])+ pow(2,arreglo1[7-i]);
        shiftOut(7,9,MSBFIRST,suma);
        Serial.print(suma);




    }

    digitalWrite(8, HIGH);


}

float ingresa_una_linea(int auxi){

    float suma = 0;

    int *arreglo1;
    arreglo1= arreglo(8);
    int aux[4];
    int *auxiliar= aux;
    for (int i = 0 ; i<8; i++){

        if (auxi% 3!= 0){

            suma = suma+ round(pow( 2,arreglo1[i]));
        }
        else  {

        }
        auxi++;
    }
    return suma;
}
void imprimirPatron3 (){

    float suma;


    for (int i = 0; i<8;i++){
        if (i>=2 && i<4|| i>=6 ){
            suma = ingresa_una_linea(1);
            shiftOut(7,9,MSBFIRST,suma);
        }
        else{
            suma = ingresa_una_linea(0);
            shiftOut(7,9,MSBFIRST,suma);
        }
    }




    digitalWrite(8, HIGH);
}


void imprimirPatron2( ) {

    int suma = 1;

    int *arreglo1;
    arreglo1= arreglo(8);
    int aux[4];
    int *auxiliar= aux;






    for (int i = 0; i < 4; i++) {

        suma= suma + pow(2,arreglo1[3-i])+ pow(2,arreglo1[4+i]);
        shiftOut(7,9,MSBFIRST,suma);
        suma++;
        auxiliar[i]= suma;
        Serial.println(suma);

    }
    for (int j = 3 ; j>= 0; j--){
        shiftOut(7,9,MSBFIRST,auxiliar[j]-1);
    }

    digitalWrite(8, HIGH);

}

void imprimirPatron4( ) {



    int *arreglo1;
    arreglo1= arreglo(8);


    int aux[4];
    int *auxiliar= aux;






    for (int i = 0; i < 4; i++) {
        float suma =0 ;
        for (int u = 0; u<4;u++){

            suma=round ( suma + pow(2,arreglo1[u+i]));

        }

        shiftOut(7,9,MSBFIRST,suma);
        auxiliar[i]= suma;
        Serial.println(suma);

    }



    for ( int k = 3; k >= 0; k--){
        shiftOut(7,9,MSBFIRST,auxiliar[k]);
    }





    digitalWrite(8, HIGH);

}

void setup()
{
    Serial.begin(9600);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

}

void loop()
{

    imprimirPatron3( );
}
