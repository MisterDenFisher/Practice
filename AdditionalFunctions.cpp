#include "Functions.h"

//����� ��������� � ��������
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
	cout << "> �������� ��������: ";
}

template <typename T>
void PrintMassive(const vector<T>& massive)
{
	printf("(���������� ���������: %d):\n", massive.size());
	for (int i = 0; i < massive.size(); i++)
		cout << massive[i] << ' ';
	cout << endl;
}


//���� ������ �������������
int InputInt()
{
	string input;
	while (true) {
		getline(cin, input);
		if (input[0] == '\n' || input[0] == '\0' || input[0] == ' ') {
			cout << "������ �� ������ ���� ������!\n> ��������� �������: ";
			continue;
		}
		bool cycle = false;
		for (int i = 0; i < input.length(); i++) {
			if ((input[i] < 48 || input[i] > 57) && (input[i] != 45)) {
				cout << "������ ������ ��������� ������ �����!\n> ��������� �������: ";
				cycle = true;
				break;
			}
		}
		if (!cycle) return stoi(input);
	}
}

float InputFloat()
{
	string input;
	while (true) {
		getline(cin, input);
		if (input[0] == '\n' || input[0] == '\0' || input[0] == ' ') {
			cout << "������ �� ������ ���� ������!\n> ��������� �������: ";
			continue;
		}
		bool cycle = false;
		for (int i = 0; i < input.length(); i++) {
			if ((input[i] < 48 || input[i] > 57) && (input[i] != 45) && (input[i] != 46)) {
				cout << "������ ������ ��������� ������ �����!\n> ��������� �������: ";
				cycle = true;
				break;
			}
		}
		if (!cycle) return stof(input);
	}
}

char InputChar()
{
	string input;
	while (true) {
		getline(cin, input);
		if (input[0] == '\n' || input[0] == '\0' || input[0] == ' ') {
			cout << "������ �� ������ ���� ������!\n> ��������� �������: ";
			continue;
		}
		if (input.length() != 1)
			cout << "������� ������ ���� �����!\n> ��������� �������: ";
		else
			return input[0];
	}
}

string InputString()
{
	string input;
	while (true) {
		getline(cin, input);
		if (input[0] == '\n' || input[0] == '\0' || input[0] == ' ') {
			cout << "������ �� ������ ���� ������!\n> ��������� �������: ";
			continue;
		}
		else
			return input;
	}
}

int InputAnswer(int n)
{
	string input;

	if (n == 2)
		while (true) {
			getline(cin, input);

			if (input[0] == '\n' || input[0] == '\0' || input[0] == ' ') {
				cout << "������ �� ������ ���� ������!\n> ��������� �������: ";
				continue;
			}
			else if (input.length() != 1) {
				cout << "������� ���� 'y' (��), ���� 'n' (���)!\n> ��������� �������: ";
				continue;
			}
			else if (input[0] == 'y')
				return 1;
			else if (input[0] == 'n')
				return 0;
			else cout << "������� ���� 'y' (��), ���� 'n' (���)!\n> ��������� �������: ";
		}
	else
		while (true) {
			getline(cin, input);
			if (input[0] == '\n' || input[0] == '\0' || input[0] == ' ') {
				cout << "������ �� ������ ���� ������!\n> ��������� �������: ";
				continue;
			}
			bool cycle = false;
			for (int i = 0; i < input.length(); i++) {
				if (input[i] < 48 || input[i] > 57) {
					cout << "������ ������ ��������� ������ �����!\n> ��������� �������: ";
					cycle = true;
					break;
				}
			}
			if (!cycle)
				if (stoi(input) < 1 || stoi(input) > n)
					cout << "������ �������� �����������!\n> ��������� �������: ";
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
			cout << "������������ ������� � ����� �����!\n> ��������� �������: ";
			fout.close();
			fin.close();
			continue;
		}
	}
}


