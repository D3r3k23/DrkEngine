
#ifndef ASSERT_H
#define ASSERT_H


#include "Log.h"

#include <string>
#include <cassert>
#include <filesystem>


namespace Drk
{
    class Assert
    {
        static void failed(const std::string& msg, const char* file, int line)
        {
            std::string log_msg("Assert: " + (std::string)file + " [" std::to_string(line) "] " + msg);
            LOG(LogType::ERROR, log_msg);
        }
    }
}


#ifdef EN_ASSERT
    #define ASSERT(cond, msg) \
    do \
    {
        if (!(cond)) \
        { \
            Drk::Assert::failed(msg, std::filesystem::path(__FILE__).filename().string(), __LINE__); \
            std::assert(0); \
        } \
    } while (false)
#else
    #define ASSERT(cond, msg)
#endif


#endif // ASSERT_H
