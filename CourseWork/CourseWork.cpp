#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <sys/stat.h>
using namespace std;
#define MAX_SIZE 255
#define EXTENSIONS_NUM 3


bool hasOnlyDigits(const string s); // ������� ��� �������� ����� �� ��������� ����
string getDate();

class Student {
	string studentName; // ϲ� ��������
	int studentSex; // ����� ��������
	string studentAge; // �� ��������
	int studentHobby; // ���� ���������
	int numOfQualities; // �-��� �������
	string* studentQualities;// ������� �����
	string studentQuality; //������ ����� ����� ��� ������ � ������
public:
	Student() {
		studentName = "";
		studentSex = 0;
		studentAge = "";
		studentHobby = 0;
		numOfQualities = 0;
		studentQualities = NULL;
		studentQuality = "";
	}
	void studentInput(); // ������� ��� ������� ����� ��� �������� ������������
	void studentOutput(); // ������� ��� ��������� ����� ��� �������� ������������
	void studentCharact(string inputFile, string outputFile); // ������� ��� ��������� ��������������
	string getName() {
		return this->studentName;
	}
	~Student() {
		delete[]studentQualities;
	}
};

class Characteristic {
	int charactRating; // ������� ��������������
	int charactLanguage; // ���� ��������������
	int charactPurpose; // ���� ���������� ��������������
	string nameOfStudentFile; //��'� ������������ �����, � ���� �������� �����
	string fileExtension; // ���������� �����
	string directoryName; // ����� ����� ��� ��������� �����
	string allowableExtensions[EXTENSIONS_NUM] = { "txt", "doc", "docx" };
public:
	void charactInput(); // ������� ��� ������� ����� ��� ��������������
	void charactOutput(); // ������� ��� ��������� ����� ��� ��������������
	string charactChoice(); // ������� ������ ��������� �������
	string getNameOfStudentFile(); // ������� ��� ��������� ����� �����, � ���� �������� �����
	void makeDirectory(); // ������� ��� ��������� ����� ��� ��������� �����
	bool matchExtension(string str);
};


bool Characteristic::matchExtension(string str) {
	for (int i = 0; i < EXTENSIONS_NUM; i++) {
		if (str == this->allowableExtensions[i]) {
			return true;
		}
	}
	return false;
}
void Characteristic::charactInput() {
	cout << "������ ���� ��������������: " << endl;
	cout << "1.��������� \n2.��������\n" << "> ";
	cin >> charactLanguage;
	while (!cin.good() || charactLanguage < 1 || charactLanguage > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> charactLanguage;
	}
	cout << "������ ����� ���������� ����� � ���� ���� ������� ����� ��� �����: " << endl << "> ";
	cin >> nameOfStudentFile;
	while (!cin.good() || hasOnlyDigits(nameOfStudentFile)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> nameOfStudentFile;
	}
	cout << "������ ��� ���������� �����(��������: doc, txt, docx):" << endl << "> ";
	cin >> fileExtension;
	while (!cin.good() || !matchExtension(fileExtension)) {
		cout << "������� ���, ��������� �� ���!" << endl << "������ ��� ���������� �����(��������: doc, txt, docx):" << endl << "> ";
		cin >> fileExtension;
	}
	fileExtension = '.' + fileExtension;
	cout << "������ �� ���� ��������������: " << endl;
	cout << "1.����� \n2.������� \n" << "> ";
	cin >> charactPurpose;
	while (!cin.good() || charactPurpose < 1 || charactPurpose > 2) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> charactPurpose;
	}
	cout << "������ ������� ��������������: " << endl;
	cout << "1.��������� \n2.��������� \n3.�� 50% ��������� � �� 50% ���������\n" << "> ";
	cin >> charactRating;
	while (!cin.good() || charactRating < 1 || charactRating > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> charactRating;
	}

}

void Characteristic::charactOutput() {
	cout << "Characteristic: " << endl << charactRating << endl << charactLanguage << endl << nameOfStudentFile << ".txt" << endl;
}

string Characteristic::charactChoice() {
	string filename;
	if (charactLanguage == 1) {
		if (charactRating == 1) {
			filename = "ua/pupil_positive.txt";
		}
		else if (charactRating == 2) {
			filename = "ua/pupil_negative.txt";
		}
		else {
			filename = "ua/pupil_50.txt";
		}
	}
	else if (charactLanguage == 2) {
		if (charactRating == 1) {
			filename = "rus/rus_pupil_positive.txt";
		}
		else if (charactRating == 2) {
			filename = "rus/rus_pupil_negative.txt";
		}
		else {
			filename = "rus/rus_pupil_50.txt";
		}
	}

	return filename;
}

string Characteristic::getNameOfStudentFile() {
	return this->directoryName + this->nameOfStudentFile + this->fileExtension;
}

