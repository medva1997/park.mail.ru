#include <iostream>
#define ARR 7
using namespace std;

class Figure { // Абстрактный класс
  protected:
    string _type;

  public:
    Figure(){}
    virtual const float area()=0;

    void show(){

        cout<<_type<<" с площадью = "<<area()<<endl;}

    };

class Square:public Figure {
   private:
    int length;
   public:
    Square(int l){length=l; _type="Квадрат";}
   const float area(){return length*length;}

  };

class Circle: public Figure {
 private:
    int radius;
  public:
    Circle(int r){radius=r;_type="Круг";}
    const float area(){return 3.1415 * radius *radius;}

  };
class Rectangle: public Figure {
    private:
     int a;
     int b;
   public:
     Rectangle(int x,int y){a=x;b=y;_type="Прямоугольник";}
     const float area(){return a*b;}

  };


int main()
{
    Figure *figures[ARR];
    figures[0] = new Circle (3);
    figures[1] = new Square (2);
    figures[2] = new Square (14);
    figures[3] = new Circle (5);
    figures[4] = new Rectangle(10,15);
    figures[5] = new Circle (5);
    figures[6] = new Rectangle(16,10);

    cout<<"Вызов функции area"<<endl;
    for (int i = 0; i < ARR; ++i)
      cout << figures[i]->area()<<endl;


    cout<<endl;
    for (int i = 0; i < ARR; ++i)
    {
        figures[i]->show();
    }
    int stop=0;

    while(stop!=-1)
    {
        cout<<endl;
        cout<<"Введите номер записи для редактирования (нумерация с 1) или -1 для выхода"<<endl;
        int a;
        cin>>a;
        while((a<-1)||(a>=ARR))
        {
            cout<<"Введите номер записи для редактирования"<<endl;
            cin>>a;
        }

        if(a==-1)
        {
            break;

        }

        cout<<"Введите новый тип"<<endl;
        cout<<"1) Круг"<<endl;
        cout<<"2) Квадрат"<<endl;
        cout<<"3) Прямоугольник"<<endl;
        //cout<<"4) Выход"<<endl;

        int b;
        cin>>b;
        while((b<0)||(b>=4))
        {
            cout<<"Введите корректный тип"<<endl;
            cin>>b;
        }
        int c,d;

        switch (b) // начало оператора switch
        {
             case 1: // если count = 1
             {
                 cout<<"Введите радиус"<<endl;
                 cin>>c;
                 figures[a] =new Circle (c);
                 break;
             }
             case 2: // если count = 1
             {
                 cout<<"Введите сторону квадрата"<<endl;
                 cin>>c;
                 figures[a] = new Square (c);
                 break;
             }
             case 3: // если count = 1
             {
                 cout<<"Введите первую сторону"<<endl;
                 cin>>c;
                 cout<<"Введите вторую сторону"<<endl;
                 cin>>d;
                 figures[a] = new Rectangle (c,d);
                 break;
             }
             default:
             {
                //cout<<"Выход"<<endl;
                break;
             }
        }
        for (int i = 0; i < ARR; ++i)
        {
                figures[i]->show();
        }
    }

    for (int i = 0; i < ARR; ++i)
     {
        delete figures[i];
     }

}
