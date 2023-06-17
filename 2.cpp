#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class RELATION{
  std::vector<T> domain;
  std::vector<std::vector<bool>> relation_matrix;

  //binary search. returns -1 if element not found in the domain
  int find(T item)
  {
      int l = 0;  //lower bound
      int u = domain.size() - 1;  //upper bound

      while (l <= u) {
          int m = l + (u - l) / 2;    //mid element

          if (domain[m] == item)
              return m;

          if (domain[m] < item)
              l = m + 1;
          else
              u = m - 1;
      }

      return -1;
  }

public:
    RELATION(T* Domain, int num_elements)
        {
            domain.reserve(num_elements);
            for(int i = 0; i < num_elements; i++)
                domain.push_back(Domain[i]);

            std::sort(domain.begin(), domain.end());

            //static_cast is used because elements.size() is an unsigned integer
            //and if element size is 0, it may cause integer overflow and segmentation fault
            for(int i = 0; i < static_cast<int>(domain.size()) - 1; i++)
                if(domain[i] == domain[i+1])
                {
                    domain.erase(domain.begin() + i);
                    i--;
                }

            for(int i = 0; i < num_elements; i++)
            {
                relation_matrix.push_back({});

                for(int j = 0; j < num_elements; j++)
                    relation_matrix[i].push_back(false);
            }
        }

    RELATION(){}

    void connect(T a, T b)
    {
        int x = find(a);
        int y = find(b);

        if(x == -1 || y == -1)
            throw std::domain_error("Given element is not in the Domain");

        relation_matrix[x][y] = true;
    }

    bool isReflexive()
    {
        for(int i = 0; i < domain.size(); i++)
            if(!relation_matrix[i][i])
                return false;

        return true;
    }

    bool isSymmetric()
    {
        for(int i = 0; i < domain.size(); i++)
            for(int j = 0; j < domain.size(); j++)
                if(relation_matrix[i][j] != relation_matrix[j][i])
                    return false;

        return true;
    }

    bool isAntiSymmetric()
    {
        for(int i = 0; i < domain.size(); i++)
            for(int j = 0; j < domain.size(); j++)
            {
                if(i == j)
                    continue;

                if(relation_matrix[i][j] && relation_matrix[j][i])
                    return false;
            }

        return true;
    }

    bool isTransitive()
    {
        for(int i = 0; i < domain.size(); i++)
            for(int j = 0; j < domain.size(); j++)
            {
                if(!relation_matrix[i][j])
                    continue;

                for(int k = 0; k < domain.size(); k++)
                    if(relation_matrix[j][k] && !relation_matrix[i][k])
                        return false;
            }

        return true;
    }

    bool isEquivalence()
    {
        return ( isReflexive()
              && isSymmetric()
              && isTransitive());
    }

    bool isPartialOrder()
    {
        return ( isReflexive()
              && isAntiSymmetric()
              && isTransitive());
    }

    template <typename S>
    friend std::ostream& operator<<(std::ostream& out, const RELATION<S>& set);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const RELATION<T>& r)
{
    out << "{ ";
    for(int i = 0; i < r.domain.size(); i++)
        for(int j = 0; j < r.domain.size(); j++)
            if(r.relation_matrix[i][j])
                out << "(" << r.domain[i] << ", " << r.domain[j] << "), ";

    out << "}";
    return out;
}

int main()
{
    std::string items[3] = {"a","b","c"};

    RELATION<std::string> r(items, 3);
    r.connect("a", "a");
    r.connect("b", "b");
    r.connect("c", "c");
    r.connect("b", "c");
    r.connect("c", "a");
    r.connect("b", "a");

    std::cout << "Relation is given by : " << r << std::endl;
    std::cout << std::boolalpha;

    std::cout << "Reflexive : " << r.isReflexive() << std::endl;
    std::cout << "Symmetric : " << r.isSymmetric() << std::endl;
    std::cout << "Anti Symmetric : " << r.isAntiSymmetric() << std::endl;
    std::cout << "Transitive : " << r.isTransitive() << std::endl;
    std::cout << "Equivalence : " << r.isEquivalence() << std::endl;
    std::cout << "Partial Ordered : " << r.isPartialOrder() << std::endl;

    return 0;
}
