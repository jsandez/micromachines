#include "includes/servidor/modelo/fisicas/ContactListener.h"

#include "includes/servidor/modelo/Colisionable.h"

ContactListener::ContactListener() {
}

ContactListener::~ContactListener() {    
}

void ContactListener::BeginContact(b2Contact* contact) {
    //Son raw pointers pero b2d garantiza que no se eliminan ni agregan cuerpos durante
    // las colisiones
    Colisionable* colisionableA = contact->GetFixtureA()->GetBody()->GetUserData();
    Colisionable* colisionableB = contact->GetFixtureB()->GetBody()->GetUserData();
    
    // No debería ocurrir porque no le puse data a los fixtures.
    //if(!colisionableA || !colisionableB) {
    //    return;
    //}
    colisionableA->enColisionCon(*colisionableB);
    colisionableB->enColisionCon(*colisionableA);
}

void ContactListener::EndContact(b2Contact* contact) {
}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {

}

void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
    
}