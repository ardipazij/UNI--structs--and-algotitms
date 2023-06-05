#pragma once
#include "train.h"

namespace constants{
    constexpr int TRAIN_SIZE{20};
}

class Railway_depot {
    private:
        int depot_number_{};
        Train trains[constants::TRAIN_SIZE]{};
        int size_{};
        Railway_depot * prev_;
    public:
	    Railway_depot();
        Railway_depot(int depot_number);
        void InitRailway_depot();

	    bool IsDepotFull();
	    bool IsDepotEmpty();

	    void SetCountTrains(int size);
        void SetDepot_number(int depot_number);
        void SetPrev(Railway_depot* const prev);

	    int GetCountTrains() const;
	    int GetDepot_number() const;
	    Railway_depot* GetPrev() const;

	    void AddTrain(const std::string& adress, int new_cash_machine_id);
	    void RemoveTrain(int id_to_remove);
	    int FindTrain(int search_id);

}