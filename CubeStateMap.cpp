extern "C" {

#include "CubeStateMap.h"

}

#include <unordered_map>
#include <cstring>

struct CubeStateHash {
    std::size_t operator()(CubeState cubeState) const {
        static_assert(sizeof(CubeState) == sizeof(std::size_t), "Can't compute hash");
        return serialize(cubeState);
    };
};

struct CubeStateComparator {
    bool operator()(CubeState lhs, CubeState rhs) const {
        return isSame(lhs, rhs);
    }
};


static std::unordered_map<CubeState, int,
        CubeStateHash, CubeStateComparator> MapOfStates;

extern "C" void insertState(CubeState state, int move_no)
{
    MapOfStates.insert({state, move_no});
}

extern "C" int getState(CubeState state)
{
    return MapOfStates.at(state);
}

extern "C" unsigned long isStateInMap(CubeState state)
{
    return MapOfStates.count(state);
}

extern "C" void clearMap()
{
    MapOfStates.clear();
}

extern "C" void forEachElement(void(*fun)(CubeState key, int val))
{
    for (auto& kv : MapOfStates)
    {
        fun(kv.first, kv.second);
    }
}