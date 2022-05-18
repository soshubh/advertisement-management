#include <bits/stdc++.h>
using namespace std;

// Abstract class Product
class Product
{
protected:
    string type;
    string name;
    string companyName;
    string tagLine;
    double price;
    int quantity;

public:
    Product()
    {
        price = 0, quantity = 0;
    }
    virtual void setCompanyName(string s) = 0;
    virtual void setTagLine(string s) = 0;
    virtual void checkout() = 0;
    virtual void setQuantity(int n) = 0;
    virtual double getPrice() = 0;
};

// Classes of Social Media

// Instagram ad revenues
// Merket Price : Rs. 8K per 10K impressions
class Instagram : protected Product
{
public:
    Instagram() : Product()
    {
        name = "Instagram";
        type = "Social Media";
    }

    void setCompanyName(string s)
    {
        companyName = s;
    }

    void setTagLine(string s)
    {
        tagLine = s;
    }

    void checkout()
    {
        cout << "Type: " << type << endl;
        cout << "Name: " << name << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Tagline: " << tagLine << endl;

        cout << "Quantity: " << quantity << endl;
        cout << fixed << setprecision(2) << "Price: Rs." << price << endl;
    }

    void setQuantity(int n)
    {
        quantity = quantity + n;
        price = price + 8000 * n;
    }

    double getPrice()
    {
        return price;
    }
};

// Facebook ad revenues
// Merket Price : Rs. 9K per 10K impressions
class Facebook : protected Product
{
public:
    Facebook() : Product()
    {
        name = "Facebook";
        type = "Social Media";
    }

    void setCompanyName(string s)
    {
        companyName = s;
    }

    void setTagLine(string s)
    {
        tagLine = s;
    }

    void checkout()
    {
        cout << "Type: " << type << endl;
        cout << "Name: " << name << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Tagline: " << tagLine << endl;

        cout << "Quantity: " << quantity << endl;
        cout << fixed << setprecision(2) << "Price: Rs." << price << endl;
    }

    void setQuantity(int n)
    {
        quantity = quantity + n;
        price = price + 9000 * n;
    }

    double getPrice()
    {
        return price;
    }
};

// Youtube ad revenues
// Merket Price : Rs. 9K per 1K impressions
class Youtube : protected Product
{
public:
    Youtube() : Product()
    {
        name = "Youtube";
        type = "Social Media";
    }

    void setCompanyName(string s)
    {
        companyName = s;
    }

    void setTagLine(string s)
    {
        tagLine = s;
    }

    void checkout()
    {
        cout << endl
             << "Type: " << type << endl;
        cout << "Name: " << name << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Tagline: " << tagLine << endl;

        cout << "Quantity: " << quantity << endl;
        cout << fixed << setprecision(2) << "Price: Rs." << price << endl;
    }

    void setQuantity(int n)
    {
        quantity = quantity + n;
        price = price + 9000 * n;
    }

    double getPrice()
    {
        return price;
    }
};

