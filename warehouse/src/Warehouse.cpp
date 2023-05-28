#include "include/Warehouse.hpp"
#include "include/Employee.hpp"
#include "include/Shelf.hpp"

Warehouse::Warehouse(){
    // Create an empty vector for employees and shelves.
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

// Create a bool running and set it to false.
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
    // If the itemCount is less than 1, return false.
    if (itemCount < 1)
        return false;

    // Check conditions with a while loop
    
    bool shelfNotEmpty = false;
    bool shelfContainsItem = false;
    bool enoughItems = false;

    int i = 0;
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


    // If any of the conditions are not met, return false.
    if (!shelfNotEmpty || !shelfContainsItem || !enoughItems)
        return false;


    int itemsTaken = 0;
    // set itemstaken to 0 and loop through the shelves. loop through the pallets and if the pallet contains the itemname and the itemcount is bigger then 0
    // take one item from the pallet and increment itemstaken. if itemstaken is equal to itemcount return true.
    for (auto& shelf : shelves) {
        for (auto& pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName) {
                while (itemsTaken < itemCount) {
                    if (pallet.getItemCount() > 0) {
                        pallet.takeOne();
                        itemsTaken++;
                    } else {
                        break;
                    }
                }
                if (itemsTaken == itemCount)
                    return true;
            }
        }
    }
    return false; // Return false if no matching item is found
}
