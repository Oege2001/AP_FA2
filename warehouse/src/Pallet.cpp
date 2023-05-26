#include "include/Container.hpp"
#include "include/Pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity){
    // Set the itemName and itemCapacity to the parameters.
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    // Set the itemCount to 0.
    this->itemCount = 0;
};

Pallet::Pallet(){
    // Set the itemName to an empty string.
    this->itemName = "";
    // Set the itemCapacity to 0.
    this->itemCapacity = 0;
    // Set the itemCount to 0.
    this->itemCount = 0;
};

std::string Pallet::getItemName(){
    // Return the itemName.
    return itemName;
};

int Pallet::getItemCount(){
    // Return the itemCount.
    return itemCount;
};

int Pallet::getRemainingSpace(){
    // Return the itemCapacity minus itemCount.
    return itemCapacity - itemCount;
};

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    // If the itemCount is not equal to 0 return false.
    if (getItemCount() != 0)
    return false;
    // Else set the itemName and itemCapacity to the given parameters.
    else{
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    }
};

bool Pallet::takeOne(){
    // If the itemCount is 0 return false.
    if (getItemCount() == 0)
    return false;
    // Else decrease the itemCount by 1 and return true.
    else{
        itemCount--;
        return true;
    }
};

bool Pallet::putOne(){
    // If the itemCount is equal to itemCapacity return false.
    if (getItemCount() == itemCapacity)
    return false;
    // Else increase the itemCount by 1 and return true.
    else{
        itemCount++;
        return true;
    }
};

bool Pallet::isEmpty(){
    // Check if itemCount is empty if true then return true, else return false.
            if (getItemCount() == 0)
            return true;
            else 
            return false;

        };

bool Pallet::isFull(){
    // Check if remainingSpace is empty if true return true, else return false.
            if (getRemainingSpace()== 0)
            return true;
            else 
            return false;

        };