#include<bits/stdc++.h>
using namespace std;

class User {
public:
    string name;
    string address;
    long long phone;
    string custId;
    long long balance;

    User(string name, string address, long long phone, string custId) {
        this->name = name;
        this->address = address;
        this->phone = phone;
        this->custId = custId;
        this->balance = 0;
    }
};

class Bank {
public:
    vector<User> users;

    void addCustomer(User u) {
        for (auto& i : users) {
            if (i.phone == u.phone) {
                cout << "User already exists" << endl;
                return;
            }
        }
        users.push_back(u);
        cout << "Thank you for joining us" << endl;
    }

    void deposit(string custId, long long amount) {
        for (auto& i : users) { 
            if (i.custId == custId) {
                i.balance += amount;
                cout << "Deposited successfully" << endl;
                return;
            }
        }
        cout << "Account not found" << endl;
    }

    void withdrawal(string custId, int amount) {
        for (auto& i : users) { 
            if (i.custId == custId) {
                if (i.balance >= amount) {
                    i.balance -= amount;
                    cout << "Withdrawal successful" << endl;
                    return;
                } else {
                    cout << "Insufficient balance" << endl;
                    return;
                }
            }
        }
        cout << "Account not found" << endl;
    }

    void details(string custId) {
        for (auto& i : users) { 
            if (i.custId == custId) {
                cout << "Name: " << i.name << " Address: " << i.address << " Phone: " << i.phone << " Balance: " << i.balance << endl;
                return;
            }
        }
        cout << "User does not exist" << endl;
    }
};

int main() {
    Bank B;
    cout << "Welcome to ABC Bank" << endl;
    while (true) {
        cout << "Press 1 for New customer" << endl << "Press 2 for Existing customer" << endl;
        int n;
        cin >> n;
        if (n == 1) {
            cout << "Enter Name of customer" << endl;
            string str;
            cin >> str;
            cout << "Enter Address of customer" << endl;
            string addr;
            cin >> addr;
            cout << "Enter Phone of customer" << endl;
            long long ph;
            cin >> ph;
            cout << "Enter CustID of customer" << endl;
            string custid;
            cin >> custid;
            User u(str, addr, ph, custid);
            B.addCustomer(u);
        } else {
            cout << "Enter Customer ID" << endl;
            string cus;
            cin >> cus;
            cout << "Press 1 for Deposit" << endl << "Press 2 for Withdrawal" << endl << "Press 3 for Details" << endl;
            int a;
            cin >> a;
            if (a == 1) {
                cout << "Enter amount to deposit" << endl;
                long long amt;
                cin >> amt;
                B.deposit(cus, amt);
            } else if (a == 2) {
                cout << "Enter amount to withdraw" << endl;
                int amt;
                cin >> amt;
                B.withdrawal(cus, amt);
            } else {
                B.details(cus);
            }
        }
    }
    return 0;
}
