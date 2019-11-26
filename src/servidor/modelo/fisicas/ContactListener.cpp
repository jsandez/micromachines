#include "includes/servidor/modelo/fisicas/ContactListener.h"

#include "includes/servidor/modelo/Colisionable.h"

#include "includes/servidor/modelo/entidades/carrera/Checkpoint.h"
#include "includes/servidor/modelo/superficies/SuperficieArena.h"
#include "includes/servidor/modelo/entidades/Vehiculo.h"
#include "includes/servidor/modelo/fisicas/Fisicas.h"

// Métodos privados
static void ordenar(Colisionable** A, Colisionable** B);

ContactListener::ContactListener(Fisicas& fisicas) :
    fisicas_(fisicas) {
}

ContactListener::~ContactListener() {    
}
#include <iostream>
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
            //TODO: IMPLEMENTAR
        }
        if (colisionableB->getTipo() == Colisionable::tipos::SUPERFICIE_ARENA_) {
            vehiculoVsArena(*static_cast<Vehiculo*>(colisionableA), *static_cast<SuperficieArena*>(colisionableB));
        }
        if (colisionableB->getTipo() == Colisionable::tipos::CHECKPOINT_) {
            vehiculoVsCheckpoint(*static_cast<Vehiculo*>(colisionableA), *static_cast<Checkpoint*>(colisionableB));
        }
        if (colisionableB->getTipo() == Colisionable::tipos::SUPERFICIE_TIERRA_) {
            //TODO: No se pueden modificar valores acá, hay que obtener el b2Vehiculo
        }
        if (colisionableB->getTipo() == Colisionable::tipos::SUPERFICIE_PISTA_) {
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

void ContactListener::vehiculoVsArena(Vehiculo& vehiculo, SuperficieArena& arena) {
    //TODO: VER DONDE VA LA EXPLOSION Y COMO
    fisicas_.reubicar(vehiculo, vehiculo.getPuntoRespawn());
}
void ContactListener::vehiculoVsCheckpoint(Vehiculo& vehiculo, Checkpoint& checkpoint) {
   checkpoint.registrarPaso(vehiculo);
}

void ContactListener::vehiculoVsVehiculo(Vehiculo& vehiculoA, Vehiculo& vehiculoB) {
    uint8_t disminucionVida = CONFIG_SERVIDOR.disminucionVidaChoqueConVehiculo();    
}
