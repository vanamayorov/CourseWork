#pragma once
#include "Functions.h"
#include <sys/stat.h>
#define EXTENSIONS_NUM 3
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
