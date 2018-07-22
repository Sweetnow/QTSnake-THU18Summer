#ifndef GAMEMAP_H
#define GAMEMAP_H

#include<vector>
#include"object.h"
#include"snake.h"
#include"wall.h"
#include"food.h"

#define pGAMEMAP (Gamemap::Instance())

const int TIME_BASE=300;    //最低难度回合时长

class Gamemap
{
private:
    Gamemap();
    Gamemap(const Gamemap&){}
public:
    static Gamemap* Instance(){
        static Gamemap instance;
        return &instance;
    }


    //将墙导入地图，并检测墙是否出现连续,返回true为不连续(正常)
    bool Object2Map(const Wall&);
    // 将食物导入地图，并检测食物是否可以被接触，可以返回true
    bool Object2Map(const Food&);
    //将蛇导入地图
    void Snake2Map(const Snake&);
    //删除地图中的蛇
    void ClearSnake();
    //初始化地图
    void Init();
    std::vector<const Object*>m_vObj;
    INFO nowInfo;

    //将Obj放入显示序列
    void _Object2Map(const Object&);

};

#endif // GAMEMAP_H
