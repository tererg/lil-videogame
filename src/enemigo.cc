#include "enemigo.hh"
#include "InputsSystem.hh"
#include "Animation.hh"
#include<iostream>

Animation* upEnemigo{new Animation()};
Animation* downEnemigo{new Animation()};
bool flag{};
int cont{};

enemigo::enemigo(const char* textureUrl, int col, int row, float width, float height, float scale, float moveSpeed,
sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world) :
GameObject(textureUrl, col, row, width, height, scale, position, b2BodyType::b2_dynamicBody, window, world)
{
  this->moveSpeed = moveSpeed;

  rigidbody->SetRotationFreeze(true);

  upEnemigo = new Animation(0, 5, drawable, 0.08f, 3);
  downEnemigo = new Animation(0, 5, drawable, 0.08f, 3);
    flag = false;
    cont = 900;
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
 std::cout << flag << std::endl;
    if ( flag == false){ 
        cont -= 1 ;
        rigidbody->Move(b2Vec2(0 * moveSpeed, -1 * moveSpeed / 2));

        if (cont <= -300)
            flag = true;
      //std::cout << "mayor o igual a 455 - " << this->GetPosition().y << std::endl;
       
    }

    if (flag == true)
    { 
        cont += 1;
        rigidbody->Move(b2Vec2(0 * moveSpeed, 1 * moveSpeed / 2));

        if (cont>=900)
            flag = false;
       
        //std::cout << "menor o igual a 455 " << this->GetPosition().y << std::endl;
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
    


  //rigidbody->Move(b2Vec2(InputsSystem::GetAxis().x * moveSpeed, InputsSystem::GetAxis().y * moveSpeed));
}

sf::Sprite* enemigo::GetSprite() const
{
  return drawable->GetSprite();
}
