#pragma once

#include <string>
#include <memory>
#include <vector>

namespace systelab { namespace json {

	enum Type
	{
		NULL_TYPE = 0,
		BOOLEAN_TYPE = 1,
		OBJECT_TYPE = 2,
		ARRAY_TYPE = 3,
		STRING_TYPE = 4,
		NUMBER_TYPE = 5
	};

	class IJSONDocument;
	class IJSONMember;

	class IJSONValue
	{
		template <typename Ref_> class ArrayIterator_;

	public:
		
		using ArrayIterator = ArrayIterator_<IJSONValue&>;
		using ArrayConstIterator = ArrayIterator_<const IJSONValue&>;

		virtual ~IJSONValue() {};

		virtual Type getType() const = 0;
		virtual void setType(Type) = 0;

		// Only for boolean values
		virtual bool getBoolean() const = 0;
		virtual void setBoolean(bool) = 0;

		// Only for string values
		virtual std::string getString() const = 0;
		virtual void setString(const std::string&) = 0;

		// Only for number values
		virtual bool isInteger() const = 0;
		virtual int getInteger() const = 0;
		virtual double getDouble() const = 0;

		virtual void setInteger(int) = 0;
		virtual void setLong(long) = 0;
		virtual void setLongLong(long long) = 0;
		virtual void setDouble(double) = 0;

		// Only for Null values
		virtual bool isNull() const = 0;
		virtual void setNull() = 0;

		// Only for object values
		virtual unsigned int getObjectMemberCount() const = 0;
		virtual bool hasObjectMember(const std::string&) const = 0;
		virtual std::vector<std::string> getObjectMemberNames() const = 0;
		virtual IJSONValue& getObjectMemberValue(const std::string&) const = 0;

		virtual void addMember(const std::string& name, bool value) = 0;
		virtual void addMember(const std::string& name, int value) = 0;
		virtual void addMember(const std::string& name, long value) = 0;
		virtual void addMember(const std::string& name, long long value) = 0;
		virtual void addMember(const std::string& name, double value) = 0;
		virtual void addMember(const std::string& name, const char* value) = 0;
		virtual void addMember(const std::string& name, const std::string& value) = 0;
		virtual void addMember(const std::string& name, std::unique_ptr<IJSONValue>) = 0;
		virtual void removeMember(const std::string& name) = 0;

		// Only for array values
		virtual unsigned int getArrayValueCount() const = 0;
		virtual IJSONValue& getArrayValue(unsigned int) const = 0;
		
		virtual ArrayIterator begin() = 0;
		virtual ArrayIterator end() = 0;
		virtual ArrayConstIterator begin() const = 0;
		virtual ArrayConstIterator end() const = 0;

		virtual void addArrayValue(std::unique_ptr<IJSONValue>) = 0;
		virtual void clearArray() = 0;

		// JSON pointer
		virtual IJSONValue* getJSONPointerValue(const std::string& jsonPointer) = 0;
		virtual const IJSONValue* getJSONPointerValue(const std::string& jsonPointer) const = 0;

		// Factory methods
		virtual std::unique_ptr<IJSONValue> buildValue(Type) const = 0;
		virtual std::unique_ptr<IJSONDocument> buildDocument() const = 0;

	private:

		// Array iterator for range-loop
		template <typename Ref_>
		class ArrayIterator_
		{
		public:

			~ArrayIterator_() = default;

			ArrayIterator_() = delete;

			ArrayIterator_(const IJSONValue& value, int distance) : pVal_(&value), distance_(distance) {};

			Ref_ operator*() const
			{
				return (Ref_)pVal_->getArrayValue(distance_);
			}

			void operator++()
			{
				++distance_;
			}

			bool operator!=(const ArrayIterator_<Ref_>& it)
			{
				return distance_ != it.distance_;
			}

		private:

			const IJSONValue* pVal_;
			int distance_;
		};
	};

}}
