#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <sstream>
#include <iostream>
#include <PushPopContainer.h>
#include <InsertableContainer.h>
#include <Node.h>
#include <JavaIterator.h>

template <class S,class T>
class LinkedListIterator : public JavaIterator<T>
{
    private:
        Node<S>* current;
    public:
        LinkedListIterator(Node<S>* cur);
        virtual ~LinkedListIterator();
        bool HasNext() const;
        T Next();
};

template <typename S,typename T>
LinkedListIterator<S,T>::LinkedListIterator(Node<S>* cur)
{
    current = cur;
}

template <typename S,typename T>
LinkedListIterator<S,T>::~LinkedListIterator()
{

}

template <typename S,typename T>
bool LinkedListIterator<S,T>::HasNext() const
{
    return current != nullptr;
}

template <typename S,typename T>
T LinkedListIterator<S,T>::Next()
{
    T temp = current->value;
    if(current != NULL )
    {
        //temp = current->value;
        current = current->prev;
    }
    return temp;
}


template <class T>
class LinkedList : virtual public PushPopContainer<T>, virtual public InsertableContainer<T>
{
    public:
        LinkedList();
        LinkedList(LinkedList<T> const& from);
        virtual ~LinkedList();

        T Get(int index) const; // узнать элемент по индексу index
        T& Get(int index);
        void Set(int index, T const& value);

        bool Push(T const& value);
        T Pop();
        T Peek() const; // узнать элемент
        T& Peek();

        bool InsertAt(int index, T const& value); // вставить элемент со сдвигом
        T RemoveAt(int index); // убрать элемент со сдвигом

        int Size() const; // возвращает размер контейнера
        bool IsEmpty() const; // проверяет пустой ли контейнер
        //string ToString() const; // строка со всеми элементами
        JavaIterator<T&> *createIterator();
        JavaIterator<T const&> *createIterator() const;

        bool PushBack(T const& value); // добавить в конец
        T PopBack(); // забрать с конца
        T PeekBack() const; // узнать элемент с конца
        T& PeekBack();
        bool PushFront(T const& value); // добавить в начало
        T PopFront(); // забрать из начала
        T PeekFront() const; // узнать элемент в начале
        T& PeekFront();

    protected:
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;
};
template <typename T>
LinkedList<T>::LinkedList()
{
    //ctor
    head = NULL;
    tail = NULL;
    length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> const& from)
{
    Node<T> *newCopy = from->head;

    do {
		Push(newCopy->value);
	} while ((newCopy = newCopy->prev) != NULL);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    //dtor
    Node<T> *cur;
    Node<T> *next = head;
    while(next != NULL)
    {
        cur = next;
        next = cur->prev;
        delete cur;
    }
    delete next;
}

template <typename T>
bool LinkedList<T>::Push(T const& value)
{
    Node<T> *node = new Node<T>;
    node->value = value;
    if(head != NULL) node->prev = head;
    else
    {
        node->prev = NULL;
        tail = node;
    }
    head = node;
    ++length;
    return true;
}

template <typename T>
T LinkedList<T>::Pop()
{
    if(head != NULL)
    {
        T value = head->value;
        head = head->prev;
        --length;
        return value;
    }
    else return 0;
}

template <typename T>
T LinkedList<T>::Peek() const
{
    return head->value;
}

template <typename T>
T& LinkedList<T>::Peek()
{
    return head->value;
}


template <typename T>
bool LinkedList<T>::InsertAt(int index, T const& value)
{
    Node<T> *node = new Node<T>;
    Node<T> *tempNode = head;
    node->value = value;
    for(int i =0; i<length; i++)
    {
        if(i == index)
        {
            node->prev = tempNode->prev;
            tempNode->prev = node;
            ++length;
            break;
        }
        else
        {
            tempNode = tempNode->prev;
        }
    }
    return true;
}

template <typename T>
T LinkedList<T>::RemoveAt(int index)
{
    Node<T> *tempNode = head;
    T value;
    for(int i=0; i<length;i++)
    {
        if(i == index-1)
        {
            value = (tempNode->prev)->value;
            tempNode->prev = (tempNode->prev)->prev;
            --length;
            break;
        }
        else tempNode = tempNode->prev;
    }
    return value;
}

template <typename T>
int LinkedList<T>::Size() const
{
    return length;
}

template <typename T>
bool LinkedList<T>::IsEmpty() const
{
    return length == 0;
}


/*template <typename T>
string LinkedList<T>::ToString() const
{
    Node<T> *temp = head;
	stringstream str;
	//string str2;
	while(temp != NULL)
	{
        //str2 = temp->value;
        //cout << temp->value << endl;
        str << temp->value << " ";
		temp = temp->prev;
		//cout << str.str() << endl;
	}
	//cout << str.str();
    return str.str();
    //return str2;
}*/

template <typename T>
JavaIterator<T&>* LinkedList<T>::createIterator() {
	return new LinkedListIterator<T, T&>(head);
}
template <typename T>
JavaIterator<T const&>* LinkedList<T>::createIterator() const {
	return new LinkedListIterator<T, T const&>(head);
}

template <typename T>
bool LinkedList<T>::PushBack(T const& value)
{
    Node<T> *node = new Node<T>;
    node->value = value;
    node->prev = NULL;
    if(tail != NULL) tail->prev = node;
    else head = node;
    tail = node;
    ++length;
    return true;
}

template <typename T>
T LinkedList<T>::PopBack()
{
    Node<T> *temp = head;
    T value;
    for(int i=0; i<length;i++)
    {
        if(i==length-1)
        {
            value = (temp->prev)->value;
            temp->prev = NULL;
        }
        else temp = temp->prev;
    }
    --length;
    return value;
}

template <typename T>
T LinkedList<T>::PeekBack() const
{
    return tail->value;
}

template <typename T>
T& LinkedList<T>::PeekBack()
{
    return tail->value;
}

template <typename T>
bool LinkedList<T>::PushFront(T const& value)
{
    Push(value);
    return true;
}

template <typename T>
T LinkedList<T>::PopFront()
{
    return Pop();
}

template <typename T>
T LinkedList<T>::PeekFront() const
{
    return Peek();
}

template <typename T>
T& LinkedList<T>::PeekFront()
{
    return Peek();
}

template <typename T>
T LinkedList<T>::Get(int index) const
{
    Node<T> *temp = head;
    for(int i=0; i<length;i++)
    {
        if(i==index) return temp->value;
        else temp = temp->prev;
    }
    return 0;
}

template <typename T>
T& LinkedList<T>::Get(int index)
{
    Node<T> *temp = head;
    for(int i=0; i<length;i++)
    {
        if(i==index) return temp->value;
        else temp = temp->prev;
    }
    return temp->value;
}

template <typename T>
void LinkedList<T>::Set(int index, T const& value)
{
    Node<T> *temp = head;
    for(int i=0; i<length;i++)
    {
        if(i==index) temp->value = value;
        else temp = temp->prev;
    }
}

#endif // LINKEDLIST_H
