/** 
This file is the header file for Analyzer struct and its related functions. 

Author: Kenya Holland
Course: Programming Languages
File: analyzer.h

*/

#ifndef ANALYZER_H
#define ANALYZER_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "symbol.h"

#define ID 302
#define NUM 303
#define BEGIN 400
#define END 401
#define NOT_FOUND -1
#define DONE 500
#define SIZE 20

typedef struct Analyzer{
	FILE * fp;
	int lineNo;
	char ch;
} AnalyzerStruct;

AnalyzerStruct a;

void openFile(char *argv);

int lexan();

int getLexeme();
void ignoreComment();
int getValidNum();

void closeFile();

#endif