#include "functional_tests.h"

int main()
{
    exponentialFunctionalTest();
    logisticalFunctionalTest();
    complexFunctionalTest();

    cout << endl << "\033[42mAll functional tests passed!\033[0m" << endl;

    return 0;
};