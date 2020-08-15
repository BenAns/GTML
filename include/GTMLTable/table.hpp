#ifndef GTMLTABLE_TABLE_HPP
#define GTMLTABLE_TABLE_HPP

// Main header file GTML::table, contains the class body and includes other headers for methods

namespace GTML
{
	template<typename inputType, typename outputType = inputType>
	class table
	{
		public:
			// Constructors and destructors
			table();
			table(const table<inputType, outputType>& srcTable) = default;
			table(table<inputType, outputType>&& srcTable) = default;

			~table();

			// Methods to do with manipulating the table itself in memory
			void loadFile(std::string filename);
			void saveFile(std::string filename);

			void createTable(inputType start, inputType end, inputType step, outputType(*func)(inputType funcInput));

			// Methods to do with using the table
			outputType operator()(inputType funcInput) const;

		private:
			// Table data
			outputType* tableData;
			inputType start, end, step;

			// Miscellaneous members
			bool initialised;
	};
}

#include "constructorsAndDestructors.hpp"
#include "useTableMethods.hpp"
#include "createTableMethods.hpp"

#endif