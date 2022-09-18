#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood
    float totalX = 0;
    float totalY = 0;
    float counter = 0;
    for (auto neighbor : neighborhood)
        // auto: automatic  typing
        //foreach only works well for pointers bc foreach would create a copy if it wasnt a pointer
        //(explanation from quincy)
    {
        //boid.position (in GameObject.h)
        if (neighbor != boid)
        {
            totalX += neighbor->getPosition().x;
            totalY += neighbor->getPosition().y;

            counter++;
        }
        
    }

    //find the average of the positions of all boids in neighborhood, return a vector towards that point
    if (counter == 0)
    {
        return Vector2(0, 0);
    }
    else
    {
        float newX = totalX / counter;
        float newY = totalY / counter;
        Vector2 newTarget = Vector2(newX - boid->getPosition().x, newY - boid->getPosition().y); //location the boid should move towards
        Vector2 moveForce = newTarget - boid->getPosition();
        cohesionForce = moveForce.normalized();
        //cohesionForce = moveForce;

        return cohesionForce;
    }
    
}