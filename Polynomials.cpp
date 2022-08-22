#include <iostream>
using namespace std;
struct Polynomial
{
    int coeff;
    int exp;
};
// Polynomial representation using arrays
//  Addition of polynomials
int add(struct Polynomial P1[], struct Polynomial P2[], int h1, int h2)
{
    int h3;
    struct Polynomial P3[10];
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
        else if (P1[i].exp < P2[j].exp)
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
    h3 = k;
    return h3;
}
void display_polynomial(struct Polynomial P[], int h3)
{
    for (int i = 0; i < h3; i++)
    {
        cout << "Co-eff:" << P[i].coeff << "  Exp:" << P[i].exp << endl;
    }
}
int main()
{
    struct Polynomial P1[10], P2[10];
    int h1, h2, i;
    cout << "Enter the highest degree of polynomial 1" << endl;
    cin >> h1;
    cout << "Enter the highest degree of polynomial 2" << endl;
    cin >> h2;
    cout << "For Polynomial 1" << endl;
    for (i = 0; i < h1; i++)
    {
        cout << "Enter exponent : " << endl;
        cin >> P1[i].exp;
        cout << "Enter coefficient: " << endl;
        cin >> P1[i].coeff;
    }
    cout << "For Polynomial 2" << endl;
    for (i = 0; i < h1; i++)
    {
        cout << "Enter exponent : " << endl;
        cin >> P2[i].exp;
        cout << "Enter coefficient: " << endl;
        cin >> P2[i].coeff;
    }
    return 0;
}