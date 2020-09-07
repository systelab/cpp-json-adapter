#pragma once

#include <string>


namespace systelab { namespace json {

	class IJSONValue;

	class IJSONDocument
	{
	public:
		virtual ~IJSONDocument() {};

		virtual IJSONValue& getRootValue() = 0;
		virtual const IJSONValue& getRootValue() const = 0;

		virtual std::string serialize(bool pretty = false) const = 0;
	};

}}
