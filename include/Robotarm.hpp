#pragma once

#include <stdint.h>
#include "Joints.hpp"
#include "Parser.hpp"

namespace RobotarmLib
{

    enum class ArmPositions
    {
        PARK,
        READY,
        STRAIGHT
    };

    class Robotarm
    {
    private:
        bool moveToPosition(MoveCommand command);

    public:
        bool begin();
        void update();
        bool moveToPredefinedPosition(ArmPositions position);
        bool sendCommand(char* string);
        bool stop();
    };

}