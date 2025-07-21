#include "Base.h"

int Base::globalId = 1;


Base::Base()
{
    m_UniqueId = ++globalId;
}

int Base::GetUniqueId() const
{
    return m_UniqueId;
}

int Base::GetUniqueId()
{
    return m_UniqueId;
}

std::shared_ptr<Base> Base::Get()
{
    return shared_from_this();
}
