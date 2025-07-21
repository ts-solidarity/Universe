#pragma once


#include <memory>


class Base : public std::enable_shared_from_this<Base>
{

public:
	virtual ~Base() = default;
	Base();

	int GetUniqueId() const;
	int GetUniqueId();
	
	std::shared_ptr<Base> Get();


public:

	static int globalId;


private:

	int m_UniqueId = -1;

};

