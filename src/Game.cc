#include "Game.hh"
#include "Constants.hh"
#include "Collider.hh"
#include "InputsSystem.hh"
#include "Animation.hh"
#include "Rigidbody.hh"
#include "Character.hh"
#include<iostream>
#include "TileGroup.hh"
#include "enemigo.hh"
#include "ContactEventManager.hh"


Collider* collider{new Collider(100, 100, 100, 100, sf::Color::Green, 5.f)};
sf::Clock* timer{new sf::Clock()};
float deltaTime{};
const float playerSpeed{200.f}; 
const float playerScale{4.f};

Character* character1{};
enemigo* enemigo1{};
enemigo* enemigo2{};
enemigo* enemigo3{};
enemigo* enemigo4{};
GameObject* chest1{};
GameObject* chest2{};
GameObject* chest3{};
GameObject* chest4{};
GameObject* chest5{};//primera linea
GameObject* chest6{};
GameObject* chest7{};
GameObject* chest8{};
GameObject* chest9{};
GameObject* chest10{};//segunda linea
GameObject* chest11{};
GameObject* chest12{};
GameObject* chest13{};
GameObject* chest14{};
GameObject* chest15{};//tercera linea
GameObject* chest16{};
GameObject* chest17{};
GameObject* chest18{};
GameObject* chest19{};
GameObject* chest20{};//cuarta linea
//comida
GameObject* food1{};
GameObject* food2{};
GameObject* food3{};
GameObject* food4{};
GameObject* food5{};
GameObject* food6{};
GameObject* food7{};
GameObject* food8{};
GameObject* food9{};
GameObject* food10{};

TileGroup* tileGroup{};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  //NUEVO
  windowGameOver = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH+400, WINDOW_HEIGHT), "GAME OVER BUNNY >:) ");
  windowWin = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH+400, WINDOW_HEIGHT), "BUNNY, YOURE A WINNER :D ");
  
    sf::Texture texture;
    texture.loadFromFile("assets/maxresdefault.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    windowGameOver->clear();
    windowGameOver->draw(sprite);
    
    //
    sf::Texture texture2;
    texture2.loadFromFile("assets/win.png");
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    windowWin->clear();
    windowWin->draw(sprite2);
    //windowWin->display();
    //windowGameOver->display();
    windowGameOver->setVisible(false);
    windowWin->setVisible(false);
//Then, in PlayState::render()
//game->window.draw(sprite);
  //gravity = new b2Vec2(0.f, -9.8f);
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);  
  drawPhysics = new DrawPhysics(window);
  deleteList = new std::vector<GameObject*>();
  contactEventManager = new ContactEventManager(deleteList);
  gameObjects = new std::vector<GameObject*>();
  
  
  character1 = new Character("assets/newsprites2.png", 0, 5, 16.f, 16.f,
  playerScale, playerSpeed, new sf::Vector2f(110, 155), window, world);

  character1->SetTagName("player");//nuevo

  enemigo1 = new enemigo("assets/newsprites2.png", 0, 3, 16.f, 16.f,
  playerScale, playerSpeed, new sf::Vector2f(183, 455), window, world);
  enemigo1->SetTagName("enemigo1");//nuevo
 gameObjects->push_back(enemigo1);
 enemigo2 = new enemigo("assets/newsprites2 - copia.png", 0, 3, 16.f, 16.f,
  playerScale, playerSpeed, new sf::Vector2f(330, 455), window, world);
  enemigo2->SetTagName("enemigo2");//nuevo
 gameObjects->push_back(enemigo2);
  enemigo3 = new enemigo("assets/newsprites2 - copia.png", 0, 3, 16.f, 16.f,
  playerScale, playerSpeed, new sf::Vector2f(480, 455), window, world);
  enemigo3->SetTagName("enemigo3");//nuevo
 gameObjects->push_back(enemigo3);
  enemigo4 = new enemigo("assets/newsprites2 - copia.png", 0, 3, 16.f, 16.f,
  playerScale, playerSpeed, new sf::Vector2f(622, 455), window, world);
  enemigo4->SetTagName("enemigo4");//nuevo
 gameObjects->push_back(enemigo4);

 

  //comidita
  food1 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(115, 302), b2BodyType::b2_staticBody, window, world);
  food1->SetTagName("food");
  food2 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(250, 304), b2BodyType::b2_staticBody, window, world);
  food2->SetTagName("food");
  food3 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(407, 303), b2BodyType::b2_staticBody, window, world);
  food3->SetTagName("food");
  gameObjects->push_back(food3);

  food3 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(547, 303), b2BodyType::b2_staticBody, window, world);
  food3->SetTagName("food");
  gameObjects->push_back(food3);

  food3 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(694, 301), b2BodyType::b2_staticBody, window, world);
  food3->SetTagName("food");
  gameObjects->push_back(food3);

  food3 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(113, 441), b2BodyType::b2_staticBody, window, world);
  food3->SetTagName("food");
  gameObjects->push_back(food3);
  
  food3 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(255, 441), b2BodyType::b2_staticBody, window, world);
  food3->SetTagName("food");
  gameObjects->push_back(food3);

  food3 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(403, 441), b2BodyType::b2_staticBody, window, world);
  food3->SetTagName("food");
  gameObjects->push_back(food3);

  food3 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(694, 443), b2BodyType::b2_staticBody, window, world);
  food3->SetTagName("food");
  gameObjects->push_back(food3);

  food3 = new GameObject("assets/newsprites2.png", 7, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(545, 440), b2BodyType::b2_staticBody, window, world);
  food3->SetTagName("food");
  gameObjects->push_back(food3);

  chest1 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(110, 100), b2BodyType::b2_staticBody, window, world);
  //chest1->SetTagName("chest");
  chest2 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(255, 100), b2BodyType::b2_staticBody, window, world);
  //chest2->SetTagName("chest");
  chest3 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(405, 100), b2BodyType::b2_staticBody, window, world);
  //chest3->SetTagName("chest");
  chest4 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(545, 100), b2BodyType::b2_staticBody, window, world);
  //chest4->SetTagName("chest");
  chest5 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(690, 100), b2BodyType::b2_staticBody, window, world);//TERMINA PRIMERA LINEA
  //chest5->SetTagName("chest");
  chest6 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(110, 240), b2BodyType::b2_staticBody, window, world);
  //chest6->SetTagName("chest");
  chest7 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(255, 240), b2BodyType::b2_staticBody, window, world);
  //chest7->SetTagName("chest");
  chest8 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(405, 240), b2BodyType::b2_staticBody, window, world);
  //chest8->SetTagName("chest");
  chest9 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(545, 240), b2BodyType::b2_staticBody, window, world);
  //chest9->SetTagName("chest");
  chest10 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(690, 240), b2BodyType::b2_staticBody, window, world);
  //chest10->SetTagName("chest");
  chest11 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(110, 380), b2BodyType::b2_staticBody, window, world);
  //chest11->SetTagName("chest");
  chest12 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(255, 380), b2BodyType::b2_staticBody, window, world);
  //chest12->SetTagName("chest");
  chest13 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(405, 380), b2BodyType::b2_staticBody, window, world);
  //chest13->SetTagName("chest");
  chest14 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(545, 380), b2BodyType::b2_staticBody, window, world);
  //chest14->SetTagName("chest");
  chest15 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(690, 380), b2BodyType::b2_staticBody, window, world);
  //chest16->SetTagName("chest");
  chest16 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(110, 520), b2BodyType::b2_staticBody, window, world);
  //chest16->SetTagName("chest");
  chest17 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(255, 520), b2BodyType::b2_staticBody, window, world);
  //chest17->SetTagName("chest");
  chest18 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(405, 520), b2BodyType::b2_staticBody, window, world);
 // chest18->SetTagName("chest");
  chest19 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(545, 520), b2BodyType::b2_staticBody, window, world);
  //chest19->SetTagName("chest");
  chest20 = new GameObject("assets/newsprites.png", 6, 1, 16, 16, playerScale,//nuevo
  new sf::Vector2f(690, 520), b2BodyType::b2_staticBody, window, world);
  //chest20->SetTagName("chest");
  


  //chest2_dynamic = new GameObject("assets/sprites.png", 6, 1, 16, 16, playerScale,
  //new sf::Vector2f(500, 400), b2BodyType::b2_dynamicBody, window, world);
  //chest2_dynamic->SetTagName("dynamic chest");

  tileGroup = new TileGroup(window, 13, 10, "assets/tile2.png", "assets/maps/map1.tg", 16, 16, 4.f);
 
 

  gameObjects->push_back(character1);
 
  //gameObjects->push_back(enemigo2);
