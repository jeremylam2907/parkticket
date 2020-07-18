#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;


int AgeDiscount = 0; //Reduce price for minor        {  to be used later in Price() and Discount()  }
int SeniorDiscount = 0; //Reduce price for senior    {  to be used later in Price() and Discount()  }

int GuestEnter() //Enters the name and age
{

    string Firstname;
    string Lastname;
    double Age;

    cout << "\n\nFirst Name: ";
    cin >> Firstname;
    cout << "Last Name: ";
    cin >> Lastname;
    cout << "Age: ";
    cin >> Age;
    if (Age < 18 && Age >= 0) // Number of minors saved to AgeDiscount to give a discount later
    {
        ++AgeDiscount;
    }
    else if (Age > 60 && Age <= 100)
    {
        ++SeniorDiscount;
    }
    


    return ( Age > 100 || Age < 0)? 1 : 0; // Invalid age, re -enter
    
}

void Logo()
{
    cout << "        ___________________________________\n";
    cout << "       |                                   |\n";
    cout << "       |          PARK   CHECK-IN          |\n";
    cout << "       |___________________________________|\n";
    cout << "       |                                   |\n";
    cout << "       |ADULTS ________________________ $50|\n";
    cout << "       |                                   |\n";
    cout << "       |CHILDREN (younger than 18)_____ $20|\n";
    cout << "       |                                   |\n";
    cout << "       |SENIORS (over 60)______________ $30|\n";
    cout << "       |___________________________________|\n\n\n";
}

void Price(int PricePerNight) //The total price and minor discount without coupon
{
    double PerVisit = PricePerNight*50 - 30*AgeDiscount - 20*SeniorDiscount;
    cout << "\n\n       The total is: " << "$" << PerVisit;
    if (AgeDiscount > 0 && SeniorDiscount >0)
    {
        cout << " including senior and children discount.";
    }
    else if (AgeDiscount > 0 && SeniorDiscount == 0)
    {
        cout << " including children discount.";
    }
    else if (AgeDiscount == 0 && SeniorDiscount > 0)
    {
        cout << " including senior discount.";
    }
}

void Discount(int FinalPrice, int PreDiscount) //The final price with coupon
{
    cout << setprecision(3);
    double NetPrice = (1-FinalPrice*0.01)*(PreDiscount*50 - 30*AgeDiscount - 20*SeniorDiscount);
    // *(BeforeDisc*50 - 30*AgeDiscount);
    cout << NetPrice;
}

int main()
{
    Logo(); //Display logo


        //Number of Guests
    int GuestNum;
    cout << "       How many Guests are checking in?\n";
    cin >> GuestNum;


        //Enter Guest information loop
    int i = 1;
    while( i <= GuestNum)
    {
        // GuestEnter();
        if (GuestEnter() == 1)
        {
            cout << "\n       Invalid age, please re-enter\n\n";
        }
        else
        {
            ++i;
        }
        
    }

    cout << endl << endl << "       There will be " << GuestNum - AgeDiscount - SeniorDiscount << " adult(s) and " << AgeDiscount << " child(s) and " << SeniorDiscount << " senior(s).";  


    Price(GuestNum);    


            //Discount Price
    cout << "\n\n       Do you have any discount voucher?\n";
    cout << "       Please type [yes] or [y] or [Yes] or [Y] only if you have it. \n";
    string Net;
    cin >> Net;
    int D;
    

    if ( Net == "yes" || Net == "y" || Net == "Yes" || Net == "Y")
    {
        
        cout << "       Enter the discount in percent\n";
        int NetPrice;
        cin >> NetPrice;
        cout << "\n\n\n     Applied, the final price now is: $ ";
        Discount(NetPrice, GuestNum); //Pass argument
        cout << endl << endl;
        cout << "       [<<<        HAVE AN AMAZING DAY IN THE MAGICAL WORLD OF XYZ PARK        >>>]\n\n\n\n\n\n\n";
    }
    
    system ("pause");
}
