#ifndef INSERTABLECONTAINER_H
#define INSERTABLECONTAINER_H
#include <IndexedContainer.h>
#include <Deque.h>

template <typename T>
class InsertableContainer: virtual public IndexedContainer<T>, virtual public Deque<T>
{
    public:
        InsertableContainer() {}
        virtual ~InsertableContainer() {}
        virtual bool InsertAt(int index, T const& value)=0; // вставить элемент со сдвигом
        virtual T RemoveAt(int index)=0; // убрать элемент со сдвигом
    protected:
    private:
};

#endif // INSERTABLECONTAINER_H
