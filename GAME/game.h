#ifndef GAME_H
#define GAME_H
#include <vector>
#include <tuple>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_level.h"
#include "power_up.h"

//  枚举类型在c++11 enum改为enum class 防止内部成员出现重定义
enum class GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

enum class Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};
// Defines a Collision typedef that represents collision data
typedef std::tuple<bool, Direction, glm::vec2> Collision; 

// Initial(最初的) size of the player paddle(船桨)
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// Initial velocity(速度) of the player paddle   
const float PLAYER_VELOCITY(500.0f);
// Initial velocity of the Ball
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// Radius of the ball object
const float BALL_RADIUS = 12.5f;

class Game
{
public:
    GameState               State;
    bool                    Keys[1024];
    bool                    KeysProcessed[1024];
    unsigned int            Width, Height;
    std::vector<GameLevel>  Levels;
    std::vector<PowerUp>    PowerUps;
    unsigned int            Level;
    unsigned int            Lives;
    // constructor/destructor(结构/析构)
    Game(unsigned int width, unsigned int height);
    ~Game();//  It will be executed when it is destroyed
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    void DoCollisions();
    // reset(重置)
    void ResetLevel();
    void ResetPlayer();
    // powerups(升级道具)
    void SpawnPowerUps(GameObject& block);  //  spawn 产生（产卵）
    void UpdatePowerUps(float dt);
};

#endif