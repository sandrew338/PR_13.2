/*
 lab_13_2.
 ��������� ����� �����, ������ �������� � ���� �����, ��������������
 ������� ��������� �� ��������, ��������� ����������, �����������
 ������������� ��������. �� ��������� �������� ������ ���������
 ����������� ��� ������� ��������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <string.h>
#include<fstream>
#define SQR(x) (x)*(x) // ������ � ���������� � ���������� �������� �����
#define SQRT(x) sqrt(x)// ������ � ���������� � ���������� ���������� ������ �����
// ������ ���������� ���������� � ���� �����
#define min(a,b) ((a)>(b))?(a):(b) // ������ �� ������� �����
#define ABS(x) ((x) < 0 ? -(x) : (x)) //#define ABS(x) abs(x);
#define max(a,b) ((a)<(b))?(a):(b) // ������ �� ������� �����
#define IS_DIGIT(c) ((c >= '0' && c <= '9') ? 1 : 0) // �� � �����
#define IS_ALPHABETIC(c) (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? 1 : 0)// �� � �����
#define IS_PUNCTUATION(c) (((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126)) ? 1 : 0)// �� � ����������
 // ��������� ����������� �� �������� ������ �����
#define PRINTI(w) puts("control output"); \
 printf(#w"=%d\n",w)
#define PRINTS(s) printf("No %s", s);
 // ��������������� ������ ����������� ������� '\'
// ������ '#' ��������������� ��� �ᒺ������ �����
 // ��������� ����������� �� �������� ������� �����
#define PRINTR(w) puts ("result :"); \
 printf (#w"=%f\n",(float)w)
#define PRINT_CHAR(type, count) \
printf("%s characters: %d\n", type, count);
#define PRINTSTR(type, str) \
printf("%s : %s\n", type, str.c_str());
std::string sortString(std::string s, int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (s[j] > s[j + 1]) std::swap(s[j], s[j + 1]);
		}
	}
	return s;
}
void processFile(const char* filename) {

	FILE* file = fopen(filename, "r");
	 
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int digitCount = 0, letterCount = 0, punctuationCount = 0, otherCount = 0;
	std::string digits, letters, punc_marks;
    int c;
	int i = 0;
	while ((c = fgetc(file)) != EOF) {
		if (IS_DIGIT(c)) {
			printf("Digit: %c\n", c);
			digits += (char)c;
			digitCount++;
		}
		else if (IS_ALPHABETIC(c)) {
			printf("Alphabetic: %c\n", c);
			letters += (char)c;
			letterCount++;
		}
		else if (IS_PUNCTUATION(c)) {
			printf("Punctuation: %c\n", c);
			punc_marks += (char)c;
			punctuationCount++;
		}
		else {
			otherCount++;
		}
	}
	PRINTSTR("digits", sortString(digits, digitCount));
	PRINTSTR("letters", sortString(letters, letterCount));
	PRINTSTR("punc_marks", sortString(punc_marks, punctuationCount));
	if(digitCount != letterCount && digitCount != punctuationCount)
		if (digitCount == 0)
			PRINTS("Digits");
		if(letterCount == 0)
			PRINTS("letters")
		if( punctuationCount == 0)
			PRINTS("punctuation marks")
}
void main()
{
	puts("Lab 13.2. Using macros and preprocessing directive");
	int x, y, z, w, n, n_abs, n_kvadr, n_sqrt; // ���� ��� ����������
	char ch; // ������� �� ������������ ��������� ��������
	//float rad, s; // ����� � ����� �����
	do
	{
		puts("define maximum of two numbers");
		puts("Input 3 integer numbers");
		scanf("%d", &x);// �������� �����
		PRINTI(x); // ������ ��������� �����
		scanf("%d", &y);
		PRINTI(y);
		scanf("%d", &z);
		PRINTI(z);
		if (z > 3)// ���� ����� �������,
			w = min(SQR(x - z), x - y);// �� ������ �������� � ����� �����
		// ���������� ���� ������� ��������, ���� z <= 10
		else
			w = max(x * y, y * z) + min(z * x, y * z);
		puts("Input number");
		scanf("%d", &n);
		PRINTI(w);
		n_abs = ABS(n);
		n_kvadr = SQR(n);
		n_sqrt = SQRT(n);
		PRINTI(n_abs);
		PRINTI(n_kvadr);
		PRINTI(n_sqrt);
		puts("Repeat? y /n "); ch = _getch();
	} while (ch == 'y');
    ////////////////////////////////////////////////////////////////////
    puts("2 exersice\n");
    const char* filename = "my_text_file.txt";
    processFile(filename);
}