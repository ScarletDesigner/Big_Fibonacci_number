#include <iostream>
#include <vector>
using namespace std;

class stringAdder
{
protected:
	string first, second;
	string result;
	int shorterLength;
	int firstRemainingDigits, secondRemainingDigits;
	int shift;
	int lastDigit;
	static const int ASCIofZero = 48;
	
	string addStrings(string first, string second)
	{
		initialization(first, second);
		addTillLengthMatches();
		addRemainingDigitsOfFirstString();
		addRemainingDigitsOfSecondString();
		addRemainingShiftToNewRow();
		
		return result;
	}
	
	void initialization(string a, string b)
	{
		first = a;
		second = b;
		shorterLength = isShorter();
		firstRemainingDigits = first.length();
		secondRemainingDigits = second.length();
		result = "";
		shift = 0;
	}
	
	int isShorter()
	{
		if (first.length() < second.length())
			return first.length();
	
		return second.length();
	}
	
	void addTillLengthMatches()
	{
		for(int i = 1; i <= shorterLength; i++)
		{
			firstRemainingDigits--;
			secondRemainingDigits--;
			
			lastDigit = (int)(first[firstRemainingDigits]) + 
			(int)(second[secondRemainingDigits]) + shift - 2*ASCIofZero;
			
			shift = lastDigit / 10;
			result = (char)((lastDigit % 10) + ASCIofZero) + result;
		}
	}
	
	void addRemainingDigitsOfFirstString()
	{
		while(firstRemainingDigits > 0)
		{
			lastDigit = first[--firstRemainingDigits] + shift - ASCIofZero;
			shift = lastDigit / 10;
			result = (char)((lastDigit % 10) + ASCIofZero) + result;
		}
	}
	
	void addRemainingDigitsOfSecondString()
	{
		while(secondRemainingDigits > 0)
		{
			lastDigit = second[--secondRemainingDigits] + shift - ASCIofZero;
			shift = lastDigit / 10;
			result = (char)((lastDigit % 10) + ASCIofZero) + result;
		}
	}
	
	void addRemainingShiftToNewRow()
	{
		if(shift > 0)
			result = (char)(shift + ASCIofZero) + result;
	}
};

class FibonacciNumberCreator: public stringAdder
{
	vector<string> fibonacciNumbers;
	int fibonacciNumberToDisplay;
	
public:
	void printFibonacciNumber(int fibonacciNumberToDisplay)
	{
		this -> fibonacciNumberToDisplay = fibonacciNumberToDisplay;
		checkIfRequestedFirstOrSecondFibonacciNumber();
		
		makeStartingArray();
		fillVectorTillNumberToDisplay();
		checkForEmptyResult();
		
		cout<<fibonacciNumbers[fibonacciNumberToDisplay]<<endl;
	}
	
private:
	void checkIfRequestedFirstOrSecondFibonacciNumber()
	{
		if(fibonacciNumberToDisplay == 0)
		{
			cout<<"0"<<endl;
			exit(0);
		}
			
		if(fibonacciNumberToDisplay == 1)
		{
			cout<<"1"<<endl;
			exit(0);
		}
	}	
	
	void makeStartingArray()
	{
		fibonacciNumbers.push_back("0");
		fibonacciNumbers.push_back("1");
	}
	
	void fillVectorTillNumberToDisplay()
	{
		for(int i = 2; i <= fibonacciNumberToDisplay; i++)
		{
			//every fibonacci number greater than 2 is made by adding 2 previous fibonacci numbers
			fibonacciNumbers.push_back( addStrings(fibonacciNumbers[i-1], fibonacciNumbers[i-2]) );
		}
	}
	
	void checkForEmptyResult()
	{
		if(result == "")
			result = "0";
	}
	
};

int main(){
	
	FibonacciNumberCreator a;
	a.printFibonacciNumber(1000);
	
	return 0;
}
