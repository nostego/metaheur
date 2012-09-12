#ifndef PROBLEM_HH_
# define PROBLEM_HH_

# include <vector>
# include <deque>

template <class T>
class Problem
{
public:
 Problem(int nvar_,
	  double low_,
	  double up_);

  void process();
  void go(std::vector<double>& there);
  bool already_go(std::vector<double>& there);

  int nvar;
  double low;
  double up;
  double step;
  T cost;
  std::vector<double> current;
  double current_cost;
  std::deque<std::vector<double> > q;

  double min_cost;
  std::vector<double> min;
};

# include "problem.hxx"

#endif // !PROBLEM_HH_
