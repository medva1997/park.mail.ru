#include <iostream>
#define MAXLENG 5
#include <fstream>
#include <string.h>
using namespace std;

class Element{

    private:
        int _prev=-1;
        int _next=-1;
        int _value;
        bool _used=false;
    public:
        Element(){}

        Element(const int prev,const int next, const int value)
        {
            _prev=prev;
            _next=next;
            _value=value;
            _used=true;
        }
        Element(const Element &obj)
        {

        }

        void set_element(const int prev,const int next, const int value)
        {
            _prev=prev;
            _next=next;
            _value=value;
            _used=true;
        }

        const int get_prev()
        {
            return _prev;
        }
        const int get_next()
        {
            return _next;
        }
        const int get_value()
        {
            return _value;
        }
        const bool get_used()
        {
            return _used;
        }

        void set_prev(const int prev)
        {
            _prev=prev;
        }

          void set_next(const int next)
        {
            _next=next;
        }

        void set_value(const int value)
        {
            _value=value;
            _used=true;
        }

        void set_notused()
        {

            _used=false;;
        }

};

class ARRList{
    private:
        int _head;
        int _bottom;
        int _maxforuse;
        int _used=false;
        Element* table;
        Element* newtable;
        int _firstfree;
    public:

        ARRList()
        {
            table=new Element[MAXLENG];
            _maxforuse=MAXLENG;
            _used=0;
        }

        ARRList(int leng)
        {
            table=new Element[leng];
            _maxforuse=leng;
            _used=0;
        }

        ~ARRList()
        {
            delete[] table;
            delete[] newtable;
        }

        int searchpos(int val)
        {

            int start=_head;
            while(table[start].get_value()<val)
            {
               int temp=table[start].get_next();

                if(temp==-1)
                {
                    return start;
                }
                else
                {
                    start=temp;
                }
            }
            return table[start].get_prev();

        }

        void addelement(int value)
        {

            if((_used==0)&&(_maxforuse>=1))
            {
                _head=0;
                _bottom=0;
                _used=1;
                table[0].set_element(-1,-1,value);
                _firstfree=1;
            }
            else
            {
                if(_used<_maxforuse)
                {
                    int pos=searchpos(value);
                    //cout<<pos<<"xaaaa "<<_firstfree <<endl;
                    if((pos==-1)&&(value<table[_head].get_value())){
                        //cout<<"NULL"<<endl;
                        //cout<< table[_firstfree].get_value()<<" "<<_head<<" "<< table[_head].get_value()<<endl;
                        table[_firstfree].set_element(-1,_head,value);
                        table[_head].set_prev(_firstfree);
                        _head=_firstfree;

                        //cout<< table[_firstfree].get_value()<<" h "<<_head<<" second"<< table[table[_head].get_next()].get_value()<<endl;

                    }
                    else
                    {
                        table[_firstfree].set_value(value);
                        table[_firstfree].set_prev(pos);
                        table[_firstfree].set_next(table[pos].get_next());
                        table[pos].set_next(_firstfree);


                        if(table[_firstfree].get_next()!=-1)
                        {

                            table[table[_firstfree].get_next()].set_prev(_firstfree);
                        }
                        else
                        {

                            _bottom=_firstfree;
                        }
                    }
                    _used++;

                }
                else
                {
                     cout<<"Добавление памяти"<<endl;
                     newtable=new Element[MAXLENG+_maxforuse];
                     memcpy(newtable,table,_maxforuse*sizeof(Element));
                     table=new Element[MAXLENG+_maxforuse];
                     table=newtable;
                     _maxforuse=MAXLENG+_maxforuse;
                     addelement(value);
                }

                for(int i=_firstfree; i<=_maxforuse;i++)
                {
                    if(table[i].get_used()==false)
                    {
                       _firstfree=i;
                        break;
                    }
                }
            }
        }


        void show()
        {   int start=_head;
            do
            {
                cout<<table[start].get_value()<<endl;
                start=table[start].get_next();
            }
            while(start!=-1);
        }

        int get_elem(int c)
        {
            int start=_head;
            int i=0;
            do
            {   if(i==c)
                {
                    return table[start].get_value();
                }
                i++;
                start=table[start].get_next();
            }
            while(start!=-1);
        }

        const int get_used()
        {
            return _used;
        }


        void delete_elem(int pos)
        {
            _firstfree=pos;
            table[table[pos].get_next()].set_prev(table[pos].get_prev());
            table[table[pos].get_prev()].set_next(table[pos].get_next());
            table[pos].set_notused();


        }
};


int main()
{
    cout << "Hello world!" << endl;
    //int b=0;
    int a=0;
    //cin>>b;
    ARRList* dblist1=new ARRList();
    ifstream fin("/home/aleksey/Code/Homework5/bin/Debug/list1.txt"); // открыли файл для чтения
    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"<<endl; // сообщить об этом
    else
    {
        cout << "Чтение файла №1"<<endl;; // сообщить об этом
    }
    while(fin>>a)
    {   dblist1->addelement(a);

    }
    fin.close(); // закрываем файл
    cout<<"#####################################################"<<endl;
    dblist1->show();
    cout<<"------------------------------------------------------"<<endl;


    ARRList* dblist2=new ARRList();
    ifstream fin2("/home/aleksey/Code/Homework5/bin/Debug/list2.txt"); // открыли файл для чтения
    if (!fin2.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"<<endl; // сообщить об этом
    else
    {
        cout << "Чтение файла №2"<<endl; // сообщить об этом
    }
    while(fin2>>a)
    {
        dblist2->addelement(a);
    }
	cout<<"#####################################################"<<endl;
    dblist2->show();
    cout<<"------------------------------------------------------"<<endl;

    fin2.close(); // закрываем файл

    int n=dblist1->get_used();
    int m=dblist2->get_used();

    ARRList* dblist3=new ARRList(n+m);
    for(int i=0; i<n;i++)
    {
        dblist3->addelement(dblist1->get_elem(i));
    }

    for(int i=0; i<m;i++)
    {
        dblist3->addelement(dblist2->get_elem(i));
    }

    cout<<"#####################################################"<<endl;
    dblist3->show();
    cout<<"------------------------------------------------------"<<endl;

}
