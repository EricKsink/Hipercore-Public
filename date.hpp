#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

#include<string>

class Date {
    private:

        //Vamo a poner los atributos
        int day;
        int month;
        int year;

        //No queremos tener fechas malas entonces vamos a validarlas antes de guardarlas, y si ingresa una fecha erronea se insertara la fecha actual
        bool isLeapYear(const int&);
        bool isValid(const int&, const int&, const int&);

    public:
        Date();
        Date(const Date&);
        Date(const int&, const int&, const int&);

        int getDay() const;;
        int getMonth() const;
        int getYear() const;

        std::string toString() const;

        void setDay(const int&);
        void setMonth(const int&);
        void setYear(const int&);


    };

#endif // DATE_HPP_INCLUDED
