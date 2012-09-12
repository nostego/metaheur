#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "problem.hh"

int main ()
{
  int p_size = 5;
  Problem p(p_size);
  int iter = 0;
  int count = 0;
  double lcost = p.cost();
  sf::RenderWindow App(sf::VideoMode(p_size * 100,
				     p_size * 100, 32), "Metaheuristique");

  while (App.IsOpened())
  {
    sf::Event Event;
    while (App.GetEvent(Event))
    {
      if (Event.Type == sf::Event::Closed)
        App.Close();
    }

    if (iter % 500 == 0)
    {
      std::cout << "Temperature = "
		<< p.t
		<< std::endl
		<< "Energy = "
		<< p.cost()
		<< std::endl << std::endl;
      App.Clear();
      p.draw(App);
      App.Display();
    }

    p.random_permutation();

    if (p.cost() > lcost)
    {
      if (p.t <= 0.0)
	p.undo();
      else if (((rand()) / (double)RAND_MAX) > (exp(-(p.cost() - lcost) / p.t)))
	p.undo();
    }
    ++iter;
    if (iter >= 100 * 2 * p_size * p_size)
    {
      iter = 0;
      p.t *= 0.9;
    }
    lcost = p.cost();
  }

  for (size_t nb = 0; nb < p.blocs.size(); ++nb)
  {
    std::cout << nb
	      << " "
	      << p.blocs[nb].x
	      << " "
	      << p.blocs[nb].y
	      << std::endl;
  }

  return 0;
}
