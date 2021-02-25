#include "face.h"

Mere::Face::Face::Face(const std::string &name)
    : m_name(name)
{
}

std::string Mere::Face::Face::uuid() const
{
    return m_uuid;
}

void Mere::Face::Face::uuid(const std::string &uuid)
{
    m_uuid = uuid;
}

std::string Mere::Face::Face::name() const
{
    return m_name;
}

void Mere::Face::Face::name(const std::string &name)
{
    m_name = name;
}

std::string Mere::Face::Face::path() const
{
    return m_path;
}

void Mere::Face::Face::path(const std::string &path)
{
    m_path = path;
}

