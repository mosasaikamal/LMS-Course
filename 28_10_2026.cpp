#include <iostream>
using namespace std;

class BaseAccountClass {
public:
    virtual void SendMoney() {
        cout << "Money sent successfully." << endl;
    }

    virtual void ReceiveMoney() {
        cout << "Money received successfully." << endl;
    }

    virtual ~BaseAccountClass() {}
};

class ConsumerAccountClass : public BaseAccountClass {
private:
    bool flagged;

public:
    ConsumerAccountClass(bool status) {
        flagged = status;
    }

    void SendMoney() override {
        if (flagged)
            cout << "Permission Denied: Account is flagged. Cannot send money." << endl;
        else
            cout << "Money sent successfully." << endl;
    }

    void ReceiveMoney() override {
        if (flagged)
            cout << "Permission Granted: Money can be received." << endl;
        else
            cout << "Money received successfully." << endl;
    }
};

int main() {
    BaseAccountClass* account;
    ConsumerAccountClass consumer(true);

    account = &consumer;

    account->SendMoney();
    account->ReceiveMoney();

    return 0;
}
 give me another way
