// Homework11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include<iterator>
#include <list>
using namespace std;

list<int> & tasker(const vector<int>& vect, list<int> &lst)
{
	vector<int>v=vect;						//create copy	
	vector<int>::iterator  iter = v.begin(); 
	vector<int>::iterator end = v.end();   

	//sort vector
	for (iter; iter != end; ++iter)
	{		
		vector<int>::iterator iter2 = iter + 1; 
		for (iter2; iter2 != end; ++iter2) 
		{
			if (*iter2 > *iter)
			{
				int buf = *iter2;
				*iter2 = *iter;
				*iter = buf;
			}
		}
	}
		
	
	vector<int>::iterator iter2 = v.begin();
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter != *iter2)
		{
			int i = 1;
			for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
			{
				if (i == *iter)
				{
					it = lst.erase(it);
					break;
				}
				i++;
			}
		}
		iter2 = iter;
	}

	return lst;
}

int main()
{
	vector<int>v;
	//add id for remove
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(13);
	v.push_back(1);
	v.push_back(8);
	v.push_back(8);
	v.push_back(11);

	//create list of values
	int myints[] = { 100,101,102,103,104,105,106,107,108,109,110 };
	list<int> lst(myints, myints + sizeof(myints) / sizeof(int));

	// print values
	cout << "Table of values" << endl;
	int i = 1;
	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << i << "\t" << *it << endl;
		i++;
	}

	// print ids for remove
	cout << "Table of ids for remove" << endl;	

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "\t" << *it << endl;
	}
	//start work
	lst=tasker(v, lst);

	//print results
	cout << "table of results" << endl;
	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << "\t" << *it << endl;		
	}


	


	cin.get();
    return 0;
}