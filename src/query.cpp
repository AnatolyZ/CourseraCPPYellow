#include "query.h"

std::istream& operator >>(std::istream& is, Query& q) {
	std::string cmd;
	is >> cmd;
	if (cmd == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		int stop_count;
		is >> stop_count;
		q.stops.resize(stop_count);
		for (std::string& stop : q.stops) {
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




