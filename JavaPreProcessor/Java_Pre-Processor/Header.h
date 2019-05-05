#include<stdio.h>
#include<iostream>
#include <functional>
#include <unordered_map>
#include <iterator>
#include<string>
using namespace std;

#define BUFFERSIZE 1024
#define INCLUDE 1
#define DEFINE 2

void analyser(char[], int);
int nextElementAfterSpace(char*);
int subStringLength(char buf[], char splitter);
int wordLength(char buf[]);
void Inclusion(char*, int );
