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
    void bubble_sort(); // all the heavy elements are sent to the back
    void insertion_sort();
    int partition(int l, int h);       // Partitioning procedure
    void quick_sort(int l, int h);     // recursive method
    void merge(int l, int mid, int h); // 2-way merging
    void merge_sort(int l, int h);     // recursive method
    void heap_sort();
    void count_sort();
    void wave_sort();
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
    int k = l;
    int *left = new int[mid - l + 1];
    int *right = new int[h - mid];
    int *b = new int[length];
    for (int p = 0; p < (mid - l + 1); p++)
    {
        left[p] = a[l + p];
    }
    for (int p = 0; p < (h - mid); p++)
    {
        right[p] = a[mid + 1 + p];
    }
    int p = 0;
    int q = 0;
    while ((p <= (mid - l + 1)) && (q <= (h - mid)))
    {
        if (left[p] < right[q])
        {
            b[k++] = left[p++];
        }
        else
        {
            b[k++] = right[q++];
        }
    }
    for (; p <= mid; p++)
    {
        b[k++] = a[p++];
    }
    for (; q <= h; q++)
    {
        b[k++] = a[q++];
    }
    delete left;
    delete right;
    for (int m = l; m <= h; m++)
    {
        a[m] = b[m];
    }
}
void array::merge_sort(int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
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
    First.print_arr();
    // First.bubble_sort();
    // First.quick_sort(0, (First.get_length() - 1));
    First.merge_sort(0, (First.get_length()));
    First.print_arr();

    return 0;
}