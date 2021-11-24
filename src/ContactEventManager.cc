#include<ContactEventManager.hh>
#include<GameObject.hh>
#include<iostream>

ContactEventManager::ContactEventManager()
{
}

ContactEventManager::~ContactEventManager()
{
}

void ContactEventManager::BeginContact(b2Contact *contact)
{
    GameObject* ActorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
    GameObject* ActorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};

    if (ActorA && ActorB){
        std::cout << "Collision: " << ActorA->GetTagName() << "," << ActorB->GetTagName() << std::endl;
        
    }
}
void ContactEventManager::EndContact(b2Contact *contact)
{

}