// Main function
int main()
{

    // Vector products to store items in cart
    vector<Product *> products;
    Product *p;
    string companyName, companyTagLine;

    cout << "Welcome to Nub Ad Agency" << endl
         << endl;
    cout << "We provide marketing services to help grow you and your company" << endl
         << endl;

    cout << "Let's get to know you" << endl;
    cout << "Enter Company's Name: " << endl;
    getline(cin, companyName);
    cout << "Enter Company's Tag Line : " << endl;
    getline(cin, companyTagLine);
    cout << endl;

    int packageLoopControl = 1;
    while (packageLoopControl)
    {

        cout << "Here are the Packages we offer: " << endl
             << endl;
        cout << "1. View Social Media Marketing Package" << endl;
        cout << "4. Checkout/Bill Payment" << endl;
        cout << "5. Exit" << endl
             << endl;
        cout << "Enter choice: ";
        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {

            int socialMediaLoopControl = 1;
            while (socialMediaLoopControl)
            {
                cout << endl
                     << "Welcome to the social media marketing package." << endl
                     << endl;
                cout << "Here are the following deals you can grab: " << endl
                     << endl;
                cout << "1. Instagram deal" << endl;
                cout << "Rs. 8,000 per 10,000 impressions" << endl
                     << endl;

                cout << "2. Meta (Facebook) deal" << endl;
                cout << "Rs. 9,000 per 10,000 impressions" << endl
                     << endl;

                cout << "3. Youtube deal" << endl;
                cout << "Rs. 9,000 per 1,000 impressions" << endl
                     << endl;

                cout << "Which deal are you interested in? " << endl
                     << "(Press 0 to go back)" << endl
                     << "Enter choice: ";

                int choice;
                cin >> choice;

                switch (choice)
                {
                case 1:
                {

                    int quantity = 0;
                    cout << "Enter quantity: ";
                    cin >> quantity;

                    Instagram *s = new Instagram();

                    p = (Product *)s;

                    p->setCompanyName(companyName);
                    p->setTagLine(companyTagLine);
                    p->setQuantity(quantity);

                    cout << endl;
                    p->checkout();
                    products.push_back(p);
                }
                break;
                case 0:
                    socialMediaLoopControl = 0;
                    break;
                default:
                    cout << "Seems like you have enterted an invalid choice.\nPlease try again..." << endl;
                    break;
                }
            }
        }
        break;
        case 4:
        {
            cout << endl
                 << "Loading Bill Receipt.." << endl
                 << endl;

            if (products.size() == 0)
                cout << endl
                     << "Cart is empty. Please enter some items." << endl
                     << endl;
            else
            {

                double totalPrice = 0;
                int itemsCount = 0;

                for (int i = 0; i < products.size(); i++)
                {

                    cout << "Item " << i + 1 << " - " << endl
                         << endl;
                    Product *p = products[i];
                    p->checkout();
                    cout << endl;

                    totalPrice = totalPrice + p->getPrice();
                    itemsCount++;
                }

                cout << endl
                     << "Total Items: " << itemsCount << endl
                     << endl;
                cout << endl
                     << fixed
                     << setprecision(2) << "Total amount: Rs. " << totalPrice << endl;

                int checkoutLoopControl = 1;
                while (checkoutLoopControl)
                {

                    cout << endl
                         << "1. Buy and Exit" << endl;
                    cout << "2. Add more Products to cart" << endl;
                    cout << "3. Delete Items from cart" << endl;
                    cout << "4. Go Back" << endl;
                    cout << "Enter choice: ";
                    int checkoutChoice;
                    cin >> checkoutChoice;

                    switch (checkoutChoice)
                    {
                    case 1:
                        packageLoopControl = 0, checkoutLoopControl = 0;
                        cout << endl
                             << "Order confirmed. Thanks for choosing us." << endl
                             << endl;
                        break;
                    case 2:
                        checkoutLoopControl = 0;
                        break;
                    case 3:
                    {
                        int deleteItemIndex;
                        cout << endl
                             << "Which item would you like to delete? : ";
                        cin >> deleteItemIndex;

                        deleteItemIndex--;
                        if (deleteItemIndex >= 0 && deleteItemIndex < products.size())
                        {
                            vector<Product *>::iterator it;
                            it = products.begin() + deleteItemIndex;

                            products.erase(it);

                            cout << endl
                                 << "Item has been deleted" << endl
                                 << endl;
                        }
                        else
                            cout << "Invalid item number. \nPlease try again..." << endl
                                 << endl;

                        checkoutLoopControl = 0;
                    }
                    break;
                    case 4:
                        checkoutLoopControl = 0;
                        break;
                    default:
                        cout << "Seems like you have enterted an invalid choice.\nPlease try again..." << endl;
                        break;
                    }
                }
            }
        }

        break;
        case 5:
            packageLoopControl = 0;
            cout << endl
                 << "Hope we could be of help. Thanks for considering us." << endl
                 << endl;
            break;
        default:
            cout << endl
                 << "Seems like you have enterted an invalid choice.\nPlease try again..." << endl
                 << endl;
            break;
        }
    }

    // De allocating
    for (int i = 0; i < products.size(); i++)
        delete products[i];

    return 0;
}