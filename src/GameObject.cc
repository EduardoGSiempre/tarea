#include "GameObject.hh"

GameObject::GameObject(const char* textureUrl, int col, int row, float width, float height, float scale,
sf::Vector2f* position, b2BodyType bodyType,sf::RenderWindow*& window, b2World*& world)
{
  this->window = window;
  this->world = world;
  this->scale = scale;

  texture = new sf::Texture();
  sprite = new sf::Sprite();

  texture->loadFromFile(textureUrl);
  texture->setSmooth(false);

  sprite->setTexture(*texture);
  sprite->setTextureRect(sf::IntRect(col * width, row * height, width, height));
  sprite->setColor(sf::Color::White);
  sprite->setPosition(*position);
  sprite->setScale(scale, scale);

  rigidbody = new Rigidbody(world, bodyType,
  new b2Vec2(sprite->getPosition().x, sprite->getPosition().y),
  width * scale / 2, height * scale / 2, 1, 0, 0,
  b2Vec2(sprite->getOrigin().x , sprite->getOrigin().y), 0.f);

  sprite->setOrigin(width / 2, height / 2);
}

GameObject::~GameObject()
{
}

void GameObject::Update(float& deltaTime)
{
  sprite->setPosition(rigidbody->GetPositionSFML());
}

void GameObject::Draw()
{
  window->draw(*sprite);
}