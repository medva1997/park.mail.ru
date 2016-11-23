//​Реализовать очередь с динамическим зацикленным буфером.
//

#include <iostream>

using namespace std;

struct queue {
    int *array;
    int first, end;
    int len;
};

int new_mem(struct queue *Que) {

    int buf=200 ;
    //индекс end не сдвинут с последнего элемента
    int *newarray= new int[Que->len+buf];
    int copyed = 0;

    if(Que->first<Que->end)
    {
        for (int i = Que->first; i <= Que->end; ++i) {
            newarray[copyed] = Que->array[i];
            copyed++;
        }
    }
    else {

        for (int i = Que->first; i < Que->len; ++i) {
            newarray[copyed] = Que->array[i];
            copyed++;
        }

        if (Que->end < Que->first) {
            for (int i = 0; i <= Que->end; ++i) {
                newarray[copyed] = Que->array[i];
                copyed++;
            }
        }
    }

    delete[] Que->array;

    Que->array = newarray;
    Que->first = 0;
    Que->end = copyed;
    Que->len = Que->len +buf;
}


int increase_end_poz(struct queue *Que) {

    //выход за границу массива
    if (Que->end >= Que->len - 1) {
        //Можно ли вставить вперед
        if (Que->first != 0) {
            Que->end = 0;
        } else {
            //cout<<"not enogth"<<endl;
            return -1;
        }
    } else {
        //Не упераемся ли мы в начало.
        if (Que->first != Que->end + 1) {
            Que->end++;
        }
        else
        {
            //cout<<"not enogth"<<endl;
            return -1;
        }
    }

    return  0;

}


int pop_front(struct queue &Que) {
    //если пустая
    if ((Que.first == Que.end) &&(Que.array[Que.first]==0)) {
        return -1;
    }

    //запомнили значение
    int temp = Que.array[Que.first];
    //обнулили эл массива
    Que.array[Que.first] = 0;

    //Езбегаем выхода за пределы
    if (Que.first == Que.len - 1)
        Que.first = 0;
    else {
        Que.first++;
    }
    return temp;
}

int push_back(int val, struct queue *Que) {
    Que->array[Que->end] = val;

    if (increase_end_poz(Que) == -1) {
        new_mem(Que);
    }

}

int main() {

    int n = 0;
    int task, val;
    bool flag = true;

    struct queue *Que = new struct queue();

    Que->len = 50;
    Que->array =new int[Que->len];
    Que->first = 0;
    Que->end = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> task >> val;

        switch (task) {
            case (3):
                push_back(val, Que);
                break;
            case (2):
                if (val != pop_front(*Que)) {
                    //cout << "NO" << endl;
                    flag = false;
                    //return 0;
                };
                break;
        }
    }

/*
    for (int j = 0; j <Que->len; ++j) {
        cout << " " <<Que->array[j] <<" ";
    }
    */




    if(n>0) {
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    delete []   Que->array;
    delete Que;
    return 0;
}
