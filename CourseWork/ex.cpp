#include <iostream>
#include <fstream>
#include <ctime>
#include <climits>
#include <string>
#include <sys/stat.h>
using namespace std;
#define MAX_SIZE 255
#define MIN_SIZE 10
#define EXTENSIONS_NUM 3

bool hasOnlyDigits(const string s); // функція для перевірки строк на наявність букв
string getDate(); // функція для отримання сьогоднішньої дати

class Student {
	string studentName; // ПІБ студента
	int studentSex; // стать студента
	string studentAge; // вік студента
	int studentHobby; // види захоплень
	int numOfQualities; // к-сть якостей
	string* studentQualities;// особисті якості
public:
	void studentInput(); // функція для введеня даних про студента користувачем
	void studentOutput(); // функція для виведення даних про студента користувачем
	bool studentCharact(string inputFile, string outputFile);// функція для виведення характеристики
	~Student() {
		delete[]studentQualities;
	}
};

void Student::studentInput() {
	cout << "Введіть прізвище, ім'я, по батькові:" << endl << "> ";
	getline(cin, studentName);
	getline(cin, studentName);
	while (!cin.good() || studentName.length() <= MIN_SIZE || studentName.length() >= MAX_SIZE || hasOnlyDigits(studentName)) {
		cout << "\a" << endl;
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		getline(cin, studentName);
	}
	cout << "Введіть стать(0-чоловіча, 1-жіноча): " << endl << "> ";
	cin >> studentSex;
	while (!cin.good() || (studentSex != 0 && studentSex != 1)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> studentSex;
	}
	cout << "Введіть рік народження: " << endl << "> ";
	cin >> studentAge;
	while (!cin.good() || stoi(studentAge) <= 1920 || stoi(studentAge) > 2021) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> studentAge;
	}
	cout << "Оберіть захоплення серед перелічених: " << endl;
	cout << "1.Спорт \n2.Читання книг \n3.Фотографування \n4.Графічний дизайн \n5.Електроніка  \n" << "> ";
	cin >> studentHobby;
	while (!cin.good() || studentHobby < 1 || studentHobby > 5) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\a" << endl;
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
		cout << "\a" << endl;
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
			cout << "\a" << endl;
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
		cout << "\a" << endl;
		cout << "Виникла помилка при відкритті файлу-шаблону" << endl;
		return false;
	}

	if (!studentFile.is_open()) {
		cout << "\a" << endl;
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
		cout << "\a" << endl;
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
		cout << "\a" << endl;
		cout << "Виникла помилка при відкритті файлу-характеристики" << endl;
		return false;
	}
	studentFile << str;
	studentFile.close();

	return true;
}

class Characteristic {
	int charactRating; // рейтинг характеристики
	int charactLanguage; // мова характеристики
	int charactPurpose; // куди призначена характеристика
	string nameOfStudentFile; //ім'я створюваного файлу, в який ведеться запис
	string fileExtension; // розширення файлу
	string directoryName; // назва папки для зберігання файлів
	string allowableExtensions[EXTENSIONS_NUM] = { "txt", "doc", "docx" }; // дозволені розширення файлу
public:
	void charactInput(); // функція для введеня даних про характеристику
	void charactOutput(); // функція для виведення даних про характеристику
	string charactChoice(); // функція вибору потрібного шаблону
	string getNameOfStudentFile(); // функція для отримання назви файлу, в який ведеться запис
	void makeDirectory(); // функція для створення папки для зберігання файлів
	bool matchExtension(string str); // функція для перевірки дозволених розширень файлу
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
			cout << "\a" << endl;
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
			cout << "\a" << endl;
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

string getDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	string str;
	return str = to_string(now->tm_mday) + '.' + to_string(now->tm_mon + 1) + '.' + to_string(now->tm_year + 1900);
}


bool hasOnlyDigits(const string s) {
	string notDigitsArray = { "0123456789!@№;$%^:?&*()_-+=/|.," };
	for (long unsigned int i = 0; i < notDigitsArray.length(); i++) {
		if (s.find(notDigitsArray[i]) != string::npos) {
			return false;
		}
	}
	return true;
}

