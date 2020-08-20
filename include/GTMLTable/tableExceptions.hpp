#ifndef GTMLTABLE_TABLEEXCEPTIONS_HPP
#define GTMLTABLE_TABLEEXCEPTIONS_HPP

#include <exception>

// File that defines exceptions for GTML::table

namespace GTML
{
	// Exception for when the file returns an IO error
	class tableIOError: public std::exception
	{
		public:
			tableIOError(std::string filename): std::exception(), filename(filename)
			{}

		protected:
			virtual const char* what() const throw()
			{
				return (std::string("IO error while loading/saving a table: ") + filename).c_str();
			}

			std::string filename;
	};

	// Exception for when the file cannot be opened
	class tableFileOpenError: public tableIOError
	{
		virtual const char* what() const throw()
		{
			return (std::string("Unable to load a file for a table: ") + filename).c_str();
		}
	};

	// Exception for when the file wasn't able to be loaded into the table
	class tableLoadError : public tableIOError
	{
		virtual const char* what() const throw()
		{
			return (std::string("Unable to load table from file: ") + filename).c_str();
		}
	};

	// Exception for when the file ended at an unexpected point
	class tableSaveError : public tableIOError
	{
		virtual const char* what() const throw()
		{
			return (std::string("Unable to save table to file : ") + filename).c_str();
		}
	};

	// Exception for when the file doesn't end when it should
	class tableExceptedEOFError: public tableIOError
	{
		virtual const char* what() const throw()
		{
			return (std::string("Excepted EOF but file didn't end when loading a table: ") + filename).c_str();
		}
	};

	// Exception for when the types of a table file are the not the same as that of the class
	class tableFileTypeError: public std::exception
	{
		public:
			tableFileTypeError(std::string filename): std::exception(), filename(filename)
			{}

		protected:
			virtual const char* what() const throw()
			{
				return (std::string("Input or output type of file does not correspond with that of class: ") + filename).c_str();
			}

			std::string filename;
	};
}

#endif