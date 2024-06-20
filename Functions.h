#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <cstdio>
#include <random>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

//Параметры генерации
const int maxRange = 500;
const int maxNumb = 1000;

struct ArrData {
	vector<int> intArr;
	vector<float> floatArr;
	vector<char> charArr;
	vector<string> stringArr;
};

//Основные функции
void StartProgram();
void GenerationFiles();
void SearchMethods();
void BarrierSearch();
void BinarySearch();
void FakeCoinSearch();
void EndProgram();

//Генерация файлов
void FileGenerator(int, int);
void GenerateOneFile(ofstream&, int, int);
void CreateUserFile(ofstream&, int);

//Вывод сообщений и массивов
void PrintMessage(int, vector<string>);
template <typename T> 
void PrintMassive(const vector<T>&);

//Ввод данных пользователем
int InputInt();
float InputFloat();
char InputChar();
string InputString();
int InputAnswer(int);
string InputFilename();

//Чтение файла, запись данных в массив
int Transfer(ArrData*);

//Поиск с барьером
bool BaS_AnalyzeFile(ArrData*, int);
template <typename T> 
bool BaS_Cycle(vector<T>&, T);

//Бинарный поиск
bool BiS_AnalyzeFile(ArrData*, int);
template <typename T> int* BiS_Sorting(vector<T>&);
template <typename T> bool BiS_Cycle(vector<T>&, int*, T x);

//Фальшивая монета
bool FakeCoin_AnalyzeFile(ArrData*);
bool FakeCoin_CompHeap(vector<char>&, int);
void FakeCoin_Cycle(vector<char>&);