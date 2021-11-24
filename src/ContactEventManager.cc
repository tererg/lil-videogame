#include<ContactEventManager.hh>
#include<GameObject.hh>
#include<iostream>

ContactEventManager::ContactEventManager(std::vector<GameObject*>*& deleteList)
{ 
    this->deleteList = deleteList;
}

ContactEventManager::~ContactEventManager()
{
}

void ContactEventManager::BeginContact(b2Contact *contact)
{
    GameObject* ActorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
    GameObject* ActorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};
    std::string tagg = ActorB->GetTagName();
    if (ActorA && ActorB){
      if (tagg == "food"){
        std::cout << "Collision: " << ActorA->GetTagName() << "," << ActorB->GetTagName() << std::endl;
        deleteList->push_back(ActorB);
    }
    if (ActorB->GetTagName() == "enemigo"){
        std::cout << "Collision: " << ActorA->GetTagName() << "," << ActorB->GetTagName() << std::endl;
        
        //deleteList->push_back(ActorB);
    }
}
}
void ContactEventManager::EndContact(b2Contact *contact)
{

}
