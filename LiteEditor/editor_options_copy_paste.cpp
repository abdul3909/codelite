//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "editor_options_copy_paste.h"


// Declare the bitmap loading function
extern void wxCA7InitBitmapResources();

static bool bBitmapLoaded = false;


EditorOptionsCopyPasteBase::EditorOptionsCopyPasteBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCA7InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer2);
    
    wxArrayString m_radioBoxCopyOptionsArr;
    m_radioBoxCopyOptionsArr.Add(wxT("Copy / Cut the caret line to the clipboard"));
    m_radioBoxCopyOptionsArr.Add(wxT("Copy / Cut the caret line to the clipboard only when the caret line is not empty"));
    m_radioBoxCopyOptionsArr.Add(wxT("Do nothing"));
    m_radioBoxCopyOptions = new wxRadioBox(this, wxID_ANY, _("What to copy/cut when there is no selection:"), wxDefaultPosition, wxSize(-1,-1), m_radioBoxCopyOptionsArr, 1, wxRA_SPECIFY_COLS);
    m_radioBoxCopyOptions->SetSelection(0);
    
    boxSizer2->Add(m_radioBoxCopyOptions, 0, wxALL|wxEXPAND, 5);
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
}

EditorOptionsCopyPasteBase::~EditorOptionsCopyPasteBase()
{
}
