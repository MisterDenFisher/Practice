#include "Functions.h"

void PrintMessage(int n, vector<string> message)
{
	if (n != 2) {
		int i;
		for (i = 0; i < n; i++)
			printf("[%d] %s\n", i + 1, message[i].c_str());
	}
	else {
		printf("[y] %s\n", message[1].c_str());
		printf("[n] %s\n", message[0].c_str());
	}
	cout << "Выберите действие: ";
}

int InputInt()
{
	string input;
	while (true) {
		getline(cin, input);
		if (input[0] == '\n' || input[0] == '\0' || input[0] == ' ') {
			cout << "Строка не должна быть пустой! Повторите попытку: ";
			continue;
		}
		bool cycle = false;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] < 48 || input[i] > 57) {
				cout << "Строка должна содержать только цифры! Повторите попытку: ";
				cycle = true;
				break;
			}
		}
		if (!cycle) return stoi(input);
	}
}

int InputAnswer(int n)
{
	string input;

	if (n == 2)
		while (true) {
			getline(cin, input);

			if (input[0] == '\n' || input[0] == '\0' || input[0] == ' ') {
				cout << "Строка не должна быть пустой! Повторите попытку: ";
				continue;
			}
			else if (input.length() != 1) {
				cout << "Введите либо 'y' (да), либо 'n' (нет). Повторите попытку: ";
				continue;
			}
			else if (input[0] == 'y')
				return 1;
			else if (input[0] == 'n')
				return 0;
			else cout << "Введите либо 'y' (да), либо 'n' (нет). Повторите попытку: ";
		}
	else
		while (true) {
			getline(cin, input);
			if (input[0] == '\n' || input[0] == '\0' || input[0] == ' ') {
				cout << "Строка не должна быть пустой! Повторите попытку: ";
				continue;
			}
			bool cycle = false;
			for (int i = 0; i < input.length(); i++) {
				if (input[i] < 48 || input[i] > 57) {
					cout << "Строка должна содержать только цифры! Повторите попытку: ";
					cycle = true;
					break;
				}
			}
			if (!cycle)
				if (stoi(input) < 1 || stoi(input) > n)
					cout << "Данное действие отсутствует. Повторите попытку: ";
				else
					return stoi(input);
		}
}

string InputFilename()
{
	string input;
	while (true) {
		getline(cin, input);
		input += " [UF].txt";
		ofstream fout(input);
		ifstream fin(input);
		if (fin.good()) {
			fout.close();
			fin.close();
			return input;
		}
		else {
			cout << "Недопустимые символы для имени файла. Повторите попытку: ";
			fout.close();
			fin.close();
			continue;
		}
	}
}

void FileGenerator(int count, int dataType)
{
	string filename;
	int _language = 1;

	if (dataType >= 3) {
		vector<string> language{ "Кириллица", "Латиница" };
		cout << "> При генерации файла(-ов) использовать латиницу?\n";
		PrintMessage(language.size(), language);
		_language = InputAnswer(language.size());
	}

	for (int i = 0; i < count; i++) {
		filename = to_string(i + 1) + " [GF].txt";
		ofstream fout(filename);
		GenerateOneFile(fout, dataType, _language);
		printf("Файл '%s' сгенерирован!\n", filename.c_str());
	}

}

void GenerateOneFile(ofstream& fout, int dataType, int _language)
{
	random_device machine;
	mt19937 gen(machine());
	uniform_int_distribution<> dis(1, maxRange);

	int countNumb = dis(gen);

	switch (dataType) {
		case 1:
		{
			fout << "Int" << endl;

			uniform_int_distribution<> _int(-maxNumb, maxNumb);
			for (int i = 0; i < countNumb; i++)
				fout << _int(gen) << ' ';
			break;
		}

		case 2:
		{
			fout << "Float" << endl;

			uniform_real_distribution<> _real(-maxNumb, maxNumb);
			for (int i = 0; i < countNumb; i++)
				fout << round(_real(gen) * 10) / 10.0 << ' ';
			break;
		}
		case 3:
		{
			fout << "Char" << endl;

			if (_language == 1) {
				uniform_int_distribution<>_char(97, 122);
				for (int i = 0; i < countNumb; i++)
					fout << static_cast<char>(_char(gen) - 32 * (rand() % 2)) << ' ';
			}
			else {
				uniform_int_distribution<>_char(224, 255);
				for (int i = 0; i < countNumb; i++)
					fout << static_cast<char>(_char(gen) - 32 * (rand() % 2)) << ' ';
			}
			break;
		}
		case 4:
		{
			fout << "String" << endl;

			int lenght;
			string word;
			uniform_int_distribution<>size(1, 16);

			if (_language == 1) {
				uniform_int_distribution<>_char(97, 122);
				for (int i = 0; i < countNumb; i++) {
					lenght = size(gen);
					word += static_cast<char>(_char(gen) - 32 * (rand() % 2));
					for (int j = 1; j < lenght; j++)
						word += static_cast<char>(_char(gen));
					fout << word << ' ';
					word = "";
				}
			}
			else {
				uniform_int_distribution<>_char(224, 255);
				for (int i = 0; i < countNumb; i++) {
					lenght = size(gen);
					word += static_cast<char>(_char(gen) - 32 * (rand() % 2));
					for (int j = 1; j < lenght; j++)
						word += static_cast<char>(_char(gen));
					fout << word << ' ';
					word = "";
				}
				break;
			}
		}
	}
}

void CreateUserFile(ofstream& fout, int choice)
{
	cout << "!Вводите данные через пробел!\n> ";

	switch (choice) {
		case 1:
			fout << "Int" << endl;
			break;
		case 2:
			fout << "Float" << endl;
			break;
		case 3:
			fout << "Char" << endl;
			break;
		case 4:
			fout << "String" << endl;
			break;
	}
	
	string data;
	while (true)
	{
		getline(cin, data);
		if (data.empty()) {
			cout << "Файл не может быть пустым! Продолжите ввод\n> ";
			continue;
		}
		fout << data;
		if (data[data.length() - 1] != ' ')
			fout << ' ';
		break;
	}
	fout.close();
}

bool Transfer(ArrData* massive)
{
	string filename;

	cout << "Введите имя файла, где производить поиск: ";
	getline(cin, filename);
	int attempt = 1;

	ifstream fin(filename);
	
	while (!fin.good()) {
		cout << "Файла с указанным названием не существует! Повторите попытку: ";
		getline(cin, filename);
		ifstream fin(filename);
		if (attempt == 2)
			return false;
		++attempt;
	}
	
	string dataType;
	string data;
	string oneElem;

	getline(fin, dataType);
	getline(fin, data);

	if (dataType == "Int"){
		int number;
		for (int i = 0; i < data.length(); i++) {
			if (data[i] != ' ')
				oneElem += data[i];
			else {

			}
		}
	}
	else if (dataType == "Real") {

	}
	else if (dataType == "Char") {

	}
	else {

	}
	return true;

}