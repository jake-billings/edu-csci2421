#ifndef MYVECTOR_
#define MYVECTOR_
/*Defines a MyVector type which mirrors the STL vector class.  It uses templates and dynamic memory allocation*/

namespace HW4
{
typedef int T;
class MyVector
{
private:
    int vsize = 0;
    T* vec = nullptr;

public:
    MyVector();
    T operator[] (int index);
    void pop_back();
    void push_back(T value);
    int size(); //returns the vector size
    bool empty();//determine if is empty
    int search(T Value);
    
    
};

}//namespace
#endif
