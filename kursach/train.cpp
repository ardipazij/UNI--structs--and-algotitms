#include "train.h"

Train::Train()
    : model_{"Default"}
    , id_ {-1}
{
}
Train::Train(const std::string& model, int id) 
    : model_{model}
    , id_{id} 
{
}

void Train::setModel(const std::string& model)
{
	model_ = model;
}

void Train::setId(int id)
{
	id_ = id;
}

std::string Train::getModel() const { return model_; }
int Train::getId() const { return id_; }