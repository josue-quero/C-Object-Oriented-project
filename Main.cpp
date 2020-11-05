#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Vuelo.h"
#include "Pasajero.h"

//Autor: David Josue Marcial Quero Matricula: A00828702
//Fecha de creacion: 01/12/2019
//Ultima fecha de modificacion: 01/12/2019
//Programa que carga datos de vuelos, de pasajeros y sus atributos(numero de vuelo, nombre, hora, etc.)
//permite dar de alta datos de pasajeros, vuelos y sus atributos, asi como solicitar informacion de todos
//los vuelos y pasajeros que tiene un aeorpuerto.

//Funcion que recibe la lista de vuelos, la cantidad de los mismos y
//un numeor de vuelo a buscar dentro de la lista, si lo encuentra, regresa
// un valor boleano verdadero si no, uno falso.
bool encontrarVuelo(int numEncontrar, Vuelo listaVuelo[], int cantVuelo){
    for (int i = 0; i < cantVuelo; i++){ //Recorre cada valor de los vuelos seg�n su numero de vuelo
        if (listaVuelo[i].getNumeroVuelo() == numEncontrar){ //Si el numero de vuelo en la lista de vuelo es
            return true;                                     //el mismo que el dado, regresa true.
        }
    }
    return false;
}

//Funcion que recibe la lista de Vuelos y la cantidad de ellos para
//a�adir un nuevo vuelo en dicha lista.
void darAltaVuelo(Vuelo listaVuelo[], int &cantVuelo, int totalVuelos){
    int numeroV, hora, minuto, duracion, nueVuelos;
    int cont = 0;
    string origen, destino;
    Tiempo temporal;

    cout << "Cuantos vuelos? " << " Solo " << (totalVuelos - cantVuelo) << " espacios disponibles" << endl;
    cin >> nueVuelos;

    for (int i = 0; i < nueVuelos; i++){
        do{
        if (cont != 0){
            cout << "ERROR: Numero de vuelo ya existente" << endl; //Si se da un numero de vuelo repetido, se genra una advertencia y se
        }                                                          //vuelve a solicitar el numero de vuelo

        cout << "Ingrese el numero de vuelo(4 digitos juntos): " << endl;
        cin >> numeroV;

        cont++;
        }
        while (encontrarVuelo(numeroV, listaVuelo, cantVuelo));       //Comprueba que no exista algun otro vuelo con el mismo numero de vuelo
        cout << "Ingrese primero la hora y despues el minuto de partida(separados por un espacio): " << endl;  //que el que se est� dando de alta
        cin >> hora >> minuto;

        cout << "Ingrese las 3 siglas en mayuscula de la ciudad de origen: " << endl;
        cin >> origen;

        cout << "Ingrese las 3 siglas en mayuscula de la ciudad de destino: " << endl;
        cin >> destino;

        cout << "Ingrese la duracion del vuelo en minutos: " << endl;
        cin >> duracion;
        cont = 0;

        temporal.setHora(hora);
        temporal.setMinuto(minuto);

        listaVuelo[cantVuelo].setNumeroVuelo(numeroV);
        listaVuelo[cantVuelo].setHoraInicio(temporal);
        listaVuelo[cantVuelo].setOrigen(origen);
        listaVuelo[cantVuelo].setDestino(destino);
        listaVuelo[cantVuelo].setDuracion(duracion);

        cantVuelo++;
    }
}


// Funcion que recibe un nombre, un apellido, la lista de pasajeros y la cantidad de ellos para
//buscar en la lista de pasajeros si el nombre y el apellido dados estan repetidos, si lo est�n,
//regresa verdadero, sino falso.
bool encontrarPasajero(string nomEncontrar, string apeEncontrar, Pasajero listaPasajeros[], int cantPasajeros){
    for (int i = 0; i < cantPasajeros; i++){ //Se recorren todos los pasajeros y se busca aquel que tenga el mismo nombre y apellido que el dado a la funcion.
        if ((listaPasajeros[i].getNombre() == nomEncontrar)&(listaPasajeros[i].getApellido() == apeEncontrar)){
            return true;
        }
    }
    return false;
}

