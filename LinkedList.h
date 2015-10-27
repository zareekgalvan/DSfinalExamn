//
//  linkedList.h
//  listaEncadenada
//
//  Created by Zareek Galvan on 2/3/15.
//  Copyright (c) 2015 Zareek Galvan. All rights reserved.
//

#ifndef listaEncadenada_linkedList_h
#define listaEncadenada_linkedList_h


template <class T>
class LinkedList
{
private:
    node<T> *head;
    void borra();
    
public:
    int count;
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    T deleteFirst();
    T deleteLast();
    T del(int pos);
    int deleteAll();
    T get(int pos);
    T set(T data, int pos);
    bool change(int pos, int pos2);
    void print();
    void reverse();
    void shift(int pos);
    void spin(int pos);
    bool operator==(LinkedList<T> list);
    void operator+=(T data);
    void operator+=(LinkedList<T> list);
    LinkedList(LinkedList const &list);
    void operator=(LinkedList<T> list);
    
    
    
};

template <typename T>
void LinkedList<T>::borra()
{
    node<T> *aux = head;
    while (head!=NULL)
    {
        head = head->getNext();
        delete aux;
        aux=head;
    }
}


template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = NULL;
    count=0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    borra();
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return (head==NULL);
}

template <typename T>
void LinkedList<T>::addFirst(T data)
{
    this->head = new node<T>(data, head);
    count++;
}

template <typename T>
void LinkedList<T>::addLast(T data)
{
    if (this->isEmpty())
    {
        this->addFirst(data);
    }
    else
    {
        node<T> *aux = this->head;
        while (aux->getNext() != NULL)
        {
            aux== aux->getNext();
        }
        aux->setNext(new node<T>(data));
        count++;
    }
}

template <typename T>
bool LinkedList<T>::add(T data, int pos)
{
    if (pos < 0 || pos > count)
    {
        return false;
    }
    if (count==0)
    {
        this->addFirst(data);
    }
    else if (pos == count)
    {
        addLast(data);
    }
    else
    {
        node<T> *aux = this->head;
        for (int i=1; i<pos; i++)
        {
            aux= aux->getNext();
        }
        aux->setNext(new node<T>(data, aux->getNext()));
        count++;
    }
    return true;
}

template <typename T>
T LinkedList<T>::deleteFirst()
{
    if (isEmpty())
    {
        return NULL;
    }
    T dataAux= head->getData();
    node<T> *aux = head;
    head = head->getNext();
    delete aux;
    count--;
    return dataAux;
}

template <typename T>
T LinkedList<T>::deleteLast()
{
    if (count>=1)
    {
        return this->deleteFirst();
    }
    node<T> *aux = this->head;
    while (aux->getNext()->getNext() != NULL)
    {
        aux= aux->getNext();
    }
    node<T> *aux2 = aux->getNext();
    T dataAux= aux2->getData();
    aux->setNext(NULL);
    delete aux2;
    count--;
    return dataAux;
}

template <typename T>
T LinkedList<T>::del(int pos)
{
    if (pos>=count)
    {
        return NULL;
    }
    if (pos==0)
    {
        return deleteFirst();
    }
    if (pos==count-1)
    {
        return deleteLast();
    }
    node<T> *aux = this->head;
    for (int i=1; i<pos; i++)
    {
        aux= aux->getNext();
    }
    node<T> *aux2 = aux->getNext();
    T dataAux= aux2->getData();
    aux->setNext(aux2->getNext());
    delete aux2;
    count--;
    return dataAux;
}

template <typename T>
int LinkedList<T>::deleteAll()
{
    int cont = count;
    borra();
    count = 0;
    return cont;
}

template <typename T>
T LinkedList<T>::get(int pos)
{
    if (pos<0 || pos>=count)
    {
        return NULL;
    }
    node<T> *aux = this->head;
    for (int i=1; i<=pos; i++)
    {
        aux= aux->getNext();
    }
    return aux->getData;
}

template <typename T>
T LinkedList<T>::set(T data, int pos)
{
    if (pos<0 || pos>=count)
    {
        return NULL;
    }
    node<T> *aux = this->head;
    for (int i=1; i<=pos; i++)
    {
        aux= aux->getNext();
    }
    T dataAux=aux->getData();;
    this->aux->setData(data);
    return dataAux;
}

