#include "include/Container.hpp"
#include "include/Pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity){
    // Set the itemname and itemcapacity to the given parameters.
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    // Set the itemcount to 0.
    this->itemCount = 0;
};

Pallet::Pallet(){
    // Set the itemname to empty string.
    this->itemName = "";
    // Set the itemcapacity to 0.
    this->itemCapacity = 0;
    // Set the itemcount to 0.
    this->itemCount = 0;
};

std::string Pallet::getItemName(){
    // Return the itemname.
    return itemName;
};

int Pallet::getItemCount(){
    // Return the itemcount.
    return itemCount;
};

int Pallet::getRemainingSpace(){
    // Return the itemcapacity - itemcount.
    return itemCapacity - itemCount;
};

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    // If the itemcount is not 0 return false.
    if (getItemCount() != 0)
    return false;
    // Else set the itemname and itemcapacity to the given parameters.
    else{
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    }
};

bool Pallet::takeOne(){
    // If the itemcount is 0 return false.
    if (getItemCount() == 0)
    return false;
    // Else decrease the itemcount by 1 and return true.
    else{
        itemCount--;
        return true;
    }
};

bool Pallet::putOne(){
    // If the itemcount is equal to itemcapacity return false.
    if (getItemCount() == itemCapacity)
    return false;
    // Else increase the itemcount by 1 and return true.
    else{
        itemCount++;
        return true;
    }
};




























bool Pallet::isEmpty(){
    // First check if itemcount is empty if true then return true else return false.
            if (getItemCount() == 0)
            return true;
            else 
            return false;

        };

bool Pallet::isFull(){
    // First check if remainingspace is empty if true return true else return false.
            if (getRemainingSpace()== 0)
            return true;
            else 
            return false;

        };