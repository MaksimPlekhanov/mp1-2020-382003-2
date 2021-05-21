#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;	

class Books
{
public:
	string Input(int i)
	{
		 return sample[i];
	}
	int sizevector()
	{
		return sample.size();
	}
private:
	vector<string> sample = { "Book1_2000year_au1_250str" , "Book2_2000year_au3_250str" , "Book3_2000year_au2_400str" , "Book4_2001year_au3_100str" , "Book5_2001year_au2_400str" , "Book6_2001year_au1_200str" , "Book7_2001year_au3_100str" , "Book8_2002year_au2_250str" , "Book9_2002year_au3_1000str" , "Book1_2002year_au1_60str" };
};

class Polka
{
public:

	void RecordingToFile(string a)
	{
		ofstream Booklist("booklist.txt",  ios::app);
		if (Booklist.is_open())
		{
			Booklist << a ;
		}
		Booklist.close();
	}

	void ReadFile()
	{
		ifstream Booklist("booklist.txt");
		for (int i = 0; i < forrec.size(); i++)
		{
			Booklist >> buff;
			cout << buff << " " << endl;
		}
		Booklist.close();
	}

	void InputVector()
	{
		for (int i = 0; i < objforrec.sizevector(); i++)
		{
			forrec.push_back(objforrec.Input(i));
		}
	}

	void Processing()
	{
		cin >> user;
		for (int i = 0; i < forrec.size(); i++)
		{
			if (Check(user, forrec[i]))
			{
				RecordingToFile(forrec[i]);
			}
		}
	}

	bool Check(string slovo, string book)
	{
		vector<string> w;
		size_t next;
		size_t prev = 0;
		string delim("_");
		size_t delta = delim.length();
		while ((next = book.find(delim, prev)) != string::npos) 
		{
			string tmp = book.substr(prev, next - prev);
			w.push_back(book.substr(prev, next - prev));
			prev = next + delta;
		}
		string tmp = book.substr(prev);
		w.push_back(book.substr(prev));
		vector<string>::iterator p;
		int a;
		p = find(w.begin(), w.end(), slovo);
		a = p - w.begin();
		if (a != 4)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void DeleterFile()
	{
		Booklist.open("booklist.txt", ios::out | ios::trunc);
		Booklist.close();
	}

private:
	string buff;
	string user;
	ofstream Booklist;
	vector<string> forrec;
	Books objforrec;
};

int main()
{
	setlocale(LC_ALL, "ru");
	Polka number1;
	number1.InputVector();
	cout << "Введите название книги, год её написания, её автора или кол-во страниц" << endl;
	number1.Processing();
	number1.ReadFile();
	number1.DeleterFile();
	return 0;
}