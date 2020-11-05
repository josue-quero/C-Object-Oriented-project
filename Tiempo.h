#ifndef TIEMPO_H_INCLUDED
#define TIEMPO_H_INCLUDED

class Tiempo{
public:
    Tiempo();
    Tiempo(int hr, int mint);
    void setHora(int hr);
    void setMinuto(int mint);
    int getHora();
    int getMinuto();

private:
    int hora, minuto;
};
    //Constructor default que determina los valores
    //por default de los atributos de la clase Tiempo
    Tiempo :: Tiempo(){
        hora = 1;
        minuto = 1;
    }
    //Constructor con parametros que establece los valores
    //de los atributos de la clase Tiempo en base a sus parametros
    Tiempo :: Tiempo(int hr, int mint){

        hora = hr;
        minuto = mint;

    }
    //Metodo que establece la hora en base
    //al valor integro de su parametro
    void Tiempo :: setHora(int hr){

        hora = hr;

    }
    //Metodo que establece el minuto en base
    //al valor integro de su parametro
    void Tiempo :: setMinuto(int mint){

        minuto = mint;

    }
    //Metodo que regresa la hora guardada
    //en el objeto
    int Tiempo :: getHora(){

        return hora;
    }
    //Metodo que regresa el valor del minuto
    //guardado en el objeto
    int Tiempo :: getMinuto(){
        return minuto;
    }


#endif // TIEMPO_H_INCLUDED
