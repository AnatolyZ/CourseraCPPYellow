#include "bus_manager.h"

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	buses_to_stops[bus] = stops;
	for (auto& stop : stops) {
		stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	BusesForStopResponse result;
	if (stops_to_buses.count(stop) == 0) {
		return result;
	} else {
		for (const auto& bus : stops_to_buses.at(stop)) {
			result.buses.push_back(bus);
		}
	}
	return result;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
	StopsForBusResponse result;
	result.bus = bus;
	if (buses_to_stops.count(bus) == 0) {
		return result;
	}
	int i = 0;
	result.stops.resize(stops_to_buses.size());
	for (auto& s : buses_to_stops.at(bus)) {
		if (stops_to_buses.count(s) != 0) {
			result.stops[i].first = s;
			result.stops[i].second = stops_to_buses.at(s);
		}
		i++;
	}

	return result;
}

AllBusesResponse BusManager::GetAllBuses() const {
	AllBusesResponse result;
	result.buses = buses_to_stops;
	return result;
}

