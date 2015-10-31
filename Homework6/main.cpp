#include <iostream>
using namespace std;

class Figure { // Абстрактный класс
  public:
    Figure(){}
    virtual const float area()=0;
    void show(){cout<<area()<<endl;}
    ~Figure(){}
  };

class Square:public Figure {
   private:
    int length;
   public:
    Square(int l){length=l;}
   const float area(){return length*length;}
    ~Square(){}
  };

class Circle: public Figure {
 private:
    int radius;
  public:
    Circle(int r){radius=r;}
    const float area(){return 3.1415 * radius *radius;}
    ~Circle(){}
  };
class Rectangle: public Figure {
    private:
     int a;
     int b;
   public:
     Rectangle(int x,int y){a=x;b=y;}
     const float area(){return a*b;}
     ~Rectangle(){}
  };

int main()
{

    Figure *figures[7];
    figures[0] = new Circle (3);
    figures[1] = new Square (2);
    figures[2] = new Square (14);
    figures[3] = new Circle (5);
    figures[4] = new Rectangle(10,15);
    figures[5] = new Circle (5);
    figures[6] = new Rectangle(16,10);

    // for (int i = 0; i < 7; ++i)
    //  cout << figures[i]->area() <<endl;
    for (int i = 0; i < 7; ++i)
    {
        figures[i]->show();
    }

    return 0;
}
