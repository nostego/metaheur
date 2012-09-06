#ifndef PROBLEM_HH_
# define PROBLEM_HH_

# include <cstdlib>
# include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

struct Bloc
{
  int x;
  int y;
  std::vector<int> links;
};

class Problem// : public SimulatedAnnealing
{
public:
  Problem(int n);

  void initialize();
  void draw(sf::RenderWindow& App);

  double cost();
  void undo();

  void random_permutation();
  void permutation(int n, int m);
  int size;
  std::vector<Bloc> blocs;

  int lastn;
  int lastm;

};

#endif // !PROBLEM_HH_
