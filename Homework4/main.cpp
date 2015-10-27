#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fstream>
#include <iostream>
#define limit 50
using namespace std;



// объявление класса
class Building
{
  private:
    char* _adress;
    char* _Arhitector;
    int _year;
    char* _typeofbuilding;
    int _num_of_fl;

  public:
    char* get_adress();
    char* get_Arhitector();
    int get_year();
    char* get_typeofbuilding();
    int get_num_of_fl();
    void set_adress(char adress[]);
    void set_Arhitector(char Arhitector[]);
    void set_year(int year);
    void set_typeofbuilding(char typeofbuilding[]);
    void set_num_of_fl(int num_of_fl);
    void setallparams(char adress[],char Arhitector[],int year,char typeofbuilding[],int num_of_fl);
    Building();
    ~Building();
    Building(Building &obj);
    void Show();
    void editBuilding();
};

  char* Building::get_adress()
  {
    return _adress;
  }

  char* Building::get_Arhitector()
  {
    return _Arhitector;
  }

  int Building::get_year()
  {
    return _year;
  }

  char* Building::get_typeofbuilding()
  {
    return _typeofbuilding;
  }

  int Building::get_num_of_fl()
  {
    return _num_of_fl;
  }

  void Building::set_adress(char adress[])
  {
      free(_adress);
      _adress =(char*) malloc(limit*sizeof(char*));
      int i=0;
      for(i=0; i<limit;i++)
      {
        _adress[i]=adress[i];
      }

  }

  void Building::set_Arhitector(char Arhitector[])
  {
      free(_Arhitector);
      _Arhitector==(char*) malloc(limit*sizeof(char*));
      int i=0;
      for(i=0; i<limit;i++)
      {
      _Arhitector[i]=Arhitector[i];
      }
  }

  void Building::set_year(int year)
  {
     _year=year;
  }

  void Building::set_typeofbuilding(char typeofbuilding[])
  {
      free(_typeofbuilding);
      _typeofbuilding==(char*) malloc(limit*sizeof(char*));
      int i=0;
      for(i=0; i<limit;i++)
      {
      _typeofbuilding[i]=typeofbuilding[i];
      }
  }

  void Building::set_num_of_fl(int num_of_fl)
  {
     _num_of_fl=num_of_fl;
  }


  void Building::setallparams(char adress[],char Arhitector[],int year,char typeofbuilding[],int num_of_fl)
  {
      int i=0;
      for(i=0; i<limit;i++)
      {
        _adress[i]=adress[i];
      }
      for(i=0; i<limit;i++)
      {
        _typeofbuilding[i]=typeofbuilding[i];
      }
      for(i=0; i<limit;i++)
      {
        _Arhitector[i]=Arhitector[i];
      }
      _year=year;
      _num_of_fl=num_of_fl;
  }


   Building::Building()
   {
        _adress =(char*) malloc(limit*sizeof(char));
        _Arhitector =(char*) malloc(limit*sizeof(char));
        _typeofbuilding =(char*) malloc(limit*sizeof(char));
        _year=0;
        _num_of_fl=-1;
    }


    Building::~Building()
    {   //cout << "Запись о здании по адресу " <<_adress<<" уничтожена"<< endl;
        free(_adress);
        free(_Arhitector);
        free(_typeofbuilding);
    }

    void Building::Show()
    {
      cout<<endl;
      cout <<"***********************************************************************"<<endl;
      cout <<"Адрес "<< get_adress() <<endl;
      cout <<"Архитектор "<< _Arhitector <<endl;
      cout <<"Год постройки "<< get_year()  <<endl;
      cout <<"Тип здания "<< _typeofbuilding  <<endl;
      cout <<"Количество этажей "<< _num_of_fl <<endl;
    }

    void Building::editBuilding()
    {
        int a=-1;
        while((a>3)||(a<=0))
        {
         cout << "Введите один из пунктов:"<<endl;
         cout << "1) Редактирование одного из пунктов."<<endl;
         cout << "2) Редактирование всей записи"<<endl;
         cout << "3) Выход"<<endl;
         cin >> a;
        }
        if(a==1)
        {
            int b=-1;
            while((b>5)||(b<=0))
            {
                cout << "Выберете один из пунктов для редактирования:"<<endl;
                cout <<"    1) Адрес "<< get_adress() <<endl;
                cout <<"    2) Архитектор "<< get_Arhitector() <<endl;
                cout <<"    3) Год постройки "<< get_year() <<endl;
                cout <<"    4) Тип здания "<< get_typeofbuilding()  <<endl;
                cout <<"    5) Количество этажей "<< get_num_of_fl() <<endl;
                cin >> b;
            }
            cout <<"Укажите новое значение для поля ";
            switch (b)
            {
                case 1:
                    {
                    cout <<"Адрес ";
                    char *temp=(char*) malloc(limit*sizeof(char));
                    cin>> temp;
                    set_adress(temp);
                    free(temp);
                    break;
                    }
                case 2:
                    {
                    cout <<"Архитектор ";
                    char *temp=(char*) malloc(limit*sizeof(char));
                    cin>> temp;
                    set_Arhitector(temp);
                    free(temp);
                    break;
                    }
                case 3:
                    {
                    cout <<"Год постройки ";
                    int temp;
                    cin>> temp;
                    set_year(temp);
                    break;
                    }
                case 4:{
                    cout <<"Тип здания ";
                    char *temp=(char*) malloc(limit*sizeof(char));
                    cin>> temp;
                    set_typeofbuilding(temp);
                    free(temp);
                    break;
                    }
                default:
                    cout <<"Количество этажей ";
                    int temp;
                    cin>> temp;
                    set_num_of_fl(temp);
                    break;
            }
            cout<<endl;
            cout << "Информация сохранена"<<endl;
            Show();
        }
        if(a==2)
        {
            cout <<"Обновление полей "<<endl;
            for(int b=1; b<6;b++)
            {
                switch (b)
                    {
                        case 1:
                            {
                            cout <<"Адрес ";
                            char *temp=(char*) malloc(limit*sizeof(char));
                            cin>> temp;
                            set_adress(temp);
                            free(temp);
                            break;
                            }
                        case 2:
                            {
                            cout <<"Архитектор ";
                            char *temp=(char*) malloc(limit*sizeof(char));
                            cin>> temp;
                            set_Arhitector(temp);
                            free(temp);
                            break;
                            }
                        case 3:
                            {
                            cout <<"Год постройки ";
                            int temp;
                            cin>> temp;
                            set_year(temp);
                            break;
                            }
                        case 4:{
                            cout <<"Тип здания ";
                            char *temp=(char*) malloc(limit*sizeof(char));
                            cin>> temp;
                            set_typeofbuilding(temp);
                            free(temp);
                            break;
                            }
                        default:
                            cout <<"Количество этажей ";
                            int temp;
                            cin>> temp;
                            set_num_of_fl(temp);
                            break;
                    }
                }
            cout<<endl;
            cout << "Информация сохранена"<<endl;
            Show();
        }
    }

    Building::Building(Building &obj)
    {
        this->set_adress(obj.get_adress());
        this->set_Arhitector(obj.get_Arhitector());
        this->set_num_of_fl(obj.get_num_of_fl());
        this->set_typeofbuilding(obj.get_typeofbuilding());
        this->set_year(obj.get_year());
    }

