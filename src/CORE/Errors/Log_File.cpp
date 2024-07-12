#ifdef ENABLE_ERROR_LOG

#include "Error_Definition.h"
#include "Log_File.h"

#include <fstream>

void Atlas::CORE::Errors::ClearLogFile() {
	
	std::ofstream LogFile;

	LogFile.open(LOG_PATH, std::ofstream::out | std::ofstream::trunc);

	LogFile.close();
}

#endif