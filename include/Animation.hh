#pragma once
#include<SFML/Graphics.hpp>

class Animation
{
private:
  float delay{};
  int startFrame{};
  int endFrame{};
  sf::Sprite* sprite;
  float timer{};
  int currentFrame{};
  int currentAnimation{};
public:
  Animation();
  Animation(int startFrame, int endFrame, sf::Sprite*& sprite, float delay, int currentAnimation);
  ~Animation();

  void Play(float& deltaTime);
};