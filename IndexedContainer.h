#ifndef INDEXEDCONTAINER_H
#define INDEXEDCONTAINER_H

template <typename T>
class IndexedContainer: virtual public Container<T>
{
    public:
        IndexedContainer() {}
        virtual ~IndexedContainer() {}
        virtual T Get(int index) const =0; // узнать элемент по индексу index
        virtual T& Get(int index) =0;
        virtual void Set(int index, T const& value) =0; // задать значение элементу

        T operator[](int index) {
		return Get(index);
	}
    protected:
    private:
};

#endif // INDEXEDCONTAINER_H
