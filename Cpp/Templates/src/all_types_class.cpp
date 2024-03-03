#include <algorithm>

template<class T>
struct test_templates {

    T type_T(T value) {
        return value;
    }

    T type_const_T(const T value) {
        return value;
    }

    T type_T_ref(T &value) {
        return value;
    }

    T type_const_T_ref(const T &value) {
        return value;
    }

    T type_T_ref_ref(T &&value) {
        return value;
    }

    T type_const_T_ref_ref(const T &&value) {
        return value;
    }
};

int main() {
    auto test = test_templates<int>();
    int lvalue = 10;
    const int const_lvalue = 10;

    test.type_T(lvalue);
    test.type_T(const_lvalue);
    test.type_T(10);
    test.type_T(std::move(lvalue));

    test.type_const_T(lvalue);
    test.type_const_T(const_lvalue);
    test.type_const_T(10);
    test.type_const_T(std::move(lvalue));

    test.type_T_ref(lvalue);
    test.type_T_ref(const_lvalue);
    test.type_T_ref(10);
    test.type_T_ref(std::move(lvalue));

    test.type_const_T_ref(lvalue);
    test.type_const_T_ref(const_lvalue);
    test.type_const_T_ref(10);
    test.type_const_T_ref(std::move(lvalue));

    test.type_T_ref_ref(lvalue);
    test.type_T_ref_ref(const_lvalue);
    test.type_T_ref_ref(10);
    test.type_T_ref_ref(std::move(lvalue));

    test.type_const_T_ref_ref(lvalue);
    test.type_const_T_ref_ref(const_lvalue);
    test.type_const_T_ref_ref(10);
    test.type_const_T_ref_ref(std::move(lvalue));

    return 0;
}
