#include <iostream>
#include <vector>
using namespace std;

class Bank
{
private:
    string name[10];
    string address[10];
    string city[10];
    string postalCode[10];
    double accBal[10];
    double dep[10];
    double extract[10];

public:
    Bank()
    {
        for (int i = 0; i < 10; i++)
        {
            accBal[i] = 0.0;
        }
    }

    void getCustomerData(int i)
    {
        cout << "Welcome to Simple Bank:\n";
        cout << " _________________ \n";
        cout << "                  \n";
        cout << "   SIMPLE BANK     \n";
        cout << "    _________    \n";
        cout << "                 \n";
        cout << "      $$$$$      \n";
        cout << "    _________    \n";
        cout << " _______________ \n";
        cout << " ||||||||||||||||| \n";
        cout << " |_______________| \n";

        cout << "\nInput name of customer #" << i + 1 << ":\n";
        getline(cin, name[i]);

        cout << "\nInput address of customer #" << i + 1 << ":\n";
        getline(cin, address[i]);

        cout << "\nInput city of customer #" << i + 1 << ":\n";
        getline(cin, city[i]);

        bool isValid = false;
        do
        {
            cout << "\nInput postal code of customer #" << i + 1 << " (format A1B2C3):\n";
            getline(cin, postalCode[i]);

            if (postalCode[i].length() == 6 &&
                ((postalCode[i][0] >= 'A' && postalCode[i][0] <= 'Z') || (postalCode[i][0] >= 'a' && postalCode[i][0] <= 'z')) &&
                (postalCode[i][1] >= '0' && postalCode[i][1] <= '9') &&
                ((postalCode[i][2] >= 'A' && postalCode[i][2] <= 'Z') || (postalCode[i][2] >= 'a' && postalCode[i][2] <= 'z')) &&
                (postalCode[i][3] >= '0' && postalCode[i][3] <= '9') &&
                ((postalCode[i][4] >= 'A' && postalCode[i][4] <= 'Z') || (postalCode[i][4] >= 'a' && postalCode[i][4] <= 'z')) &&
                (postalCode[i][5] >= '0' && postalCode[i][5] <= '9'))
            {
                isValid = true;
            }
            else
            {
                cout << "Invalid postal code format! Please enter in the format A1B2C3.\n";
            }
        } while (!isValid);

        cout << "\nInput opening balance of customer #" << i + 1 << ":\n";
        cin >> accBal[i];
        cin.ignore();
    }

    void deposit(int i)
    {
        cout << "\nHello Customer #" << i + 1
             << ", how much would you like to deposit into account name: "
             << name[i] << " with a balance of: " << accBal[i] << "\n";
        cin >> dep[i];
        accBal[i] += dep[i];
    }

    void withdraw(int i)
    {
        cout << "\nHello Customer #" << i + 1
             << ", how much would you like to withdraw from account name: "
             << name[i] << " with a balance of: " << accBal[i] << "\n";
        cin >> extract[i];
        if (extract[i] > accBal[i])
        {
            cout << "Insufficient funds, withdrawal was unsuccessful!\n";
        }
        else
        {
            accBal[i] -= extract[i];
        }
    }

    void showData(int i)
    {
        cout << "\nThe name of customer " << i + 1 << ": " << name[i];
        cout << "\nThe address of customer " << i + 1 << ": " << address[i];
        cout << "\nThe city of customer " << i + 1 << ": " << city[i];
        cout << "\nThe postal code of customer " << i + 1 << ": " << postalCode[i];
        cout << "\nThe updated balance of the customer " << i + 1 << ": " << accBal[i] << "\n";
    }

    void showMenu(int i)
    {
        int userans;
        do
        {
            cout << "\nCustomer #" << i + 1 << ", pick one of the following options:\n";
            cout << "1. Deposit Money\n2. Withdraw Money\n3. View Updated Account\n4. Complete Operations\n";
            cin >> userans;
            cin.ignore();

            switch (userans)
            {
            case 1:
                deposit(i);
                break;
            case 2:
                withdraw(i);
                break;
            case 3:
                showData(i);
                break;
            case 4:
                system("clear");
                cout << "Customer #" << i + 1 << ". Thank you for using Simple Bank.\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
                break;
            }
        } while (userans != 4);
    }

    void Customers()
    {
        for (int i = 0; i < 10; i++)
        {
            getCustomerData(i);
            showMenu(i);
        }
    }
};

int main()
{
    Bank obj;
    obj.Customers();

    cout << "Thank you for using Simple Bank. Goodbye!\n";

    return 0;
}
