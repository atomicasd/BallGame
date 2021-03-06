#pragma once
#include <string>

class IProperty
{
public: 
	virtual ~IProperty() {}

	virtual const std::string &GetName() const = 0;

	//virtual bool IsNull() const = 0;

	virtual bool IsDirty() const = 0;
	virtual void ClearDirty() = 0;

	//virtual std::string ToString() const = 0;
	//virtual void SetFromString(const std::string &value) = 0;
	//virtual int GetTypeId() const = 0;
};