#include "Characteristic.h"

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
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> charactLanguage;
	}
	cout << "������ ����� ���������� ����� � ���� ���� ������� ����� ��� �����: " << endl << "> ";
	cin >> nameOfStudentFile;
	while (!cin.good()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> nameOfStudentFile;
	}
	cout << "������ ��� ���������� �����(�������: doc, txt, docx):" << endl << "> ";
	cin >> fileExtension;
	while (!cin.good() || !matchExtension(fileExtension)) {
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���!" << endl << "������ ��� ���������� �����(�������: doc, txt, docx):" << endl << "> ";
		cin >> fileExtension;
	}
	fileExtension = '.' + fileExtension;
	cout << "������ �� ���� ��������������: " << endl;
	cout << "1.����� \n2.������� \n" << "> ";
	cin >> charactPurpose;
	while (!cin.good() || charactPurpose < 1 || charactPurpose > 2) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> charactPurpose;
	}
	cout << "������ ������� ��������������: " << endl;
	cout << "1.��������� \n2.��������� \n3.�� 50% ��������� � �� 50% ���������\n" << "> ";
	cin >> charactRating;
	while (!cin.good() || charactRating < 1 || charactRating > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "������� ���, ��������� �� ���:" << endl << "> ";
		cin >> charactRating;
	}

}

void Characteristic::charactOutput() {
	cout << "Characteristic: " << endl << charactRating << endl << charactLanguage << endl << nameOfStudentFile << ".txt" << endl;
}

string Characteristic::charactChoice() {
	string filename;
	switch (charactLanguage)
	{
	case 1:
		switch (charactRating)
		{
		case 1:
			filename = "ua/pupil_positive.txt";
			break;
		case 2:
			filename = "ua/pupil_negative.txt";
			break;
		default:
			filename = "ua/pupil_50.txt";
			break;
		}
		break;
	case 2:
		switch (charactRating)
		{
		case 1:
			filename = "rus/rus_pupil_positive.txt";
			break;
		case 2:
			filename = "rus/rus_pupil_negative.txt";
			break;
		default:
			filename = "rus/rus_pupil_50.txt";
			break;
		}
		break;
	}
	return filename;
}

string Characteristic::getNameOfStudentFile() {
	return this->directoryName + this->nameOfStudentFile + this->fileExtension;
}

void Characteristic::makeDirectory() {
	int choice;
	cout << "������ �������� ��������� ��� ��������� �����?(0 - �, 1 - ���)" << endl << "> ";
	cin >> choice;
	while (!cin.good() || choice < 0 || choice > 1) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
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
		int status = mkdir(this->directoryName.c_str(), 0777);
		if (!status) {
			cout << "��������� " + this->directoryName + " ���� ������ ��������!" << endl;
			this->directoryName += '/';
		}
		else {
			cout << "\a" << endl;
			cout << "������� ������� ��� �������� ��������" << endl;
			return;
		}
	}
	else {
		cout << "������� ����� ������ ����������� � ������� �������� ����� � ���������" << endl;
		this->directoryName = ' ';
	}
}