//��������� ������
void FileGenerator(int count, int dataType)
{
	string filename;
	int _language = 1;

	if (dataType == 3 || dataType == 4) {
		vector<string> language{ "���������", "��������" };
		cout << "> ��� ��������� �����(-��) ������������ ��������?\n";
		PrintMessage(language.size(), language);
		_language = InputAnswer(language.size());
	}

	for (int i = 0; i < count; i++) {
		filename = to_string(i + 1) + " [GF].txt";
		ofstream fout(filename);
		GenerateOneFile(fout, dataType, _language);
		printf("���� '%s' ������������!\n", filename.c_str());
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
			break;
		}
		case 5:
		{
			fout << "FakeCoin" << endl;

			int typeGen = rand() % 3 + 1;
			countNumb = rand() % maxRange + 3;

			switch (typeGen) {
				case 1:
				{
					int numb = rand() % 10;
					int FakeCoin = rand() % 10;
					while (numb == FakeCoin)
						FakeCoin = rand() % 10;

					int posFakeCoin = rand() % countNumb;
					int i;
					for (i = 0; i < posFakeCoin - 1; i++)
						fout << numb << ' ';
					fout << FakeCoin << ' ';
					for (i = posFakeCoin; i < countNumb; i++)
						fout << numb << ' ';
					break;
				}

				case 2:
				{
					int _charCode = rand() % 64 + 192;
					int FakeCoinCode = rand() % 64 + 192;
					while (_charCode == FakeCoinCode)
						FakeCoinCode = rand() % 64 + 192;

					char _char = static_cast<char>(_charCode);
					char FakeCoin = static_cast<char>(FakeCoinCode);

					int posFakeCoin = rand() % countNumb;
					int i;
					for (i = 0; i < posFakeCoin - 1; i++)
						fout << _char << ' ';
					fout << FakeCoin << ' ';
					for (i = posFakeCoin; i < countNumb; i++)
						fout << _char << ' ';
					break;
				}

				case 3:
				{
					int _charCode = (rand() % 26 + 65) + (rand() % 2 * 32);
					int FakeCoinCode = (rand() % 26 + 65) + (rand() % 2 * 32);
					while (_charCode == FakeCoinCode)
						FakeCoinCode = (rand() % 26 + 65) + (rand() % 2 * 32);

					char _char = static_cast<char>(_charCode);
					char FakeCoin = static_cast<char>(FakeCoinCode);

					int posFakeCoin = rand() % countNumb;
					int i;
					for (i = 0; i < posFakeCoin - 1; i++)
						fout << _char << ' ';
					fout << FakeCoin << ' ';
					for (i = posFakeCoin; i < countNumb; i++)
						fout << _char << ' ';
					break;
				}
			}
			break;
		}
	}
}

void CreateUserFile(ofstream& fout, int choice)
{
	cout << "!������� ������ ����� ������!\n> ";

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
			cout << "���� �� ����� ���� ������! ���������� ����\n> ";
			continue;
		}
		fout << data;
		if (data[data.length() - 1] != ' ')
			fout << ' ';
		break;
	}
	fout.close();
}


//������ �����, ������ ������ � ������
int Transfer(ArrData* massive)
{
	string filename;
	bool userFile = false;

	cout << "\n����������: ��� ����� �������� ����� ��� ���������� (.txt) ��������� �� �����, � ��� ����� ([UF]/[GF]) ����������� ����� ��������� (��� �������, ��� �� ��������� ���� � ����������)\n\n";
	cout << "> ������� ��� �����, ��� ����������� �����: ";
	getline(cin, filename);
	filename += ".txt";
	while (!fs::exists(filename)) {
		cout << "����� � ��������� ��������� �� ����������!\n> ��������� �������: ";
		getline(cin, filename);
		filename += ".txt";
	}
	ifstream fin(filename);

	if (filename[filename.size() - 7] == 'U')
		userFile = true;
	
	string dataType;
	string data;
	string elem;

	getline(fin, dataType);
	getline(fin, data);

	if (dataType == "Int") {
		if (!userFile)
			for (int i = 0; i < data.length(); i++)
				if (data[i] != ' ')
					elem += data[i];
				else {
					massive->intArr.push_back(stoi(elem));
					elem = "";
				}
		else {
			int number;
			size_t pos;
			for (int i = 0; i < data.length(); i++)
				if (data[i] != ' ')
					elem += data[i];
				else {
					try {
						number = stoi(elem, &pos);
						if (pos != elem.length()) {
							cout << "���� �������� ��������, �� ��������������� ������������ ���� ������!!!\n";
							return -1;
						}
						massive->intArr.push_back(number);
						elem = "";
					}
					catch (const invalid_argument& e) {
						cerr << "���� �������� ��������, �� ��������������� ������������ ���� ������!!!\n";
						return -1;
					}
					
				}
		}
		return 1;
	}
	else if (dataType == "Float") {
		if (!userFile)
			for (int i = 0; i < data.length(); i++)
				if (data[i] != ' ')
					elem += data[i];
				else {
					massive->floatArr.push_back(stof(elem));
					elem = "";
				}
		else {
			float number;
			size_t pos;
			for (int i = 0; i < data.length(); i++)
				if (data[i] != ' ')
					elem += data[i];
				else {
					try {
						number = stof(elem, &pos);
						if (pos != elem.length()) {
							cout << "���� �������� ��������, �� ��������������� ������������ ���� ������!!!\n";
							return -1;
						}
						massive->floatArr.push_back(number);
						elem = "";
					}
					catch (const invalid_argument& e) {
						cerr << "���� �������� ��������, �� ��������������� ������������ ���� ������!!!\n";
						return -1;
					}

				}
		}
		return 2;
	}
	else if (dataType == "Char" || dataType == "FakeCoin") {
		for (int i = 0; i < data.length(); i++)
			if (data[i] != ' ')
				massive->charArr.push_back(data[i]);
		if (dataType == "Char")
			return 3;
		else
			return 5;
	}
	else {
		for (int i = 0; i < data.length(); i++)
			if (data[i] != ' ')
				elem += data[i];
			else {
				massive->stringArr.push_back(elem);
				elem = "";
			}
		return 4;
	}
}


