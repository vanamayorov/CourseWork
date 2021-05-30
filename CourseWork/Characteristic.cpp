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
	cout << "Оберіть мову характеристики: " << endl;
	cout << "1.Українська \n2.Російська\n" << "> ";
	cin >> charactLanguage;
	while (!cin.good() || charactLanguage < 1 || charactLanguage > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> charactLanguage;
	}
	cout << "Введіть назву текстового файлу у який буде вестись запис про особу: " << endl << "> ";
	cin >> nameOfStudentFile;
	while (!cin.good()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> nameOfStudentFile;
	}
	cout << "Введіть тип розширення файлу(доступні: doc, txt, docx):" << endl << "> ";
	cin >> fileExtension;
	while (!cin.good() || !matchExtension(fileExtension)) {
		cout << "\a" << endl;
		cout << "Невірний ввід, спробуйте ще раз!" << endl << "Введіть тип розширення файлу(доступні: doc, txt, docx):" << endl << "> ";
		cin >> fileExtension;
	}
	fileExtension = '.' + fileExtension;
	cout << "Оберіть на кого характеристика: " << endl;
	cout << "1.Учень \n2.Студент \n" << "> ";
	cin >> charactPurpose;
	while (!cin.good() || charactPurpose < 1 || charactPurpose > 2) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> charactPurpose;
	}
	cout << "Оберіть рейтинг характеристики: " << endl;
	cout << "1.Позитивна \n2.Негативна \n3.На 50% позитивна і на 50% негативна\n" << "> ";
	cin >> charactRating;
	while (!cin.good() || charactRating < 1 || charactRating > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
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
	cout << "Бажаєте створити директорію для зберігання файлів?(0 - ні, 1 - так)" << endl << "> ";
	cin >> choice;
	while (!cin.good() || choice < 0 || choice > 1) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> choice;
	}
	if (choice) {
		cout << "Введіть назву директорії: " << endl << "> ";
		cin >> this->directoryName;
		while (this->directoryName.length() >= 255) {
			cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
			cin >> this->directoryName;
		}
		int status = mkdir(this->directoryName.c_str(), 0777);
		if (!status) {
			cout << "Директорія " + this->directoryName + " була успішно створена!" << endl;
			this->directoryName += '/';
		}
		else {
			cout << "\a" << endl;
			cout << "Виникла помилка при створенні директорії" << endl;
			return;
		}
	}
	else {
		cout << "Створені файли будуть знаходитися у поточній директорії разом з програмою" << endl;
		this->directoryName = ' ';
	}
}