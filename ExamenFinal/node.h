//
//  node.h
//  listaEncadenada
//
//  Created by Zareek Galvan on 2/3/15.
//  Copyright (c) 2015 Zareek Galvan. All rights reserved.
//

#ifndef listaEncadenada_node_h
#define listaEncadenada_node_h
template <class  T>
class node
{	public:
    node(T data);
    node(T data, node<T> *next);
    T getData();
    node<T>* getNext();
    void setData(T data);
    void setNext(node<T> *next);
    
private:
    T data;
    node<T>  *next;
};

template <typename T>
node<T>::node(T data)
{
    this->data = data;
    this->next = NULL;
}

template <typename T>
node<T>::node(T data, node<T> *next)
{
    this->data = data;
    this->next = next;
}

template <typename T>
T node<T>::getData()
{
    return this->data;
}

template <typename T>
node<T>* node<T>::getNext()
{
    return this->next;
}

template <typename T>
void node<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
void node<T>::setNext(node<T> *next)
{
    this->next = next;
}


#endif
