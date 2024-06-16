#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <cstdio>
#include <random>

using namespace std;

const int maxRange = 1000;
const int maxNumb = 100;

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
//void AnalyzeFile(int, int, vector<int>&, string filename = "NN");