//Funcion que recibe la lista de pasajeros, la cantidad de ellos, la lista de vuelos y la cantidad de vuelos, para
//dar de alta un nuevo pasajero
void darAltaPasajero(Pasajero listaPasajeros[], int &cantPasajeros, Vuelo listaVuelos[], int cantVuelos, int totalPasajeros){
    string nombre, apellido, asiento;
    int numeroVuelo, nuePasajero;
    int cantDisponible = totalPasajeros - cantPasajeros;
    int contId = 0000;
    int cont = 0;
    int contValidar = 0;
    Pasajero temporal;

    cout << "Cuantos Pasajeros? " << " Solo " << cantDisponible << " espacios disponibles" << endl;
    cin >> nuePasajero;

    for (int i = 0; i < nuePasajero; i++){
        do{
            if (cont != 0){
                cout << "ERROR: Nombre de pasajero ya existente" << endl;
            }
            cout << "Ingrese el nombre y apellido del pasajero(separados por un espacio): " << endl;
            cin >> nombre >> apellido;

            cont++;
        }
        while (encontrarPasajero(nombre, apellido, listaPasajeros, cantPasajeros));                                                     //Se llama la funcion que comprueba que el nombre y apelldos
            cout << "Ingrese el asiento, primero numero de 0- 30, y luego letra mayuscula de A-F(separados por un espacio): " << endl;  //no son repetidos. Si lo son, vuelve a preguntar por el
            cin >> asiento;                                                                                                             //nombre y apellidos
            do{
                if (contValidar > 0){
                    cout << "Error, numero de vuelo inexistente" << endl;
                }
                cout << "Ingrese numero de vuelo(4 digitos juntos): " << endl;
                cin >> numeroVuelo;
                contValidar++;
            }
            while (!encontrarVuelo(numeroVuelo, listaVuelos, cantVuelos));             //Se llama a la funcion que comprueba que existe el
                contValidar = 0;                                                       //vuelo que se le esta dando. Sino, vuelve a preguntar
                cont = 0;                                                              //por el numero de vuelo
                contId = 1 + cantPasajeros;

                listaPasajeros[cantPasajeros].setAsiento(asiento);
                listaPasajeros[cantPasajeros].setNumeroVuelo(numeroVuelo);
                listaPasajeros[cantPasajeros].setNombre(nombre);
                listaPasajeros[cantPasajeros].setApellido(apellido);
                listaPasajeros[cantPasajeros].setId(contId);

                cantPasajeros++;
    }
}

//Funcion que carga los datos de los pasajeros de un archivo de texto a un arreglo de objetos
void cargaDatosPasajeros(Pasajero listaPasajeros[], int &cantPasajeros){
    ifstream archListaPasajeros;
    int numVue, numId;                                                      //Se crean las variables para leer los datos del archivo de texto
    string nombre, apellido, asiento;
    cantPasajeros = 0;

    archListaPasajeros.open("Pasajeros.txt");                              //Se abre el archivo de texto de donde se obtendr�n los datos
    while (archListaPasajeros >> nombre >> apellido >> asiento >> numVue >> numId){
        listaPasajeros[cantPasajeros].setNombre(nombre);
        listaPasajeros[cantPasajeros].setApellido(apellido);
        listaPasajeros[cantPasajeros].setAsiento(asiento);
        listaPasajeros[cantPasajeros].setNumeroVuelo(numVue);              //Se asignan los valores de los archivos a los lugares correspondientes
        listaPasajeros[cantPasajeros].setId(numId);                        //en el arreglo del objeto
        cantPasajeros++;
    }
    archListaPasajeros.close();
}

//Funcion que recibe la lista de pasajeros y la cantidad de ellos para
//mostrarlo al usuario
void muestraDatosPasajeros(Pasajero listaPasajeros[], int cantPasajeros){
    cout << "Pasajeros" << endl;
    for (int i = 0; i < cantPasajeros; i++){                            //Loop que permite mostrar los atributos de cada pasajero
        cout << "Nombre completo " << listaPasajeros[i].getNombre() << " ";
        cout << listaPasajeros[i].getApellido() << " ";
        cout << "Asiento " << listaPasajeros[i].getAsiento() << " ";
        cout << "Numero de vuelo " << listaPasajeros[i].getNumeroVuelo() << " ";
        cout << "ID: " << listaPasajeros[i].getId() << endl;
    }
}
//Funcion que recibe la lista de vuelos y la cantidad de vuelos vacios para
//poder cargar de un archivo de texto los datos de vuelos a dicha lista.
void cargaDatosVuelo(Vuelo listaVuelo[], int &cantVuelo){
    ifstream archListaVuelo;
    int numVuelo, duracion, hora, minuto;            //Se crean las variables necesarias para leer los valores del archivo de texto
    string origen, destino;
    Tiempo temp;
    archListaVuelo.open("Vuelos.txt");              //Se abre el documento de texto que contiene todos los vuelos
    cantVuelo = 0;

    while(archListaVuelo >> numVuelo >> hora >> minuto >> origen >> destino >> duracion){
        listaVuelo[cantVuelo].setNumeroVuelo(numVuelo);
        temp.setHora(hora);
        temp.setMinuto(minuto);
        listaVuelo[cantVuelo].setHoraInicio(temp);
        listaVuelo[cantVuelo].setOrigen(origen);
        listaVuelo[cantVuelo].setDestino(destino);
        listaVuelo[cantVuelo].setDuracion(duracion);
        cantVuelo++;
    }
    archListaVuelo.close();
}

