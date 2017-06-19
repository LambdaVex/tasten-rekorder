#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>

namespace Helper {
	
	template <class T>
	std::string ToString(const T &);

	struct DateTime {
		// Constructor
		DateTime() {
			time_t ms;
			time(&ms);
			struct tm *info = localtime(&ms);

			D = info->tm_mday;
			m = info->tm_mon + 1; //because it start from zero
			y = 1900 + info->tm_year;
			M = info->tm_min;
			H = info->tm_hour;
			S = info->tm_sec;
		}
		// For later use
		DateTime(int D, int m, int y, int H, int M, int S) : D(D), m(m), y(y), H(H), M(M), S(S) {}
		DateTime(int D, int m, int y) : D(D), m(m), y(y), H(0), M(0), S(0) {}

		// method
		DateTime Now() const {
			return DateTime();
		}

		int D, m, y, H, M, S;

		std::string GetDateString() const {
			return std::string(D < 10 ? "0" : "") + ToString(D) +
				std::string(m < 10 ? ".0" : ".") + ToString(m) + ".";

		}
	};

}


#endif
