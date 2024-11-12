///      Code optimizations
///Describe how (and –bonus– why) would you optimize the following code sections:

#include <iostream>

using namespace std;

///structura A si B sunt identice deci pastram doar una
///structura nu este folosita deci o eliminam

///inlocuim apeluri ne necesare de functii si reducem nr de caseuri
/// cobinam toate functiile de switch

void MaxFValueIntervals(double dB)///am eliminat variabilele inutile
{
    //maximum of the function (x*x + y*y)/(y*y +4y + b)

    if (dB <= 0) return;
    if (dB > 1000) return;

    //This is the potential maximum value of the function
    //and all other values could be bigger or smaller
    double dMaximumValue = 2/(1+dB/10000);

    double dMaximumX = -100;
    double dMaximumY = -100;

    for (double dX = -100; dX <= 100; dX += 1.0)
        for (double dY = -100; dY <= 100; dY += 1.0)
            if (dMaximumValue < ((dX * dX + dY * dY) / (dY * dY + 4 * dY + dB)))
            {
                dMaximumValue = ((dX * dX + dY * dY) / (dY * dY + 4 * dY + dB));
                dMaximumX = dX;
                dMaximumY = dY;
            }

    cout << "Maximum value of the function is=" << dMaximumValue << endl;
    cout << endl << endl;
    cout << "Value for x=" << dMaximumX << endl
         << "Value for y=" << dMaximumY << endl;
}

void CodeOptimization()
{
     cout << "f1 called\nf1 called\nf1 called\n";
    ///eliminam functia switch afisand doar rezultatul ei final

    for (int i = 0; i < 100; i++)
    {
      cout<<i<<'\n';
            ///fy face doar cout << i
    }///se va afisa i indiverent de natura lui

    ///punem direct counter pe 100 fara for si il eliminam fiindca nu e folosit

        cout << "12345678910\n"; ///fx face doar cout << i
        ///am inlocuit forul cu stringul adegvat

    MaxFValueIntervals(3.2);
}

int main()
{
    CodeOptimization();
    return 0;
}
