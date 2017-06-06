#ifndef LINKEDDEQUE_H
#define LINKEDDEQUE_H

template <class S,class T>
class LinkedDequeIterator : JavaIterator<T>
{
    private:
        Node<S>* current;
    public:
        LinkedDequeIterator(Node<S>* cur);
        virtual ~LinkedDequeIterator();
        bool HasNext() const;
        T Next();
};

template <class S,class T>
LinkedDequeIterator<S,T>::LinkedDequeIterator(Node<S>* cur)
{
    current = cur;
}

template <class S,class T>
LinkedDequeIterator<S,T>::~LinkedDequeIterator()
{

}

template <class S,class T>
bool LinkedDequeIterator<S,T>::HasNext() const
{
    return current != nullptr;
}

template <class S,class T>
T LinkedDequeIterator<S,T>::Next()
{
    T temp = current->value;
    if(temp != nullptr) current = current->prev;
    return temp;
}

template <typename T>
class LinkedDeque
{
    public:
        LinkedDeque();
        LinkedDeque(LinkedDeque<T> const& from);
        virtual ~LinkedDeque();

        int Size() const; // возвращает размер контейнера
        bool IsEmpty() const; // проверяет пустой ли контейнер
        string ToString() const; // строка со всеми элементами

        bool PushFront(T value); // добавить в начало
        bool PushBack(T value); // добавить в конец
        T PopFront(); // забрать из начала
        T PopBack(); // забрать с конца
        T PeekFront(); // узнать элемент в начале
        T PeekBack(); // узнать элемент с конца
    protected:
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;
};

template <typename T>
LinkedDeque<T>::LinkedDeque()
{

}
template <typename T>
LinkedDeque<T>::LinkedDeque(LinkedDeque<T> const& from)
{
    Node<T> *newCopy = from->head;

    do {
		Push(newCopy->value);
	} while ((newCopy = newCopy->prev) != NULL);
}
template <typename T>
LinkedDeque<T>::~LinkedDeque()
{

}

template <typename T>
T LinkedDeque<T>::Size() const
{
    return length;
}
template <typename T>
bool LinkedDeque<T>::IsEmpty() const
{
    return length == 0;
}

template <typename T>
string LinkedDeque<T>::ToString() const
{

}

template <typename T>
bool LinkedDeque<T>::PushFront(T value)
{
    Node<T> *node = new Node<T>;
	node->value = value;
	if(head == NULL) node->prev = NULL;
	else node->prev = head;
	head = node;
	++length;
	return true;
}
template <typename T>
bool LinkedDeque<T>::PushBack(T value)
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
T LinkedDeque<T>::PopFront()
{
    T n = head->value;
	head = head->prev;
	--length;
	return n;
}

template <typename T>
T LinkedDeque<T>::PopBack()
{
    T n = tail->value;
	tail = tail->next;
	--length;
	return n;
}

template <typename T>
T LinkedDeque<T>::PeekFront())
{
    return head->value;
}

template <typename T>
T LinkedDeque<T>::PeekBack()
{
    return tail->value;
}

#endif // LINKEDDEQUE_H
