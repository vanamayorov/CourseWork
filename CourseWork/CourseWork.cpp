#include <iostream>
#include <string>
#include <climits>
using namespace std;
#define MAX_SIZE 255

bool hasOnlyDigits(const string s); // ������� ��� �������� ����� �� �������� ����

class Student {
	string studentName; // ϲ� ��������
	int studentSex; // ����� ��������
	int studentAge; // �� ��������
	int studentHobby; // ���� ���������
	int numOfQualities; // �-��� �������
	string* studentQualities;// ������� �����
	string studentQuality; //������ ����� ����� ��� ������ � ������
public:
	Student() {
		studentName = "";
		studentSex = 0;
		studentAge = 0;
		studentHobby = 0;
		numOfQualities = 0;
		studentQualities = NULL;
		studentQuality = "";
	}
	void studentInput(); // ������� ��� ������� ����� ��� �������� ������������
	void studentOutput(); // ������� ��� ��������� ����� ��� �������� ������������
	~Student() {
		delete[]studentQualities;
	}
};

class Characteristic {
	int charactRating; // ������� ��������������
	int charactLanguage; // ���� ��������������
public:
	void charactInput(); // ������� ��� ������� ����� ��� ��������������
	void charactOutput(); // ������� ��� ��������� ����� ��� ��������������
};

void Student::studentInput() {
	cout << "������ �������, ��'�, �� �������:" << endl;
	getline(cin, studentName);
	while (!cin.good() || studentName.length() <= 10 || studentName.length() >= 255 || hasOnlyDigits(studentName)) {
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		getline(cin, studentName);
	}
	cout << "������ �����(0-�������, 1-�����): ";
	cin >> studentSex;
	while (!cin.good() || (studentSex != 0 && studentSex != 1)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> studentSex;
	}
	cout << "������ ��: ";
	cin >> studentAge;
	while (!cin.good() || studentAge <= 0 || studentAge > 150) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> studentAge;
	}
	cout << "������ ���������� ����� ����������: " << endl;
	cout << "1.����� \n2.������� ���� \n3.�������������� \n4.��������� ������ \n5.����������  \n" << "> ";
	cin >> studentHobby;
	while (!cin.good() || studentHobby < 1 || studentHobby > 5) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl;
		cout << "������ ���������� ����� ����������: " << endl;
		cout << "1.����� \n2.������� ���� \n3.�������������� \n4.��������� ������ \n5.����������  \n"
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
	cout << "������ ����� ��������:" << endl << "> ";
	for (int i = 0; i < numOfQualities; i++) {
		cin >> studentQuality;
		while (studentQuality.length() == 0 || !cin.good() || hasOnlyDigits(studentQuality)) {
			cout << "������� ���, ��������� �� ���:" << endl << "> ";
			cin >> studentQuality;
		}
		studentQualities[i] = studentQuality;

	}
	/*do {
		cout << "������ ������� ����� ����� ����������: " << endl;
		cout << "1.���������� \n2.�������������� \n3.�������������� \n4.��������� " <<
			"\n5.�����������  \n6.������� \n7.������������� \n8.³������������\n";
		cin >> studentQuality;
	} while (studentQuality < 1 || studentQuality > 9);*/

}

void Student::studentOutput() {
	cout << "Student:" << endl << studentName << endl << studentSex << endl << studentAge << endl;
	for (int i = 0; i < numOfQualities; i++) {
		cout << studentQualities[i] << " ";
	}
	cout << endl;
}

void Characteristic::charactInput() {
	cout << "������ ������� ��������������: " << endl;
	cout << "1.��������� \n2.��������� \n3.�� 10% ��������� � �� 90% ��������� \n4.�� 90% ��������� � �� 10% ���������\n5.�� 50% ��������� � �� 50% ���������\n";
	cin >> charactRating;
	while (!cin.good() || charactRating < 1 || charactRating > 6) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> charactRating;
	}

	cout << "������ ���� ��������������: " << endl;
	cout << "1.��������� \n2.�������� \n3.���������\n";
	cin >> charactLanguage;
	while (!cin.good() || charactLanguage < 1 || charactLanguage > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> charactLanguage;
	}
}

void Characteristic::charactOutput() {
	cout << "Characteristic: " << endl << charactRating << endl << charactLanguage << endl;
}


bool hasOnlyDigits(const string s) {
	return s.find_first_not_of("0123456789!@�;$%^:?&*()_-+=/|.,") == string::npos;
}


int main() {
	system("chcp 1251 && cls");
	Student person;
	Characteristic �haracteristic;
	cout << "\t<---����������� ��������� �������������--->" << "\n\n";
	person.studentInput();
	�haracteristic.charactInput();
	person.studentOutput();
	�haracteristic.charactOutput();
	return 0;
}