#pragma once

#include <memory>
#include <string>


namespace systelab { namespace json {

	class IJSONValue;

	class IJSONMember
	{
	public:
		virtual ~IJSONMember() {};

		virtual std::string getName() const = 0;
		virtual IJSONValue& getValue() const = 0;
	};

}}
