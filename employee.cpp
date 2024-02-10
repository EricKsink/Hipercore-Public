#include"employee.hpp"

#include<iostream>
#include<string>
#include<random>
#include<cstring>

///Se usan en el toString
#include<sstream>
#include<iomanip> ///Se usa para la funcion fixed y setprecision

using namespace std;

Employee::Employee() {
    ///El contructor hace que el empleado cuando se crea ya tenga un DNI
    setDni();
    }

Employee::Employee(const Employee& other) {
    ///Constructor copia
    strncpy(this->name, other.name, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0'; // Asegura que name esté terminado con '\0'

    strncpy(this->dni, other.dni, sizeof(this->dni) - 1);
    this->dni[sizeof(this->dni) - 1] = '\0'; // Asegura que dni esté terminado con '\0'

    strncpy(this->job, other.job, sizeof(this->job) - 1);
    this->job[sizeof(this->job) - 1] = '\0'; // Asegura que job esté terminado con '\0'

    this->age = other.age;
    this->salary = other.salary;
    this->hireDate = other.hireDate;
    }

string Employee::getName() const {
    string nameString(name);
    return nameString;
    }

string Employee::getDni() const {
    string dniString(dni);
    return dniString;
    }

string Employee::getJob() const {
    string jobString(job);
    return jobString;
    }

int Employee::getAge() const {
    return age;
    }

float Employee::getSalary() const {
    return salary;
    }

Date Employee::getHireDate() const {
    return hireDate;
    }

string Employee::toString() const {
    string myStr;

    string dniString=dni;
    string nameString=name;
    string jobString=job;

    ///Funcion sacada de stackoverflow no pregunte maestra :c
    stringstream ss;
    ss << fixed << setprecision(2) << salary; /// Configurar 2 decimales con setprecision, (fixed lo dejamos así, si no no jala)
    string salaryString = ss.str();

    myStr = dniString +"|"+ nameString +"|"+ jobString +"|$"+ salaryString +"|"+ hireDate.toString();

    return myStr;
    }

void Employee::setName(string& n) {
    ///Convertimos la variable string a mayuscula
    for(int i=0; i < n.length(); i++){
        n[i] = toupper(n[i]);
    }

    ///Copiamos n en name
    ///     Destino, Fuente, Num de caracteres  (se usa c_str ya que estamos ingresando una variable de tipo string a un arreglo de caracteres)
    strncpy(name, n.c_str(), sizeof(name));


    ///Rellenamos con espacios en blanco menos el ultimo caracter, El ultimo caracter devera de ser \0
    for (int i = n.length(); i < sizeof(name) - 1; i++) {
        name[i] = ' ';
        }

    name[sizeof(name) - 1] = '\0'; /// Asegura que nombre termine con '\0'

    }

void Employee::setDni() {
    ///Esto de abajo es un generador de numeros aleatorios
    random_device rd;
    mt19937 generator(rd());

    ///Le digo al programa de que valor a que valor a que valor
    uniform_int_distribution<int> distribucion(0, 99999999);



    int randomNumber = distribucion(generator);

    int remainder = randomNumber % 23;

    ///int leftover[23]={0 ,1, 2,  3,  4,  5,  6,  7,  8,  9,  10,  11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};

    ///Guarda primero el numero random y despues la letra
    snprintf(dni,sizeof(dni),"%08i%c",randomNumber,letter[remainder]);

    }

void Employee::setJob(string& j) {
    ///Convertimos la variable string a mayuscula

    for(int i=0; i < j.length(); i++){
        j[i] = toupper(j[i]);
    }


    ///Copiamos n en job
    ///Destino, Fuente, Num de caracteres  (se usa c_str ya que estamos ingresando una variable de tipo string a un arreglo de caracteres)
    strncpy(job, j.c_str(), sizeof(job));

    ///Llenamos con espacios en blanco
    for (int i = j.length(); i < sizeof(job) - 1; i++) {
        job[i] = ' ';
        }

    job[sizeof(job) - 1] = '\0'; /// Asegura que nombre termine con '\0'

    }

void Employee::setAge(const int& a) {
    age = a;
    }

void Employee::setSalary(const float& s) {
    salary = s;
    }

void Employee::setHireDate(const Date& d) {
    hireDate = d;
    }

