#include <iostream>
#include <vector>

//recursion function
void __withRepetition(const char* set, int num_items, char* characters, int level)
{
    for(int i = 0; i < num_items; i++)
    {
        characters[level] = set[i];

        if(level < num_items - 1){
            __withRepetition(set, num_items, characters, level + 1);
            continue;
        }

        for(int j = 0; j < num_items; j++)
            std::cout << characters[j];

        std::cout << std::endl;
    }
}

void __withoutRepetition(const char* set, int num_items, std::vector<bool>& isUsed, char* characters, int level)
{
    for(int i = 0; i < num_items; i++)
    {
        if(isUsed[i])
            continue;

        characters[level] = set[i];
        isUsed[i] = true;

        if(level < num_items - 1){
            __withoutRepetition(set, num_items, isUsed, characters, level + 1);
            isUsed[i] = false;
            continue;
        }

        isUsed[i] = false;

        for(int j = 0; j < num_items; j++)
            std::cout << characters[j];

        std::cout << std::endl;
    }
}

//user facing functions
void withRepetition(const char* set, int num_items)
{
    if(num_items < 1)
        return;

    //to pass values between functions
    char* characters = new char[num_items];

    __withRepetition(set, num_items, characters, 0);
    delete[] characters;
}

void withoutRepetition(const char* set, int num_items)
{
    if(num_items < 1)
        return;

    char* characters = new char[num_items];

    //stores whether the character has already been used
    std::vector<bool> isUsed(num_items, false);

    __withoutRepetition(set, num_items, isUsed, characters, 0);
    delete[] characters;
}

int main()
{
    std::cout << "With Repetition : \n";
    withRepetition("abc", 3);

    std::cout << "\n\n";
    std::cout << "Without Repetition : \n";
    withoutRepetition("abc", 3);

    return 0;
}
