#include <iostream>
#include <string>
using namespace std;

class Student {
	string studentName; // ПІБ студента
	int studentSex; // стать студента
	int studentAge; // вік студента
	int studentHobby; // види захоплень
	int studentQuality; // особисті якості
public:
	void studentInput(); // функція для введеня даних про студента користувачем
	void studentOutput(); // функція для виведення даних про студента користувачем
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
	do {
		cout << "Введіть стать(0-чоловіча, 1-жіноча): ";
		cin >> studentSex;
	} while (studentSex != 0 && studentSex != 1);
	do {
		cout << "Введіть вік: ";
		cin >> studentAge;
	} while (studentAge < 0 || studentAge > 150);
	do {
		cout << "Оберіть захоплення серед перелічених: " << endl;
		cout << "1.Спорт \n2.Читання книг \n3.Фотографування \n4.Графічний дизайн \n5.Електроніка  \n";
		cin >> studentHobby;
	} while (studentHobby < 1 || studentHobby > 5);
	do {
		cout << "Оберіть особисті якості серед перелічених: " << endl;
		cout << "1.Амбіційність \n2.Харизматичність \n3.Кооперативність \n4.Ввічливість " <<
			"\n5.Креативність  \n6.Чесність \n7.Пунктуальність \n8.Відповідальність\n";
		cin >> studentQuality;
	} while (studentQuality < 1 || studentQuality > 9);

}

void Student::studentOutput() {
	cout << "Student:" << endl << studentName << endl << studentSex << endl << studentAge << endl
		<< studentHobby << endl << studentQuality << endl;
}

void Characteristic::charactInput() {
	do {
		cout << "Оберіть рейтинг характеристики: " << endl;
		cout << "1.Позитивна \n2.Негативна \n3.На 10% позитивна і на 90% негативна \n4.На 90% позитивна і на 10% негативна\n5.На 50% позитивна і на 50% негативна\n";
		cin >> charactRating;
	} while (charactRating < 1 || charactRating > 6);
	do {
		cout << "Оберіть мову характеристики: " << endl;
		cout << "1.Українська \n2.Російська \n3.Англійська\n";
		cin >> charactLanguage;
	} while (charactLanguage < 1 || charactLanguage > 3);
}

void Characteristic::charactOutput() {
	cout << "Characteristic: " << endl << charactRating << endl << charactLanguage << endl;
}

int main() {
	system("chcp 1251 && cls");
	Student person;
	Characteristic сharacteristic;
	cout << "\t<---Автоматичне написання характеристик--->" << "\n\n";
	person.studentInput();
	person.studentOutput();
	сharacteristic.charactInput();
	сharacteristic.charactOutput();
	return 0;
}