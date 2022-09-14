#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 averageVelocity = Vector2::zero();

    // todo: add your code here to align each boid in a neighborhood
    // hint: iterate over the neighborhood

    //find the average of the velocity of all boids in neighborhood, return it
    //boid->getVelocity()

    float totalX = 0;
    float totalY = 0;
    float counter = 0;
    for (auto boid : neighborhood)
        // auto: automatic  typing
        //foreach only works well for pointers bc foreach would create a copy if it wasnt a pointer
    {
        totalX += boid->getVelocity().x;
        totalY += boid->getVelocity().y;

        counter++;
    }

    //find the average of the velocities of all boids in neighborhood, return that velocity
    float newX = totalX / counter;
    float newY = totalY / counter;
    Vector2 newVelocity = Vector2(newX, newY); //location the boid should move towards
    return newVelocity.normalized();

}