#pragma once

#include <stdint.h>

namespace RobotarmLib
{

    enum class Joints
    {
        UNDEFINED,
        SHOULDER_ROTATE,
        SHOULDER_UP_DOWN,
        ELBOW,
        WRIST_ROTATE,
        WRIST_UP_DOWN,
        GRIPPER
    };

    class Joint
    {
    private:
        uint8_t pinNr;

    public:
        uint16_t currentPosition;
        uint16_t targetPosition;
        uint32_t targetTime;

        uint16_t minPosition;
        uint16_t maxPosition;
        uint16_t centerPosition;

        bool begin(uint8_t pinNr);
        bool begin(uint8_t pinNr, uint16_t minPosition, uint16_t maxPosition);
        void update();
        bool stop();
        bool moveTo(uint16_t newPosition);
        bool moveTo(uint16_t newPosition, uint32_t timeToComplete);
    };

}