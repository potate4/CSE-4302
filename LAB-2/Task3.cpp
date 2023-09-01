#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100;
class BankAccount
{
    private:
    int accountNo;
    string name;
    string type;
    double currentBalance;
    double minBalance;
    double interest = 3;
    vector <double> transactions;

    public:
    
        BankAccount()
        {

        }
        BankAccount(int n, string s, string t, double cb, double mb)
        {
            accountNo = n;
            name = s;
            type = t;
            currentBalance = cb;
            minBalance = mb;
        }
        void showBalance()
        {
            cout << "BALANCE IS: ";
            cout << currentBalance << endl;
        }
        void deposit(double amount)
        {
            currentBalance += amount;
            transactions.push_back(amount);
        }
        void withdraw(double amount)
        {
            if(currentBalance - amount < minBalance)
            {
                cout << "INVALID REQUEST" << endl;
            }
            else
            {
                currentBalance -= amount;
                transactions.push_back(-amount);
            } 
        }
        void giveInterest()
        {
            currentBalance -= (currentBalance * (10.0/100.0));
            currentBalance += (currentBalance * (interest/100.0));
        }
        void printAccountStatement()
        {
            cout << "TRANSACTIONS : " << endl;
            for(int i = 0; i < transactions.size(); i++)
            {
                cout << transactions[i] << endl;
            }
        }
        void appPentalty(int fee)
        {
            if(currentBalance < minBalance)
                currentBalance -= fee;  
        }
        ~BankAccount()
        {
            cout << "Account of " << name << " with account no " << accountNo << " is destroyed with a balance of BDT " << currentBalance << endl;
        }  
};
int main()
{
    BankAccount ac1(10, "A","savings", 100, 10), ac2(11, "B","savings", 200, 10), ac3(12, "C","savings", 200, 10);
    ac1.showBalance();
    ac1.deposit(200);
    ac1.showBalance();
    ac1.withdraw(20);
    ac1.showBalance();
    ac1.printAccountStatement();

    return 0;
}
