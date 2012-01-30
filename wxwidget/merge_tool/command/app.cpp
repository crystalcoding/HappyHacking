#include <wx/wx.h>
#include "app.h"
#include "dialog.h"

DECLARE_APP(app)
IMPLEMENT_APP(app)

bool app::OnInit()
{
  dialog *my_dialog = new dialog(wxT("Dialog Title"));
  my_dialog->Show(true);

  return true;
}
