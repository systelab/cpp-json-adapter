#pragma once

#include <string>


namespace systelab { namespace json {

	class IJSONDocument;

	class IJSONSchemaValidator
	{
	public:
		virtual ~IJSONSchemaValidator() {};

		virtual bool validate(const IJSONDocument&, std::string& reason) const = 0;
	};

}}