template <typename T>
bool LinkedList<T>::change(int pos, int pos2)
{
    if (pos>=count || pos2>=count || pos<0 || pos2<0)
    {
        return false;
    }
    if (pos == pos2)
    {
        return true;
    }
    node<T> *aux = this->head;
    node<T> *aux2 = this->head;
    int posmay = (pos>pos2 ? pos:pos2);
    int posmen = (pos<pos2 ? pos:pos2);
    for (int i=1; i<=posmen; i++)
    {
        aux2=aux=aux->getNext();
    }
    for (int i=posmen+1; i<=posmay; i++)
    {
        aux2=aux2->getNext();
    }
    
    T dataAux = aux->getData();
    aux->setData(aux2->getData());
    aux2->setData(dataAux);
    return true;
}

template <typename T>
void LinkedList<T>::print()
{
    node<T> *aux = this->head;
    cout<<"Inicio de la lista"<<endl;
    while (aux!=NULL)
    {
        cout<<aux->getData()<<endl;
        aux=aux->getNext();
    }
    cout<<"Fin de la lista"<<endl;
}

template <typename T>
void LinkedList<T>::reverse()
{
    int pos = count;
    int x=0,y=count-1;
    while (pos>0)
    {
        change(x, y);
        x++;
        y--;
        pos-=2;
    }
}

template <typename T>
void LinkedList<T>::shift(int pos)
{
    if (pos<0)
    {
        pos+=count;
    }
    for (int c=0;c<pos%count; c++)
    {
        node<T> *aux = this->head;
        node<T> *aux2 = this->head;
        while (aux->getNext()->getNext() != NULL)
        {
            aux= aux->getNext();
            aux2= aux2->getNext();
        }
        
        aux=aux->getNext();
        aux2->setNext(NULL);
        aux->setNext(head->getNext());
        head->setNext(aux);
        change(0, 1);
    }
}

//Por algua razon no quiere funcionar
template <typename T>
void LinkedList<T>::operator+=(T data)
{
    addLast(data);
}

//No deja asignar los avalores y marca error
template <typename T>
void LinkedList<T>::operator+=(LinkedList<T> list)
{
    node<T> *aux = list->head;
    while (aux->getNext()!=NULL)
    {
        addLast(new node<T>(aux->getData()));
        aux=aux->getNext();
    }
}

template <typename T>
void LinkedList<T>::operator=(LinkedList<T> list)
{
    this->borra();
    node<T> *aux = list->head;
    this->head->setNext(NULL);
    while (aux->getNext()!=NULL)
    {
        aux->getNext();
        head->setNext(add(aux->getData()));
        
    }
}

//Siempre sale false
template <typename T>
bool LinkedList<T>::operator==(LinkedList<T> list)
{
    node<T> *aux = this->head;
    node<T> *aux2 = list->head;
    bool x;
    if(count!=list->count)
    {
        return false;
    }
    for(int i=0; i<count-1; i++)
    {
        aux= aux->getNext();
        aux2= aux2->getNext();
        if (aux->getData()==aux2->getData())
        {
            x=true;
        }
        if (aux->getData()!=aux2->getData())
        {
            return false;
        }
    }
    return x;
}

//No funciona por el operador +=
template <typename T>
void LinkedList<T>::spin(int pos)
{
    int cant = count/pos;
    if (count%pos>0)
    {
        cant++;
    }
    node<T> *aux = this->head;
    LinkedList<T> *temp;
    node<T> *aux2;
    aux=aux->getNext();
    for (int i=0; i<cant; i++)
    {
        for (int e=0; e<pos; e++)
        {
            temp+=new node<T>(aux->getData());
            aux->getNext();
        }
        temp->reverse();
        aux2+=temp;
        temp->borra();
    }
    aux=aux2;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList const &list)
{
    node<T> *aux = list.head;
    this->head->setNext(NULL);
    while (aux->getNext()!=NULL)
    {
        aux->getNext();
        head->setNext(addLast(aux->getData()));
        
    }
}

#endif
