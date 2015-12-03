#include <iostream>
#define MAXLENG 5
#define OBJ_LEN_ARR 5

using namespace std;

template <typename keytype,typename valuetype>
class Multimap
{
    private:
        keytype* keys;
        valuetype* values;
        int used=0;
        int maxforuse=MAXLENG;

    public:

    Multimap()
    {
        keys=new keytype[MAXLENG];
        values=new valuetype[MAXLENG];
        used=0;
        maxforuse=MAXLENG;
    }

    Multimap(const Multimap &object)
    {
        maxforuse=object.getused();
        keys=new keytype[maxforuse];
        values=new valuetype[maxforuse];

        for(int i=0; i<object.getused();i++)
        {
            keys[i]=object.getkey(i);
            values[i]=object.getvalue(i);
        }
        used=object.getused();
    }

    ~Multimap()
    {
        delete keys;
        delete values;
    }


    void addmemory()
    {
        keytype* keys2=new keytype[maxforuse*2];
        valuetype* values2=new valuetype[maxforuse*2];
        for(int i=0; i<used;i++)
        {
            keys2[i]=keys[i];
            values2[i]=values[i];
        }

        delete keys;
        delete values;

        keys=new keytype[maxforuse*2];
        values=new valuetype[maxforuse*2];

        for(int i=0; i<used;i++)
        {
            keys[i]=keys2[i];
            values[i]=values2[i];
        }

        delete keys2;
        delete values2;
        cout<<"                           Add memory"<<endl;

        maxforuse=maxforuse*2;


    }

    void append(keytype key, valuetype value)
    {
        if(used>=maxforuse)
        {
            addmemory();
        }

        keys[used]=key;
        values[used]=value;
        used++;
    }

    int getused()
    {
        return used;
    }

    void del(int index)
    {
        for(int i=index; i<used-1;i++)
        {
            keys[i]=keys[i+1];
            values[i]=values[i+1];
        }
        used--;
    }

    const valuetype search_by_key(keytype key)
    {
        int i=0;
        while((keys[i]!=key)and(i<used))
        {
            i++;
        }
        return values[i];
    }

     bool search_by_pair(keytype key,valuetype value)
     {
        int i=0;
        while(i<used)
        {
            if((keys[i]==key)and(values[i]==value)){return true;}
            i++;
        }
        return false;
     }


    void show_par(keytype key)
    {
        cout<<"Key "<<key<<" Value "<<search_by_key(key)<<endl;
    }

    void show_par(int index)
    {
       cout<<"Key "<<keys[index]<<" Value "<<values[index]<<endl;
    }

    void show_all()
    {
        for(int i=0; i<used;i++)
        {
            show_par(i);
        }
    }

    const keytype getkey(int index)
    {
        return keys[index];
    }

    const valuetype getvalue(int index)
    {
        return values[index];
    }


    Multimap& operator + ( Multimap<keytype,valuetype>& second)
    {
        Multimap <keytype,valuetype>*C=new Multimap();

        for(int i=0; i<second.getused();i++)
        {
            C->append(second.getkey(i),second.getvalue(i));
        }

        for(int i=0; i<used;i++)
        {
            if(second.search_by_pair(keys[i],values[i])==false)
            {
                C->append(keys[i],values[i]);
            }
        }
        return *C;
    }

    Multimap& operator - ( Multimap<keytype,valuetype>& second)
    {
        Multimap <keytype,valuetype>*C=new Multimap();
        for(int i=0; i<used;i++)
        {
            if(second.search_by_pair(keys[i],values[i])==true)
            {
                C->append(keys[i],values[i]);
            }
        }
        return *C;
    }

    Multimap& operator=(Multimap<keytype,valuetype>& second)
    {
        for(int i=0; i<second.getused();i++)
        {
            append(second.getkey(i),second.getvalue(i));
        }
        return *this;

    }

    valuetype operator[](keytype  i){return search_by_key(i);}

    Multimap& discard(Multimap<keytype,valuetype>& second)
     {

        Multimap <keytype,valuetype>*C=new Multimap();

        for(int i=0; i<used;i++)
        {
            if(second.search_by_pair(keys[i],values[i])==false)
            {
                C->append(keys[i],values[i]);
            }
        }
        return *C;
     }


};



int main()
{
    Multimap <double,double>object[OBJ_LEN_ARR];
    //object0=new Multimap();
    cout << "\nfirst" << endl;
    object[0].append(0.001,1.1111);
    object[0].append(0.002,2.1111);
    object[0].append(0.003,3.1111);
    object[0].append(0.007,4.1111);
    object[0].append(0.005,5.1111);
    object[0].append(0.006,6.1111);
    object[0].show_all();
    cout << "\nsecond" << endl;
    object[1].append(0.001,1.1111);
    object[1].append(0.007,2.1111);
    object[1].append(0.003,3.1111);
    object[1].append(0.004,4.1111);
    object[1].show_all();


    cout<<"\nindex "<<object[0][0.003]<<endl;

    cout << "\nUnion!" << endl;
    object[2]=object[0]+object[1];
    object[2].show_all();

    cout << "\nintersection" << endl;
    object[3]=object[0]-object[1];
    object[3].show_all();

    cout << "\ndiscard" << endl;
    object[4]=object[2].discard(object[3]);
    object[4].show_all();



    cout << "\nmagic" << endl;
    object[0].del(0);
    object[1]=object[0];
    object[1].show_all();


    return 0;
}
