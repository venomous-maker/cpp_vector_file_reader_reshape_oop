#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
	private:
		vector<vector<string>> data;
		int num_of_rows;
		int num_of_columns;
	public:
		Matrix()
		{
			int num_of_rows = 0;
			int num_of_columns = 0;
		}
	string reshape(int num_c, int num_r){
	string path = '';
	cout<<"Input File Path: ";
	cin>>path;
	ifstream file(path);
	ofstream writedata;
	writedata.open("after.txt");
	if(!file.is_open())
	{
		cout <<"Error opening the file"<<endl;
	}
	else
	{
		string line;
		int num_line = 1;
		stringstream ss;
		while(getline(file, line))
		{
				if(num_line > 2)
				{
					string word = "";
				vector<string> v;
				for (auto x : line) 
				{
				word = "";
				if (x == ' ')
				{
					//	v.push_back(word);
				word = "";
				}
				else {
					word = word + x;
					v.push_back(word);
				}
				}
				data.push_back(v);
			}
		
			num_line += 1;
		}
	}
	int n = 1;
	num_of_rows = data.size();
	num_of_columns = data[0].size();
	//cout<<num_of_rows;
	if (num_of_columns * num_of_rows != num_c * num_r){
		cout<<"Illegal reshaping";
	}
	else{
		writedata << num_r<<"\t"<< num_c<<"\n\n";
	for (int i = 0; i < num_of_rows; i++)
    {
        for (int j = 0; j < num_of_columns; j++)
        {n++;
            cout << data[i][j] << "\t";
            writedata << data[i][j] << "\t";
            if (n > num_c) {
                    n = 1;
                    cout << "\n";
                    writedata<<"\n";
                }
        }    
    }
    writedata.close();
}
	return 0;
}
};
main()
{
	Matrix dispObject;
	int num_r;
	cout << "Enter the number of row: ";
	cin>> num_r;
	int num_c;
	cout << "Enter the number of columns: ";
	cin>> num_c;
	dispObject.reshape(num_c, num_r);
	return 1;
}
