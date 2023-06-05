#pragma once
#include "railway.h"

class Menu{
    public:
        int getNumber();
        std::string getString();
        void print_info();
        void Railway_add(Railway& railway);
        void Depot_search( Railway railway);
        void Console_output(const Railway railway);
        void Delete_Depot(Railway& railway);
        void Train_add(Railway& railway);
};