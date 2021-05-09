#include <iostream>
#include <string>
#include <climits>
using namespace std;
#define MAX_SIZE 255

bool hasOnlyDigits(const string s); // функція для перевірки строк на наявність букв

class Student {
	string studentName; // ПІБ студента
	int studentSex; // стать студента
	int studentAge; // вік студента
	int studentHobby; // види захоплень
	int numOfQualities; // к-сть якостей
	string* studentQualities;// особисті якості
	string studentQuality; //окремо взята якість для запису у массив
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
	void studentInput(); // функція для введеня даних про студента користувачем
	void studentOutput(); // функція для виведення даних про студента користувачем
	~Student() {
		delete[]studentQualities;
	}
};

class Characteristic {
	int charactRating; // рейтинг характеристики
	int charactLanguage; // мова характеристики
public:
	void charactInput(); // функція для введеня даних про характеристику
	void charactOutput(); // функція для виведення даних про характеристику
};

void Student::studentInput() {
	cout << "Введіть прізвище, ім'я, по батькові:" << endl;
	getline(cin, studentName);
	while (!cin.good() || studentName.length() <= 10 || studentName.length() >= 255 || hasOnlyDigits(studentName)) {
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		getline(cin, studentName);
	}
	cout << "Введіть стать(0-чоловіча, 1-жіноча): ";
	cin >> studentSex;
	while (!cin.good() || (studentSex != 0 && studentSex != 1)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> studentSex;
	}
	cout << "Введіть вік: ";
	cin >> studentAge;
	while (!cin.good() || studentAge <= 0 || studentAge > 150) {
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
	while (!cin.good() || numOfQualities <= 0 || numOfQualities >= 10) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> numOfQualities;
	}
	studentQualities = new string[numOfQualities];
	cout << "Введіть якості студента:" << endl << "> ";
	for (int i = 0; i < numOfQualities; i++) {
		cin >> studentQuality;
		while (studentQuality.length() == 0 || !cin.good() || hasOnlyDigits(studentQuality)) {
			cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
			cin >> studentQuality;
		}
		studentQualities[i] = studentQuality;

	}
	/*do {
		cout << "Оберіть особисті якості серед перелічених: " << endl;
		cout << "1.Амбіційність \n2.Харизматичність \n3.Кооперативність \n4.Ввічливість " <<
			"\n5.Креативність  \n6.Чесність \n7.Пунктуальність \n8.Відповідальність\n";
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
	cout << "Оберіть рейтинг характеристики: " << endl;
	cout << "1.Позитивна \n2.Негативна \n3.На 10% позитивна і на 90% негативна \n4.На 90% позитивна і на 10% негативна\n5.На 50% позитивна і на 50% негативна\n";
	cin >> charactRating;
	while (!cin.good() || charactRating < 1 || charactRating > 6) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> charactRating;
	}

	cout << "Оберіть мову характеристики: " << endl;
	cout << "1.Українська \n2.Російська \n3.Англійська\n";
	cin >> charactLanguage;
	while (!cin.good() || charactLanguage < 1 || charactLanguage > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> charactLanguage;
	}
}

void Characteristic::charactOutput() {
	cout << "Characteristic: " << endl << charactRating << endl << charactLanguage << endl;
}


bool hasOnlyDigits(const string s) {
	return s.find_first_not_of("0123456789!@№;$%^:?&*()_-+=/|.,") == string::npos;
}


int main() {
	system("chcp 1251 && cls");
	Student person;
	Characteristic characteristic;
	cout << "\t<---Автоматичне написання характеристик--->" << "\n\n";
	person.studentInput();
	characteristic.charactInput();
	person.studentOutput();
	characteristic.charactOutput();
	return 0;
}