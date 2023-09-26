// C++ code
//
#include <math.h>
int opcion;
#define total 255

//CREA UN PUNTERO QUE APUNTA A UN ARREGLO DINAMICO
int* arreglo ( int columnas){
    int * arreglo =  new int [columnas];

    for (int i = 0;i<columnas;i++){
        arreglo[i] = i;
    }
    return arreglo;
}







// FUNCION VERIFICACION PERMITE ENCENDER Y APAGAR LOS LEDS
void apagayprende(int frecuencia){
    unsigned long long int num = 0;
    digitalWrite(8, LOW);
    for (int i = 0; i<8;i++){
        shiftOut(7,9,MSBFIRST,total);
    }
    digitalWrite(8, HIGH);
    delay(frecuencia);
    digitalWrite(8, LOW);
    apagar();
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
void Verificacion(){
    int z=0;
    int freq, cant;
    Serial.println("Ingrese la frecuencia de encendido");
    freq=  leerDato();
    Serial.println("Ingrese la cantidada de veces de repeticion");
    cant = leerDato();
    while(z<cant){
        apagayprende(freq);
        z=z+1;
    }

}


//IMPRIME EL PATRON #1
void imprimirPatron1( ) {
    digitalWrite(8, LOW);
    int suma = 0;
    int *arreglo1;
    arreglo1= arreglo(8);




    for (int i = 0; i < 8; i++) {
        suma = 1;
        suma= suma + pow(2,arreglo1[i])+ pow(2,arreglo1[7-i]);
        shiftOut(7,9,MSBFIRST,suma);





    }

    digitalWrite(8, HIGH);


}
// ESTA FUNCION PERTENECE A LA PATRON 3 PERMITE IMPRIMIR UNA LINEA DESPLAZADA
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
void apagar(){
    digitalWrite(8, LOW);
    for (int i = 0; i<8;i++){
        shiftOut(7,9,MSBFIRST,0);
    }
    digitalWrite(8, HIGH);
}

// IMPRIME EL PATRON 3
void imprimirPatron3 (){
    digitalWrite(8, LOW);
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

// IMPRIME EL PATRON 2
void imprimirPatron2( ) {
    digitalWrite(8, LOW);
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


    }
    for (int j = 3 ; j>= 0; j--){
        shiftOut(7,9,MSBFIRST,auxiliar[j]-1);
    }

    digitalWrite(8, HIGH);

}

// IMPRIME EL PATRON 4
void imprimirPatron4( ) {

    digitalWrite(8, LOW);
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


    }



    for ( int k = 3; k >= 0; k--){
        shiftOut(7,9,MSBFIRST,auxiliar[k]);
    }





    digitalWrite(8, HIGH);

}
// ESTA FUNCION PERMITE IMPRIMIR EN LA PANTALLA DE LEDS 1 DE LOS 4 PATRONES
void Imagen(){
    Serial.println("INGRESE EL NUMERO DEL PATRON QUE QUIERA OBSERVAR\n1.PATRON 1\n2.PATRON 2\n3.PATRON 3\n4.PATRON 4");
    int opcion;
    opcion= leerDato();
    if (opcion == 1){
        imprimirPatron1();
    }
    else if(opcion==2){
        imprimirPatron2();
    }
    else if(opcion == 3){
        imprimirPatron3();
    }
    else if(opcion== 4){
        imprimirPatron4();
    }
}
//FUNCION PUBLICK
void publik(){
    Serial.println("SELECCIONE\n1.VERRIFICAR FUNCIONAMIENTO\n2.MOSTRAR IMAGEN\n3.FORMA ALTERNADA");
    int opcion;
    opcion = leerDato();
    if (opcion == 1){
        Verificacion();
    }
    else if(opcion==2){
        int z= 0;
        Serial.print("INGRESE LA FRECUENCIA");
        int freq = leerDato();
        Serial.println("INGRESE EL NUMERO DEL PATRON QUE QUIERA OBSERVAR\n1.PATRON 1\n2.PATRON 2\n3.PATRON 3\n4.PATRON4");
        int opc;
        opc= leerDato();
        if (opc == 1){
            while(z<4){
                imprimirPatron1();
                delay(freq);
                apagar();
                delay(freq);
                z++;
            }
        }
        else if(opc==2){
            while(z<4){
                imprimirPatron2();
                delay(freq);
                apagar();
                delay(freq);
                z++;
            }
        }
        else if(opc == 3){
            while(z<4){
                imprimirPatron3();
                delay(freq);
                apagar();
                delay(freq);
                z++;
            }
        }
        else if(opc== 4){
            while(z<4){
                imprimirPatron4();
                delay(freq);
                apagar();
                delay(freq);
                z++;
            }
        }
    }

    else if(opcion == 3){
        Serial.print("INGRESE LA FRECUENCIA");
        int freq = leerDato();
        imprimirPatron1();
        delay(freq);
        imprimirPatron2();
        delay(freq);
        imprimirPatron3();
        delay(freq);
        imprimirPatron4();
        delay(freq);
    }
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

    publik();
}
