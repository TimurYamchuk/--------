#include <iostream>
#include <string>

using namespace std;

class Action {
public:
    virtual void Perform() = 0;
};

class Parrot : public Action {
public:
    void Perform() override {
        cout << "Попугай: Привет!" << endl;
    }
};

class Airplane : public Action {
public:
    void Perform() override {
        cout << "Самолет: Полетели!" << endl;
    }
};

void PerformAction(Action* action) {
    action->Perform();
}

int main() {
    Parrot parrot;
    Airplane airplane;

    cout << "Вызов функции с объектом Попугая:" << endl;
    PerformAction(&parrot);

    cout << "\nВызов функции с объектом Самолета:" << endl;
    PerformAction(&airplane);

    return 0;
}
