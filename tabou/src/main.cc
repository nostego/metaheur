#include <iostream>
#include "problem.hh"
#include <cmath>
#include <vector>

struct Regression
{
  virtual double cost(std::vector<double> a) = 0;
  bool operator() (std::vector<double> a,
		   std::vector<double> b)
    {
      return cost(a) < cost(b);
    }
};

struct Dejong : public Regression
{
  virtual double cost(std::vector<double> a)
    {
      double ret = 0.0;

      for (size_t k = 0; k < a.size(); ++k)
      {
	ret += a[k] * a[k];
      }
      return ret;
    }
};

struct Michalewicz : public Regression
{
  virtual double cost(std::vector<double> a)
    {
      double ret = 0.0;

      for (size_t k = 0; k < a.size(); ++k)
      {
	ret += sin(a[k]) *
	  pow(sin(((k + 1) * a[k] * a[k]) / M_PI),
	      20.0);
      }
      return -ret;
    }
};

struct Dejong3 : public Regression
{
  virtual double cost(std::vector<double> a)
    {
      double ret = 0.0;

      for (size_t k = 0; k < a.size(); ++k)
      {
	int signe = (a[k] < 0.0);

	if (!signe)
	  signe = -1;
	ret += signe * (-1) * ceil(fabs(a[k]));
      }
      return ret;
    }
};

struct Schwefel : public Regression
{
  virtual double cost(std::vector<double> a)
    {
      double ret = 0.0;

      for (size_t k = 0; k < a.size(); ++k)
      {
         ret -= a[k] * sin(sqrt(fabs(a[k])));
      }
      return ret;
    }
};

int main ()
{
  Problem<Schwefel> p(2, -500, 500);

  for (int iter = 0; iter < 10000; ++iter)
  {
    std::cout << p.current_cost <<  " @ "
        << p.current[0] << std::endl;
    p.process();
  }
  std::cout << "MIN = " << p.min_cost << " @ "
    << p.min[0] << std::endl;
  return 0;
}
