#include <iostream>
#include <cstdlib>
using namespace std;
class array
{
private:
    int *a;
    int length;
    int size;

public:
    array();
    ~array();
    friend void menu(array &First, array &second);
    void create_arr(int len, int s);
    void enter_elements();
    void append_at_last(int x);
    void traverse_and_print();
    void delete_element(int x);
    void sort(); // bubble sort
    int linear_search(int x);
    int binary_search(int x);
    void set_element(int x, int index); // set element at index
    int get_element(int index);         // get element from a given index
    int max_element();
    int min_element();
    int sum_of_elements();
    int recursive_sum(); // Doubt
    int avg_elements();
    void rev_arr_new_arr();
    void rev_arr();
    int insert_ele_in_sorted_arr(int index, int num);
    bool check_sorted_or_not();
    void shift_negative_num();
    array arr_union(array A1, array A2);
    void diff_arr();
    void intersect_arr();
    void merge_arr();
};
array::array()
{
    std::cout << "Default constructor" << endl;
}
array::~array()
{
    std::cout << "Destructor called" << endl;
    delete[] a;
}
void array::enter_elements()
{
    int First[length];
    std::cout << "Enter the elements to be added in the array:- " << endl;
    for (int i = 0; i < length; i++)
    {
        std::cin >> First[i];
        a[i] = First[i];
    }
}
void array::create_arr(int len, int s)
{
    length = len;
    size = s;
    a = new int[size]{0};
}
void array ::append_at_last(int x)
{
    try
    {
        if (length < size)
        {
            a[length++] = x;
        }
        else
            throw length;
    }
    catch (int x)
    {
        std::cout << "Length exceeded the size of array" << endl;
    }
}
void array::traverse_and_print()
{
    int i = 0;
    std::cout << "Elements of the array are: " << endl;
    while (i < length)
    {
        std::cout << a[i] << endl;
        i++;
    }
    std::cout << "The length is " << length << endl;
}
void array::delete_element(int x)
{
    for (int i = x; i < length; i++)
    {
        a[i] = a[i + 1];
    }
    length--;
}
void array::sort()
{
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
int array::linear_search(int x)
{
    for (int i = 0; i < length; i++)
    {
        if (a[i] == x)
        {
            return i; // element found at ith place
        }
    }
    return -1; // element not found
}
int array::binary_search(int x)
{
    int low, high, mid;
    low = 0;
    high = length - 1;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
    }
    return -1;
}
int array::get_element(int index)
{
    return a[index];
}
void array::set_element(int x, int index)
{
    a[index] = x;
}
int array::max_element()
{
    int i = 0;
    int max;
    max = a[i];
    do
    {
        if (max < a[i])
        {
            max = a[i];
        }
        i++;
    } while (i < length);
    return max;
}
int array::min_element()
{
    int min;
    int i = 0;
    min = a[i];
    do
    {

        if (min > a[i])
        {
            min = a[i];
        }
        i++;
    } while (i < length);
    return min;
}
int array::sum_of_elements()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += a[i];
    }

    return sum;
}
int array ::recursive_sum() // doubt
{
    if (length <= 0)
        return 0;
    return recursive_sum();
}
int array::avg_elements()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {

        sum += a[i];
    }
    return (float)(sum / length);
}
void array::rev_arr_new_arr()
{
    int *b;
    b = new int[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        b[j] = a[i];
    }
    for (int i = 0; i < length; i++)
    {
        a[i] = b[i];
    }
    delete[] b;
}
void array::rev_arr()
{
    int i, j, temp;
    for (i = length - 1, j = 0; i > j; i--, j++)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
bool array::check_sorted_or_not()
{
    int i, count = 0;
    for (i = 1; i < length; i++)
    {
        if (a[i - 1] > a[i])
        {
            count++;
        }
    }
    if (a[length] > a[0])
    {
        count++;
    }
    return count <= 1;
}
int array::insert_ele_in_sorted_arr(int index, int num)
{
    if (length >= size)
    {
        std::cout << "Size exceeded : element cannot be inserted" << endl;
        return 0;
    }
    for (int i = length; i >= index; i--)
    {
        a[i + 1] = a[i];
    }
    a[index] = num;
    length++;
    return 1;
}
void array::shift_negative_num()
{
    int i, j, temp;
    i = 0;
    j = length - 1;
    while (i < j)
    {
        while (a[i] < 0)
        {
            i++;
        }
        while (a[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
}
array array::arr_union(array A1, array A2)
{
    array temp;
    int len, s;
    len = A1.length + A2.length;
    s = A1.size + A2.size;
    temp.create_arr(len, s);
    return temp;
}
void array::diff_arr() {}
void array::intersect_arr() {}
void array::merge_arr() {}

void menu(array &First, array &second)
{
    std::cout << "-----: Welcome to Array ADT :-----" << endl;
    std::cout << "Enter your choice of operation (Array will be created by default then also one can create another array)" << endl;
    int choice;
    std::cout << "Enter the choice 1 to Create two arrays and enter elements in it" << endl;
    std::cout << "Enter the choice 2 to append element at last" << endl;
    std::cout << "Enter the choice 3 to delete element" << endl;
    std::cout << "Enter the choice 4 to sort arrays in ascending order" << endl;
    std::cout << "Enter the choice 5 to linear search element" << endl;
    std::cout << "Enter the choice 6 to binary search element" << endl;
    std::cout << "Enter the choice 7 to set an element at an index" << endl;
    std::cout << "Enter the choice 8 to get element from an index" << endl;
    std::cout << "Enter the choice 9 to find minimum element" << endl;
    std::cout << "Enter the choice 10 to find maximum element" << endl;
    std::cout << "Enter the choice 11 to find sum of all elements in an array" << endl;
    std::cout << "Enter the choice 12 to find average of all elements in an array" << endl;
    std::cout << "Enter the choice 13 to reverse an array using a new array" << endl;
    std::cout << "Enter the choice 14 to reverse an array without using a new array" << endl;
    std::cout << "Enter the choice 15 to insert an element in a sorted array at a given index" << endl;
    std::cout << "Enter the choice 16 to check whether the array is sorted or not" << endl;
    std::cout << "Enter the choice 17 to shift all the negative numbers to the left side" << endl;
    std::cout << "Enter the choice 18 to find union of arrays" << endl;
    std::cout << "Enter the choice 19 to find difference of arrays" << endl;
    std::cout << "Enter the choice 20 to find intersection of arrays" << endl;
    std::cout << "Enter the choice 21 to merge arrays" << endl;
    std::cout << "Enter choice : " << endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        std::cout << "First array: " << endl;
        First.create_arr(6, 10); // first array
        First.enter_elements();  // array 2
        std::cout << "Second array: " << endl;
        second.create_arr(8, 10);
        second.enter_elements();
        break;
    }
    case 2:
    {
        First.append_at_last(23);
        First.traverse_and_print();
        std::cout << "Do you want to append again?  Yes or no" << endl;
        string yes_no;
        std::cin >> yes_no;
        if ("yes")
        {
            int num;
            std::cout << "Enter number " << endl;
            std::cin >> num;
            First.append_at_last(num);
        }
        else
            break;
    }
    case 3:
    {
        std::cout << "Enter the index you want to delete: "
                  << "(Index starts from 0)" << endl;
        int n;
        std::cin >> n;
        First.delete_element(n);
        First.traverse_and_print();
        break;
    }
    case 4:
    {
        First.sort();
        First.traverse_and_print();
        break;
    }
    case 5:
    {
        std::cout << "Enter number to be searched in an array" << endl;
        int o;
        std::cin >> o;
        int a = First.linear_search(o);
        if (a == -1)
        {
            std::cout << "Element not found" << endl;
        }
        else
            std::cout << "Element found at : " << a << "th index" << endl;
        break;
    }
    case 6:
    {
        std::cout << "Enter number to be searched in an array" << endl;
        int o;
        std::cin >> o;
        int a = First.binary_search(o);
        if (a == -1)
        {
            std::cout << "Element not found" << endl;
        }
        else
            std::cout << "Element found at : " << a << "th index" << endl;
        break;
    }
    case 7:
    {
        int ck, kk;
        std::cout << "Enter the index at which you want to insert: " << endl;
        std::cin >> ck;
        std::cout << "Enter thr element you want to insert" << endl;
        std::cin >> kk;
        First.set_element(kk, ck);
        break;
    }
    case 8:
    {
        int index;
        std::cout << "Enter the index from which you get the element: " << endl;
        std::cin >> index;
        int p;
        p = First.get_element(index);
        std::cout << "The value of  " << index << "th element is " << p << endl;
        break;
    }
    case 9:
    {
        int num;
        num = First.min_element();
        std::cout << "Minimum in array is  " << num << endl;
        break;
    }
    case 10:
    {
        int k;
        k = First.max_element();
        std::cout << "Maximum in array is  " << k << endl;
        break;
    }
    case 11:
    {
        int sum;
        sum = First.sum_of_elements();
        std::cout << "Sum of all the elements is " << sum << endl;
        break;
    }
    case 12:
    {
        int avg;
        avg = First.sum_of_elements();
        std::cout << "Average of all the elements is " << avg << endl;
        break;
    }
    case 13:
    {
        First.rev_arr_new_arr();
        First.traverse_and_print();
        break;
    }
    case 14:
    {
        First.rev_arr();
        First.traverse_and_print();
        break;
    }
    case 15:
    {
        int numn, xx;
        std::cout << "Enter the index at which you want to insert: " << endl;
        std::cin >> xx;
        std::cout << "Enter the number you want to insert: " << endl;
        std::cin >> numn;
        First.insert_ele_in_sorted_arr(xx, numn);
        break;
    }
    case 16:
    {
        int nll;
        nll = First.check_sorted_or_not();
        if (nll)
        {
            std::cout << "Sorted array" << endl;
        }
        else
        {
            std::cout << "Array is not sorted" << endl;
        }
        break;
    }
    case 17:
    {
        First.shift_negative_num();
        First.traverse_and_print();
        break;
    }
    case 18:
        /*code */
        break;
    case 19:
        /*code */
        break;
    case 20:
        /*code */
        break;
    case 21:
        /*code */
        break;
    default:
        break;
    }
}
int main()
{
    array First;
    array Second;
    menu(First, Second);
    while (1)
    {
        std::cout << "Do you want to do any more operations?? " << endl;
        char ans;
        std::cin >> ans;
        if (ans=='y')
        {
            menu(First, Second);
        }
        else
        {
            exit(1);
        }
    }

    return 0;
}