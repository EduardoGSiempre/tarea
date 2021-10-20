#include "Animation.hh"

Animation::Animation()
{
}

Animation::Animation(int startFrame, int endFrame, sf::Sprite*& sprite, float delay, int currentAnimation)
{
  this->startFrame = startFrame;
  this->endFrame = endFrame;
  this->sprite = sprite;
  this->delay = delay;
  this->currentAnimation = currentAnimation;
  currentFrame = this->startFrame;
}

Animation::~Animation()
{
}

void Animation::Play(float& deltaTime)
{
  timer += deltaTime;
  if(timer >= delay)
  {
    sprite->setTextureRect(sf::IntRect(currentFrame * sprite->getTextureRect().width, 
    currentAnimation * sprite->getTextureRect().height, 
    sprite->getTextureRect().width,
    sprite->getTextureRect().height));

    timer = 0;
    if(currentFrame == endFrame)
    {
      currentFrame = startFrame;
    }
    else
    {
      currentFrame++;
    }
  }
}