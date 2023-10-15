#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovements();
    Rectangle getCollisionRec();
    virtual void tick(float deltaTime);
    virtual Vector2 getScreenPos() = 0;
    bool getAlive() { return alive; }
    void setAlive(bool isAlive) { alive = isAlive; }

protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // Animation variables
    float runningTime{};
    int frame{};
    const int maxFrame{6};
    const float updateTime{1.f / 12.f};
    // 1.0: right, -1.0: left
    float rightleft{1.0};
    // Map Movement speed
    float speed{4.0};
    float width{};
    float height{};
    float scale{4.0};
    Vector2 velocity{};

private:
    bool alive{true};
};

#endif