void Characteristic::makeDirectory() {
	int choice;
	cout << "������ �������� ��������� ��� ��������� �����?(0 - ��, 1 - ���)" << endl << "> ";
	cin >> choice;
	while (!cin.good() || choice < 0 || choice > 1) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> choice;
	}
	if (choice) {
		cout << "������ ����� ��������: " << endl << "> ";
		cin >> this->directoryName;
		while (this->directoryName.length() >= 255) {
			cout << "������� ���, ��������� �� ���:" << endl << "> ";
			cin >> this->directoryName;
		}
		this->directoryName += '/';
		int status = mkdir(this->directoryName.c_str(), 0777);
		if (!status) {
			cout << "��������� " + this->directoryName + "���� ������ ��������" << endl;
		}
		else {
			cout << "������� ������� ��� ��������� ��������" << endl;
			return;
		}
	}
	else {
		this->directoryName = ' ';
	}
}

void Student::studentInput() {
	cout << "������ �������, ��'�, �� �������:" << endl << "> ";
	getline(cin, studentName);
	getline(cin, studentName);
	while (!cin.good() || studentName.length() <= 10 || studentName.length() >= 255 || hasOnlyDigits(studentName)) {
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		getline(cin, studentName);
	}
	cout << "������ �����(0-�������, 1-�����): " << endl << "> ";
	cin >> studentSex;
	while (!cin.good() || (studentSex != 0 && studentSex != 1)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> studentSex;
	}
	cout << "������ �� ����������: " << endl << "> ";
	cin >> studentAge;
	while (!cin.good() || stoi(studentAge) <= 1920 || stoi(studentAge) > 2021) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> studentAge;
	}
	cout << "������ ���������� ����� ����������: " << endl;
	cout << "1.����� \n2.������� ���� \n3.�������������� \n4.��������� ������ \n5.�����������  \n" << "> ";
	cin >> studentHobby;
	while (!cin.good() || studentHobby < 1 || studentHobby > 5) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl;
		cout << "������ ���������� ����� ����������: " << endl;
		cout << "1.����� \n2.������� ���� \n3.�������������� \n4.��������� ������ \n5.�����������  \n"
			<< endl << "> ";
		cin >> studentHobby;
	}
	cout << "������ �-��� ������� ��������: " << endl << "> ";
	cin >> numOfQualities;
	while (!cin.good() || numOfQualities <= 0 || numOfQualities >= 10) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> numOfQualities;
	}
	studentQualities = new string[numOfQualities];
	cout << "������ ����� ��������:" << endl;
	for (int i = 0; i < numOfQualities; i++) {
		cout << "> ";
		cin >> studentQuality;
		while (studentQuality.length() == 0 || !cin.good() || hasOnlyDigits(studentQuality)) {
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

void Student::studentCharact(string inputFile, string outputFile) {
	bool ind;
	do
	{
		fstream templateSample, studentFile;
		templateSample.exceptions(fstream::failbit | fstream::badbit);
		studentFile.exceptions(fstream::failbit | fstream::badbit);
		try {
			templateSample.open(inputFile, fstream::in);
			studentFile.open(outputFile, fstream::out);

			/*if (!templateSample.is_open()) {
				throw "��������� ������� ����-������.\n";
			}

			if (!studentFile.is_open()) {
				throw "��������� ������� ����-��������������.\n";
			}*/
			char ch;
			string str = "";

			templateSample.unsetf(ios::skipws);
			studentFile.unsetf(ios::skipws);
			while (!templateSample.eof()) {
				templateSample >> ch;
				studentFile << ch;
			}
			studentFile.close();
			templateSample.close();


			studentFile.open(outputFile, fstream::in);
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
							str += "�����������";
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
			studentFile << str;
			studentFile.close();
			ind = false;
		}
		catch (const fstream::failure& err) {
			cout << err.what() << endl;
			cout << "***������� ������� ��� �������/���������/������� �����***" << endl;
			cout << "�������� �� ���?(1 - ���, 0 - ��)" << endl << "> ";
			cin >> ind;
		}
	} while (ind);

}



int main() {
	setlocale(LC_CTYPE, "rus");
	Student person;
	Characteristic characteristic;
	bool choice;
	cout << "\t<---����������� ��������� �������������--->" << "\n\n";
	characteristic.makeDirectory();
	do
	{
		characteristic.charactInput();
		person.studentInput();
		characteristic.charactOutput();
		person.studentOutput();
		person.studentCharact(characteristic.charactChoice(), characteristic.getNameOfStudentFile());
		cout << "������ ���������� ��������� ��������?(1 - ���, 0 - ��)" << endl << "> ";
		cin >> choice;
	} while (choice);

	return 0;
}

string getDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	string str;
	return str = to_string(now->tm_mday) + '.' + to_string(now->tm_mon + 1) + '.' + to_string(now->tm_year + 1900);
}

bool hasOnlyDigits(const string s) {
	return s.find_first_not_of("0123456789!@�;$%^:?&*()_-+=/|.,") == string::npos;
}

