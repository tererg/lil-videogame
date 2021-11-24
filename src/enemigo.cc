#include "enemigo.hh"
#include "InputsSystem.hh"
#include "Animation.hh"


Animation* upEnemigo{new Animation()};
Animation* downEnemigo{new Animation()};

enemigo::enemigo(const char* textureUrl, int col, int row, float width, float height, float scale, float moveSpeed,
sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world) :
GameObject(textureUrl, col, row, width, height, scale, position, b2BodyType::b2_dynamicBody, window, world)
{
  this->moveSpeed = moveSpeed;

  rigidbody->SetRotationFreeze(true);

  upEnemigo = new Animation(0, 5, drawable, 0.08f, 4);
  downEnemigo = new Animation(0, 5, drawable, 0.08f, 7);
}

enemigo::~enemigo()
{
}

void enemigo::Draw()
{
  GameObject::Draw();
}

void enemigo::Update(float& deltaTime)
{
  GameObject::Update(deltaTime);

  //FlipSprite();
  Move();

  if(std::abs(InputsSystem::GetAxis().y < 0))
  {
    upEnemigo->Play(deltaTime);
  }else if(std::abs(InputsSystem::GetAxis().y > 0))
  {
    downEnemigo->Play(deltaTime);
  }  
  else
  {
    downEnemigo->Play(deltaTime);
  }
}
/*
void enemigo::FlipSprite()
{
    drawable->GetSprite()->setScale(InputsSystem::GetAxis().x > 0 ? scale :
    InputsSystem::GetAxis().x < 0 ? -scale :
    drawable->GetSprite()->getScale().x, drawable->GetSprite()->getScale().y);
}*/

void enemigo::Move()
{
    if ( this->GetPosition().y >= 455){
      rigidbody->Move(b2Vec2(0 * moveSpeed, -1 * moveSpeed));
    }
    if (this->GetPosition().y <= 160)
    {
        rigidbody->Move(b2Vec2(0 * moveSpeed, 1 * moveSpeed));
    }
  //rigidbody->Move(b2Vec2(InputsSystem::GetAxis().x * moveSpeed, InputsSystem::GetAxis().y * moveSpeed));
}

sf::Sprite* enemigo::GetSprite() const
{
  return drawable->GetSprite();
}
