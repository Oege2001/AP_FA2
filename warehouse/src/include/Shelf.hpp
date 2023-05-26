#include <iostream>
#pragma once
#include "Container.hpp"
#include "Pallet.hpp"
#include <array>



class Shelf:public IContainer{

    public:
    std::array<Pallet, 4> pallets;

    
    Shelf();
    
    
    bool swapPallets(int slot1, int slot2);

    bool isEmpty();

    bool isFull();

};


