#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

ios_base::fmtflags cout_base_flags(std::cout.flags());

void zad1()
{
    float x=0, y=0;
    cout << "Wprowadz 2 liczby\nx:";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << setprecision(2)<<fixed;
    cout << "x+y=" << x + y
        << "\nx-y=" << x - y
        << "\nx*y=" << x * y
        << "\nx/y=" << x / y << "\n\n";

    cout.flags(cout_base_flags); //reset flags
}

void zad2()
{
    cout << "t wylacza petle\n";
    char letter = 0;
    while (letter != 't')
    {
        cin >> letter;
        cout << letter;
    }

    cout << "End zad2\n\n";
}

void zad3()
{
    double a = 0, b = 0, c = 0;
    cout << "Wpisz rownanie kwadratowe ax^2 + bx + c\n";
    cout << "a=";
    cin >> a;
    if (a == 0)
    {
        cout << "Podane rownanie nie jest rownaniem kwadratowym\n"
            << "a=0\n\n";
        return;
    }

    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;


    cout << "Twoja funkcja kwadratowa:\n";
    cout << a << "x^2";
    if (b != 0)
        cout << (b > 0 ? "+" : "") << b<<"x";
    if (c != 0)
        cout << (c > 0 ? "+" : "") << c << "\n";

    double delta = pow(b, 2) -(4 * a * c);

    if (delta > 0)
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\n"
            << "x2 = " << (-b - sqrt(delta)) / (2 * a) << "\n\n";
    else if (delta == 0)
        cout << "x0 = " << -b / (2 * a) << "\n\n";
    else
        cout << "Funkcja kwadratowa nie ma miejsc zerowych\n\n";

}

long int factorial(const unsigned int& num)
{
    long int output = 1;
    for (int x = 1; x <= num; x++)
        output *= x;

    return output;
}

/// <summary>
/// calculates binomial coefficient
/// </summary>
/// <returns>biomial coefficient or -1 if parameters are wrong</returns>
long int binomial_coeff(const long& n, const long& k)
{
    if (n < k)
        return -1;

    return factorial(n) / (factorial(k) * factorial(n - k));
}

void zad4()
{
    unsigned int row_count = 0;
    cout << "Podaj ilosc wierszy w twoim trojkacie pascala: ";
    cin >> row_count;
    //jesli uzytkownik wpisze ujemna liczbe, to nastapi przeciazenie i pojawi sie duza liczba, dlatego ograniczamy do 50 maks
    if (row_count > 50)
    {
        cout << "Probojesz zrobic zbyt wielki trojakt!";
        return;
    }

    int actual_row = 0;
    int col= 0;

    int width = row_count;

    while (actual_row < row_count+1)
    {
        int spaces = (width - actual_row);
        for (int x = 0; x < spaces; x++)
            cout << " ";

        while (col <= actual_row)
            cout << binomial_coeff(actual_row, col++) << " ";

        cout << "\n";
        actual_row++;
        col = 0;
    }
}


int main()
{
    zad1();
    zad2();
    zad3();
    zad4();
}