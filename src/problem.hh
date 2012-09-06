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

  int size;
  std::vector<Bloc> blocs;
};

#endif // !PROBLEM_HH_
