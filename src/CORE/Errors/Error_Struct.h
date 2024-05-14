#pragma once

#ifdef ENABLE_ERROR_LOG

#include <iostream>

using std::string;

namespace Atlas {
	namespace CORE {
		namespace Errors {

			enum ErrorType {
				None = -2,
				Unknown = -1,
				Core = 0,
				ShaderCompilation = 1,
				Buffer = 2,
				Math = 3,
				OpenGL = 4,
				FileRead = 5,
				FileWrite = 6
			};
			enum ErrorSeverity {
				Debug, 
				Info,
				Warning, //Could cause unexpected outcomes
				Moderate, //Will cause unexpected outcomes
				Critical, //Execution can stop
				Fatal, //Execution will stop

			};

			static string ErrorTypeToString(ErrorType s);
			static string ErrorSeverityToString(ErrorSeverity s);

			struct Error {
				ErrorType Type;
				ErrorSeverity Severity;

				unsigned int ErrorCode;

				string Description;

				string file;
				string function;

				int line;


				Error();
				Error(ErrorType t_E, ErrorSeverity t_S,
					string t_Description,
					string t_File, string t_Function, int t_Line);

				string GetErrorMessage();

				void LogErrorToFile();
				void LogErrorToFile(string path);
				
				void LogDebugInfoToFile();
			};
		}
	}
}

#endif