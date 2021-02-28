
#ifndef CORE_HPP
#define CORE_HPP


#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <ctime>


#ifdef DRK_DEBUG

    #define DRK_EN_LOGGING
    #define DRK_EN_ASSERTS

    #ifdef __linux__
        #include <signal.h>
        #define DRK_DEBUG_BREAK raise(SIGTRAP)
    #elif _WIN32
        #define DRK_DEBUG_BREAK __debugbreak()
    #endif

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

    
    ////////// Logging //////////
    #ifdef DRK_EN_LOGGING

        #define DRK_LOGGER_INIT(name) Drk::Logger::init(name);
        #define DRK_LOG(type, msg)    Drk::Logger::log(LogType::type, msg);
        #define DRK_LOGGER_SAVE()     Drk::Logger::save();

        enum class LogType;

        class Logger // Singleton
        {
        public:
            static void init(const char* name="");
            static void log(LogType type, const char* msg);
            static void log(LogType type, const std::string& msg);
            static void save(void);

            Logger(const char* name);
            ~Logger(void);
            Logger(Logger&) = delete;
            Logger& operator=(const Logger&) = delete;

        private:
            std::ofstream logfile;

            static Ptr<Logger> s_instance;
        };

        enum class LogType
        {
            INFO,
            WARN,
            ERR,
            ASSERT
        };

        std::ostream& operator<<(std::ostream& os, LogType& type);

    #else // Unimplemented
        #define DRK_LOGGER_INIT(name)
        #define DRK_LOG(type, msg)
        #define DRK_LOG()
    #endif // DRK_EN_LOGGING


    ////////// Asserts //////////
    #ifdef DRK_EN_ASSERTS

        // std::filesystem::path(__FILE__).filename().string() ???
        #define DRK_ASSERT(cond, msg)                         \
        do {                                                  \
            if (!(cond))                                      \
                Drk::Assert::failed(msg, __FILE__, __LINE__); \
        } while (false)
        
        namespace Assert
        {
            void failed(const std::string& msg, const std::string& file, int line);
        }

    #else // Unimplemented 
        #define DRK_ASSERT(cond, msg)
    #endif // DRK_EN_ASSERTS
}


#endif // CORE_HPP
