#include "Functions.h"

void StartProgram()
{
	int answer;
	vector<string> mainMenu{ "Методы поиска", "Создание файлов", "Выход из программы" };

	cout << "Вас приветствует программа, созданная Солохином Д.А.\n";

	while(true)
	{
		cout << "\nГЛАВНОЕ МЕНЮ\n";
		PrintMessage(mainMenu.size(), mainMenu);
		answer = InputAnswer(mainMenu.size());
		
		switch (answer) {
			case 1:
				SearchMethods();
				break;
			case 2:
				GenerationFiles();
				break;
			case 3:
				mainMenu.clear();
				mainMenu.shrink_to_fit();
				return;
		}
	}
}

void GenerationFiles()
{
	cout << "\nСОЗДАНИЕ ФАЙЛОВ\n";
	cout << "Примечание: в зависимости от выбора метода создания у файлов в названии будут разные приписки:\n - [GF] (Сгенерированный файл)\n - [UF] (Пользовательский файл)\n\n";

	vector<string> dataType{ "Целые числа", "Вещественные числа", "Символы", "Слова", "Фальшивая монета" };
	vector<string> createFile{ "Сгенерировать файл", "Пользовательский файл", "НАЗАД" };

	PrintMessage(createFile.size(), createFile);
	int answer = InputAnswer(createFile.size());

	switch (answer) {
		case 1: {
			cout << "> Сколько файлов сгенерировать? ";
			int count = InputInt();
			while (count < 1) {
				cout << "Число не может быть отрицательным или равняться 0. Повторите попытку: ";
				count = InputInt();
			}

			cout << "Тип генерации\n";
			PrintMessage(dataType.size(), dataType);
			int choice = InputAnswer(dataType.size());

			FileGenerator(count, choice);
			break;
		}
		case 2: {
			cout << "Какое имя вы хотите дать своему файлу?\n> ";
			string filename = InputFilename();
			ofstream fout(filename);

			cout << "> Выберите тип данных в файле\n";
			PrintMessage(dataType.size(), dataType);
			int choice = InputAnswer(dataType.size());

			CreateUserFile(fout, choice);
			printf("Ваш файл '%s' сохранён!\n", filename.c_str());

			break;
		}
	}

	dataType.clear();
	dataType.shrink_to_fit();
	createFile.clear();
	createFile.shrink_to_fit();
}

void SearchMethods()
{
	cout << endl;
	vector<string> nameMethods{ "С барьером", "Бинарный", "Фальшивая монета", "НАЗАД"};
	PrintMessage(nameMethods.size(), nameMethods);
	int answer = InputAnswer(nameMethods.size());
	
	switch (answer) {
		case 1:
			BarrierSearch();
			break;
		case 2:
			BinarySearch();
			break;
		case 3:
			FakeCoinSearch();
			break;
		case 4:
			nameMethods.clear();
			nameMethods.shrink_to_fit();
			break;
	}
	cout << endl;
}

void BarrierSearch()
{
	ArrData* massive = new ArrData;
	int dataType;

	do {
		dataType = Transfer(massive);

		if (dataType == -1)
			break;
		else if (dataType == 5) {
			cout << "Файл не подходит для данного метода!\n";
			break;
		}
		
	} while (BaS_AnalyzeFile(massive, dataType));

	delete(massive);
}

void BinarySearch()
{
	ArrData* massive = new ArrData;
	int dataType;

	do {

		dataType = Transfer(massive);

		if (dataType == -1)
			break;
		else if (dataType == 5) {
			cout << "Файл не подходит для данного метода!\n";
			break;
		}

	} while (BiS_AnalyzeFile(massive, dataType));

	delete(massive);
}

void FakeCoinSearch()
{
	ArrData* massive = new ArrData;
	int dataType;

	do {
		dataType = Transfer(massive);

		if (dataType == -1)
			break;
		else if (dataType != 5) {
			cout << "Файл не подходит для данного метода!\n";
			break;
		}

	} while (FakeCoin_AnalyzeFile(massive));

	delete(massive);
}

void EndProgram()
{
	vector<string> closeQuestion{ "Нет", "Да" };
	cout << "Удалить все созданные файлы?\n";
	PrintMessage(closeQuestion.size(), closeQuestion);
	int answer = InputAnswer(closeQuestion.size());

	if (answer == 1)
		try {
			fs::path currentPath = fs::current_path();
			for (const auto& entry : fs::directory_iterator(currentPath))
				if (entry.is_regular_file() && entry.path().extension() == ".txt")
					fs::remove(entry.path());
			cout << "Папка очищена!\n";
		}
	catch (const fs::filesystem_error& e) {
		std::cerr << "Упс... Не получилось" << e.what() << '\n';
	}
	catch (const std::exception& e) {
		std::cerr << "Ошибка: " << e.what() << '\n';
	}

	cout << "Спасибо за оказанное внимание! :)\n";
	return;
}