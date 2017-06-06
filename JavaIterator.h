#ifndef JAVAITERATOR_H
#define JAVAITERATOR_H

template <typename T>
class JavaIterator
{
    public:
        JavaIterator() {}
        virtual ~JavaIterator() {}
        virtual T Next()=0;
        virtual bool HasNext() const =0;
    protected:
    private:
};

#endif // JAVAITERATOR_H
