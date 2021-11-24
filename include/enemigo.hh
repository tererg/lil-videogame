#pragma once

#include<SFML/Graphics.hpp>
#include "Rigidbody.hh"
#include "GameObject.hh"

class enemigo : public GameObject
{
private:
  float moveSpeed{};

  void Move();
 
public:
  enemigo(const char* textureUrl, int col, int row, float width, float height, float scale, float moveSpeed,
  sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world);
  ~enemigo();

  void Update(float& deltaTime) override;
  void Draw() override;

  sf::Sprite* GetSprite() const;
};