#include "Student.h"


void Student::studentInput() {
	cout << "������ �������, ��'�, �� �������:" << endl << "> ";
	getline(cin, studentName);
	getline(cin, studentName);
	while (!cin.good() || studentName.length() <= MIN_SIZE || studentName.length() >= MAX_SIZE || !hasOnlyDigits(studentName)) {
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		getline(cin, studentName);
	}
	cout << "������ �����(0-�������, 1-�����): " << endl << "> ";
	cin >> studentSex;
	while (!cin.good() || (studentSex != 0 && studentSex != 1)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> studentSex;
	}
	cout << "������ �� ����������: " << endl << "> ";
	cin >> studentAge;
	while (!cin.good() || stoi(studentAge) <= 1920 || stoi(studentAge) > 2021) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> studentAge;
	}
	cout << "������ ���������� ����� ����������: " << endl;
	cout << "1.����� \n2.������� ���� \n3.�������������� \n4.��������� ������ \n5.����������  \n" << "> ";
	cin >> studentHobby;
	while (!cin.good() || studentHobby < 1 || studentHobby > 5) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���:" << endl;
		cout << "������ ���������� ����� ����������: " << endl;
		cout << "1.����� \n2.������� ���� \n3.�������������� \n4.��������� ������ \n5.����������  \n"
			<< endl << "> ";
		cin >> studentHobby;
	}
	cout << "������ �-��� ������� ��������: " << endl << "> ";
	cin >> numOfQualities;
	while (!cin.good() || numOfQualities <= 0 || numOfQualities >= MIN_SIZE) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> numOfQualities;
	}
	studentQualities = new string[numOfQualities];
	string studentQuality;
	cout << "������ ����� ��������:" << endl;
	for (int i = 0; i < numOfQualities; i++) {
		cout << "> ";
		cin >> studentQuality;
		while (studentQuality.length() == 0 || !cin.good() || hasOnlyDigits(studentQuality)) {
			cout << "\a" << endl;
			cout << "������� ���, ��������� �� ���:" << endl << "> ";
			cin >> studentQuality;
		}
		studentQualities[i] = studentQuality;

	}
}

void Student::studentOutput() {
	cout << "Student:" << endl << studentName << endl << ((studentSex) ? "Ƴ����" : "�������") << " �����" << endl << studentAge << endl;
	for (int i = 0; i < numOfQualities; i++) {
		cout << studentQualities[i] << " ";
	}
	cout << endl;
}

bool Student::studentCharact(string inputFile, string outputFile) {
	fstream templateSample, studentFile;

	templateSample.open(inputFile, fstream::in);
	studentFile.open(outputFile, fstream::out);

	if (!templateSample.is_open()) {
		cout << "\a" << endl;
		cout << "������� ������� ��� ������� �����-�������" << endl;
		return false;
	}

	if (!studentFile.is_open()) {
		cout << "\a" << endl;
		cout << "������� ������� ��� ������� �����-��������������" << endl;
		return false;
	}
	char ch;
	string str;

	templateSample.unsetf(ios::skipws);
	studentFile.unsetf(ios::skipws);
	while (!templateSample.eof()) {
		templateSample >> ch;
		studentFile << ch;
	}
	studentFile.close();
	templateSample.close();


	studentFile.open(outputFile, fstream::in);
	if (!studentFile.is_open()) {
		cout << "\a" << endl;
		cout << "������� ������� ��� ������� �����-��������������" << endl;
		return false;
	}
	while (!studentFile.eof()) {
		studentFile >> ch;
		if (!studentFile.eof()) {
			if (ch == '1') {
				str += studentName;
			}
			else if (ch == '2') {
				str += studentAge;
			}
			else if (ch == '3') {
				switch (studentHobby) {
				case 1:
					str += "������";
					break;
				case 2:
					str += "������� ����";
					break;
				case 3:
					str += "��������������";
					break;
				case 4:
					str += "���������� �������";
					break;
				case 5:
					str += "����������";
					break;
				}
			}
			else if (ch == '4') {
				for (int i = 0; i < numOfQualities; i++) {
					if (i == numOfQualities - 1) {
						str += studentQualities[i];
					}
					else {
						str += studentQualities[i];
						str += ", ";
					}
				}
			}
			else if (ch == '^') {
				str += getDate();
			}
			else {
				str += ch;
			}
		}
	}
	cout << str << endl;
	studentFile.close();
	studentFile.open(outputFile, fstream::out);
	if (!studentFile.is_open()) {
		cout << "\a" << endl;
		cout << "������� ������� ��� ������� �����-��������������" << endl;
		return false;
	}
	studentFile << str;
	studentFile.close();

	return true;
}


