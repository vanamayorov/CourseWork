#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Functions.h"
#include "Student.h"
#include "Characteristic.h"
using namespace std;

int main() {
	setlocale(LC_CTYPE, "ua");
	Student person;
	Characteristic characteristic;
	bool choice, ind;
	cout << "\t<---����������� ��������� �������������--->" << "\n\n";
	characteristic.makeDirectory();
	do
	{
		characteristic.charactInput();
		person.studentInput();
		characteristic.charactOutput();
		person.studentOutput();
		ind = person.studentCharact(characteristic.charactChoice(), characteristic.getNameOfStudentFile());
		if (ind) {
			cout << "�������� ������ ��������!" << endl;
		}
		else {
			cout << "��������� �� ���" << endl;
			characteristic.charactInput();
			person.studentInput();
			characteristic.charactOutput();
			person.studentOutput();
			ind = person.studentCharact(characteristic.charactChoice(), characteristic.getNameOfStudentFile());
		}
		cout << "������ ���������� ��������� ��������?(1 - ���, 0 - �)" << endl << "> ";
		cin >> choice;
	} while (choice);

	return 0;
}


