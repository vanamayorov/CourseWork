#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Functions.h"
#include "Student.h"
#include "Characteristic.h"
using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	Student person;
	Characteristic characteristic;
	bool choice, ind;
	cout << "\t<---Автоматичне написання характеристик--->" << "\n\n";
	characteristic.makeDirectory();
	do
	{
		characteristic.charactInput();
		person.studentInput();
		characteristic.charactOutput();
		person.studentOutput();
		ind = person.studentCharact(characteristic.charactChoice(), characteristic.getNameOfStudentFile());
		if (ind) {
			cout << "Програма успішно виконана!" << endl;
		}
		else {
			cout << "Спробуйте ще раз" << endl;
			characteristic.charactInput();
			person.studentInput();
			characteristic.charactOutput();
			person.studentOutput();
			ind = person.studentCharact(characteristic.charactChoice(), characteristic.getNameOfStudentFile());
		}
		cout << "Бажаєте продовжити виконання програми?(1 - так, 0 - ні)" << endl << "> ";
		cin >> choice;
	} while (choice);

	return 0;
}


