#include "responses.h"



std::ostream& operator <<(std::ostream& os, const BusesForStopResponse& r) {
	if (r.buses.size() == 0) {
		os << "No stop";
	} else {
		for (const std::string& bus : r.buses) {
			os << bus << " ";
		}
	}
	return os;
}


std::ostream& operator <<(std::ostream& os, const StopsForBusResponse& r) {
	if (r.stops.size() == 0) {
		os << "No bus";
	} else {
		for (const auto& stop : r.stops) {
			if (stop.second.size() != 0) {
				os << "Stop " << stop.first << ": ";
				if (stop.second.size() == 1) {
					os << "no interchange";
				} else {
					for (const std::string& other_bus : stop.second) {
						if (r.bus != other_bus) {
							os << other_bus << " ";
						}
					}
				}
				os << std::endl;
			}
		}
	}
	return os;
}


std::ostream& operator <<(std::ostream& os, const AllBusesResponse& r) {
	if (r.buses.empty()) {
		os << "No buses";
	} else {
		for (const auto& bus_item : r.buses) {
			os << "Bus " << bus_item.first << ": ";
			for (const std::string& stop : bus_item.second) {
				os << stop << " ";
			}
			os << std::endl;
		}
	}
	return os;
}
