#pragma once
#include<SFML/Graphics.hpp>
#include<box2d/box2d.h>
#include "DrawPhysics.hh"
#include "GameObject.hh"

class Game
{
private:
  sf::RenderWindow* window{};
  sf::Event* event{};
  b2Vec2* gravity{};
  b2World* world{};
  b2Draw* drawPhysics{};
  std::vector<GameObject*>* gameObjects;
  std::vector<Tile*>* tiles;
public:
  Game();
  ~Game();

  void UpdatePhysics();
  void Render();
  void Init();
  void Update();
  void Draw();
  void Inputs();
};
