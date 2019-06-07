#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

Date::Date(int d, int m, int y) {
	if ((d < 1) || (d > 31)) throw(d);
	if ((m < 1) || (m > 12)) throw(d);
	if ((y < 1800) || (y > 2200)) throw(d);

	day = d;
	month = m;
	year = y;
}

ostream& operator << (ostream& os, const Weather& w) {
	os << w.get_name() << ": rating" << w.get_rating() << "," << w.my_loc;
	return os;
}

ostream& operator << (ostream& os, const GPS& gps) {
	os << "Latitude: " << gps.latitude << ", Longitude:" << gps.longitude << endl;
	return os;
}

ostream& operator << (ostream& os, const WReading& wr) {
	os << wr.date << ": temp;" << wr.temperature << "; humid:"
		<< wr.humidity << "; wind:" << wr.windspeed;
	return os;
}

ostream& operator <<(ostream& os, const Date& date) {
	os << date.month << " / " << date.day << " / " << date.year;
	return os;
}


string Weather::get_name() const{
    return station_nm;
}

int Weather::get_rating()const {
	return rating;
}

void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}