#include "problem.hh"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>

template <class T>
Problem<T>::Problem(int nvar_,
                    double low_,
                    double up_) :
  nvar(nvar_),
  low(low_),
  up(up_)
{
  srand(time(NULL));
  for (int ind = 0; ind < POPULATION_SIZE; ++ind)
  {
    std::vector<double> individu;

    for (int k = 0; k < nvar; ++k)
    {
      individu.push_back(low_ + ((rand() /
                                  (double)RAND_MAX) * (up_ - low_)));
    }
    individus.push_back(individu);
  }
}

template <class T>
void Problem<T>::print_best()
{
  if(individus.size() == 0)
  {
    std::cerr << "Error: empty population" << std::endl;
  }
  else
  {
    sort(individus.begin(), individus.end(), comp);
    std::cout << "Minimum: " << comp.cost(individus[0]) << std::endl;
    std::cout << "At: ";
    for (int k = 0; k < nvar; ++k)
      std::cout << individus[0][k] << " ";
    std::cout << std::endl;
  }
}


template <class T>
void Problem<T>::clone(std::vector<double> a)
{
  individus.push_back(a);
}

template <class T>
void Problem<T>::mutation(std::vector<double>& a)
{
  int sel = rand() % nvar;

  a[sel] = low + ((rand() /
		    (double)RAND_MAX) * (up - low));
}

template <class T>
void Problem<T>::process()
{
  for (size_t k = 0; k < individus.size() - POPULATION_SIZE; ++k)
    individus.pop_back();
  for (size_t k = 0; k < POPULATION_SIZE; ++k)
  {
    clone(individus[k]);
    mutation(individus[k]);
  }
  sort(individus.begin(), individus.end(), comp);
}
