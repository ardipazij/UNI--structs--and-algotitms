#include "railway.h"

Railway::Railway():
	name_("DEFAULT"),
	root(nullptr)
{
}

Railway::Railway(const std::string& name):
	name_(name),
	root(nullptr)
{
}

Railway::~Railway(){
    DestroyRailway();
}

std::string&  Railway::GetName(){
    return name_;
}
void Railway::SetName(const std::string& name){
    name_ = name;
}