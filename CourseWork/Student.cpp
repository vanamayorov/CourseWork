#include "Student.h"


void Student::studentInput() {
	cout << "Введіть прізвище, ім'я, по батькові:" << endl << "> ";
	getline(cin, studentName);
	getline(cin, studentName);
	while (!cin.good() || studentName.length() <= MIN_SIZE || studentName.length() >= MAX_SIZE || hasOnlyDigits(studentName)) {
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		getline(cin, studentName);
	}
	cout << "Введіть стать(0-чоловіча, 1-жіноча): " << endl << "> ";
	cin >> studentSex;
	while (!cin.good() || (studentSex != 0 && studentSex != 1)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> studentSex;
	}
	cout << "Введіть рік народження: " << endl << "> ";
	cin >> studentAge;
	while (!cin.good() || stoi(studentAge) <= 1920 || stoi(studentAge) > 2021) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> studentAge;
	}
	cout << "Оберіть захоплення серед перелічених: " << endl;
	cout << "1.Спорт \n2.Читання книг \n3.Фотографування \n4.Графічний дизайн \n5.Електроніка  \n" << "> ";
	cin >> studentHobby;
	while (!cin.good() || studentHobby < 1 || studentHobby > 5) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl;
		cout << "Оберіть захоплення серед перелічених: " << endl;
		cout << "1.Спорт \n2.Читання книг \n3.Фотографування \n4.Графічний дизайн \n5.Електроніка  \n"
			<< endl << "> ";
		cin >> studentHobby;
	}
	cout << "Введіть к-сть якостей студента: " << endl << "> ";
	cin >> numOfQualities;
	while (!cin.good() || numOfQualities <= 0 || numOfQualities >= MIN_SIZE) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> numOfQualities;
	}
	studentQualities = new string[numOfQualities];
	string studentQuality;
	cout << "Введіть якості студента:" << endl;
	for (int i = 0; i < numOfQualities; i++) {
		cout << "> ";
		cin >> studentQuality;
		while (studentQuality.length() == 0 || !cin.good() || hasOnlyDigits(studentQuality)) {
			cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
			cin >> studentQuality;
		}
		studentQualities[i] = studentQuality;

	}
}

void Student::studentOutput() {
	cout << "Student:" << endl << studentName << endl << ((studentSex) ? "Жіноча" : "Чоловіча") << " стать" << endl << studentAge << endl;
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
		cout << "Виникла помилка при відкритті файлу-шаблону" << endl;
		return false;
	}

	if (!studentFile.is_open()) {
		cout << "Виникла помилка при відкритті файлу-характеристики" << endl;
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
		cout << "Виникла помилка при відкритті файлу-характеристики" << endl;
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
					str += "спорту";
					break;
				case 2:
					str += "читання книг";
					break;
				case 3:
					str += "фотографування";
					break;
				case 4:
					str += "графічного дизайну";
					break;
				case 5:
					str += "електроніки";
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
		cout << "Виникла помилка при відкритті файлу-характеристики" << endl;
		return false;
	}
	studentFile << str;
	studentFile.close();

	return true;
}

string Student::getName() {
	return this->studentName;
}

