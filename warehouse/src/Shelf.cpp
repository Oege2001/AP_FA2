#include "include/Container.hpp"
#include "include/Pallet.hpp"
#include "include/Shelf.hpp"



Shelf::Shelf(){
    // Set the pallets to empty Pallets.
    for (int i = 0; i < 4; i++){
        pallets[i] = Pallet();
    }
};


bool Shelf::swapPallets(int slot1, int slot2){
    // If the slot1 or slot2 is not between 0 and 3 return false.
    if (slot1 < 0 || slot1 > 3 || slot2 < 0 || slot2 > 3)
    return false;
    // Else swap the pallets at slot1 and slot2 and return true.
    else{
        
        Pallet temp = pallets[slot1];
        pallets[slot1] = pallets[slot2];
        pallets[slot2] = temp;
        return true;
    }
};

bool Shelf::isEmpty(){
    // For each pallet in pallets.
    // if the pallet is not empty return false.
    for (int i = 0; i < 4; i++){
        if (!pallets[i].isEmpty())
        return false;
    }
    // Return true.
    return true;
};

bool Shelf::isFull(){
    // For each pallet in pallets.
    // If the pallet is not full return false.
    for (int i = 0; i < 4; i++){
        if (!pallets[i].isFull())
        return false;
    }
    return true;
};


