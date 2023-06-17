#include <iostream>
#include <vector>
#include <array>
#include <algorithm>    //for std::sort
#include <utility>  //for std::pair
#include <limits>

template <typename T>
class SET{
    std::vector<T> elements;

    //binary search
    int find(T item)
    {
        int l = 0;  //lower bound
        int u = elements.size() - 1;  //upper bound

        while (l <= u) {
            int m = l + (u - l) / 2;    //mid element

            if (elements[m] == item)
                return m;

            if (elements[m] < item)
                l = m + 1;
            else
                u = m - 1;
        }

        return l;
    }

public:
    SET(T* array, int num_elements)
    {
        elements.reserve(num_elements);
        for(int i = 0; i < num_elements; i++)
            elements.push_back(array[i]);

        std::sort(elements.begin(), elements.end());

        //static_cast is used because elements.size() is an unsigned integer
        //and if element size is 0, it may cause integer overflow and segmentation fault
        for(int i = 0; i < static_cast<int>(elements.size()) - 1; i++)
            if(elements[i] == elements[i+1])
            {
                elements.erase(elements.begin() + i);
                i--;
            }
    }

    SET()
    {}

    bool ismember(T item)
    {
        if(!elements.size())
            return false;

        return elements[find(item)] == item;
    }

    void add(T item)
    {

        if(!elements.size()){
            elements.insert(elements.begin(), item);
            return;
        }

        int pos = find(item);
        if(elements[pos] != item)
            elements.insert(elements.begin() + pos, item);
    }

    void powerset()
    {
        if(elements.size() > 31)
        {
            std::cout << "The given set contains too many elements. "
                         "Powerset of this set is too big to display\n";
            return;
        }

        //unsigned long ensures that it can display at least upto 2^32 - 1
        unsigned long max = 1u << elements.size();

        unsigned long bits[32];
        for(int i = 0; i < 32; i++)
            bits[i] = 1u << i;

        std::cout << "{ ∅, ";
        for(unsigned long i = 1; i < max; i++)
        {
            std::cout << "{ ";

            for(int j = 0; j < elements.size(); j++)
                if(i & bits[j])
                    std::cout << elements[j] << ", ";

            std::cout << "}, ";
        }

        std::cout << "}";
    }

    bool subset(SET<T>& s)
    {
        for(int i = 0; i < s.elements.size(); i++)
            if(! ismember(s.elements[i]))
                return false;

        return true;
    }

    SET<T> Union(SET<T>& s)
    {
        SET<T> out;

        for(auto i : elements)
            out.add(i);

        for(auto i : s.elements)
            out.add(i);

        return out;
    }

    SET<T> Intersection(SET<T>& s)
    {
        SET<T> out;

        for(auto i : s.elements)
            if(ismember(i))
                out.add(i);

        return out;
    }

    SET<T> complement(SET<T>& universal)
    {
        SET<T> out;

        for(auto i : elements)
            if(!universal.ismember(i))
                throw std::invalid_argument("Given set is not the universal set");

        for(auto i : universal.elements)
            if(!ismember(i))
                out.add(i);

        return out;
    }

    SET<T> difference(SET<T>& s)
    {
        SET<T> out;

        for(auto i : elements)
            if(!s.ismember(i))
                out.add(i);

        return out;
    }

    SET<T> symm_difference(SET<T>& s)
    {
        SET<T> s1 = difference(s);
        SET<T> s2 = s.difference(*this);

        return s1.Union(s2);
    }

    SET<std::pair<T,T>> product(SET<T>& s)
    {
        SET<std::pair<T,T>> out;

        for(auto i : elements)
            for(auto j : s.elements)
                out.add(std::make_pair(i,j));

        return out;
    }

    template <typename S>
    friend std::ostream& operator<<(std::ostream& out, const SET<S>& set);
};

//for printing std::pair
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::pair<T,T>& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

//for printing SET
template <typename T>
std::ostream& operator<<(std::ostream& out, const SET<T>& set)
{
    if(!set.elements.size())
        return (out << "∅");

    out << "{ ";

    for(auto i : set.elements)
        out << i << ", " ;

    out << "}";

    return out;
}

SET<int> getInput()
{
    int num_elements;
    std::cout << "Please Enter Number of Elements in the Set : ";
    std::cin >> num_elements;

    std::cout << "Please Enter Each Elements Separated by Spaces : ";

    int* elements = new int[num_elements];

    for(int i = 0; i < num_elements; i++)
        std::cin >> elements[i];

    SET<int> ret(elements, num_elements);

    //clear buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    delete[] elements;

    return ret;
}

int main()
{
    std::cout << "Set 1 : \n";
    auto s1 = getInput();

    //Menu driven Program
    while(1)
    {
        std::cout << "\n\n";

        std::cout << "Given Set : " << s1 << "\n";

        std::cout << "Enter Any choice From Below\n"
                     "1. ismember\n"
                     "2. powerset\n"
                     "3. subset\n"
                     "4. union and intersection\n"
                     "5. complement\n"
                     "6. set difference and symmetric difference\n"
                     "7. cartesian product\n"
                     "8. exit\n\n";

        int option = 0;
        while(option < 1 || option > 8)
        {
            std::cout << ">> ";
            std::cin >> option;
        }


        switch(option)
        {
            case 1 :
            {
                int el;
                std::cout << "Please Enter an Element : ";
                std::cin >> el;

                std::cout << "the element " << el;
                if(s1.ismember(el))
                    std::cout << " exists in the given set\n";
                else
                    std::cout << " does not exists in the given set\n";
                break;
            }

            case 2:
                s1.powerset();
                break;

            case 3:
            {
                std::cout << "Set 2 : \n";
                auto s2 = getInput();

                std::cout << "\n";

                if(s1.subset(s2))
                    std::cout << "The given set is a subset of set 1\n";
                else
                    std::cout << "The given set is NOT a subset of set 1\n";

                break;
            }

            case 4:
            {
                std::cout << "Set 2 : \n";
                auto s2 = getInput();

                std::cout << "\nThe Union of given sets : " << s1.Union(s2);
                std::cout << "\nThe Intersection of given sets : " << s1.Intersection(s2);
                break;
            }

            case 5:
            {
                std::cout << "Please Enter The Universal Set : \n";
                auto universal = getInput();

                try{
                    auto c = s1.complement(universal);
                    std::cout << "Complement of Given Set is : " << c;
                }catch(std::invalid_argument i)
                {
                    std::cout << "ERROR : " << i.what();
                }

                break;
            }

            case 6:
            {
                std::cout << "Set 2 : \n";
                auto s2 = getInput();

                std::cout << "\nThe difference of given sets : " << s1.difference(s2);
                std::cout << "\nThe symmetric difference of given sets : " << s1.symm_difference(s2);
                break;
            }

            case 7:
            {
                std::cout << "Set 2 : \n";
                auto s2 = getInput();

                std::cout << "\nThe Product of given sets : " << s1.product(s2);
                break;
            }

            case 8:
                return 0;
        }
    }
}

