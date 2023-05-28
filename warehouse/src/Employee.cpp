#include "include/Employee.hpp"


Employee::Employee(std::string name, bool forkliftCertificate)
{
    this->name = name;
    this->forkliftCertificate = forkliftCertificate;
    this->busy = false;
}


std::string Employee::getName(){
    // Return the name.
    return this -> name;
}

bool Employee::getBusy(){
    // Return the busy status.
    return this -> busy;
}

void Employee::setBusy(bool busy){
    // Set the busy status to the given parameter.
    this->busy = busy;
}

bool Employee::getForkliftCertificate(){
    // Return the forkliftCertificate status.
    return this -> forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate){
    // Set the forkliftCertificate status to the given parameter.
    this -> forkliftCertificate = forkliftCertificate;
}



