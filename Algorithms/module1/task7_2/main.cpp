/*В большой IT­фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с
желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое
может быть удовлетворено. Число заявок ≤ 100000.
Формат входных данных:  Вход содержит только пары целых чисел — начала и концы заявок.
Формат выходных данных: Выход должен содержать натуральное число — максимальное число заявок.
 */

#include <iostream>
#include <algorithm>
using namespace std;


struct meeting {
    int start;
    int end;
};

struct meeting * readinput(int *l_size)
{
    int size=0;
    int start, end;
    int maxsize=0;
    struct meeting *list=NULL;
    while(1)
    {
        //инициализация массива и перевыделение памяти если ее не хватает
        if(size==maxsize)
        {
            struct meeting *temp_list_of_records = new struct meeting[maxsize + 100];

            for (int i = 0; i < size; i++) {
                temp_list_of_records[i] = list[i];
            }

            //освобождаем старую
            delete[] list;
            list = temp_list_of_records;

            maxsize = maxsize + 100;
        }

        cin>>start>>end;

        if (cin.eof())
        {
            break;
        }


        list[size].start=start;
        list[size].end=end;

        size=size+1;
    }

    *l_size=size;
    return list;
}

//for sort
bool meeting_comp (meeting i, meeting j) {
    return i.end < j.end;
}

int max_meetings(meeting *temp_list_of_records,const int size)
{
    int meets=1; //количество встреч
    int last_meet=0; // индекс последней выбранной брони

    //сорпировка по времени
    sort(temp_list_of_records,temp_list_of_records+size,meeting_comp);

    for(int i=0; i<size;i++)
    {
        if(temp_list_of_records[last_meet].end <= temp_list_of_records[i].start)
        {
            meets++;
            last_meet=i;
        }
    }

    return meets;

}

int main() {
    meeting *list_of_records =NULL;
    int size=0;

    //Читаем в импровезированный список
    list_of_records=readinput(&size);
    //Ищем максимальное количество
    std::cout << max_meetings(list_of_records,size) << std::endl;

    delete[] list_of_records;
    return 0;
}