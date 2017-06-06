#include <iostream>
#include <LinkedList.h>
#include <Stack.h>
#include <Queue.h>
#include <StaticArray.h>
#include <string>

using namespace std;

int main()
{
    LinkedList<string> lList;
    lList.Push("a");
    lList.Push("b");
    //lList.ToString();
    //cout << lList;
    Stack<int> st;
    /*Queue<int> q;
    q.Push(6);
    q.Push(11);
    q.Push(3);
    cout << q;*/
    st.Push(10);
    st.Push(2);
    st.Push(30);
    st.Push(4);
    st.Push(53);
    cout << st << endl;
    st.sortContainer();
    cout << st << endl;


//    StaticArray<int> sa = new StaticArray<int>(10);
    cout << "Hello world!" << endl;
    return 0;
}
