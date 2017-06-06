#ifndef STACK_H
#define STACK_H
#include <PushPopContainer.h>
#include <sstream>


template <class T,class S>
class StackIterator : public JavaIterator<S>
{
    private:
        Node<T>* current;
    public:
        StackIterator(Node<T>* cur);
        virtual ~StackIterator();
        bool HasNext() const;
        S Next();
};

template <typename T, typename S>
StackIterator<T,S>::StackIterator(Node<T>* cur)
{
    current = cur;
}

template <typename T, typename S>
StackIterator<T,S>::~StackIterator()
{

}

template <typename T, typename S>
bool StackIterator<T,S>::HasNext() const
{
    return current != nullptr;
}

template <typename T, typename S>
S StackIterator<T,S>::Next()
{
    S temp = current->value;
    if(temp != NULL) current = current->prev;
    return temp;
}


template <class T>
class Stack : virtual public PushPopContainer<T>
{
    public:
        Stack();
        Stack(Stack<T> const& from);
        virtual ~Stack();

        bool Push(T const& value);
		T Pop();
		T Peek() const; // узнать элемент
		T& Peek();

        bool IsEmpty() const; // проверяет пустой ли контейнер
        string ToString() const; // строка со всеми элементами
		int Size() const;
        JavaIterator<T&>* createIterator();
        JavaIterator<T const&>* createIterator() const;

    protected:
    private:
        Node<T> *head;
        int length;

};

template <typename T>
Stack<T>::Stack()
{
    //ctor
    head = NULL;
    length = 0;
}

template <typename T>
Stack<T>::Stack(Stack<T> const& from)
{
    Node<T> *newCopy = from->head;

    do {
		Push(newCopy->value);
	} while ((newCopy = newCopy->prev) != NULL);
}
template <typename T>
Stack<T>::~Stack()
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
bool Stack<T>::Push(T const& value){
	Node<T> *node = new Node<T>;
	node->value = value;
	if(head == NULL) node->prev = NULL;
	else node->prev = head;
	head = node;
	++length;
	return true;
}

template <typename T>
T Stack<T>::Pop(){
	T n = head->value;
	head = head->prev;
	--length;
	return n;
}

template <typename T>
string Stack<T>::ToString() const
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

template <typename T>
T Stack<T>::Peek() const
{
    return head->value;
}

template <typename T>
T& Stack<T>::Peek()
{
    return head->value;
}

template <typename T>
int Stack<T>::Size() const
{
	return length;
}


template <typename T>
bool Stack<T>::IsEmpty() const
{
    return (head == NULL)? true : false;
}

template <typename T>
JavaIterator<T&>* Stack<T>::createIterator() {
	return new StackIterator<T, T&>(head);
}
template <typename T>
JavaIterator<T const&>* Stack<T>::createIterator() const {
	return new StackIterator<T, T const&>(head);
}
#endif // STACK_H
