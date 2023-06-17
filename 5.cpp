#include <iostream>

double evaluate(double* coefficients, int num_power, double x)
{
    if(num_power < 0)
        return 0.0;

    double y = 1.0;
    double val = 0.0;
    for(int i = 0; i <= num_power; i++)
    {
        val += coefficients[num_power - i] * y;
        y *= x;
    }

    return val;
}

int main()
{
    int num_power;
    std::cout << "Please Enter Max Power of the expression : ";
    std::cin >> num_power;

    double* coefficients = new double[num_power + 1];

    for(int i = 0; i <= num_power; i++)
    {
        std::cout << "Please Enter coefficient for x^" << i << " : ";
        std::cin >> coefficients[num_power - i];
    }

    double x = 0.0;
    std::cout << "Please Enter value for x : ";
    std::cin >> x;

    std::cout << "Given Expression produces : "
              << evaluate(coefficients, num_power, x)
              << std::endl;

    delete[] coefficients;
    return 0;
}
