#include "file.h"
#include <filesystem>
void File::writeToFile(const Railway& railway, const std::string& filename){
    std::ofstream outputFile{ filename };

	outputFile << "Железная дорога:" << railway.GetName() << '\n';
	Railway_depot * current{ railway.GetRoot() } ;
	while (current != nullptr)
	{
		outputFile << "Depot:" << current->GetDepot_number() << '\n';
        
		const Train* temp{ current->GetTrain() };
		outputFile << "Trains:";
        int  i{0};
		while (temp[i].getId() != -1 )
		{
			outputFile << temp[i].getId() << ',' << temp[i].getModel();
			outputFile << ';';
                i++;
		}
		outputFile << '\n';
		current = current->GetPrev();
	}
}

bool File::readFromFile(Railway& railway, const std::string& filename)
{
	if (!std::filesystem::exists(filename))
	{
		std::cerr << "\ncoudln't open file " << filename << '\n';
		return false;
	}

	if (std::filesystem::file_size(filename) == 0)
	{
		std::cerr << "\nfile " << filename << " is empty\n";
		return false;
	}

	std::ifstream inputFile{ filename };
	std::string line{};

	std::getline(inputFile, line);
	auto pos{ line.find(':') };
	if (pos != std::string::npos)
		railway.SetName(line.substr(pos + 1));
	else
	{
		std::cout << "invalid input.txt: no airline name\n";
		return false;
	}

	while (std::getline(inputFile, line))
	{
		pos = line.find(':');
		if (pos == std::string::npos)
		{
			std::cout << "invalid input.txt: depot info\n";
			return false;
		}

		int currentDepot_name{ std::stoi(line.substr(pos + 1)) };
		railway.pushDepot(currentDepot_name);

		std::getline(inputFile, line);
		pos = line.find(':');
		if (pos == std::string::npos)
		{
			std::cout << "invalid input.txt: train info\n";
			return false;
		}

		std::string trainLine{ line.substr(pos + 1) };
		std::size_t startOfInfo{ 0 };
		std::size_t endOfInfo{ trainLine.find(';') };
		while (true)
		{
			std::string trainInfo{ trainLine.substr(startOfInfo, endOfInfo) };
			if (trainInfo.empty())
				break;
			std::size_t endOfTrainModelInfo{ trainInfo.find(',') };
			std::string trainModel{ trainInfo.substr(startOfInfo, endOfTrainModelInfo) };
			int train_id{
				std::stoi(trainInfo.substr(endOfTrainModelInfo + 1, endOfInfo)) };
			railway.add_train_to_depot(currentDepot_name, train_id, trainModel);

			if (trainLine.find(';') == std::string::npos)
				break;
			trainLine = trainLine.substr(trainLine.find(';') + 1);
			endOfInfo = trainLine.find(';');
		}
	}

	return true;
}