#include<ContactEventManager.hh>
#include<GameObject.hh>
#include<iostream>


int contFood{};
int contEnemies{};

ContactEventManager::ContactEventManager(std::vector<GameObject*>*& deleteList)
{ 
    this->deleteList = deleteList;
    contFood = 0;
    contEnemies = 0;
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
        if (contFood == 1){//cambiar a 10
            //win
             std::cout << "ganas" << std::endl;
        }
    }
    if (tag1 == "player" && tag2 == "enemigo"){
        std::cout << "Collision: " << ActorA->GetTagName() << "," << ActorB->GetTagName() << std::endl;
        //3 veces = gameover
        contEnemies+=1;
        if (contEnemies == 1){//cambiar a 4
            //lose
             std::cout << "pierdes" << std::endl;
        }
        //deleteList->push_back(ActorB);
    }
}
}
void ContactEventManager::EndContact(b2Contact *contact)
{

}
