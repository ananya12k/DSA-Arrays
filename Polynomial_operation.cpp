#include <iostream>
using namespace std;
struct Polynomial
{
    int coeff;
    int exp;
};
// void display_polynomial(struct Polynomial P[], int k)
// {
// }
// Polynomial representation using arrays
//  Addition of polynomials
int add(struct Polynomial P1[], struct Polynomial P2[], struct Polynomial P3[], int h1, int h2)
{
    int i, j, k;
    i = j = k = 0;
    while (i < h1 && j < h2)
    {
        if (P1[i].exp < P2[j].exp)
        {
            P3[k].coeff = P2[j].coeff;
            P3[k].exp = P2[j].exp;
            j++;
            k++;
        }
        else if (P1[i].exp > P2[j].exp)
        {
            P3[k].coeff = P1[i].coeff;
            P3[k].exp = P1[i].exp;
            i++;
            k++;
        }
        else
        {
            P3[k].coeff = P1[i].coeff + P2[j].coeff;
            P3[k].exp = P1[i].exp;
            i++;
            j++;
            k++;
        }
    }
    while (i < h1)
    {
        P3[k].coeff = P1[i].coeff;
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
    return k;
}
int multiply(struct Polynomial P1[], struct Polynomial P2[], struct Polynomial P3[], int h1, int h2)
{
    int next3, j, k, i, flag;
    int ex, co;
    i = next3 = 0;
    while (i < h1)
    {
        j = 0;
        while (j < h2)
        {
            ex = P1[i].exp + P2[j].exp;
            co = P1[i].coeff * P2[j].coeff;
            k = flag = 0;
            while (k < next3 && !flag)
            {
                if (P3[k].exp == ex)
                {
                    flag = 1;
                    break;
                }
                else
                    k++;
            }

            if (flag == 1)
                P3[k].coeff = P3[k].coeff + co;
            else
            {
                P3[next3].exp = ex;
                P3[next3].coeff = co;
                next3++;
            }
            j++;
        }
        i++;
    }
    return next3;
}
int main()
{
    struct Polynomial P1[10], P2[10], P3[10];
    int h1, h2, i;
    cout << "Enter no of terms in polynomial 1" << endl;
    cin >> h1;
    cout << "Enter no of terms in polynomial 2" << endl;
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
    int t = add(P1, P2, P3, h1, h2);
    cout << "Resultant Polynomial Sum: " << endl;
    for (int i = 0; i < t; i++)
    {
        cout << "Exp:" << P3[i].exp << "  Co-eff:" << P3[i].coeff << endl;
    }
    int p = multiply(P1, P2, P3, h1, h2);
    cout << "Resultant Polynomial product: " << endl;
    for (int i = 0; i < p; i++)
    {
        cout << "Exp:" << P3[i].exp << "  Co-eff:" << P3[i].coeff << endl;
    }
    return 0;
}