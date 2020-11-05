#ifndef PASAJERO_H_INCLUDED
#define PASAJERO_H_INCLUDED
#include <string>

class Pasajero{
public:

    Pasajero();
    Pasajero(string nom, string ape, string asi, int num, int id);
    void setNumeroVuelo(int num);
    void setNombre(string nom);
    void setApellido(string ape);
    void setAsiento(string asi);
    void setId(int id);
    int getNumeroVuelo();
    int getId();
    string getNombre();
    string getApellido();
    string getAsiento();

private:
    string nombre, apellido, asiento;
    int numeroVuelo, identificacion;
};
    //Constructor default que establece los valores iniciales
    //de los atributos de la clase
    Pasajero :: Pasajero(){
        nombre = "David";
        apellido = "Marcial";
        asiento = "4F";
        numeroVuelo = 0000;
        identificacion = 0001;
    }
    //Constructor con parametros que establece los valores de los atributos
    //de la clase en base a sus parametros
    Pasajero :: Pasajero(string nom, string ape, string asi, int num, int id){
        nombre = nom;
        apellido = ape;
        asiento = asi;
        numeroVuelo = num;
        identificacion = id;
    }
    //Metodo que establece el valor del numero de vuelo
    //en base al valor recibido en su parametro
    void Pasajero :: setNumeroVuelo(int num){
        numeroVuelo = num;
    }
    //Metodo que establece el nombre del pasajero en base
    //al valor del string en su parametro
    void Pasajero :: setNombre(string nom){

        nombre = nom;

    }
    //Metodo que establece el valor del apellido del pasajero
    //en base a su parametro
    void Pasajero :: setApellido(string ape){
        apellido = ape;
    }
    //Metodo que establece el asiento del pasajero
    //en base al valor recibido en su parametro
    void Pasajero :: setAsiento(string asi){

        asiento = asi;

    }
    //Metodo que establece el id del pasajero
    //en base al valor de su parametro
    void Pasajero :: setId(int id){
        identificacion = id;
    }
    //Metodo que regresa el valor del numero de vuelo
    //del pasajero
    int Pasajero :: getNumeroVuelo(){
        return numeroVuelo;
    }
    //Metodo que regresa el nombre del pasajero
    //contenido en el objeto
    string Pasajero :: getNombre(){
        return nombre;
    }
    //Metodo que regresa el valor del apellido del pasajero
    string Pasajero :: getApellido(){
        return apellido;
    }
    //Metodo que regresa el asiento asignado al pasajero
    string Pasajero :: getAsiento(){
        return asiento;
    }
    //Metodo que regresa el numeor de id del pasajero
    int Pasajero :: getId(){
        return identificacion;
    }


#endif // PASAJERO_H_INCLUDED
