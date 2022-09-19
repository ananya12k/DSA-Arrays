#include <iostream>
using namespace std;
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void quickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int p = a[left];
        int i = left;
        int j = right + 1;

        do
        {
            do
            {
                i++;
            } while (p > a[i]);
            do
            {
                j--;
            } while (p < a[j]);
            if (i < j)
                swap(a, i, j);

            if (i > j)
                swap(a, left, j);
            for (int i = 0; i < 8; i++)
                cout << a[i] << "  ";
            cout << endl;

        } while (i < j);
        if (i >= j)
        {
            quickSort(a, left, j - 1);
            quickSort(a, j + 1, right);
        }
    }
    for (int i = 0; i < 8; i++)
        cout << a[i] << "  ";
    cout << endl;
}

int main()
{
    int a[] = {5, 4, 6, 3, 0, 3, 1, 0};
    quickSort(a, 0, 7);
    // swap(a,1,4);
    for (int i = 0; i < 8; i++)
        cout << a[i] << "  ";

    return 0;
}