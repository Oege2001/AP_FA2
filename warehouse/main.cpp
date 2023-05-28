#include <iostream>
#include "src/include/Warehouse.hpp"


int main(void) {
    // Create an empty wearehouse
    Warehouse warehouse = Warehouse();
    // Create a shelf with 4 pallets filled with items to put into the warehouse
    Shelf shelf = Shelf();
    shelf.pallets = {
        Pallet("Shoes", 30, 20),
        Pallet("TV's", 50, 40),
        Pallet("TV's", 15, 10),
        Pallet("Shoes", 69, 14)
    };

    // Add the shelf into the warehouse
    warehouse.addShelf(shelf);
    // Create an employee with no forkliftCertificate
    Employee Jacob = Employee("Jacob", true);
    // Add an employee to the warehouse who doesn't have a forkliftCertificate
    warehouse.addEmployee(Jacob);


    // Picking items and rearranging shelves
    // We raerrange shelves by sorting them on item count
    if(warehouse.rearrangeShelf(shelf))
    {
        std::cout << "Rearranged shelf" << std::endl;
    };
    // We can also pick items and a certain amount
    if(warehouse.pickItems("Shoes", 10))
    {
        std::cout << "Picked items" << std::endl;
    };

}

