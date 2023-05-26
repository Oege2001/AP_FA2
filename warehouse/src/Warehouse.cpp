#include "include/Warehouse.hpp"
#include "include/Employee.hpp"
#include "include/Shelf.hpp"

Warehouse::Warehouse(){
    // Create a new warehouse.
    // Create a new employee.
    Employee employee("Johannes", true);
    // Add the employee to the warehouse.
    addEmployee(employee);
    // Create a new shelf.
    Shelf shelf;
    // Add the shelf to the warehouse.
    addShelf(shelf);
}

void Warehouse::addEmployee(Employee employee){
    // Add the employee to the employees vector.
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    // Add the shelf to the shelves vector.
    shelves.push_back(shelf);

}

bool Warehouse::rearrangeShelf(Shelf& shelf){
    // If the shelf is empty return false.
    if (shelf.isEmpty())
    return false;
    // If the shelf is full return false.
    if (shelf.isFull())
    return false;
    // If the employee is busy or does not have a forklift certificate return false.
    for (int i = 0; i < employees.size(); i++){
        if (employees[i].getBusy() == true)
        return false;
    }
    for (int i = 0 ; i < employees.size(); i++){
        if (employees[i].getForkliftCertificate() == false)
        return false;
    }

    for (int i = 0; i < 4; i++){
        if (shelf.pallets[i].getItemCount() > shelf.pallets[i + 1].getItemCount()) {
                // Swap pallets using the swapPallets function
                shelf.swapPallets(i, i + 1);
            }
        
        }
    return true;
    }
    
    

bool Warehouse::pickItems(std::string itemName, int itemCount){
    // If the itemCount is less than 1 return false.
    if (itemCount < 1)
    return false;
    // If the employee is busy return false.
    for (int i = 0; i < employees.size(); i++){
        if (employees[i].getBusy() == true)
        return false;
    }
    // If the shelf is empty return false.
    for (int i = 0; i < shelves.size(); i++){
        if (shelves[i].isEmpty() == true)
        return false;
    }
    // If the shelf is full return false.
    for (int i = 0; i < shelves.size(); i++){
        if (shelves[i].isFull() == true)
        return false;
    }
    // If the shelf does not contain the item return false.
    for (int i = 0; i < shelves.size(); i++){
        if (shelves[i].pallets[i].getItemName() != itemName)
        return false;
    }
    // If the shelf does not contain enough items return false.
    for (int i = 0; i < shelves.size(); i++){
        if (shelves[i].pallets[i].getItemCount() < itemCount)
        return false;
    }
    // If the employee does not have a forklift certificate return false.
    for (int i = 0; i < employees.size(); i++){
        if (employees[i].getForkliftCertificate() == false)
        return false;
    }
    // Else pick the items and return true.
    for (int i = 0; i < shelves.size(); i++){
        if (shelves[i].pallets[i].getItemName() == itemName){
            // Take one item from each pallet keep doing this till we got the amount of items we wanted.
            for (int j = 0; j < itemCount; j++)
                shelves[j].pallets[j].takeOne();
            return true;
        }
    }
    
}