//����� � ��������
bool BaS_AnalyzeFile(ArrData* massive, int typeData)
{
	cout << "���������� ����� ";
	bool _continue;

	switch (typeData) {
	case 1:
		PrintMassive(massive->intArr);
		do {
			cout << "\n> ����� ����� �� ������ ����� � ������ �����?	";
			int x = InputInt();
			cout << "������� �����: ";
			_continue = BaS_Cycle(massive->intArr, x);
		} while (_continue);
		break;

	case 2:
		PrintMassive(massive->floatArr);
		do {
			cout << "\n> ����� ����� �� ������ ����� � ������ �����?	";
			float x = InputFloat();
			cout << "������� �����: ";
			_continue = BaS_Cycle(massive->floatArr, x);
		} while (_continue);
		break;
	case 3:
		PrintMassive(massive->charArr);
		do {
			cout << "\n> ����� ����� �� ������ ����� � ������ �����?	";
			char x = InputChar();
			cout << "������� �������: ";
			_continue = BaS_Cycle(massive->charArr, x);
		} while (_continue);
		break;
	case 4:
		PrintMassive(massive->stringArr);
		do {
			cout << "\n> ����� ����� �� ������ ����� � ������ �����?	";
			string x = InputString();
			cout << "������� �����: ";
			_continue = BaS_Cycle(massive->stringArr, x);
		} while (_continue);
		break;
	}
	cout << "> ���������� �������� � ���� ������� ������?\n";
	vector<string> closeQuestion{ "���", "��" };
	PrintMessage(closeQuestion.size(), closeQuestion);
	int answer = InputAnswer(closeQuestion.size());
	closeQuestion.shrink_to_fit();
	closeQuestion.clear();

	if (answer == 0)
		return 0;
	else
		return 1;
}

template <typename T>
bool BaS_Cycle(vector<T>& massive, T x)
{
	vector<string> closeQuestion{ "���", "��" };
	bool found;
	bool last;

	while (true) {
		found = false;
		last = false;

		if (massive.back() == x)
			last = true;

		int i = 0;
		massive.back() = x;
		while (true) {
			while (true) {
				if (massive[i] == massive.back())
					break;
				i++;
			}
			if (i == massive.size() - 1)
				break;
			found = true;
			cout << i + 1 << ' ';
			i++;
		}

		if (last)
			cout << massive.size();
		else if (!found)
			cout << "�����������!!!";
		cout << endl;
		break;
	}


	cout << "> ������ �� �� ���������� ����� � ������� �����?\n";
	PrintMessage(closeQuestion.size(), closeQuestion);
	int answer = InputAnswer(closeQuestion.size());
	closeQuestion.shrink_to_fit();
	closeQuestion.clear();

	if (answer == 0) {
		massive.shrink_to_fit();
		massive.clear();
		return 0;
	}
	else
		return 1;
}


//�������� �����
bool BiS_AnalyzeFile(ArrData* massive, int typeData)
{
	bool _continue = false;
	int* pos;

	switch (typeData) {
		case 1:
			pos = BiS_Sorting(massive->intArr);
			do {
				cout << "\n> ����� ����� �� ������ ����� � ������ �����?	";
				int x = InputInt();
				_continue = BiS_Cycle(massive->intArr, pos, x);

			} while (_continue);
			break;
		case 2:
			pos = BiS_Sorting(massive->floatArr);
			do {
				cout << "\n> ����� ����� �� ������ ����� � ������ �����?	";
				float x = InputFloat();
				_continue = BiS_Cycle(massive->floatArr, pos, x);

			} while (_continue);
			break;
		case 3:
			pos = BiS_Sorting(massive->charArr);
			do {
				cout << "\n> ����� ����� �� ������ ����� � ������ �����?	";
				char x = InputChar();
				_continue = BiS_Cycle(massive->charArr, pos, x);
			} while (_continue);
			break;
		case 4:
			pos = BiS_Sorting(massive->stringArr);
			do {
				cout << "\n> ����� ����� �� ������ ����� � ������ �����?	";
				string x = InputString();
				_continue = BiS_Cycle(massive->stringArr, pos, x);

			} while (_continue);
			break;
	}

	cout << "> ���������� �������� � ���� ������� ������?\n";
	vector<string> closeQuestion{ "���", "��" };
	PrintMessage(closeQuestion.size(), closeQuestion);
	int answer = InputAnswer(closeQuestion.size());

	closeQuestion.shrink_to_fit();
	closeQuestion.clear();

	if (answer == 0)
		return 0;
	else
		return 1;
}

