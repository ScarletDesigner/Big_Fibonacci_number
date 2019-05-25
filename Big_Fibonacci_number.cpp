#include <iostream>
using namespace std;
int isShorter(string a, string b)
{
	if (a.length() < b.length())
		return a.length();
	else
		return b.length();
}

class AttributesToAddStrings
{
	public:
		string first, second;
		int shorterLength;
		int firstLeftDigits, secondLeftDigits;
		string result;
		int shift;
		int lastDigit;
		int ASCIofZero;
	AttributesToAddStrings()
	{
		result = "";
		shift = 0;
		ASCIofZero = 48;
	}
	initialization(string one, string two)
	{
		first = one;
		second = two;
		shorterLength = isShorter(one, two);
		firstLeftDigits = one.length();
		secondLeftDigits = two.length();
	}
};
void addTillLengthMatches(AttributesToAddStrings &a)
{
	for(int i=1; i <= a.shorterLength; i++)
	{
		a.lastDigit = (int)(a.first[--a.firstLeftDigits]) + (int)(a.second[--a.secondLeftDigits]) + a.shift - 96;
		a.shift = a.lastDigit / 10;
		a.result = (char)((a.lastDigit % 10) + a.ASCIofZero) + a.result;
	}
}
void addLeftDigitsOfFirstString(AttributesToAddStrings &a)
{
	while(a.firstLeftDigits > 0)
	{
		a.lastDigit = a.first[--a.firstLeftDigits] + a.shift - a.ASCIofZero;
		a.shift = a.lastDigit / 10;
		a.result = (char)((a.lastDigit % 10) + a.ASCIofZero) + a.result;
	}
}
void addLeftDigitsOfSecondString(AttributesToAddStrings &a)
{
	while(a.secondLeftDigits > 0)
	{
		a.lastDigit = a.second[--a.secondLeftDigits] + a.shift - 48;
		a.shift = a.lastDigit / 10;
		a.result = (char)((a.lastDigit % 10) + 48) + a.result;
	}
}
void addLeftShiftToNewRow(AttributesToAddStrings &a)
{
	if(a.shift > 0)
		a.result = (char)(a.shift + 48) + a.result;
}
void checkForEmptyResult(AttributesToAddStrings &a)
{
	if(a.result == "")
		a.result = "0";
}
string add(string first, string second)
{
	AttributesToAddStrings a;
	a.initialization(first, second);
	addTillLengthMatches(a);
	addLeftDigitsOfFirstString(a);
	addLeftDigitsOfSecondString(a);
	addLeftShiftToNewRow(a);
	checkForEmptyResult(a);
	return a.result;
}

string fibonacci(int n)
{
	if(n == 0)
		return "0";
	if(n == 1)
		return "1";
	string fib[n+1];
	fib[0] = '0';
	fib[1] = '1';
	for(int i=2; i<=n; i++)
	{
		fib[i] = add(fib[i-1], fib[i-2]);
	}
	return fib[n];
}
int main(){
cout<<fibonacci(1000);
	return 0;
}
