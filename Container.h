#ifndef CONTAINER_H
#define CONTAINER_H
#include <sstream>
#include <string>
#include <JavaIterator.h>

using namespace std;

template <typename T>
class Container
{
    public:
        Container() {}
        virtual ~Container() {}
        virtual int Size() const =0; // возвращает размер контейнера
        virtual bool IsEmpty() const {
            return Size() ==0;
        } // проверяет пустой ли контейнер
        virtual string ToString() const
        {
            JavaIterator<T const&> *iter = createIterator();
            T temp;
            stringstream str;
            while(iter->HasNext())
            {
                temp = iter->Next();
                str << temp << " ";
            }
            return str.str();
        } // строка со всеми элементами
        virtual JavaIterator<T&>* createIterator(){}
        virtual JavaIterator<T const&>* createIterator() const{}

        bool operator ==(Container const& container) const{
            JavaIterator<T const&> iterContainer = container.createIterator();
            while (this->hasNext() && iterContainer->hasNext()) {
                if (this->next() != iterContainer->next())
                    return false;
            }
            return !this->hasNext() && !iterContainer->hasNext();
        }
        virtual void sortContainer()
        {
            JavaIterator<T&> *iter1 = createIterator();
            for(int i=0; iter1->HasNext() ;i++)
            {
                JavaIterator<T&> *iter2 = createIterator();
                for(int j=0; j<i; j++) iter2->Next();
                T& minValue = iter2->Next();
                while(iter2->HasNext())
                {
                    T& temp1 = iter2->Next();
                    T temp2 = minValue;
                    if(temp1 < minValue)
                    {
                        minValue = temp1;
                        temp1 = temp2;
                    }
                }
                iter1->Next();
            }
        }
    protected:
    private:
};
template <typename T>
ostream& operator<<(ostream& os, Container<T> const& c){
    os << c.ToString();
	return os;
}

#endif // CONTAINER_H
