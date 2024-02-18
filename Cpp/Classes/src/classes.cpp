#include <iostream>

class Id {
    // public члены класса доступны в любой части кода
public:
    // Конструктор по умолчанию
    Id() {
        value_ = defaultValue;
        counter++;
    }

    // explicit отключает автоматическое преобразование типа для этого конструктора
    explicit Id(int value) : value_(value) {
        value_ = value;
        counter++;
        // this->value_ = value; // Можно и через указатель this
    }

    inline static int counter = 0;
    static void print() {
        counter++;
    }

    int getValue() const {
        return value_;
    }

    void setValue(int value) {
        value_ = value;
    }

    ~Id () {
        counter--;
    }

    // Доступ к protected членам класса имеют только наследники
protected:
    int value_ = 0;

    // Доступ к private членам класса закрыт для всех вне этого класса (кроме friend функций и friend классов)
private:
    int defaultValue = 0;
};

int main() {
    using namespace std;

    Id id1(1);
//    Id::counter = 0;
    // Скопируется объект, не его ссылка! (Компилятор автоматически генерирует оператор присваивания =)
    cout << Id::counter << endl;
    {
        Id id2(1);
        id1.setValue(2);
        cout << Id::counter << endl;
    }
    cout << Id::counter << endl;
    cout << "id1.getValue() = " << id1.getValue() << endl;
//    cout << "id2.getValue() = " << id2.getValue() << endl;

    return 0;
}
