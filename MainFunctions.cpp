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

//
//void AnalyzeFile(int n, int x, vector<int>& massive, string filename)
//{
//	if (filename == "NN") 
//		string filename = to_string(n) + " [Explored].txt";
//	else
//		filename += " [Explored].txt";
//	ofstream fout(filename);
//
//	if (massive.back() == x) {
//		fout << massive.back() << endl;
//	}
//	else {
//		int i = 0;
//		massive.back() = x;
//		while (true) {
//			if (massive[i] == massive.back()) {
//				fout << "Позиция искомого числа: " << i + 1 <<endl;
//				break;
//			}
//			i++;
//		}
//	}
//	fout.close();
//}
//
void BarrierSearch()
{
	ArrData* massive = new ArrData;
	if (!Transfer(massive))
		return;
		

	cout << "BS1";
	int x;
	cin >> x;
	

}

void BinarySearch()
{
	cout << "BS2";
	int x;
	cin >> x;
}

void FakeCoinSearch()
{
	cout << "BS3";
	int x;
	cin >> x;
}

void GenerationFiles()
{
	cout << "\nСоздание файлов\n";
	cout << "Примечание: в зависимости от выбора метода создания у файлов в названии будут разные приписки:\n - [GF] (Сгенерированный файл)\n - [UF] (Пользовательский файл)\n";

	vector<string> dataType{ "Целые числа", "Вещественные числа", "Символы", "Слова" };
	vector<string> createFile{ "Сгенерировать файл", "Пользовательский файл", "НАЗАД" };

	PrintMessage(createFile.size(), createFile);
	int answer = InputAnswer(createFile.size());

	switch (answer) {
		case 1:{
			cout << "> Сколько файлов сгенерировать? ";
			int count = InputInt();

			cout << "> Тип данных в файле(-ах)\n";
			PrintMessage(dataType.size(), dataType);
			int choice = InputAnswer(dataType.size());

			FileGenerator(count, choice);
			break;
		}
		case 2: {
			cout << "Какое имя вы хотите дать своему файлу?\n";
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
