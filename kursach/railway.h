#pragma once
#include "railway_depot.h"
class Railway{
    private:
        std::string name_{};
        Railway_depot * root{};
    public:
        Railway();
        Railway(const std::string& name);
        ~Railway();

        std::string& GetName();
	    void SetName(const std::string& name);

        
        
}