#include<iostream> //cin, cout
#include<fstream> //ifstream, ofstream fstream
#include<string> //string
using namespace std;

int main()
{
	string name;

	ifstream input;
	ofstream output;

	input.open("in.txt");
	output.open("output.txt");

	for (int i = 1; i <= 4; i++)
	{
		cout << "Please enter a string: ";
		getline(cin, name);
		output << name << endl;
	}

	input.close();
	output.close();

	cin.get();
	return 0;
}
