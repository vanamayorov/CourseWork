#include <iostream>
#include <string>
#include <climits>
#include <fstream>
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
	void studentCharact(string filename); // ������� ��� ��������� ��������������
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
	string charactChoise(); // ������� ������ ��������� �������
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
	cout << "������ �� ����������: ";
	cin >> studentAge;
	while (!cin.good() || studentAge <= 1920 || studentAge > 2021) {
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
	cout << "Student:" << endl << studentName << endl << ((studentSex) ? "Ƴ����" : "�������") << " �����"  << endl << studentAge << endl;
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

string Characteristic::charactChoise(){
    string filename;
	if (charactRating==1) filename="pupil_positive.txt";
	else filename="pupil_negative.txt";
    return filename;
}

void Student::studentCharact(string filename){
    ifstream fin(filename);
    if(!fin){
        cout<<"��������� ������� ����.\n";
        return;
    }
    char symbol;
    fin.unsetf(ios::skipws);
    while (!fin.eof()){
		fin >> symbol;
		if (!fin.eof()){
		    if (symbol == '1') 
				cout << studentName;
		    if (symbol == '4'){
		        for (int i = 0; i < numOfQualities; i++)
		        cout << studentQualities[i] << " ";
		    } 
		    if (symbol == '2') 
				cout << studentAge;
			if (symbol == '3'){
				switch (studentHobby){
					case 1:
					cout << "������";
					break;
					case 2:
					cout << "������� ����";
					break;
					case 3:
					cout << "��������������";
					break;
					case 4:
					cout << "���������� �������";
					break;
					case 5:
					cout << "����������";
					break;
				}
			}
		    else cout<<symbol;
		}
    }
	fin.close();
}


bool hasOnlyDigits(const string s) {
	return s.find_first_not_of("0123456789!@�;$%^:?&*()_-+=/|.,") == string::npos;
}


int main() {
	system("chcp 1251 && cls");
	Student person;
	Characteristic characteristic;
	cout << "\t<---����������� ��������� �������������--->" << "\n\n";
	person.studentInput();
	characteristic.charactInput();
	person.studentOutput();
	characteristic.charactOutput();
	string filename = characteristic.charactChoise();
	person.studentCharact(filename);
	return 0;
}