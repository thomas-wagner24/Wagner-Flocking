#include "WindRule.h"
#include <imgui.h>
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 WindRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    // todo: add a wind force here
    // hint: use the windAngle variable

    //return Vector2 of the wind angle (use trig rules)
    //Vector2(cos(x),sin(x))
    double radWindAngle = windAngle*(M_PI / 180);

    float newX = (float)cos(radWindAngle);
    float newY = (float)sin(radWindAngle);

    return Vector2(newX, newY).normalized();

    //return Vector2::zero();
}

bool WindRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valueHasChanged = false;

    if (ImGui::SliderAngle("Wind Direction", &windAngle, 0)) {
        valueHasChanged = true;
    }

    return valueHasChanged;
}