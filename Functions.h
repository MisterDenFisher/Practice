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

const int maxRange = 50;
const int maxNumb = 1000;

struct ArrData {
	vector<int> intArr;
	vector<float> floatArr;
	vector<char> charArr;
	vector<string> stringArr;
};

void StartProgram();
void SearchMethods();
void GenerationFiles();
void FileGenerator(int, int);
void GenerateOneFile(ofstream&, int, int);
void CreateUserFile(ofstream&, int);

void PrintMessage(int, vector<string>);
int InputInt();
int InputAnswer(int);
string InputFilename();


void BarrierSearch();
void BinarySearch();
void FakeCoinSearch();

int Transfer(ArrData*);
bool BaS_AnalyzeFile(ArrData*, int);
template <typename T> void BaS_PrintMassive(const vector<T>&);
template <typename T> bool BaS_Cycle(vector<T>&, T);

bool BiS_AnalyzeFile(ArrData*, int);
template <typename T> void BiS_Sorting(vector<T>&);
template void BiS_Sorting<int>(vector<int>&);
template <typename T> bool BiS_Cycle(vector<T>&, T x);
