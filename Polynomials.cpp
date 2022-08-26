#include <iostream>
using namespace std;
struct Polynomial
{
    int coeff;
    int exp;
} P1[10], P2[10], P3[10];
// void display_polynomial(struct Polynomial P[], int k)
// {
// }
// Polynomial representation using arrays
//  Addition of polynomials
void add(struct Polynomial P1[], struct Polynomial P2[], int h1, int h2)
{
    int i, j, k;
    i = j = k = 0;
    while (i < h1 && j < h2)
    {
        if (P1[i].exp == P2[j].exp)
        {
            P3[k].coeff = P1[i].exp + P2[j].exp;
            P3[k].exp = P1[i].exp;
            i++;
            j++;
            k++;
        }

        else if (P1[i].exp > P2[j].exp)
        {
            P3[k].coeff = P1[i].exp;
            P3[k].exp = P1[i].exp;
            i++;
            k++;
        }
        else
        {
            P3[k].coeff = P2[j].exp;
            P3[k].exp = P2[j].exp;
            j++;
            k++;
        }
    }
    while (i < h1)
    {
        P3[k].coeff = P1[i].exp;
        P3[k].exp = P1[i].exp;
        i++;
        k++;
    }
    while (j < h2)
    {
        P3[k].coeff = P2[j].exp;
        P3[k].exp = P2[j].exp;
        j++;
        k++;
    }
    cout << "Resultant Polynomial: " << endl;
    for (int i = 0; i <= k; i++)
    {
        cout << "Co-eff:" << P3[i].coeff << "  Exp:" << P3[i].exp << endl;
    }
}
int main()
{
    int h1, h2, i;
    cout << "Enter the highest degree of polynomial 1" << endl;
    cin >> h1;
    cout << "Enter the highest degree of polynomial 2" << endl;
    cin >> h2;
    cout << "For Polynomial 1" << endl;
    for (i = 0; i <= h1; i++)
    {
        cout << "Enter exponent : " << endl;
        cin >> P1[i].exp;
        cout << "Enter coefficient: " << endl;
        cin >> P1[i].coeff;
    }
    cout << "For Polynomial 2" << endl;
    for (i = 0; i <= h1; i++)
    {
        cout << "Enter exponent : " << endl;
        cin >> P2[i].exp;
        cout << "Enter coefficient: " << endl;
        cin >> P2[i].coeff;
    }
    add(P1, P2, h1, h2);
    return 0;
}