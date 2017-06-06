#ifndef PUSHPOPCONTAINER_H
#define PUSHPOPCONTAINER_H
#include <Container.h>

template <typename T>
class PushPopContainer: virtual public Container<T>
{
    public:
        PushPopContainer() {}
        virtual ~PushPopContainer() {}
        virtual bool Push(T const& value)=0; // добавить элемент
        virtual T Pop()=0; // забрать элемент
        virtual T Peek() const =0; // узнать элемент
        virtual T& Peek()=0;
    protected:
    private:
};

#endif // PUSHPOPCONTAINER_H
