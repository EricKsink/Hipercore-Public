#ifndef EMPLOYEE_HPP_INCLUDED
#define EMPLOYEE_HPP_INCLUDED

#include<string>

#include"date.hpp"

class Employee {
    private:

        char name[50];
        char dni[10];
        char job[20];
        int age;
        float salary;
        Date hireDate;

    public:

        Employee();
        Employee(const Employee&);

        std::string getName() const;
        std::string getDni() const;
        std::string getJob() const;
        int getAge() const;
        float getSalary() const;
        Date getHireDate() const;

        std::string toString() const;

        void setName( std::string&);
        void setDni();
        void setJob( std::string&);
        void setAge(const int&);
        void setSalary(const float&);
        void setHireDate(const Date&);

    };

#endif // EMPLOYEE_HPP_INCLUDED
