#include<ContactEventManager.hh>
#include<GameObject.hh>
#include<iostream>
#include<Game.hh>

int contFood{};
int contEnemies{};
  int resultado;
ContactEventManager::ContactEventManager(std::vector<GameObject*>*& deleteList)
{ 
    this->deleteList = deleteList;
    contFood = 0;
    contEnemies = 0;
    resultado = 0;
   this->resultado;
}

ContactEventManager::~ContactEventManager()
{
}

void ContactEventManager::BeginContact(b2Contact *contact)
{
    GameObject* ActorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
    GameObject* ActorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};
    std::string tag1 = ActorA->GetTagName();
    std::string tag2 = ActorB->GetTagName();
    if (ActorA && ActorB){
      if (tag1 == "player" && tag2 == "food"){
        std::cout << "Collision: " << ActorA->GetTagName() << "," << ActorB->GetTagName() << std::endl;
        deleteList->push_back(ActorB);
        contFood+=1;
        if (contFood == 10){//cambiar a 10
            //win
             std::cout << "ganas" << std::endl;
             resultado = 1;
        }
    }
    if (tag1 == "player" && (tag2 == "enemigo1" || tag2 == "enemigo2" 
    || tag2 == "enemigo3" || tag2 == "enemigo4")){
        std::cout << "Collision: " << ActorA->GetTagName() << "," << ActorB->GetTagName() << std::endl;
        //3 veces = gameover
       std::cout << "pierdes" << std::endl;
             resultado = 2;
        //deleteList->push_back(ActorB);
    }
}
}
void ContactEventManager::EndContact(b2Contact *contact)
{

}

int ContactEventManager::getResultado()
{
    return resultado;
}