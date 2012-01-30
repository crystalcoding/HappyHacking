#include <wx/wx.h>
#include <wx/statline.h> //or wxStaticLine does not name a type

class dialog: public wxDialog
{
 public:
  dialog(const wxString& title);
  
 private:
  enum { COMMAND_ONE_BUTTON_ID = 1000,
         COMMAND_TWO_BUTTON_ID, 
	 COMMAND_LISTBOX_ID, 
	 
       };

  wxBoxSizer* top_sizer;
  wxBoxSizer* box_sizer;
  wxBoxSizer* mid_sizer;
  wxPanel* listbox_panel;
  wxPanel* description_panel;
  wxStaticLine* line;
  wxStaticLine* line2;
  wxButton* command_one_button;
  wxButton* command_two_button;
  void  create_controls();
  void on_command_one_button(wxCommandEvent& event);
  
  //must define the event table later if the table is declared here
  DECLARE_EVENT_TABLE()

};
