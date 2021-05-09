#include <iostream>
#include <string>
using namespace std;

class Student {
	string studentName; // ϲ� ��������
	int studentSex; // ����� ��������
	int studentAge; // �� ��������
	int studentHobby; // ���� ���������
	int studentQuality; // ������� �����
public:
	void studentInput(); // ������� ��� ������� ����� ��� �������� ������������
	void studentOutput(); // ������� ��� ��������� ����� ��� �������� ������������
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
	do {
		cout << "������ �����(0-�������, 1-�����): ";
		cin >> studentSex;
	} while (studentSex != 0 && studentSex != 1);
	do {
		cout << "������ ��: ";
		cin >> studentAge;
	} while (studentAge < 0 || studentAge > 150);
	do {
		cout << "������ ���������� ����� ����������: " << endl;
		cout << "1.����� \n2.������� ���� \n3.�������������� \n4.��������� ������ \n5.����������  \n";
		cin >> studentHobby;
	} while (studentHobby < 1 || studentHobby > 5);
	do {
		cout << "������ ������� ����� ����� ����������: " << endl;
		cout << "1.���������� \n2.�������������� \n3.�������������� \n4.��������� " <<
			"\n5.�����������  \n6.������� \n7.������������� \n8.³������������\n";
		cin >> studentQuality;
	} while (studentQuality < 1 || studentQuality > 9);

}

void Student::studentOutput() {
	cout << "Student:" << endl << studentName << endl << studentSex << endl << studentAge << endl
		<< studentHobby << endl << studentQuality << endl;
}

void Characteristic::charactInput() {
	do {
		cout << "������ ������� ��������������: " << endl;
		cout << "1.��������� \n2.��������� \n3.�� 10% ��������� � �� 90% ��������� \n4.�� 90% ��������� � �� 10% ���������\n5.�� 50% ��������� � �� 50% ���������\n";
		cin >> charactRating;
	} while (charactRating < 1 || charactRating > 6);
	do {
		cout << "������ ���� ��������������: " << endl;
		cout << "1.��������� \n2.�������� \n3.���������\n";
		cin >> charactLanguage;
	} while (charactLanguage < 1 || charactLanguage > 3);
}

void Characteristic::charactOutput() {
	cout << "Characteristic: " << endl << charactRating << endl << charactLanguage << endl;
}

int main() {
	system("chcp 1251 && cls");
	Student person;
	Characteristic �haracteristic;
	cout << "\t<---����������� ��������� �������������--->" << "\n\n";
	person.studentInput();
	person.studentOutput();
	�haracteristic.charactInput();
	�haracteristic.charactOutput();
	return 0;
}