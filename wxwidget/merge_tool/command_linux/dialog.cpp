#include "dialog.h"

dialog::dialog(const wxString& title):wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)
{
  create_controls();
}

void dialog::create_controls()
{
  top_sizer = new wxBoxSizer(wxVERTICAL);
  this->SetSizer(top_sizer);
  box_sizer = new wxBoxSizer(wxVERTICAL);


  listbox_panel = new wxPanel(this, wxID_ANY);
  line2 = new wxStaticLine(listbox_panel);
  wxArrayString command_strings;
  command_strings.Add(wxT("Pidgin"));
  command_strings.Add(wxT("FireFox"));
  command_strings.Add(wxT("Mail"));
  command_strings.Add(wxT("SVN"));
  command_strings.Add(wxT("Report Maint."));

  wxListBox* command_listbox = new wxListBox(listbox_panel, COMMAND_LISTBOX_ID, wxDefaultPosition, wxDefaultSize, command_strings);

  box_sizer->Add(listbox_panel);

  //wxStaticLine *sl1 = new wxStaticLine(this);

  wxButton* command_one_button = new wxButton(this, COMMAND_ONE_BUTTON_ID, wxT("One"));
  wxButton* command_two_button = new wxButton(this, COMMAND_TWO_BUTTON_ID, wxT("Two"));
  mid_sizer = new wxBoxSizer(wxHORIZONTAL);
  mid_sizer->Add(command_one_button);
  mid_sizer->Add(command_two_button);
  //mid_sizer->SetSizeHints(this);
  mid_sizer->Fit(this);

  //box_sizer->Add(mid_sizer);


  description_panel = new wxPanel(this);
  line = new wxStaticLine(description_panel, wxID_STATIC, wxDefaultPosition, wxSize(150, -1), wxLI_HORIZONTAL);

  box_sizer->Add(description_panel);
  //box_sizer->SetSizeHints(this);

  top_sizer->Add(box_sizer,0 , wxALIGN_CENTER_HORIZONTAL|wxALL);
  top_sizer->Add(mid_sizer,0, wxALIGN_CENTER_HORIZONTAL|wxALL);
  SetSizer(top_sizer);
  top_sizer->Fit(this);
  top_sizer->SetSizeHints(this);
  //top_sizer->Fit(this);
  //SetSizeAndFit();
}

void dialog::on_command_one_button(wxCommandEvent& event)
{
  wxMessageBox(wxT("wxMessageBox"));
}

//definition for DECLARE_EVENT_TABLE
//check p26 wxwidget
BEGIN_EVENT_TABLE(dialog, wxDialog)
    EVT_BUTTON (COMMAND_ONE_BUTTON_ID, dialog::on_command_one_button)
END_EVENT_TABLE()
