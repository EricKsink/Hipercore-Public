#include "menu.hpp"

#include <iostream>
using namespace std;

Menu::Menu() {
    mainMenu();
    }

void Menu::enterToContinue() {
    fflush(stdin);
    cout<<"Enter para continuar..."<<endl;
    cin.get();
    }

void Menu::mainMenu() {

    int op;

    do {
        system("cls");

        cout<<"Bienvenido Digite la opcion deseada"<<endl;
        cout<<"1)Insertar Registro"<<endl;
        cout<<"2)Mostrar todos los registros"<<endl;
        cout<<"3)Consultar registro por DNI"<<endl;
        cout<<"4)Eliminar registro de manera logica"<<endl;
        cout<<"5)Generar lista de disponibles"<<endl;
        cout<<"6)Salir"<<endl;

        cout<<"Seleccione una opcion: ";
        cin>>op;

        switch(op) {
            case 1:
                addEmployee();
                break;
            case 2:
                showEmployee();
                break;
            case 3:
                findEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                ///AYUDAAA PAROOOOOOO
                break;
            case 6:
                cout<<"\nMaestra ponganos 10 Gracias :)";
                break;
            default:
                cout<<"\nOpcion invalida, intente de nuevo..."<<endl;
                enterToContinue();
            }

        }
    while(op!=6);

    }

void Menu::addEmployee() {
    char op;

    do {
        fflush(stdin);
        system("cls");

        Employee myEmployee;
        string myStr;
        float myFloat;
        Date myDate;

        cout<<"Digite el nombre del empleado :";
        getline(cin,myStr);
        myEmployee.setName(myStr);

        cout<<"Digite el cargo:";
        getline(cin,myStr);

        myEmployee.setJob(myStr);

        cout<<"Digite el salario: $";
        cin>>myFloat;

        myEmployee.setSalary(myFloat);

        cout<<"Digite la fecha de contratacion en formato [DD/MM/AAAA]: ";
        getline(cin,myStr,'/');
        myDate.setDay(stoi(myStr));
        getline(cin,myStr,'/');
        myDate.setMonth(stoi(myStr));
        getline(cin,myStr);
        myDate.setYear(stoi(myStr));

        myEmployee.setHireDate(myDate);

        cout<<"El empleado es...\n"<<myEmployee.toString();

        myList.push_back(myEmployee);

        do {
            cout<<"\n\nDesea Agregar otro empleado? [S/N]:";

            cin>>op;

            cin.ignore();

            op = toupper(op);
            }
        while(op != 'S' and op != 'N');

        }
    while(op == 'S');


    }

void Menu::showEmployee() {
    ///En este tipo de ciclos, necesitamos el tipo de dato y la lista a recorrer

    for (const Employee& myEmployee : myList) {
        cout<<myEmployee.toString()<<endl;
        }

        enterToContinue();
    }


void Menu::findEmployee() {

    }

void Menu::deleteEmployee() {

    }
