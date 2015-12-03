// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <fstream>

#define MAXLENG 5
#define OBJ_LEN_ARR 5
#define DEBUG 2
#include "debug.h"

using namespace std;

#define LEVEL 0
const char *filename = "testfile.txt";
//FILE *fout;
void debug(int level, char* str);

template <typename keytype, typename valuetype>
struct elem    
{
	keytype key;
	valuetype value;
};

template <typename keytype, typename valuetype>
class Multimap
{
private:
	keytype* keys;
	valuetype* values;
	int used = 0;
	int maxforuse = MAXLENG;

public:

	Multimap()
	{	
		debug(5, "-->Multimap");
		try
		{
			keys = new keytype[MAXLENG];
			values = new valuetype[MAXLENG];
		}
		catch (...)
		{
			debug(1, "Multimap--Unknown error! Can`t create arrays for obj");			
		}
		
		used = 0;
		maxforuse = MAXLENG;
		debug(5, "Multimap-->");
	}

	Multimap(const Multimap &object)
	{
		debug(5, "-->Multimap(const Multimap &object) ")
		maxforuse = object.getused();		
		try
		{
			keys = new keytype[maxforuse];
			values = new valuetype[maxforuse];
		}
		catch (...)
		{
				debug(1, "Multimap(const Multimap &object)--Unknown error! Can`t create arrays for obj")				
		}

		try
		{
			for (int i = 0; i < object.getused(); i++)
			{
				keys[i] = object.getkey(i);
				values[i] = object.getvalue(i);
			}
		}
		catch (...)
		{
				debug(1, "Multimap(const Multimap &object)--Array copy error! ")				
		}
		used = object.getused();

		debug(5, "-->Multimap(const Multimap &object)")
	}

	~Multimap()
	{
		debug(5, "-->~Multimap ");		
		delete keys;
		delete values;
		debug(5, "~Multimap -->");
	}


	void addmemory()
	{
		PDEBUG(1, "%s %d", "qwerty", 5786)
		debug(5, "--> addmemory");
		keytype* keys2;
		valuetype* values2;		
		keys2 = new keytype[maxforuse * 2];
		values2 = new valuetype[maxforuse * 2];		

		for (int i = 0; i < used; i++)
		{
				keys2[i] = keys[i];
				values2[i] = values[i];
		}
		
		delete keys;
		delete values;

		keys = keys2;
		values = values2;
		
		//std::cout << "Add memory" << endl;

		maxforuse = maxforuse * 2;
		debug(5, " addmemory--> ");
	}

	void append(keytype key, valuetype value)
	{
		debug(5, "--> append");
		try {
			if (used >= maxforuse)
			{
				throw used;
			}
		}
		catch (int used)
		{
			debug(1, "append -Not free memory. Adding");			
			addmemory();
		}
		

		keys[used] = key;
		values[used] = value;
		used++;
		debug(5, "append -->");
	}

	int getused()
	{
		debug(5, "--> getused ");
		debug(5, "getused -->");
		return used;
	}

	void del(int index)
	{
		debug(5, "--> del	");
		try
		{
			for (int i = index; i<used - 1; i++)
			{
				keys[i] = keys[i + 1];
				values[i] = values[i + 1];
			}
			--used;

		}
		catch (...)
		{
			debug(1, "del--Unknown error! Can`t remove from array");			
		}

		debug(5, "del -->");
	}

	const valuetype search_by_key(keytype key)
	{
		debug(5, "--> valuetype search_by_key ");
		int i = 0;
		while ((keys[i] != key) && (i<used))
		{
			i++;
		}
		debug(5, "valuetype search_by_key -->");
		return values[i];
	}
	
	bool search_by_pair(keytype key, valuetype value)
	{
		debug(5, " -->search_by_pair");

		int i = 0;
		while (i<used)
		{
			if ((keys[i] == key) && (values[i] == value)) { return true; }
			i++;
		}
		debug(5, "search_by_pair -->");
		return false;
	}
	
	int search_by_key_int(keytype key)
	{
		debug(5, "--> search_by_key_int		");
		int i = 0;
		while (i<used)
		{
			if (keys[i] == key)  { return i; }
			i++;
		}
		debug(5, "search_by_key_int -->");
		return i;
	}

	void show_par(keytype key)
	{
		debug(5, "--> show_par(keytype key) -->");
		std::cout << "Key " << key << " Value " << search_by_key(key) << endl;
	}
	
	void show_par(int index)
	{
		debug(5, "--> show_par(int index) -->	");
		std::cout << "Key " << keys[index] << " Value " << values[index] << endl;
	}
	
	void show_all()
	{
		debug(5, "--> show_all() ");
		for (int i = 0; i<used; i++)
		{
			show_par(i);
		}
		debug(5, "show_all() -->");
	}
	
	const keytype getkey(int index)
	{	
		debug(5, "--> getkey(int index) -->	");
		return keys[index];
	}
	
	const valuetype getvalue(int index)
	{
		debug(5, "--> getkey(int index)	");
		try
		{
			if (index >= used) throw index;
			
		}
		catch (int index)
		{
			debug(1, "Out of range" + index);
		}
		debug(5, "getkey(int index)-->");
		return values[index];
	}

