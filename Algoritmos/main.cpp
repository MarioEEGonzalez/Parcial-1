// C++ code
//
int a, opcion;
int **matriz;
int **matriz1;
unsigned long long int patron1;
#define total 18446744073709551615


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

void encender(unsigned long long int LED1){
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

int leerDato( ){
    int variable;
    while(Serial.available()== 0){

    }
    variable = Serial.parseInt();
    return variable;

}


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



void setup()
{
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

    Serial.begin(9600);
    Serial.println( "Seleccione un opcion");
    Serial.println("1. Verificar funcionamiento\n2. Mostrar Imagen\n3. Forma alternada");
}

void loop()

{




    if(Serial.available()){
        char opcion = Serial.read();
        if (opcion == '1'){
            verificar_funcionamiento();
        }
        /*
  else if (opcion=='2'){
    Mostrar imagen prueba()
 }
 else if (opcion == '3'){
   Forma_alternada()
 }
 */

    }
