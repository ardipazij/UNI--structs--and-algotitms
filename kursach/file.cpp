#include "file.h"
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

// bool FileIO::readAirlinesFromFile(Airline& airline, const std::string& filename)
// {
// 	if (!std::filesystem::exists(filename))
// 	{
// 		std::cerr << "\ncoudln't open file " << filename << '\n';
// 		return false;
// 	}

// 	if (std::filesystem::file_size(filename) == 0)
// 	{
// 		std::cerr << "\nfile " << filename << " is empty\n";
// 		return false;
// 	}

// 	std::ifstream inputFile{ filename };
// 	std::string line{};

// 	std::getline(inputFile, line);
// 	auto pos{ line.find(':') };
// 	if (pos != std::string::npos)
// 		airline.setName(line.substr(pos + 1));
// 	else
// 	{
// 		std::cout << "invalid input.txt: no airline name\n";
// 		return false;
// 	}

// 	while (std::getline(inputFile, line))
// 	{
// 		pos = line.find(':');
// 		if (pos == std::string::npos)
// 		{
// 			std::cout << "invalid input.txt: airport info\n";
// 			return false;
// 		}

// 		std::string currentAirportName{ line.substr(pos + 1) };
// 		airline.addAirport(currentAirportName);

// 		std::getline(inputFile, line);
// 		pos = line.find(':');
// 		if (pos == std::string::npos)
// 		{
// 			std::cout << "invalid input.txt: airplane info\n";
// 			return false;
// 		}

// 		std::string airplanesLine{ line.substr(pos + 1) };
// 		std::size_t startOfInfo{ 0 };
// 		std::size_t endOfInfo{ airplanesLine.find(';') };
// 		while (true)
// 		{
// 			std::string airplaneInfo{ airplanesLine.substr(startOfInfo, endOfInfo) };
// 			if (airplaneInfo.empty())
// 				break;
// 			std::size_t endOfAirplaneModelInfo{ airplaneInfo.find(',') };
// 			std::string airplaneModel{ airplaneInfo.substr(startOfInfo, endOfAirplaneModelInfo) };
// 			int airplaneYearOfManufacture{
// 				std::stoi(airplaneInfo.substr(endOfAirplaneModelInfo + 1, endOfInfo)) };
// 			airline.addAirplane(currentAirportName, airplaneModel, airplaneYearOfManufacture);

// 			if (airplanesLine.find(';') == std::string::npos)
// 				break;
// 			airplanesLine = airplanesLine.substr(airplanesLine.find(';') + 1);
// 			endOfInfo = airplanesLine.find(';');
// 		}
// 	}

// 	return true;
// }