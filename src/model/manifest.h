#ifndef MERE_FACE_MANIFEST_H
#define MERE_FACE_MANIFEST_H

#include "../global.h"
#include <iostream>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Manifest
{
public:
    Manifest();
    explicit Manifest(const std::string &fqfn);

    std::string file() const;

    std::string uuid() const;
    void uuid(const std::string &uuid);

    std::string name() const;
    void name(const std::string &name);

    std::string note() const;
    void note(const std::string &note);

    std::string when() const;
    void when(const std::string &when);

    std::string site() const;
    void site(const std::string &site);

    std::string hash() const;
    void hash(const std::string &hash);

    std::string author() const;
    void author(const std::string &author);

    std::string version() const;
    void version(const std::string &version);

private:
    std::string m_uuid;
    std::string m_name;
    std::string m_note;
    std::string m_when;
    std::string m_site;
    std::string m_hash;

    std::string m_author;
    std::string m_version;

    std::string m_fqfn;
};

}
}
#endif // MERE_FACE_MANIFEST_H
