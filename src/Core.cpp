#include "Core.h"

#include <EclipseEngine/include/EclipseTime.h>
#include <EclipseEngine/include/Console.h>
#include <EclipseEngine/include/Core.h>

// std
#include <stdexcept>
#include <string>

namespace Eclipse
{
    namespace Debug
    {
        void Log(const std::string& str, const std::string& function, unsigned line)
        {
            Engine::Console::Write("[LOG] ", Engine::Console::ConsoleColor::GREEN);
            Engine::Console::Write(Engine::EclipseTime::GetTimeAsString() + " ", Engine::Console::ConsoleColor::DARKGREEN);
            Engine::Console::Write(function + " ", Engine::Console::ConsoleColor::GREEN);
            Engine::Console::Write(std::to_string(line) + " ", Engine::Console::ConsoleColor::GREEN);
            Engine::Console::WriteLine(str);
        }

        void Debug(const std::string& str, const std::string& function, unsigned line)
        {
            Engine::Console::Write("[DEBUG] ", Engine::Console::ConsoleColor::YELLOW);
            Engine::Console::Write(Engine::EclipseTime::GetTimeAsString() + " ", Engine::Console::ConsoleColor::DARKYELLOW);
            Engine::Console::Write(function + " ", Engine::Console::ConsoleColor::YELLOW);
            Engine::Console::Write(std::to_string(line) + " ", Engine::Console::ConsoleColor::YELLOW);
            Engine::Console::WriteLine(str);
        }

        void Error(const std::string& str, const std::string& function, unsigned line)
        {
            Engine::Console::Write("[ERROR] ", Engine::Console::ConsoleColor::RED);
            Engine::Console::Write(Engine::EclipseTime::GetTimeAsString() + " ", Engine::Console::ConsoleColor::DARKRED);
            Engine::Console::Write(function + " ", Engine::Console::ConsoleColor::RED);
            Engine::Console::Write(std::to_string(line) + " ", Engine::Console::ConsoleColor::RED);
            Engine::Console::WriteLine(str);
        }

        void NotImplemented(const std::string& functionName, const std::string& function, unsigned line)
        {
            Error((std::string(functionName) + " has not been implemented.").c_str());
            throw std::invalid_argument(std::string(functionName) + " has not been implemented.");
        }
    }
}