template <typename T> 
int* BiS_Sorting(vector<T>& massive)
{
	int* pos = new int[massive.size()];
	for (int i = 0; i < massive.size(); i++)
		pos[i] = i + 1;

	cout << "����������� ���������� ����� ";
	PrintMassive(massive);

	T temp;
	for (int i = 0; i < massive.size() - 1; i++)
		for (int j = i + 1; j > 0; j--)
			if (massive[j] < massive[j - 1]) {
				swap(massive[j], massive[j - 1]);
				swap(pos[j], pos[j - 1]);
			}
			else
				break;

	cout << "���� ����� ���������� ";
	PrintMassive(massive);

	return pos;
}

template <typename T> 
bool BiS_Cycle(vector<T>& massive, int* pos, T x)
{
	bool found = false;
	int left = 0;
	int right = massive.size() - 1;
	int mid;
	
	cout << "������� �������� ��������: ";
	while (left <= right) {
		mid = (left + right) / 2;
		if (massive[mid] == x) {
			while (mid > left && massive[mid - 1] == x)
				mid--;
			while (mid < right && massive[mid + 1] == x) {
				cout << pos[mid] << ' ';
				mid++;
			}
			cout << pos[mid] << endl;
			found = true;
			break;
		}
		else if (massive[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}		
	}
	if (!found)
		cout << "����� �����������\n";

	cout << "> ������ �� �� ���������� ����� � ������� �����?\n";
	vector<string> closeQuestion{ "���", "��" };
	PrintMessage(closeQuestion.size(), closeQuestion);
	int answer = InputAnswer(closeQuestion.size());
	
	closeQuestion.shrink_to_fit();
	closeQuestion.clear();

	if (answer == 0) {
		massive.shrink_to_fit();
		massive.clear();
		delete(pos);
		return 0;
	}
	else
		return 1;
}


//��������� ������
bool FakeCoin_AnalyzeFile(ArrData* massive)
{
	if (massive->charArr.size() < 3) 
		cout << "���� �������� ������ 3 ��������. ����������� ��������� ������ ����������!\n";
	else {
		cout << "���������� �����\n";
		FakeCoin_Cycle(massive->charArr);
	}

	vector<string> closeQuestion{ "���", "��" };
	cout << "> ���������� �������� � ���� ������� ������?\n";
	PrintMessage(closeQuestion.size(), closeQuestion);
	int answer = InputAnswer(closeQuestion.size());
	closeQuestion.shrink_to_fit();
	closeQuestion.clear();

	if (answer == 0)
		return 0;
	else
		return 1;
}

void FakeCoin_Cycle(vector<char>& massive)
{
	int heap;
	char RealCoin;

	vector<int> pos;
	pos.reserve(massive.size());
	for (int i = 0; i < massive.size(); i++)
		pos.push_back(i + 1);
	
	if (massive[0] == massive[1])
		RealCoin = massive[0];
	else if (massive[0] == massive[2]) {
		cout << "������� ��������� ������: 2\n";
		return;
	}
	else {
		cout << "������� ��������� ������: 1\n";
		return;
	}

	while (true)
	{
		PrintMassive(massive);

		if (massive.size() < 3) {
			cout << "������� ��������� ������: ";
			if (massive[0] != RealCoin)
				cout << pos[0] << endl;
			else
				cout << pos[1] << endl;
			break;
		}
		else {
			heap = massive.size() / 3;

			if (FakeCoin_CompHeap(massive, heap)) {
				massive.erase(massive.begin(), massive.begin() + (heap * 2));
				pos.erase(pos.begin(), pos.begin() + heap * 2);
			}
			else {
				massive.erase(massive.begin() + (heap * 2), massive.end());
				pos.erase(pos.begin() + (heap * 2), pos.end());
			}
		}
	}

	massive.shrink_to_fit();
	massive.clear();
	pos.shrink_to_fit();
	pos.clear();
}

bool FakeCoin_CompHeap(vector<char>& massive, int heap)
{
	int heap1_s = 0;
	int heap2_s = 0;
	int i;

	for (i = 0; i < heap; i++) 
		heap1_s += static_cast<int>(massive[i]);
	for (; i < heap * 2; i++)
		heap2_s += static_cast<int>(massive[i]);

	if (heap1_s == heap2_s)
		return true;
	else
		return false;

}
