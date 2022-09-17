#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Try to avoid boids too close
    
    Vector2 separatingForce;
    
    float desiredDistance = desiredMinimalDistance;
    /*
    //do the opposite of cohesion rule (find average of positions, then move away from it) do the opposite subtraction to find the vector

    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
    if (!neighborhood.empty()) {
        Vector2 position = boid->transform.position;
        int countCloseFlockmates = 0;


    }

    separatingForce = Vector2::normalized(separatingForce);

    return separatingForce;
    */
    float totalX = 0;
    float totalY = 0;
    float counter = 0;
    for (auto boid : neighborhood)
    {
        //boid.position (in GameObject.h)
        //if(distance < desiredDistance

        float boidDistance = sqrt(pow(boid->getPosition().x - getPosition().x, 2) + pow(boid->getPosition().y - getPosition().y, 2) * 1.0); //getting distance between each boid in neighborhood


        if (boidDistance < desiredDistance)
        {
            totalX += boid->getPosition().x;
            totalY += boid->getPosition().y;

            counter++;
        }
        
    }

    //find the average of the positions of all boids in neighborhood, return a vector away from that point

    if (counter == 0)
    {
        return Vector2(0, 0);
    }
    else
    {
        float newX = totalX / counter;
        float newY = totalY / counter;
        Vector2 newTarget = Vector2(newX, newY);
        Vector2 moveForce = boid->getPosition() - newTarget;
        separatingForce = moveForce.normalized();

        return separatingForce;
    }
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
