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
    //�ؿ�������һ������
    //����0����ש�飬��ʾ�ؿ��пյ�����
    //����1��һ����Ӳ��ש�飬���ɱ��ݻ�
    //����1�����֣�һ���ɱ��ݻٵ�ש�飬��ͬ�����ִ�С����ש�����ɫ
    // render level
    void Draw(SpriteRenderer& renderer);
    // check if the level is completed (all non-solid tiles are destroyed)
    bool IsCompleted();
private:
    // initialize level from tile data
    void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
};

#endif