//  gameObjects->push_back(enemigo3);
  //gameObjects->push_back(enemigo4);
  gameObjects->push_back(chest1);
  gameObjects->push_back(chest2);
  gameObjects->push_back(chest3);
  gameObjects->push_back(chest4);
  gameObjects->push_back(chest5);//first line
  gameObjects->push_back(chest6);
  gameObjects->push_back(chest7);
  gameObjects->push_back(chest8);
  gameObjects->push_back(chest9);
  gameObjects->push_back(chest10);//second line
  gameObjects->push_back(chest11);
  gameObjects->push_back(chest12);
  gameObjects->push_back(chest13);
  gameObjects->push_back(chest14);
  gameObjects->push_back(chest15);//third line
  gameObjects->push_back(chest16);
  gameObjects->push_back(chest17);
  gameObjects->push_back(chest18);
  gameObjects->push_back(chest19);
  gameObjects->push_back(chest20);//fourth line
  gameObjects->push_back(food1);
  gameObjects->push_back(food2);
  gameObjects->push_back(food3);

  

}

Game::~Game()
{
}

void Game::Inputs()
{

}

void Game::Draw()
{
  tileGroup->Draw();
  for(auto& gameObject : *gameObjects)
  {
    gameObject->Draw();
  }
  world->DebugDraw();
}

void Game::Render()
{
  for(auto& gameObject : *deleteList){
    gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameObject), gameObjects->end());
    delete gameObject;
  }
  deleteList->clear();
  window->clear(sf::Color(0, 0, 0, 255));
  Draw();
  window->display();
}
void Game::Init()
{
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(b2Draw::e_shapeBit);
  world->SetContactListener(contactEventManager);
  Update();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
  //std::cout << deltaTime << std::endl;
}

void Game::Update()
{
  bool juego, win, lose;
  while (juego)
  {
    while (window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }
    deltaTime = timer->getElapsedTime().asSeconds();
    timer->restart();

    UpdatePhysics();


    while (contactEventManager->resultado == 1)//ganar
    {
     sf::Texture texture2;
    texture2.loadFromFile("assets/win.png");
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    window->clear();
    window->draw(sprite2);
    window->display();
    
    }
     while(contactEventManager->resultado == 2)
    {
       sf::Texture texture;
    texture.loadFromFile("assets/maxresdefault.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window->clear();
    window->draw(sprite);
    window->display();
    
    }



    Inputs();
    //view1->move();//nuevo
    for(auto& gameObject : *gameObjects)
    {
      gameObject->Update(deltaTime);
    }
    Render();
  }
while (win)
{
  
   
}
while(lose)
{

}
  delete window;
  delete event;
}
