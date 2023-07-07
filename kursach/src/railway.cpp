#include "railway.h"

Railway::Railway():
	name_("DEFAULT"),
	root_(nullptr)
{
}

Railway::Railway(const std::string& name):
	name_(name),
	root_(nullptr)
{
}

Railway::~Railway(){
	Railway_depot* old{ root_};
	while (root_ != nullptr)
	{
		root_ = root_->GetPrev();
		delete old;
		old = root_;
	}   
}

std::string Railway::GetName() const{
    return name_;
}
void Railway::SetName(const std::string& name){
    name_ = name;
}
Railway_depot * Railway::GetRoot() const{
    return root_;
}
bool Railway::IsRailwayEmpty() const{
    return root_ == nullptr;
}
bool Railway::findDepot(int depot_number) const
{
	Railway_depot * current{ root_ };
	while (current != nullptr)
	{
		if (current->GetDepot_number() == depot_number)
			return true;

		current = current->GetPrev();
	}

	return false;
}
void Railway::pushDepot(int depot_number){
    if(findDepot(depot_number)){
        std::cout << "Депо с таким номером уже есть" << std::endl;
        return;
    }
    Railway_depot* new_depot{ new Railway_depot{depot_number} };
	new_depot->SetPrev(root_);
    root_ = new_depot;
}
void Railway::popDepot(){
    if(IsRailwayEmpty()){
        std::cout << "У железной дороге нет депо для удаления" << std::endl;
		return;
    }
    Railway_depot * cur = root_ ;   
	root_ = root_-> GetPrev();
	delete cur;
	return;
}

void Railway::add_train_to_depot(int depot_number, int id, const std::string& model){
    Railway_depot * current {root_};
    while (current != nullptr && current->GetDepot_number() != depot_number)
		current = current->GetPrev();
    if (current == nullptr)
	{
		std::cout << "Депо не найдено"  << '\n';
		return;
	}

	current->AddTrain(model, id);
}
void Railway::remove_train_from_depot(int depot_number, int id){
    Railway_depot * current {root_};
    while (current != nullptr && current->GetDepot_number() != depot_number)
		current = current->GetPrev();
    if (current == nullptr)
	{
		std::cout << "Депo не найдено"  << '\n';
		return;
	}

	current->RemoveTrain(id);
}

void Railway::printDepots() const{
    if (IsRailwayEmpty())
	{
		std::cout << "\nЖелезная дорога не имеет депо\n";
		return;
	}

	Railway_depot * temp {root_};
	while (temp != nullptr)
	{
		std::cout << "Депо: " << temp->GetDepot_number() << '\n';
		temp->PrintTrain();
		temp = temp->GetPrev();
	}
}