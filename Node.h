#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
    public:
        Node() {}
        virtual ~Node() {}

        T value;
        Node *prev;
        Node *next;
    protected:
    private:
};

#endif // NODE_H
