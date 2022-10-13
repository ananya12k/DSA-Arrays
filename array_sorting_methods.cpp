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
    array();          // Constuctor
    ~array();         // Destructor
    int get_length(); // fetches the length of array
    void enter_ele();
    void print_arr();
    void bubble_sort(); // all the heavy elements are sent to the back
    void insertion_sort();
    int partition(int l, int h);       // Partitioning procedure
    void quick_sort(int l, int h);     // recursive quick sort
    void merge(int l, int mid, int h); // 2-way merging
    void merge_sort(int l, int h);     // recursive merge sort
    void heap_sort();
    void selection_sort(); // lighter elements are brought to front
    void count_sort();
    void wave_sort();
    void DNF_sort();
    void radix_sort(); // also known as bucket sort
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
    cout << "\nArray elements are: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
}
int array::partition(int l, int h)
{
    int pivot = a[l];
    int i = l + 1;
    int j = h;
    do
    {

        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    int k = a[l];
    a[l] = a[j];
    a[j] = k;

    return j;
}
void array::insertion_sort()
{
    int j;
    for (int i = 1; i < length; i++) // Loop to perform passes
    {
        j = i - 1;
        int x = a[i];
        while (j > -1 && a[j] > x) // loop to do shifting in each pass
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
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
void array::merge(int l, int mid, int h)
{
    int *b = new int[h - l + 1];
    int k = l;
    int i = l, j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= h)
    {
        b[k++] = a[j++];
    }
    for (int i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}
void array::merge_sort(int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, h);
        merge(l, mid, h);
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
    cout << "Before Sorting: " << endl;
    First.print_arr();
    cout << "\nAfter Sorting: " << endl;
    // First.bubble_sort();
    // First.quick_sort(0, (First.get_length() - 1));
    // First.insertion_sort();
    First.merge_sort(0, (First.get_length() - 1));
    First.print_arr();

    return 0;
}