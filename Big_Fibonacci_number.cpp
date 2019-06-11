#include <iostream>
using namespace std;

class FibonacciNumberCreator
{
	string first, second;
	int shorterLength;
	int firstLeftDigits, secondLeftDigits;
	string result;
	int shift;
	int lastDigit;
	static const int ASCIofZero = 48;
	
public:
	string fibonacciNumber(int n)
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
			fib[i] = addStrings(fib[i-1], fib[i-2]);
		}
		
		checkForEmptyResult();
		
		return fib[n];
	}
	
private:

	string addStrings(string a, string b)
	{
		initialization(a, b);
		addTillLengthMatches();
		addRemainingDigitsOfFirstString();
		addRemainingDigitsOfSecondString();
		addRemainingShiftToNewRow();
		
		return result;
	}

	initialization(string a, string b)
	{
		first = a;
		second = b;
		shorterLength = isShorter();
		firstLeftDigits = first.length();
		secondLeftDigits = second.length();
		result = "";
		shift = 0;
	}
	
	int isShorter()
	{
		if (first.length() < second.length())
			return first.length();
		else
			return second.length();
	}
	
	void addTillLengthMatches()
	{
		for(int i = 1; i <= shorterLength; i++)
		{
			lastDigit = (int)(first[--firstLeftDigits]) + (int)(second[--secondLeftDigits]) + shift - 2*ASCIofZero;
			shift = lastDigit / 10;
			result = (char)((lastDigit % 10) + ASCIofZero) + result;
		}
	}
	
	void addRemainingDigitsOfFirstString()
	{
		while(firstLeftDigits > 0)
		{
			lastDigit = first[--firstLeftDigits] + shift - ASCIofZero;
			shift = lastDigit / 10;
			result = (char)((lastDigit % 10) + ASCIofZero) + result;
		}
	}
	
	void addRemainingDigitsOfSecondString()
	{
		while(secondLeftDigits > 0)
		{
			lastDigit = second[--secondLeftDigits] + shift - ASCIofZero;
			shift = lastDigit / 10;
			result = (char)((lastDigit % 10) + ASCIofZero) + result;
		}
	}
	
	void addRemainingShiftToNewRow()
	{
		if(shift > 0)
			result = (char)(shift + ASCIofZero) + result;
	}
	
	void checkForEmptyResult()
	{
		if(result == "")
			result = "0";
	}
	
};

int main(){
	
	FibonacciNumberCreator a;
	cout<<a.fibonacciNumber(1000);
	
	return 0;
}
