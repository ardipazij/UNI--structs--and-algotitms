#include "railway_depot.h"

Railway_depot::Railway_depot():
    depot_number_{-1},
    size_{0},
    prev_{nullptr}
{
    InitRailway_depot();
}

void Railway_depot::InitRailway_depot(){
    for (int i{ 0 }; i < constants::TRAIN_SIZE; i++) {
		trains[i] = Train();
	}
}

Railway_depot::Railway_depot(int depot_number):
    depot_number_{depot_number},
    size_{0},
    prev_{nullptr}
{
    InitRailway_depot();
}
bool Railway_depot::IsDepotFull() const{
    return size_ == constants::TRAIN_SIZE;
}
bool Railway_depot::IsDepotEmpty() const{
    return size_ == 0;
}
void Railway_depot::SetCountTrains(int size){
    size_ = size;
}
int Railway_depot::GetCountTrains() const{
    return size_;
}
void Railway_depot::SetDepot_number(int depot_number){
    depot_number_ = depot_number;
}
int Railway_depot::GetDepot_number() const{
    return depot_number_;
}
void Railway_depot::SetPrev(Railway_depot* const prev){
    prev_ = prev;
}
Railway_depot * Railway_depot::GetPrev() const{
    return prev_;
}

void Railway_depot::AddTrain(const std::string& model, int id) {

	if (IsDepotFull()) {
		std::cout << "В депо нет мест для регистрации новых поездов" << std::endl;
		return;
	}
    if(FindTrain(id) != -1){
        std::cout << "Поезд с таким регистрационным номером уже есть" << std::endl;
		return;
    }
	Train new_train= Train(model,id);
	if (IsDepotEmpty()) {
		trains[0] = new_train;
	}
	else {
		int i;
		for (i = 0; i < size_; i++) {
			if ( trains[i].getId() > new_train.getId()) {
				for (int j = size_; j > i; j--) {
					trains[j] = trains[j - 1];
				}
				trains[i] = new_train;
				break;
			}
		}
		if (i == size_) {
			trains[i] = new_train;
		}
	}
	size_++;
}
int Railway_depot::FindTrain(int search_id) const{
    int first{ 0 };
	int last{ size_ - 1 };
	int mid{};
	while (first <= last) {
		mid = (first + last) / 2;
		if (trains[mid].getId() == search_id) {
			return mid;
		}
		else if (trains[mid].getId() > search_id) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	return -1;
}
void Railway_depot::RemoveTrain(int id_to_remove){
	int find_ind{ FindTrain(id_to_remove) };
	for (int i = find_ind; i < size_ - 1; i++) {
		trains[i] = trains[i + 1];
	}
	size_--;
}

void Railway_depot::PrintTrain() const
{
	if (IsDepotEmpty())
	{
		std::cout << "\nДепо пусто\n";
		return;
	}
    int i;
    for(i = 0; i < size_; i++){
        std::cout << "Поезд: " << trains[i].getId() << " (" <<
			trains[i].getModel() << ")\n";
    }
}

const Train *Railway_depot::GetTrain() const {
    return trains;
}