	Multimap& operator - (keytype key)
	{
		debug(5, "-->  operator -	");
		del(search_by_key_int(key));
		debug(5, " operator -  -->");
		return *(this);
	}
	
	Multimap& operator + (struct elem<keytype, valuetype>  element)
	{
		debug(5, "-->  operator + (struct elem...");
		append(element.key, element.value);
		debug(5, " operator + (struct elem...  -->");
		return *(this);
	}

	Multimap& operator + (Multimap<keytype, valuetype>& second)
	{
		debug(5, "-->  operator + (Multimap<...");
		Multimap <keytype, valuetype>*C = new Multimap();
		try
		{

			for (int i = 0; i < second.getused(); i++)
			{
				C->append(second.getkey(i), second.getvalue(i));
			}

			for (int i = 0; i < used; i++)
			{
				if (second.search_by_pair(keys[i], values[i]) == false)
				{
					C->append(keys[i], values[i]);
				}
			}
		}
		catch (...)
		{
			debug(1, " operator + (Multimap<...		Error!");
		}
		debug(5, " operator + (Multimap<... -->");
		return *C;
	}

	Multimap& operator * (Multimap<keytype, valuetype>& second)
	{
		debug(5, "--> operator * ");
		Multimap <keytype, valuetype>*C = new Multimap();
		try
		{
			
			for (int i = 0; i < used; i++)
			{
				if (second.search_by_pair(keys[i], values[i]) == true)
				{
					C->append(keys[i], values[i]);
				}
			}
		}
		catch (...)
		{
			debug(1, " operator *		Error!");
		}
		debug(5, " operator * -->");
		return *C;
	}

	Multimap& operator=(Multimap<keytype, valuetype>& second)
	{
		debug(5, "--> operator = ");
		int m = getused();
		int m2 = second.getused();
		try
		{

			for (int i = 0; i < m2; i++)
			{
				append(second.getkey(i), second.getvalue(i));
			}
			for (int i = 0; i < m; i++)
			{
				del(0);
			}
		}
		catch (...)
		{
			debug(1, " operator =		Error!");
		}
		debug(5, " operator = -->");
		return *this;

	}

	valuetype operator[](keytype  i) { debug(5, "--> operator [] -->"); return search_by_key(i); }

	Multimap& discard(Multimap<keytype, valuetype>& second)
	{
		debug(5, "-->  discard");
		Multimap <keytype, valuetype>*C = new Multimap();
		try
		{
			for (int i = 0; i < used; i++)
			{
				if (second.search_by_pair(keys[i], values[i]) == false)
				{
					C->append(keys[i], values[i]);
				}
			}
		}
		catch (...)
		{
			debug(1, "discard		Error!");
		}
		debug(5, "discard = -->");
		return *C;
	}

	friend ostream& operator <<(ostream& os, Multimap<keytype, valuetype>& map)
	{
		debug(5, "--> operator << ");
		try
		{
			for (int i = 0; i < map.used; i++)
			{
				os << "Key " << map.keys[i] << " Value " << map.values[i] << endl;
			}
		}
		catch (...)
		{
			debug(1, " operator <<		Error!");
		}
		debug(5, "operator << -->");
		return os;
	}
	
};

void debug(int level,const char* str) {
	if (level < LEVEL)
	{
		std::cout << str << endl;
		try
		{
			ofstream fout(filename, ios::app);
			fout << str << endl;
			fout.close();
		}
		catch (...)
		{
			std::cout << "\n Can`t write to log file" << endl;
		}
	}
	
}


int main()
{
	try
	{
		ofstream fout(filename);
		fout.close();
	}
	catch (...)
	{
		std::cout << "\n Can`t rewrite log file" << endl;
	}

	Multimap <double, double>object[OBJ_LEN_ARR];
	
	std::cout << "\nfirst obj" << endl;
	object[0].append(0.001, 1.1111);
	object[0].append(0.001, 2.1111);
	object[0].append(0.003, 3.1111);
	object[0].append(0.007, 4.1111);
	object[0].append(0.005, 5.1111);
	
	struct elem <double, double> six;
	six.key = 0.006;
	six.value = 6.1111;
	object[0]=object[0] + six;
	std::cout << object[0];
	
	
	std::cout << "\nsecond obj" << endl;
	object[1].append(0.001, 1.1111);
	object[1].append(0.007, 2.1111);
	object[1].append(0.003, 3.1111);
	object[1].append(0.004, 4.1111);
	object[1].show_all();


	

	std::cout << "\nUnion!" << endl;
	object[2] = object[0] + object[1];
	std::cout << object[2];

	std::cout << "\nintersection" << endl;
	object[3] = object[0] * object[1];
	std::cout << object[3];

	std::cout << "\ndiscard" << endl;
	object[4] = object[2].discard(object[3]);
	std::cout << object[4];
	
	std::cout << "\nindex " << object[0][0.003] << endl;

	std::cout << "\n assignment obj 1=obj 0" << endl;	
	object[1] = object[0];	
	std::cout << object[1];	

	
	std::cin.get();

	//fclose(fout);
	return 0;
}

