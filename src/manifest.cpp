#include "manifest.h"

Mere::Face::Manifest::Manifest()
{

}

Mere::Face::Manifest::Manifest(const std::string &fqfn)
    : m_fqfn(fqfn)
{

}

std::string Mere::Face::Manifest::file() const
{
    return m_fqfn;
}

std::string Mere::Face::Manifest::uuid() const
{
    return m_uuid;
}

void Mere::Face::Manifest::uuid(const std::string &uuid)
{
    m_uuid = uuid;
}

std::string Mere::Face::Manifest::name() const
{
    return m_name;
}

void Mere::Face::Manifest::name(const std::string &name)
{
    m_name = name;
}

std::string Mere::Face::Manifest::note() const
{
    return m_note;
}

void Mere::Face::Manifest::note(const std::string &note)
{
    m_note = note;
}

std::string Mere::Face::Manifest::when() const
{
    return m_when;
}

void Mere::Face::Manifest::when(const std::string &when)
{
    m_when = when;
}

std::string Mere::Face::Manifest::site() const
{
    return m_site;
}

void Mere::Face::Manifest::site(const std::string &site)
{
    m_site = site;
}

std::string Mere::Face::Manifest::hash() const
{
    return m_hash;
}

void Mere::Face::Manifest::hash(const std::string &hash)
{
    m_hash = hash;
}


