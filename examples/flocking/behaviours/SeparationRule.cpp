#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"


Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Try to avoid boids too close
    
    Vector2 separatingForce = { 0,0 };
    
    float desiredDistance = desiredMinimalDistance;
    /*
    //do the opposite of cohesion rule (find average of positions, then move away from it) do the opposite subtraction to find the vector

    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
    */
    float totalX = 0;
    float totalY = 0;
    float counter = 0;
    for (auto neighbor : neighborhood)
    {
        float calcX = boid->getPosition().x - neighbor->getPosition().x;
        float calcY = boid->getPosition().y - neighbor->getPosition().y;
        float boidDistance = sqrt(pow(calcX, 2) + pow(calcY, 2)); //get real distance;

        if (boidDistance > 0 && boidDistance <= desiredDistance) //boid within minimal distance
        {
            //Vector2 normalizedDistance = Vector2(calcX, calcY).normalized();

            //Vector2 force = Vector2(normalizedDistance.x / boidDistance, normalizedDistance.y / boidDistance);

            Vector2 displacement = Vector2(calcX, calcY);
            // The force is inversely proportional to distance
            Vector2 force = displacement / exp(boidDistance / 100.f);
            
            separatingForce.x += force.x;
            separatingForce.y += force.y;
            counter++;
        }
    }
    
    if (counter == 0)
    {
        return separatingForce;
    }
    return separatingForce.normalized();
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
