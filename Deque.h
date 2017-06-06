#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
class Deque : virtual public Container<T>
{
    public:
        Deque() {}
        virtual bool PushFront(T const& value)=0; // добавить в начало
        virtual bool PushBack(T const& value)=0; // добавить в конец
        virtual T PopFront()=0; // забрать из начала
        virtual T PopBack()=0; // забрать с конца
        virtual T PeekFront() const =0; // узнать элемент в начале
        virtual T& PeekFront()=0;
        virtual T PeekBack() const =0; // узнать элемент с конца
        virtual T& PeekBack()=0;
    protected:
    private:
};

#endif // DEQUE_H
