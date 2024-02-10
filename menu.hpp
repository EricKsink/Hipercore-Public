#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include"employee.hpp"

#include<list>

class Menu {
    private:

        std::list<Employee> myList;

    public:

        Menu();
        void mainMenu();
        void enterToContinue();
        void addEmployee();
        void showEmployee();
        void findEmployee();
        void deleteEmployee();

        //void GENERA La lista de disponibles

    };

#endif // MENU_HPP_INCLUDED
