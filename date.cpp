#include"date.hpp"

#include<ctime>
#include<iostream>
#include<string>

using namespace std;

bool Date::isValid(const int& d, const int& m, const int& y) {
    /*
    Vamos a hacer los mas facil primero,
    Un año no puede ser menor a 0, un mes no puede ser menor a 1 (no existe dia 0)
    no hay mas de 12 meses y tampoco puede ser menor que 1.
    */

    if (y < 0 || m < 1 || m > 12 || d < 1)
        return false;

    //Se crea un arreglo para modificarlo en el caso de que febrero sea el mes ingresado
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //En caso de que el a�o sea bisiesto y el mes ingresado gebrero modificamos los dias de este dentro del arreglo
    if (isLeapYear(y) && m == 2) {
        //febrero  = 29
        daysInMonth[2] = 29;
        }

    //Hacemos comparacion del dia con respecto del numero de dias del mes ingresado
    return (d >= 1 && d <= daysInMonth[m]);

    }

bool Date::isLeapYear(const int& y) {
    /*
    AJSDJASJ no sabia cuando es un a�o bisiesto o no entonces investigue las reglas
    1.-Es un a�o bisiesto s� es divisible por 4
    2.-Pero si es divisible por 100 no lo es
    3.-Pero si es divisible entre 400 entonces si es un a�o bisiesto
    */
    return((y % 4 == 0 && y % 100!=0) || (y % 400 == 0));
    }

//construtor
Date::Date() {
// Obtener la fecha actual del sistema
    time_t now = time(0);
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);  //Maestra si lee esto no pregunte por esto, buscamos las funciones en internet :c

    day = timeinfo.tm_mday;
    month = timeinfo.tm_mon + 1;  // Se suma 1 porque en la estructura tm, enero es 0
    year = timeinfo.tm_year + 1900;  // Se suma 1900 porque tm_year cuenta los a�os desde 1900
    }

//construtor copia
Date::Date(const Date& d) :day(d.day),month(d.month),year(d.year) {}

//construtor con parametros
Date::Date(const int& d, const int& m, const int& y) : Date() {
//Si se desea crear un objeto tipo fecha con parametros debemos de ver que los parametro esten correctos
    if(isValid(d,m,y)) {
        day = d;
        month = m;
        year = y;
        }

    }

//ZZZZZZZZZZZZZZZZZZZZ lo de abajo

int Date::getDay() const {
    return day;
    }

int Date::getMonth() const {
    return month;
    }

int Date::getYear() const {
    return year;
    }

string Date::toString() const {
    char myStr[10];
    ///sprintf sirve parecido a printf, en este caso lo usaremos para guardar la fecha en formato DD/MM/YYYY
    sprintf(myStr,"%02i/%02i/%04i",day,month,year);
    return myStr;
    }

void Date::setDay(const int& d) {
    if(isValid(d,month,year)) {
        day = d;
        }
    }

void Date::setMonth(const int& m) {
    if(isValid(day,m,year)) {
        month = m;
        }
    }

void Date::setYear(const int& y) {
    if(isValid(day,month,y)) {
        year = y;
        }
    }

