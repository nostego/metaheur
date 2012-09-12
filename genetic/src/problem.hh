#ifndef PROBLEM_HH_
# define PROBLEM_HH_

# define POPULATION_SIZE 100

# include <vector>

template <class T>
class Problem
{
public:
  Problem(int nvar_,
	  double low_,
	  double up_);
  void process();
  void print_best();

  void clone(std::vector<double> a);
  void mutation(std::vector<double>& a);
  void reproduce(std::vector<double>& a,
                 std::vector<double>& b);
  T comp;
  int nvar;
  double low;
  double up;
  std::vector<std::vector<double> > individus;
};

# include "problem.hxx"

#endif // !PROBLEM_HH_
