#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <map>

struct BusesForStopResponse {
	std::vector<std::string> buses;
};
std::ostream& operator <<(std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	std::vector<std::pair<std::string, std::vector<std::string>>> stops;
	std::string bus;
};
std::ostream& operator <<(std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	std::map<std::string, std::vector<std::string>> buses;
};
std::ostream& operator <<(std::ostream& os, const AllBusesResponse& r);
