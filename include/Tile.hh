#pragma once

#include "Rigidbody.hh"
#include "SFML/Graphics.hpp"

class GameObject
{
protected:
  sf::Texture* texture{};
  sf::Sprite* sprite{};
  Rigidbody* rigidbody{};
  sf::CircleShape* pivotPoint{};
  sf::RenderWindow* window{};
  b2World* world{};
  float scale{};

public:
  Tile(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position, b2BodyType bodyType,sf::RenderWindow*& window, b2World*& world);
  Tile(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world);
  ~Tile();

  virtual void Draw();
};