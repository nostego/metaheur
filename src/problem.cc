#include "problem.hh"
#define OFFSET 20
#define W_RECT 50
#define TOPOS(X) OFFSET + 100 * X

Problem::Problem(int n) :
  size(n)
{
  initialize();
}

void Problem::draw(sf::RenderWindow& App)
{
 
  for (size_t nb = 0; nb < blocs.size(); ++nb)
  {
    Bloc b = blocs[nb];

    for (size_t l = 0; l < b.links.size(); ++l)
    {
      Bloc d = blocs[b.links[l]];

      App.Draw(sf::Shape::Line(TOPOS(b.x) + W_RECT / 2,
			       TOPOS(b.y) + W_RECT / 2,
			       TOPOS(d.x) + W_RECT / 2,
			       TOPOS(d.y) + W_RECT / 2,
			       1, sf::Color(255, 0 ,0)));
    }
  }

  for (int y = 0; y < size; ++y)
    for (int x = 0; x < size; ++x)
    {
      App.Draw(sf::Shape::Rectangle(TOPOS(x), TOPOS(y),
				    TOPOS(x) + W_RECT, TOPOS(y) + W_RECT,
				    sf::Color(200, 200, 200)));
    }
}

void Problem::initialize()
{
  for (int y = 0; y < size; ++y)
    for (int x = 0; x < size; ++x)
    {
      Bloc b;

      b.x = x;
      b.y = y;
      if (x - 1 >= 0)
	b.links.push_back((x - 1) + y * size);
      if (x + 1 < size)
	b.links.push_back(x + 1 + y * size);
      if (y - 1 >= 0)
	b.links.push_back((y - 1) * size + x);
      if (y + 1 < size)
	b.links.push_back((y + 1) * size + x);
      blocs.push_back(b);
    }
}

