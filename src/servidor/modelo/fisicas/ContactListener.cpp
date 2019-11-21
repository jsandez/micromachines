#include "includes/servidor/modelo/fisicas/ContactListener.h"

#include "includes/servidor/modelo/Colisionable.h"

// Métodos privados
#include <iostream>
static void ordenar(Colisionable** A, Colisionable** B);

ContactListener::ContactListener() {
}

ContactListener::~ContactListener() {    
}

void ContactListener::BeginContact(b2Contact* contact) {
    //Son raw pointers pero b2d garantiza que no se eliminan ni agregan cuerpos durante
    // las colisiones
    Colisionable* colisionableA = contact->GetFixtureA()->GetBody()->GetUserData();
    Colisionable* colisionableB = contact->GetFixtureB()->GetBody()->GetUserData();

    ordenar(&colisionableA, &colisionableB);

    // No debería ocurrir porque no le puse data a los fixtures.
    //if(!colisionableA || !colisionableB) {
    //    return;
    //}

    if (colisionableA->getTipo() == Colisionable::tipos::VEHICULO_) {
        if (colisionableB->getTipo() == Colisionable::tipos::VEHICULO_) {
            std::cout << "Vehiculo vs Vehiculo\n";
        }
        if (colisionableB->getTipo() == Colisionable::tipos::SUPERFICIE_ARENA_) {
            std::cout << "Vehiculo vs Arena\n";
        }
    }
}

void ContactListener::EndContact(b2Contact* contact) {
}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
    /*b2WorldManifold worldManifold;
    contact->GetWorldManifold(&worldManifold);
    b2PointState state1[2], state2[2];
    b2GetPointStates(state1, state2, oldManifold, contact->GetManifold());
    if (state2[0] == b2_addState) {
        const b2Body* bodyA = contact->GetFixtureA()->GetBody();
        const b2Body* bodyB = contact->GetFixtureB()->GetBody();
        b2Vec2 point = worldManifold.points[0];
        b2Vec2 vA = bodyA->GetLinearVelocityFromWorldPoint(point);
        b2Vec2 vB = bodyB->GetLinearVelocityFromWorldPoint(point);
        float32 approachVelocity = b2Dot(vB -vA, worldManifold.normal);    */        
}

void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
    
}

static void ordenar(Colisionable** A, Colisionable** B) {
    
    Colisionable* Aptr = *A;
    Colisionable* Bptr = *B;
    
    int tipoDeA = Aptr->getTipo();
    int tipoDeB = Bptr->getTipo();

    if (tipoDeB < tipoDeA) {
        Colisionable* tmp = *B;
        *B = *A;
        *A = tmp;
    }
}
