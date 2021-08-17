#pragma once

#include <stdint.h>

#include "Joints.hpp"

namespace RobotarmLib {

    enum class MessageTypes
    {
        INVALID,
        STOP,
        MOVEMENT,
        PREDEFINED_MOVEMENT,
        CENTER_OFFSET,
        QUERY_STATUS,
        QUERY_PULSE_WIDTH
    };

    class Parser
    {
    private:
        // TODO: vector of pairs (pointer to first char of segment | pointer to char just outside of segment)

        void splitStringInSegments();
        
        bool isStopCommand();
        bool isQueryCommand();
        bool isPositionQueryCommand();
        bool isJoint(uint8_t segmentIndex);
        bool isOffset(uint8_t segmentIndex);
        bool isPosition(uint8_t segmentIndex);
        bool isSpeed(uint8_t segmentIndex);
        bool isTime(uint8_t segmentIndex);

        Joints getJoint(uint8_t segmentIndex);
        uint16_t getOffset(uint8_t segmentIndex);
        uint16_t getPosition(uint8_t segmentIndex);
        uint16_t getSpeed(uint8_t segmentIndex);
        uint32_t getTime(uint8_t segmentIndex);

    public:
        // To be read after the parsing is complete
        MessageTypes messageType;
        // TODO: Vector of MoveCommands

        bool parseString(char* string);
    };

    struct MoveCommand
    {
    public:
        MoveCommand(Joints joint);

        Joints joint;
        uint16_t newPosition;
        uint16_t speed;
        uint32_t timeToComplete;
    };

}