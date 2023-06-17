#include <iostream>

void brute(int sum, int num_vars, int *values, int cur_sum, int level)
{
    for(int i = 0; i < sum; i++)
    {
        values[level] = i;

        if(level < num_vars - 1){
            brute(sum, num_vars, values, cur_sum + i, level + 1);
            continue;
        }

        if(cur_sum + i == sum){
            std::cout << values[0];
            for(int j = 1; j < num_vars; j++)
                std::cout << " + " << values[j];

            std::cout << " = " << sum << std::endl;
            return;
        }
    }
}

void brute_force(int sum, int num_vars)
{
    if(num_vars < 0)
        return;

    if(num_vars >= 32)
        throw std::runtime_error("More than 31 variables not allowed");

    if(sum < 0)
        return;

    int* values = new int[num_vars];
    brute(sum, num_vars, values, 0, 0);
    delete[] values;
}

int main()
{
    try{
        brute_force(7,5);
    }catch(std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
