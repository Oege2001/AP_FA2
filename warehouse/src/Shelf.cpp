#include "include/Container.hpp"
#include "include/Pallet.hpp"
#include "include/Shelf.hpp"


// create shelf here
Shelf::Shelf(){
};


bool Shelf::swapPallets(int slot1, int slot2){

    Pallet pallet = pallets[slot1];
    pallets[slot1] = pallets[slot2];
    pallets[slot2] = pallet;
    return true; 
};

bool Shelf::isEmpty(){
    // For each pallet in pallets.
    // if the pallet is not empty return false.
    for (int i = 0; i < 4; i++){
        if (!pallets[i].isEmpty()){
            return false;
        }
    }
    // Return true.
    return true;
};

bool Shelf::isFull(){
    // For each pallet in pallets.
    // If the pallet is not full return false.
    for (int i = 0; i < 4; i++){
        if (!pallets[i].isFull()){
            return false;
        }
    }
    return true;
};


