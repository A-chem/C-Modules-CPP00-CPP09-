#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <ctime>


class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;

    bool isValid(const std::string &s);
    bool exists(int vl);
    void parse(int ac, char **av);

    std::vector<int> sortVector(std::vector<int> v);
    std::deque<int> sortDeque(std::deque<int> d);

    template <typename T>
    void insertSorted(T &c, int val);

public:
    PmergeMe();                          
    PmergeMe(const PmergeMe &other);    
    PmergeMe &operator=(const PmergeMe &other); 
    ~PmergeMe(); 
    void run(int ac, char **av);
};

#endif