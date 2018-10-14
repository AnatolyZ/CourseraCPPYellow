#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus, BusesForStop, StopsForBus, AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >>(istream& is, Query& q) {
	string cmd;
	is >> cmd;
	if (cmd == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		int stop_count;
		is >> stop_count;
		q.stops.resize(stop_count);
		for (string& stop : q.stops) {
			is >> stop;
		}
	} else if (cmd == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	} else if (cmd == "STOPS_FOR_BUS") {
		is >> q.bus;
		q.type = QueryType::StopsForBus;
	} else if (cmd == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	return is;
}

struct BusesForStopResponse {
	vector<string> buses;
};

ostream& operator <<(ostream& os, const BusesForStopResponse& r) {
	if (r.buses.size() == 0) {
		os << "No stop";
	} else {
		for (const string& bus : r.buses) {
			os << bus << " ";
		}
	}
	return os;
}

struct StopsForBusResponse {
	vector<pair<string, vector<string>>> stops;
	string bus;
};

ostream& operator <<(ostream& os, const StopsForBusResponse& r) {
	if (r.stops.size() == 0) {
		os << "No bus";
	} else {
		for (const auto& stop : r.stops) {
			if (stop.second.size() != 0) {
				os << "Stop " << stop.first << ": ";
				if (stop.second.size() == 1) {
					os << "no interchange";
				} else {
					for (const string& other_bus : stop.second) {
						if (r.bus != other_bus) {
							os << other_bus << " ";
						}
					}
				}
				os << endl;
			}
		}
	}
	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> buses;
};

ostream& operator <<(ostream& os, const AllBusesResponse& r) {
	if (r.buses.empty()) {
		os << "No buses";
	} else {
		for (const auto& bus_item : r.buses) {
			os << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				os << stop << " ";
			}
			os << endl;
		}
	}
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;
		for (auto& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
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

	StopsForBusResponse GetStopsForBus(const string& bus) const {
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

	AllBusesResponse GetAllBuses() const {
		AllBusesResponse result;
		result.buses = buses_to_stops;
		return result;
	}
private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
