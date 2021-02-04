
#ifndef CORE_H
#define CORE_H


#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <memory>
#include <cassert>
#include <filesystem>


#ifndef DRK_EN_LOGGING
#define DRK_EN_LOGGING
#endif


namespace Drk
{
    ////////// Refs //////////
    
    template <typename T>
    using Ptr = std::shared_ptr<T>;
    
    template <typename T, typename ... Args>
    constexpr Ptr<T> make_ptr(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
    

    ////////// Logger //////////
    
    enum class LogType
    {
        INFO,
        WARN,
        ERR
    };

    std::ostream& operator<<(std::ostream& os, LogType& type);

    class Logger
    {
    public:
        static void init(void);
        static void log(LogType type, const char* msg);
        static void log(LogType type, const std::string& msg);
        static void save(void);
    
    private:
        static std::ofstream logfile;
        static std::tm* logtime;
        static std::string fp;
        static bool ready;
    };

    #ifdef DRK_EN_LOGGING
        #define LOG(type, msg) Logger::log(type, msg)
    #else
        #define LOG(type, msg)
    #endif


    ////////// Asserts //////////

    class Assert
    {
    public:
        static void failed(const std::string& msg, const std::string& file, int line);
    };

    #ifdef DRK_EN_ASSERTS
        #define ASSERT(cond, msg) \
        do { \
            if (!(cond)) \
            { \
                Assert::failed(msg, std::filesystem::path(__FILE__).filename().string(), __LINE__); \
                assert(false); \
            } \
        } while (false)
    #else
        #define ASSERT(cond, msg)
    #endif
}


#endif // CORE_H
