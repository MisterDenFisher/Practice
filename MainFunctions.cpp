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
//				fout << "������� �������� �����: " << i + 1 <<endl;
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
	cout << "\n�������� ������\n";
	cout << "����������: � ����������� �� ������ ������ �������� � ������ � �������� ����� ������ ��������:\n - [GF] (��������������� ����)\n - [UF] (���������������� ����)\n";

	vector<string> dataType{ "����� �����", "������������ �����", "�������", "�����" };
	vector<string> createFile{ "������������� ����", "���������������� ����", "�����" };

	PrintMessage(createFile.size(), createFile);
	int answer = InputAnswer(createFile.size());

	switch (answer) {
		case 1:{
			cout << "> ������� ������ �������������? ";
			int count = InputInt();

			cout << "> ��� ������ � �����(-��)\n";
			PrintMessage(dataType.size(), dataType);
			int choice = InputAnswer(dataType.size());

			FileGenerator(count, choice);
			break;
		}
		case 2: {
			cout << "����� ��� �� ������ ���� ������ �����?\n";
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
