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
    array();
    ~array();
    int get_length();
    void enter_ele();
    void print_arr();
    void bubble_sort();
    void insertion_sort();
    void quick_sort(int l, int h);
    void merge_sort();
    void heap_sort();
    void count_sort();
    void wave_sort();
    int partition(int l, int h);
    void DNF_sort();
};
int array::get_length()
{
    return length;
}
void array::enter_ele()
{
    cout << "Enter elements in array: " << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> a[i];
    }
}
void array::print_arr()
{
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
}
int array::partition(int l, int h)
{
    int i = 0;
    int j = length;
    int pivot = a[l];
    do
    {
        do
        {
            i++;
        } while (a[i] > pivot);

        do
        {
            j--;
        } while (a[j] <= pivot);
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    if (j > i)
    {
        int k = a[l];
        a[l] = a[j];
        a[j] = k;
    }

    return j;
}
void array::insertion_sort()
{
}
void array::quick_sort(int l, int h)
{
    if (l < h)
    {
        int j = partition(l, h);
        quick_sort(l, j - 1);
        quick_sort(j + 1, h);
    }
}

void array::bubble_sort()
{
    cout << "\nBubble sorting array" << endl;
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
array::array()
{
    std::cout << "Constructor called" << endl;
    cout << "Enter total size of array that you want to create: " << endl;
    int s;
    cin >> s;
    size = s;
    cout << "Enter how many elements you want to enter in array: " << endl;
    int len;
    cin >> len;
    length = len;
    if (length <= size)
    {
        a = new int[size];
    }
    else
    {
        cout << "Length of array exceeds size" << endl;
    }
}
array::~array()
{
    std::cout << "\nDestructor called" << endl;
    delete a;
}

int main()
{
    array First;
    First.enter_ele();
    First.print_arr();
    // First.bubble_sort();
   
    First.quick_sort(0,( First.get_length()));
    First.print_arr();

    return 0;
}