#include <iostream>
#include <cstdlib>
using namespace std;
class array
{
private:
    int *a;
    int size;
    int length;

public:
    array() { std::cout << "Default constructor" << endl; }
    array(int len, int s);
    ~array();
    void bubble_sort();
    void insertion_sort();
    void quick_sort();
    void merge_sort();
    void heap_sort();
    void count_sort();
    void wave_sort();
    void DNF_sort();
};

void array::insertion_sort()
{

}
void array::quick_sort()
{

}
void array::bubble_sort()
{
    cout<< "Bubble sorting array" << endl;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (a[i] > a[j]) // ascending order
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
array::array(int len, int s)
{
    std::cout << "Constructor called" << endl;
    size = s;
    length = len;
    a = new int[size];
}
array::~array()
{
    std::cout << "Destrcutor called" << endl;
    delete a;
}

int main()
{
    array First(2, 5);
    return 0;
}