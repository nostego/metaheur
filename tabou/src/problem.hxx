#include "problem.hh"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cfloat>

#define QUEUE_SIZE 100
#define PERC_STEP 0.001

template <class T>
Problem<T>::Problem(int nvar_,
                    double low_,
                    double up_) :
  nvar(nvar_),
  low(low_),
  up(up_)
{
    std::vector<double> c;

    srand(0);
    step = fabs(up_ - low_) * PERC_STEP;
    std::cout << "STEP = " << step << std::endl;

    for (int k = 0; k < nvar; ++k)
    {

        c.push_back(low_ + ((rand() /
                        (double)RAND_MAX) * (up_ - low_)));
    }
    min_cost = DBL_MAX;
    min = current;
    go(c);

}
template <class T>
void Problem<T>::go(std::vector<double>& there)
{
    current = there;
    current_cost = cost.cost(current);
    q.push_front(current);
    if (q.size() > QUEUE_SIZE)
        q.pop_back();
    if (min_cost > current_cost)
    {
        min_cost = current_cost;
        min = current;
    }
}

template <class T>
bool Problem<T>::already_go(std::vector<double>& there)
{
    std::deque<std::vector<double> >::iterator it = q.begin();

    while (it != q.end())
    {
        bool diff = false;

        for (int k = 0; k < nvar; ++k)
        {
            if ((*it)[k] != there[k])
                diff = true;
        }
        if (!diff)
            return true;
        it++;
    }
    return false;
}

template <class T>
void Problem<T>::process()
{
    double n_cost;


    for (int k = 0; k < nvar; ++k)
    {
        std::vector<double> n(current);

        n[k] -= step;
        if ((low <= n[k]) && (n[k] <= up)  && (!already_go(n)))
        {
            n_cost = cost.cost(n);
            if (n_cost < current_cost)
            {
                go(n);
                return;
            }
        }

        n[k] += step * 2;
        if ((low <= n[k]) && (n[k] <= up) && (!already_go(n)))
        {
            n_cost = cost.cost(n);
            if (n_cost < current_cost)
            {
                go(n);
                return;
            }
        }
    }
    for (int k = 0; k < nvar; ++k)
    {
        std::vector<double> n(current);

        n[k] -= step;
        if ((low <= n[k]) && (n[k] <= up))
        {
            if (!already_go(n))
            {
                go(n);
                return;
            }
        }
        n[k] += step * 2;
        if ((low <= n[k]) && (n[k] <= up))
        {
            if (!already_go(n))
            {
                go(n);
                return;
            }
        }
    }
    if (q.size() > 0)
        q.pop_back();
}