int main(int argc, char *argv[])
{
    int N=0;
    ifstream fin(argv[1]);
    //ifstream fin("/home/aleksey/Documents/code/Homework4/bin/Debug/file1.txt");
    fin >> N;
    //N++;
	char *adr=(char*) malloc(limit*sizeof(char));
    char *Arh=(char*) malloc(limit*sizeof(char));
    int year;
    char *typeofbuild=(char*) malloc(limit*sizeof(char));
    int num_of_fl;
    int count=0;

    Building arr[N];

	while (count<N) {
        fin>>adr>>Arh>>year>>typeofbuild>>num_of_fl;
		arr[count].setallparams(adr,Arh,year,typeofbuild,num_of_fl);
        arr[count].Show();
        count++;
	}

	cout<<endl;
	cout<<endl;

    int a=-2;
    int b=-1;

    while(a!=5){
        while((a>5)||(a<=0))
        {
         cout << "Выберете один из пунктов:"<<endl;
         cout << "1) Редактирование одной из записей."<<endl;
         cout << "2) Вывести список зданий данного типа"<<endl;
         cout << "3) Вывести список зданий данного архитектора, имеющих определённый тип"<<endl;
         cout << "4) Вывести список зданий, год постройки которых ранее заданного"<<endl;
         cout << "5) Выход"<<endl;
         cin >> a;
        }
        if(a==1)
        {
            cout << "Введите номер записи"<<endl;
            for(int i=0; i<N;i++)
            {
                cout<<i<<") c адресом "<<arr[i].get_adress()<<endl;
            }
            cin>>b;

            arr[b].editBuilding();
            a=-1;
            b=-1;
        }

        if(a==2)
        {
            cout<<"Укажите тип"<<endl;
            char *typeForsearch=(char*) malloc(limit*sizeof(char));
            cin>>typeForsearch;
            for(int i=0; i<N;i++)
            {
                if(strlen(typeForsearch)==strlen(arr[i].get_typeofbuilding()))
                {
                    bool flag=true;
                    for(int j=0; j<strlen(typeForsearch);j++)
                    {
                        if(typeForsearch[j]!=arr[i].get_typeofbuilding()[j])
                        {
                            flag=false;
                        }
                    }
                    if(flag==true)
                    {
                        arr[i].Show();
                    }
                }

            }
            a=-1;
            b=-1;
            free(typeForsearch);
        }
        if(a==3)
        {
            cout<<"Укажите тип"<<endl;
            char *typeForsearch=(char*) malloc(limit*sizeof(char));
            cin>>typeForsearch;
            cout<<"Укажите архитектора"<<endl;
            char *ARCHI=(char*) malloc(limit*sizeof(char));
            cin>>ARCHI;
            for(int i=0; i<N;i++)
            {
            bool flag=true;
                if(strlen(typeForsearch)==strlen(arr[i].get_typeofbuilding()))
                {
                    for(int j=0; j<strlen(typeForsearch);j++)
                    {
                        if(typeForsearch[j]!=arr[i].get_typeofbuilding()[j])
                        {
                            flag=false;
                        }
                    }
                }
                else{flag=false;}

                if(strlen(ARCHI)==strlen(arr[i].get_Arhitector()))
                {
                    for(int j=0; j<strlen(ARCHI);j++)
                    {
                        if(ARCHI[j]!=arr[i].get_Arhitector()[j])
                        {
                            flag=false;
                        }
                    }
                }
                else{flag=false;}

                 if(flag==true)
                {
                        arr[i].Show();
                }

            }
            a=-1;
            b=-1;
            free(typeForsearch);
            free(ARCHI);
        }
        if(a==4)
        {
            cout<<"Введите год"<<endl;
            cin>>b;
            for(int i=0; i<N;i++)
            {
                if(b>arr[i].get_year())
                {
                arr[i].Show();
                }
            }
            a=-1;
            b=-1;

        }


        cout<<endl;
        cout<<endl;
    }
	//cout<<"Final =========================================="<<endl;
	free (adr);
	free(Arh);
	free(typeofbuild);
    return 0;
}