//Funcion que recibe la lista de vuelos y la cantidad de vuelos
//para mostrar los datos dentro de la lista de vuelos al usuario
void muestraDatosVuelo(Vuelo listaVuelo[], int cantVuelo){
    cout << "Vuelos Disponibles" << endl;
    Tiempo temp;
    for (int i = 0; i < cantVuelo; i++){         //Loop para mostrar los atributos de cada vuelo

        cout << "Numero de vuelo " << listaVuelo[i].getNumeroVuelo() << " ";
        temp = listaVuelo[i].getHoraInicio();
        cout << "Hora de inicio " << temp.getHora() << ":" << temp.getMinuto() << " ";
        cout << "Origen " << listaVuelo[i].getOrigen() << " ";
        cout << "Destino " << listaVuelo[i].getDestino() << " ";
        cout << "Duracion " << listaVuelo[i].getDuracion() << " min" << endl;

    }

}

//Funcion que recibe la lista de vuelos y pasajeros, la cantidad de vuelos y pasajeros para mostrar
//los pasajeros de un determinado vuelo
void mostrarPasajerosEnVuelo(Pasajero listaPasajeros[], Vuelo listaVuelo[], int cantVuelo, int cantPasajeros){
    int nuevoVuelo;
    int contNumero = 0;

    do{
        if (contNumero > 0){
            cout << "Error, numero de vuelo inexistente: " << endl;
        }
        cout << "Ingrese el numero de vuelo (4 digitos juntos): " << endl;
        cin >> nuevoVuelo;
        contNumero++;
    }
    while(!encontrarVuelo(nuevoVuelo, listaVuelo, cantVuelo));         //Condici�n que determina si el valor del n�mero de vuelo es un
                                                                       //valor aceptable y existente.
    int cont = 0;
    for (int v = 0; v < cantVuelo; v++){
        if (listaVuelo[v].getNumeroVuelo() == nuevoVuelo){             //Se busca en la lista de vuelos, el numero de vuelo que se ingres�
            Tiempo temporal;
            temporal = listaVuelo[v].getHoraInicio();
            cout << "Los pasajeros del vuelo " << listaVuelo[v].getNumeroVuelo() << " " << temporal.getHora() << ":" //Se muestran los atributos del vuelo
            << temporal.getMinuto() << " " << listaVuelo[v].getOrigen() << " " << listaVuelo[v].getDestino() << " " << listaVuelo[v].getDuracion() << " son:" << endl;
            for (int p = 0; p < cantPasajeros; p++){
                if (listaVuelo[v].getNumeroVuelo() == listaPasajeros[p].getNumeroVuelo()){           //Se muestran los pasajeros y sud atributos,
                    cout << "Nombre completo " << listaPasajeros[p].getNombre() << " ";              //que tienen el mismo n�mero de vuelo que el del vuelo.
                    cout << listaPasajeros[p].getApellido() << " ";
                    cout << "Asiento " << listaPasajeros[p].getAsiento() << " ";
                    cout << "ID: " << listaPasajeros[p].getId() << endl;
                    cont++;
                }
            }
            if (cont == 0){
                cout << "Este vuelo aun no tiene pasajeros" << endl;      //Si el vuelo no tiene pasajeros, se le avisa al usuario
            }
        }
    }
}

int main(){
    Vuelo listaVuelo[60];        //Se crea la lista de vuelos y la variable que determina la cantidad de vuelos que hay
    int cantVuelo;
    int totalVuelo = 60;
    char opcion;

    Pasajero listaPasajeros[80];  //Se crea la lista de pasajeros y la variable que determina la cantidad de pasajeros que hay
    int cantPasajeros;
    int totalPasajeros = 80;

    cargaDatosVuelo(listaVuelo, cantVuelo);                  //Se llaman las funciones que cargan los datos de los vuelos y pasajeros de
    cargaDatosPasajeros(listaPasajeros, cantPasajeros);      //los archivos de texto
    cout << "BIENVENIDO AL AEROPUERTO INTERNACIONAL DE MONTERREY." << endl;
    cout << "ELIJA LA ACCION QUE DESEA REALIZAR" << endl;
    do{                                                      //Se muestra el men� de opciones que permite ejecutar las distintas funciones
        cout << "a)Consultar todos los vuelos" << endl;      //del programa
        cout << "b)Consultar todos los pasajeros" << endl;
        cout << "c)Dar de alta un vuelo" << endl;
        cout << "d)Dar de alta un pasajero" << endl;
        cout << "e)Consultar pasajeros de un vuelo" << endl;
        cout << "f)Terminar" << endl;
        cin >> opcion;
        switch(opcion){
            case 'a':{
                muestraDatosVuelo(listaVuelo, cantVuelo);
                break;
            }
            case 'b':{
                muestraDatosPasajeros(listaPasajeros, cantPasajeros);
                break;
            }
            case 'c':{
                darAltaVuelo(listaVuelo, cantVuelo, totalVuelo);
                break;
            }
            case 'd':{
                darAltaPasajero(listaPasajeros, cantPasajeros, listaVuelo, cantVuelo, totalPasajeros);
                break;
            }
            case 'e':{
                mostrarPasajerosEnVuelo(listaPasajeros, listaVuelo, cantVuelo, cantPasajeros);
                break;
            }

        }

    }
    while(opcion != 'f');
    return 0;
}
