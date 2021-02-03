
#ifndef ASSERT_H
#define ASSERT_H


#include "Log.h"

#include <string>
#include <cassert>
#include <filesystem>


namespace Drk
{
    void failed(const char* msg, const char* file, int line)
    {
        std::string log_msg((std::string)msg + (std::string)file + std::to_string(line);
        LOG(LogType::ERR, log_msg);
    }
}


#ifdef EN_ASSERT
    #define ASSERT(cond, msg) /
    { /
        if (!(cond)) /
        { /
            Drk::failed(msg, std::filesystem::path(__FILE__).filename().string(), __LINE__); /
            std::assert(false); /
        } /
    } /
#else
    #define ASSERT(cond, msg)
#endif


#endif // ASSERT_H
