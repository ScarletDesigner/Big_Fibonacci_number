#include <iostream>
using namespace std;

class AttributesToAddStrings
{
public:
	string first, second;
	int shorterLength;
	int firstLeftDigits, secondLeftDigits;
	string result;
	int shift;
	int lastDigit;
	static const int ASCIofZero = 48;

	initialization(string one, string two)
	{
		first = one;
		second = two;
		shorterLength = isShorter(one, two);
		firstLeftDigits = one.length();
		secondLeftDigits = two.length();
		result = "";
		shift = 0;
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
	
	string add(string first, string second)
	{
		initialization(first, second);
		addTillLengthMatches();
		addLeftDigitsOfFirstString();
		addLeftDigitsOfSecondString();
		addLeftShiftToNewRow();
		checkForEmptyResult();
		return result;
	}
	
	int isShorter(string a, string b)
	{
		if (a.length() < b.length())
			return a.length();
		else
			return b.length();
	}
	
	void addTillLengthMatches()
	{
		for(int i=1; i <= shorterLength; i++)
		{
			lastDigit = (int)(first[--firstLeftDigits]) + (int)(second[--secondLeftDigits]) + shift - 96;
			shift = lastDigit / 10;
			result = (char)((lastDigit % 10) + ASCIofZero) + result;
		}
	}
	
	void addLeftDigitsOfFirstString()
	{
		while(firstLeftDigits > 0)
		{
			lastDigit = first[--firstLeftDigits] + shift - ASCIofZero;
			shift = lastDigit / 10;
			result = (char)((lastDigit % 10) + ASCIofZero) + result;
		}
	}
	
	void addLeftDigitsOfSecondString()
	{
		while(secondLeftDigits > 0)
		{
			lastDigit = second[--secondLeftDigits] + shift - 48;
			shift = lastDigit / 10;
			result = (char)((lastDigit % 10) + 48) + result;
		}
	}
	
	void addLeftShiftToNewRow()
	{
		if(shift > 0)
			result = (char)(shift + 48) + result;
	}
	
	void checkForEmptyResult()
	{
		if(result == "")
			result = "0";
	}
	
};

int main(){
	
	AttributesToAddStrings a;
	cout<<a.fibonacci(1000);
	
	return 0;
}
