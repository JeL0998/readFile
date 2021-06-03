#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

char name[100];
char course[100];
char year[100];
string strNew(string str, int n);

void border();
void output();

int main()
{
	string subject, grade, units;
	string line;
	int total = 0;
	double totalunits = 0;
	double gpa = 0.0;

	ifstream theFile("grade.txt");
	ofstream outFile("tab.txt");

	output();

	outFile << "MidTerm Grade of Jan Eric Lonario - BSIT 1 SY 2020-2021";
	outFile << "\nComputer Studies Department\n\n";
	outFile << strNew("Subject Code", 20) << strNew("Units", 15) << "Grade" << endl;
	outFile << "====================================================================";

	border();

	if (theFile.is_open())
	{

		while (getline(theFile, line))
		{
			stringstream ss(line);
			getline(ss, subject, ' ');
			getline(ss, units, ' ');
			getline(ss, grade, ' ');
			cout << strNew(subject, 20) << strNew(units, 15) << grade << endl << endl;
			outFile << endl;
			outFile << strNew(subject, 20) << strNew(units, 15) << grade << endl;
		
			total = stoi(grade) * stoi(units);
			totalunits = totalunits + stoi(units);
			gpa = total / totalunits;
		}
	}

	border();
	outFile << endl;
	outFile << "====================================================================";
	outFile << endl;
	cout << "\nGPA: " << gpa << endl;
	outFile << "\nGPA: " << gpa << endl;
	theFile.close();
	outFile.close();

	system("pause");
	return 0;
}


void output() {

	cout << "MidTerm Grade of Jan Eric Lonario - BSIT 1 SY 2020-2021";
	cout << "\nComputer Studies Department\n\n";
	cout << strNew("Subject Code", 20) << strNew("Units", 15) << "Grade" << endl;

}

void border()
{
	cout << "==========================================================================" << endl;
}


string strNew(string str, int n) {
	int l;
	l = n - str.length();
	for (int i = 1; i <= l; i++) {
		str = str + " ";
	}
	return str;
}

