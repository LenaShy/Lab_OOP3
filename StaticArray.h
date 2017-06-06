#ifndef STATICARRAY_H
#define STATICARRAY_H
#include <IndexedContainer.h>

template <class S,class T>
class StaticArrayIterator : JavaIterator<T>
{
    private:
        S* current;
        int currentElement;
        int maxLength;
    public:
        StaticArrayIterator(S* cur, int maxL);
        virtual ~StaticArrayIterator();
        bool HasNext() const;
        T Next();
};

template <class S,class T>
StaticArrayIterator<S,T>::StaticArrayIterator(S* cur, int maxL)
{
    current = cur;
    maxLength = maxL;
}

template <class S,class T>
StaticArrayIterator<S,T>::~StaticArrayIterator()
{

}

template <class S,class T>
bool StaticArrayIterator<S,T>::HasNext() const
{
    return currentElement < maxLength;
}

template <class S,class T>
T StaticArrayIterator<S,T>::Next()
{
    T temp = current[currentElement];
    ++currentElement;
    return temp;
}

template <typename T>
class StaticArray : virtual public IndexedContainer<T>
{
    public:
        StaticArray(int mSize);
        virtual ~StaticArray();

        int Size() const; // возвращает размер контейнера
        bool IsEmpty() const; // проверяет пустой ли контейнер
        string ToString() const; // строка со всеми элементами

        T Get(int index) const; // узнать элемент по индексу index
        T& Get(int index);
        void Set(int index, T const& value); // задать значение элементу
    protected:
    private:
        T *arr;
        int maxSize;
};

template <typename T>
StaticArray<T>::StaticArray(int mSize)
{
    //ctor
    maxSize = mSize;
    arr = new T[maxSize];
}

template <typename T>
StaticArray<T>::~StaticArray()
{
    //dtor
    delete arr;
}

template <typename T>
void StaticArray<T>::Set(int index, T const& value)
{
    if(index < 0 || index > maxSize) return;
    arr[index] = value;
}

template <typename T>
T StaticArray<T>::Get(int index) const
{
    if(IsEmpty() || index < 0 || index > maxSize) return 0;
    return arr[index];
}

template <typename T>
T& StaticArray<T>::Get(int index)
{
    if(IsEmpty() || index < 0 || index > maxSize) return 0;
    return arr[index];
}


template <typename T>
int StaticArray<T>::Size () const
{
    return maxSize;
}

template <typename T>
bool StaticArray<T>::IsEmpty() const
{
    return maxSize == 0;
}

template <typename T>
string StaticArray<T>::ToString() const
{
    string str;
    for(int i=0;i<maxSize;i++)
    {
		str += arr[i];
    }
    return str;
}

#endif // STATICARRAY_H
