#include "include/Warehouse.hpp"
#include "include/Employee.hpp"
#include "include/Shelf.hpp"

Warehouse::Warehouse(){
    // // Create a new employee.
    // // Create a new warehouse.
    // Employee employee("Johannes", true);
    // // Add the employee to the warehouse.
    // addEmployee(employee);
    // // Create a new shelf.
    // Shelf shelf;
    // // Add the shelf to the warehouse.
    // addShelf(shelf);
    employees = {};
    shelves = {};

}


void Warehouse::addEmployee(Employee employee){
    // Add the employee to the employees vector.
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    // Add the shelf to the shelves vector.
    shelves.push_back(shelf);

}

bool Warehouse::rearrangeShelf(Shelf& shelf)
{
bool running = false;

for (int i =0; i < employees.size(); i++)
{   // if employee has forklift certificate and is not busy. set running to true.
    if (employees[i].getForkliftCertificate() && !employees[i].getBusy())
    {
        running = true;
        while (running)
        // while running is true, set running to false and if itemcount on pallet 1 is bigger then on pallet 2 than swap pallets. 
        {
            running = false;
            for (int i = 0; i < shelf.pallets.size() - 1; i++)
            {
                if (shelf.pallets[i].getItemCount() > shelf.pallets[i + 1].getItemCount())
                {
                    shelf.swapPallets(i, i + 1);
                    // set running to true.
                    running = true;
                }
            }
        }
        return true;
    }
    return false;
}

}




bool Warehouse::pickItems(std::string itemName, int itemCount) {
    // Had some help from chatgpt with this function.
    // If the itemCount is less than 1, return false.
    if (itemCount < 1)
        return false;

    // Check conditions with a while loop
    
    bool employeeNotBusy = false;
    bool shelfNotEmpty = false;
    bool shelfFull = false;
    bool shelfContainsItem = false;
    bool enoughItems = false;
    bool employeeHasForklift = false;

    int i = 0;
    // while i is lower then the size of the employees vector, check if the employee is busy. if not set employeeNotBusy to true and break the loop.
    // else increment i.
    while (i < employees.size()) {
        if (employees[i].getBusy() == false) {
            employeeNotBusy = true;
            break;
        }
        i++;
    }

    i = 0;
    // while i is lower then the size of shelves , check if the shelf is empty. if not set shelfNotEmpty to true and break the loop.
    // else increment i.
    while (i < shelves.size()) {
        if (shelves[i].isEmpty() == false) {
            shelfNotEmpty = true;
            break;
        }
        i++;
    }

    i = 0;
    // while i is lower then the size of shelves , check if the shelf is full. if not set shelfFull to true and break the loop.
    // else increment i.
    while (i < shelves.size()) {
        if (shelves[i].isFull() == true) {
            shelfFull = true;
            break;
        }
        i++;
    }

    i = 0;
    // While i is lower then the size of shelves , check if the shelf contains the item. if not set shelfContainsItem to true and break the loop.
    // else increment i.
    while (i < shelves.size()) {
        if (shelves[i].pallets[i].getItemName() == itemName) {
            shelfContainsItem = true;
            break;
        }
        i++;
    }

    i = 0;
    // while i is lower then the size of shelves , check if the shelf contains enough items. if not set enoughItems to true and break the loop.
    while (i < shelves.size()) {
        if (shelves[i].pallets[i].getItemCount() >= itemCount) {
            enoughItems = true;
            break;
        }
        i++;
    }

    i = 0;
    // while i is lower then the size of employees , check if the employee has a forklift certificate. if not set employeeHasForklift to true and break the loop.
    // else increment i.
    while (i < employees.size()) {
        if (employees[i].getForkliftCertificate() == true) {
            employeeHasForklift = true;
            break;
        }
        i++;
    }

    // If any of the conditions are not met, return false.
    if (!employeeNotBusy || !shelfNotEmpty || shelfFull || !shelfContainsItem || !enoughItems || !employeeHasForklift)
        return false;

    // Else pick the items and return true.
    for (int i = 0; i < shelves.size(); i++) {
        if (shelves[i].pallets[i].getItemName() == itemName) {
            // Take one item from each pallet keep doing this till we got the amount of items we wanted.
            for (int j = 0; j < itemCount; j++)
                shelves[j].pallets[j].takeOne();
            return true;
        }
    }

    return false; // Return false if no matching item is found
}
