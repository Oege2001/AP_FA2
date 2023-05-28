#include <iostream>
#pragma once


class Employee{
    private:
        std::string name;
        bool busy;
        bool forkliftCertificate;
    
    public:
        Employee(){}
        Employee(std::string name, bool forkliftCertificate);
        
        std::string getName();
        bool getBusy();
        void setBusy(bool busy);
        bool getForkliftCertificate();
        void setForkliftCertificate(bool forkliftCertificate);

};
