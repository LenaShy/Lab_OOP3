#ifndef QUEUE_H
#define QUEUE_H
#include <PushPopContainer.h>
#include <sstream>

template <class S,class T>
class QueueIterator : JavaIterator<T>
{
    private:
        Node<S>* current;
    public:
        QueueIterator(Node<S>* cur);
        virtual ~QueueIterator();
        bool HasNext() const;
        T Next();
};

template <class S,class T>
QueueIterator<S,T>::QueueIterator(Node<S>* cur)
{
    current = cur;
}

template <class S,class T>
QueueIterator<S,T>::~QueueIterator()
{

}

template <class S,class T>
bool QueueIterator<S,T>::HasNext() const
{
    return current != nullptr;
}

template <class S,class T>
T QueueIterator<S,T>::Next()
{
    T temp = current->value;
    if(temp != nullptr) current = current->prev;
    return temp;
}


template <typename T>
class Queue : virtual public PushPopContainer<T>
{
    public:
        Queue();
        Queue(Queue<T> const& from);
        virtual ~Queue();

        bool Push(T const& value);
		T Pop();
		T Peek() const; // узнать элемент
		T& Peek();

		string ToString() const;
		int Size() const;
		bool IsEmpty() const; // проверяет пустой ли контейнер
    protected:
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;
};

template <typename T>
Queue<T>::Queue()
{
    //ctor
    length = 0;
    head = NULL;
    tail = NULL;
}

template <typename T>
Queue<T>::Queue(Queue<T> const& from)
{
    Node<T> *newCopy = from->tail;

    do {
		Push(newCopy->value);
	} while ((newCopy = newCopy->prev) != NULL);
}

template <typename T>
Queue<T>::~Queue()
{
    //dtor
}

template <typename T>
bool Queue<T>::Push(T const& value)
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
T Queue<T>::Pop()
{
    T n = head->value;
	head = head->prev;
	--length;
	return n;
}

template <typename T>
int Queue<T>::Size() const
{
    return length;
}

template <typename T>
T Queue<T>::Peek() const
{
    return head->value;
}

template <typename T>
T& Queue<T>::Peek()
{
    return head->value;
}

template <typename T>
bool Queue<T>::IsEmpty() const
{
    return length == NULL;
}

template <typename T>
string Queue<T>::ToString() const
{
    Node<T> *temp = head;
	stringstream str;
	while(temp != NULL)
	{
        str << temp->value << " ";
		temp = temp->prev;
	}
    return str.str();
}
#endif // QUEUE_H
