#include "Functions.h"

void StartProgram()
{
	int answer;
	vector<string> mainMenu{ "������ ������", "�������� ������", "����� �� ���������" };

	cout << "��� ������������ ���������, ��������� ��������� �.�.\n";

	while(true)
	{
		cout << "\n������� ����\n";
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
	cout << "\n�������� ������\n";
	cout << "����������: � ����������� �� ������ ������ �������� � ������ � �������� ����� ������ ��������:\n - [GF] (��������������� ����)\n - [UF] (���������������� ����)\n\n";

	vector<string> dataType{ "����� �����", "������������ �����", "�������", "�����", "��������� ������" };
	vector<string> createFile{ "������������� ����", "���������������� ����", "�����" };

	PrintMessage(createFile.size(), createFile);
	int answer = InputAnswer(createFile.size());

	switch (answer) {
		case 1: {
			cout << "> ������� ������ �������������? ";
			int count = InputInt();
			while (count < 1) {
				cout << "����� �� ����� ���� ������������� ��� ��������� 0. ��������� �������: ";
				count = InputInt();
			}

			cout << "��� ���������\n";
			PrintMessage(dataType.size(), dataType);
			int choice = InputAnswer(dataType.size());

			FileGenerator(count, choice);
			break;
		}
		case 2: {
			cout << "����� ��� �� ������ ���� ������ �����?\n> ";
			string filename = InputFilename();
			ofstream fout(filename);

			cout << "> �������� ��� ������ � �����\n";
			PrintMessage(dataType.size(), dataType);
			int choice = InputAnswer(dataType.size());

			CreateUserFile(fout, choice);
			printf("��� ���� '%s' �������!\n", filename.c_str());

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
	vector<string> nameMethods{ "� ��������", "��������", "��������� ������", "�����"};
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
			cout << "���� �� �������� ��� ������� ������!\n";
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
			cout << "���� �� �������� ��� ������� ������!\n";
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
			cout << "���� �� �������� ��� ������� ������!\n";
			break;
		}

	} while (FakeCoin_AnalyzeFile(massive));

	delete(massive);
}

void EndProgram()
{
	vector<string> closeQuestion{ "���", "��" };
	cout << "������� ��� ��������� �����?\n";
	PrintMessage(closeQuestion.size(), closeQuestion);
	int answer = InputAnswer(closeQuestion.size());

	if (answer == 1)
		try {
			fs::path currentPath = fs::current_path();
			for (const auto& entry : fs::directory_iterator(currentPath))
				if (entry.is_regular_file() && entry.path().extension() == ".txt")
					fs::remove(entry.path());
			cout << "����� �������!\n";
		}
	catch (const fs::filesystem_error& e) {
		std::cerr << "���... �� ����������" << e.what() << '\n';
	}
	catch (const std::exception& e) {
		std::cerr << "������: " << e.what() << '\n';
	}

	cout << "������� �� ��������� ��������! :)\n";
	return;
}