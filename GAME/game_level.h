#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "sprite_renderer.h"
#include "resource_manager.h"


class GameLevel
{
public:
    std::vector<GameObject> Bricks;
    
    GameLevel() { }
    // loads level from file
    void Load(const char* file, unsigned int levelWidth, unsigned int levelHeight);
    //关卡数据是一个矩阵
    //数字0：无砖块，表示关卡中空的区域
    //数字1：一个坚硬的砖块，不可被摧毁
    //大于1的数字：一个可被摧毁的砖块，不同的数字大小区分砖块的颜色
    // render level
    void Draw(SpriteRenderer& renderer);
    // check if the level is completed (all non-solid tiles are destroyed)
    bool IsCompleted();
private:
    // initialize level from tile data
    void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
};

#endif