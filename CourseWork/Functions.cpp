#include "Functions.h"

string getDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	string str;
	return str = to_string(now->tm_mday) + '.' + to_string(now->tm_mon + 1) + '.' + to_string(now->tm_year + 1900);
}

bool hasOnlyDigits(const string s) {
	return s.find_first_not_of("0123456789!@¹;$%^:?&*()_-+=/|.,") == string::npos;
}