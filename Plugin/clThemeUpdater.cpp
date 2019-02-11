#include "clThemeUpdater.h"
#include "codelite_events.h"
#include "event_notifier.h"
#include "clSystemSettings.h"
#include <algorithm>

clThemeUpdater::clThemeUpdater()
{
    EventNotifier::Get()->Bind(wxEVT_CMD_COLOURS_FONTS_UPDATED, &clThemeUpdater::OnColoursAndFontsChanged, this);
}

clThemeUpdater::~clThemeUpdater()
{
    EventNotifier::Get()->Unbind(wxEVT_CMD_COLOURS_FONTS_UPDATED, &clThemeUpdater::OnColoursAndFontsChanged, this);
}

clThemeUpdater& clThemeUpdater::Get()
{
    static clThemeUpdater updater;
    return updater;
}

void clThemeUpdater::OnColoursAndFontsChanged(clCommandEvent& e)
{
    e.Skip();
    CallAfter(&clThemeUpdater::UpdateGlobalColours);
}

void clThemeUpdater::UpdateGlobalColours()
{
    std::for_each(m_windows.begin(), m_windows.end(), [&](wxWindow* win) {
        win->SetBackgroundColour(clSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));
        win->SetForegroundColour(clSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
        win->Refresh();
    });
}

void clThemeUpdater::RegisterWindow(wxWindow* win) { m_windows.push_back(win); }
