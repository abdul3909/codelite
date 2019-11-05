#ifndef LSPDETECTOR_HPP
#define LSPDETECTOR_HPP

#include "LanguageServerEntry.h"
#include "wx/arrstr.h"
#include <wx/sharedptr.h>
#include <wx/string.h>

class LSPDetector
{
protected:
    wxString m_name;
    wxString m_command;
    wxArrayString m_langugaes;
    wxString m_connectionString;
    int m_priority = 50;

public:
    typedef wxSharedPtr<LSPDetector> Ptr_t;

public:
    LSPDetector(const wxString& name);
    virtual ~LSPDetector();
    bool IsOk() const { return !m_command.IsEmpty(); }
    void SetCommand(const wxString& command) { this->m_command = command; }
    const wxString& GetCommand() const { return m_command; }
    void SetLangugaes(const wxArrayString& langugaes) { this->m_langugaes = langugaes; }
    void SetName(const wxString& name) { this->m_name = name; }
    const wxArrayString& GetLangugaes() const { return m_langugaes; }
    wxArrayString& GetLangugaes() { return m_langugaes; }
    const wxString& GetName() const { return m_name; }
    void SetConnectionString(const wxString& connectionString) { this->m_connectionString = connectionString; }
    const wxString& GetConnectionString() const { return m_connectionString; }
    void SetPriority(int priority) { this->m_priority = priority; }
    int GetPriority() const { return m_priority; }
    virtual bool Locate() = 0;
    virtual void GetLanguageServerEntry(LanguageServerEntry& entry);
};

#endif // LSPDETECTOR_HPP
