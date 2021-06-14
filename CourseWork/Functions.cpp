#include "Functions.h"

string getDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	string str;
	return str = to_string(now->tm_mday) + '.' + to_string(now->tm_mon + 1) + '.' + to_string(now->tm_year + 1900);
}

bool hasOnlyDigits(const string s) {
	string notDigitsArray = { "0123456789!@¹;$%^:?&*()_-+=/|.," };
	for (long unsigned int i = 0; i < notDigitsArray.length(); i++) {
		if (s.find(notDigitsArray[i]) != string::npos) {
			return false;
		}
	}
	return true;
}