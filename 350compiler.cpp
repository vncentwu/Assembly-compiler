#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

#define LINE_SIZE  100

vector< vector<char *> > lines;



bool loadFromFile(char* fileName)
{
	ifstream ifs;
	char line[LINE_SIZE];
	ifs.open(fileName);
	bool not_screwy = ifs.good();
	while(!ifs.eof() && not_screwy)
	{
		ifs.getline(line,LINE_SIZE);
		char data[LINE_SIZE];
		strcpy(data, line);
		std::vector<char*> v;
	    char* chars_array = strtok(data, " ");
	    while(chars_array)
	    {
	    	char* temp_char = (char *) malloc(3);
	    	strcpy(temp_char, chars_array);
	 	    v.push_back(temp_char); 
	        chars_array = strtok(NULL, " ,");
		}
		lines.push_back(v);
		vector<char *> x = lines.back();
	}
	ifs.close();
	return not_screwy;
}

void print_as_bin(int val, int length, ofstream* fx)
{
	fstream f = *fx;
	int theValue = val;
	int i;
	int array[length];
	for (i = 0; i < length; ++i) {  // assuming a 32 bit int
	    array[i] = theValue & (1 << i) ? 1 : 0;
	    f << array[i];
	}
	f << "\n";

}

bool parse_and_write_line(int index, ofstream* fx)
{
	ofstream f = *fx;
	vector<char *> v = lines[index];
	vector<char*> instr = lines[0];
	if(!strcmp(instr[0], "mov"))
	{
		f << "0000";
		int r1 = atoi(instr[1]);
		print_as_bin(r1, 8, f);
	}
}


bool compile(char* fileName)
{
	ofstream f;

	f.open(fileName);
	
	for(int i = 0; i < lines.size(); i++)
	{
		parse_and_write_line(i, &f);
	}
	f.close();
	return 0;
}







int main(int argc, char* argv[])
{
	loadFromFile("test2.txt");
	compile("test.txt");
	return 0;

}