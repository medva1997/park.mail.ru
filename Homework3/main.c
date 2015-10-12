#include <stdio.h>
#include <stdlib.h>
#define max_string 50

typedef struct _Node {

    char value[max_string];
    int mas_size;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _DblLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;

DblLinkedList* createDblLinkedList() {

    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void cleaner(DblLinkedList *list) {

    Node *tmp = list->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

void pushBack(DblLinkedList *list,char data[],int size) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    int i=0;
    for(i=0; i<size;i++)
    {
        tmp->value[i]=data[i];
    }
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

Node* getNth(DblLinkedList *list, size_t index) {
    Node *tmp = NULL;
    size_t i;

    if (index < list->size/2) {
        i = 0;
        tmp = list->head;
        while (tmp && i < index) {
            tmp = tmp->next;
            i++;
        }
    } else {
        i = list->size - 1;
        tmp = list->tail;
        while (tmp && i > index) {
            tmp = tmp->prev;
            i--;
        }
    }
    return tmp;
}

void* deleteNth(DblLinkedList *list, size_t index) {
    Node *elm = NULL;
    void *tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;

    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;

    return tmp;
}

void printDblLinkedList(DblLinkedList *list) {
    Node *tmp = list->head;
    while (tmp) {
        printf("%s\n",tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void insert(DblLinkedList *list, Node *elem, char data[],int size) {

    if(elem!=NULL){
        Node *ins =(Node*) malloc(sizeof(Node));

        ins->mas_size=size;

        int i=0;
        for(i=0; i<size;i++)
        {
            ins->value[i]=data[i];
        }

        ins->prev=elem->prev;
        ins->next=elem;
        elem->prev=ins;

        if(ins->prev!=NULL){
            ins->prev->next=ins;
        }
        else{
            list->head=ins;
        }
        list->size++;

    }

    if(elem==NULL){
        pushBack(list, data,size);
    }

}

int search(DblLinkedList *list,char data[]){

    Node *tmp = list->head;
    size_t i = 0;
    while (tmp) {

        if(strcmp(tmp->value, data)==0){
           return i;
        }
        tmp = tmp->next;
        i++;
    }
    return -1;

}

int search2(DblLinkedList *list,char data[]){

    Node *tmp = list->head;
    while (tmp) {
        if(strcmp(tmp->value, data)>0){
           return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    DblLinkedList *list = createDblLinkedList();

    FILE *file1 = fopen(argv[1],"r+");
    if(file1 == 0)
	{
        printf("не могу открыть файл '%s'",argv[1]);
        return 0;
	}

    char str[max_string];
    char word[max_string];
    memset (word, 0, sizeof(word));

	while ((fgets (str,sizeof(str),file1)) != NULL) {


        int i=0;
        //Начальные значения
        int action=-1;
        int startposition=-1;
        int finishposition=-1;
        while   ((str[i]!='\0')&&(i<max_string))
        {
            //Блок определения слова
            if(str[i]=='-'){ action=0;}
            if(str[i]=='+'){ action=1;}
            if(str[i]=='?'){ action=2;}
            if(str[i]=='<'){ startposition=i;}
            if(str[i]=='>') {

                finishposition=i-1;
                int k=0;
                for(k=0; k<finishposition-startposition;k++){
                    word[k]=str[k+startposition+1];
                }
                word[k+1]='\0';


                if(action==0) {
                    int  res=search(list,word);
                    if(res>=0){
                       deleteNth(list, res);
                    }

                }

                if(action==1){
                    int  res=search(list,word);
                    if(res<0){

                      insert(list, search2(list,word), word,finishposition-startposition+1);

                    }
               }

                 if(action==2){
                    int  res=search(list,word);
                    if(res>=0){
                         printf("Yes %s\n",word);
                    }
                    else{
                        printf("No %s\n",word);
                    }
                }

                //обнуление
                memset (word, 0, sizeof(word));
                action=-1;
                startposition=-1;
                finishposition=-1;
            }
            i++;
         }
	}
    printf("\n#########################################\n");

    printDblLinkedList(list);

    cleaner(list);
    fclose(file1);
    free(list);
    return 0;
}
