#include "include/Employee.hpp"

// Employee::Employee(const std::string name, bool forkliftCertificate){
//     // Set the name and forkliftCertificate to the given parameters.
//     this->busy = false;
// }


std::string Employee::getName(){
    // Return the name.
    return name;
}

bool Employee::getBusy(){
    // Return the busy status.
    return busy;
}

void Employee::setBusy(bool busy){
    // Set the busy status to the given parameter.
    this->busy = busy;
}

bool Employee::getForkliftCertificate(){
    // Return the forkliftCertificate status.
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate){
    // Set the forkliftCertificate status to the given parameter.
    this->forkliftCertificate = forkliftCertificate;
}



