#pragma once
#include "railway_depot.h"
class Railway{
    private:
        std::string name_;
        Railway_depot * root_{};
    public:
        Railway();
        Railway(const std::string& name);
        ~Railway();

        std::string GetName() const;
	    void SetName(const std::string& name);
        Railway_depot * GetRoot() const;

        bool findDepot(int depot_number) const;
        bool IsRailwayEmpty() const;
	    void pushDepot(int depot_number);
	    void popDepot();
        
        void add_train_to_depot(int depot_number, int id, const std::string& model);
        void remove_train_from_depot(int depot_number, int id);

        void printDepots() const;
};