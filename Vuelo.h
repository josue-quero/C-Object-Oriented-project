#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED
#include <string>
#include "Tiempo.h"

class Vuelo{

public:

    Vuelo();
    Vuelo(int num, int dr, string og, string des);
    void setNumeroVuelo(int num);
    void setDuracion(int dr);
    void setOrigen(string og);
    void setDestino(string des);
    int getNumeroVuelo();
    int getDuracion();

    string getOrigen();
    string getDestino();
    void setHoraInicio(Tiempo tp);
    Tiempo getHoraInicio();

private:

    Tiempo horaInicio;
    int numeroVuelo, duracion;
    string origen, destino;

};
    //Constructor default que da los valores iniciales a los atributos
    Vuelo :: Vuelo(){
    Tiempo temporal;

    horaInicio = temporal;
    numeroVuelo = 7777;
    duracion = 2222;
    origen = "MEX";
    destino = "ENG";

    }
    //Constructor con parametros que a partir de ellos, establece los
    //valores iniciales de los atributos de la clase
    Vuelo :: Vuelo(int num, int dr, string og, string des){

    numeroVuelo = num;
    duracion = dr;
    origen = og;
    destino = des;

    }
    //Método que establece el valor del numero de vuelo en base
    //al numero contenido en su parametro
    void Vuelo :: setNumeroVuelo(int num){

    numeroVuelo = num;

    }
    //Metodo que establece la duracion del vuelo en base
    //al numero contenido en su parametro
    void Vuelo :: setDuracion(int dr){

    duracion = dr;

    }
    //Metodo que establece el lugar de origen del vuelo
    //en base al string de su parametro.
    void Vuelo :: setOrigen(string og){

    origen = og;

    }
    //Metodo que establece el lugar de destino del vuelo en
    //base al string de su parametro
    void Vuelo :: setDestino(string des){

    destino = des;

    }
    //Metodo que regresa el valor del numero de vuelo
    int Vuelo :: getNumeroVuelo(){

        return numeroVuelo;

    }
    //Metodo que regresa el valor de la duracion de un vuelo
    int Vuelo :: getDuracion(){

        return duracion;

    }
    //Metodo que regresa el nombre de la ciudad de origen del vuelo
    string Vuelo :: getOrigen(){

        return origen;

    }
    //Metodo que regresa el nombre de la ciudad de destino del vuelo
    string Vuelo :: getDestino(){

        return destino;

    }
    //Metodo que establece la hora de inicio del vuelo
    //en base al objeto de clase tiempo.
    void Vuelo :: setHoraInicio(Tiempo tp){
        horaInicio = tp;
    }
    //Metodo que regresa el objeto de clase tiempo que contiene
    //la hora de inicio del vuelo
    Tiempo Vuelo :: getHoraInicio(){
        return horaInicio;
    }





#endif // VUELO_H_INCLUDED
