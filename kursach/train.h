#pragma once

#include <string>

class Train {
private:
  std::string model_;
  int id_;
public:
    Train();
    Train(const std::string& model, int id);
    
    void setModel(const std::string& model);
	void setId(int id);

    std::string getModel() const;
    int getId() const;
};