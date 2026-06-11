#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return (*this);
}
PmergeMe::~PmergeMe(){};

bool PmergeMe::exists(int vl)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec[i] == vl)
            return true;
    }
    return false;
}

bool PmergeMe::isValid(const std::string &s)
{
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); i++)
        if (!isdigit(s[i]))
            return false;
    long long n = atoll(s.c_str());
    if (n < 0 || n > INT_MAX)
        return false;
    return true;
}

void PmergeMe::parse(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        if (!isValid(av[1]))
            throw std::runtime_error("Error");
        int n = atoi(av[i]);
        if (exists(n))
            throw std::runtime_error("Error");
        vec.push_back(n);
        deq.push_back(n);
    }
}

template <typename T>
void PmergeMe::insertSorted(T &c, int val)
{
    c.insert(std::lower_bound(c.begin(), c.end(), val), val);
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> d)
{
    if (d.size() <= 1)
        return d;
    std::deque<int> main;
    std::deque<int> pend;
    for (size_t i = 0; i < d.size(); i += 2)
    {
        if (i + 1 < d.size())
        {
            int a = d[i];
            int b = d[i + 1];

            if (a > b) std::swap(a, b);

            main.push_back(b);
            pend.push_back(a);
        }
        else
            main.push_back(d[i]);
    }
    std::sort(main.begin(), main.end());
    for (size_t i = 0; i < pend.size(); i++)
        insertSorted(main, pend[i]);
    return main;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> v)
{
    if (v.size() <= 1)
        return v;
    std::vector<int> main;
    std::vector<int> pend;
    for (size_t i = 0; i < v.size(); i += 2)
    {
        if (i + 1 < v.size())
        {
            int a = v[i];
            int b = v[i + 1];

            if (a > b) std::swap(a, b);

            main.push_back(b);
            pend.push_back(a);
        }
        else
            main.push_back(v[i]);
    }
    std::sort(main.begin(), main.end());
    for (size_t i = 0; i < pend.size(); i++)
        insertSorted(main, pend[i]);
    return main;
}

void PmergeMe::run(int ac, char **av)
{
    parse(ac, av);
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    clock_t start1 = clock();
    std::vector<int> v = sortVector(vec);
    clock_t end1 = clock();
    double us1 = (static_cast<double>(end1 - start1) * 1000000.0) / CLOCKS_PER_SEC;
    clock_t start2 = clock();
    std::deque<int> d = sortDeque(deq);
    clock_t end2 = clock();
    double us2 = (static_cast<double>(end2 - start2) * 1000000.0) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of "
          << v.size()
          << " elements with std::vector : "
          << us1
          << " us"
          << std::endl;

    std::cout << "Time to process a range of "
          << d.size()
          << " elements with std::deque : "
          << us2
          << " us"
          << std::endl;
}