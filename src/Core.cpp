#include "Core.h"

#include <EclipseEngine/include/EclipseTime.h>
#include <EclipseEngine/include/Console.h>
#include <EclipseEngine/include/Core.h>
#include <termcolor/termcolor.hpp>

// std
#include <iostream>
#include <stdexcept>
#include <string>

namespace Eclipse
{
	namespace Debug
	{
		void Log(const char* str)
		{

			// TODO: Reimplement colours.

			std::stringstream ss;

			ss << termcolor::green << "[LOG] " << Engine::EclipseTime::GetTimeAsString() << termcolor::green << " " << str << termcolor::reset;

			Engine::Console::WriteLine(ss);
		}

		void Debug(const char* str)
		{
			std::stringstream ss;

			ss << termcolor::yellow << "[DEBUG] " << Engine::EclipseTime::GetTimeAsString() << termcolor::green << " " << str << termcolor::reset;

			Engine::Console::WriteLine(ss);
		}

		void Error(const char* str)
		{
			std::stringstream ss;

			ss << termcolor::red << "[ERROR] " << Engine::EclipseTime::GetTimeAsString() << str << termcolor::reset;

			Engine::Console::WriteLine(ss);
		}

		void NotImplemented(const char* functionName)
		{
			Error((std::string(functionName) + " has not been implemented.").c_str());
			throw std::invalid_argument(std::string(functionName) + " has not been implemented.");
		}
	}
}