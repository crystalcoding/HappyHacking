using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Wrox.ProCSharp.Delegates
{





   public partial class Form1 : Form
   {
      public delegate void ActionEventHandler(object sender, ActionCancelEventArgs e);

      public static event ActionEventHandler Action;
      private BusEntity busEntity;

      protected void OnAction(object sender, ActionCancelEventArgs e)
      {
         if (Action != null)
            Action(sender, e);
      }


      public Form1()
      {
         InitializeComponent();
         busEntity = new BusEntity();
      }

      private void buttonRaise_Click(object sender, EventArgs e)
      {
         ActionCancelEventArgs cancelEvent = new ActionCancelEventArgs();
         OnAction(this, cancelEvent);
         if (cancelEvent.Cancel)
            labelInfo.Text = cancelEvent.Message;
         else
            labelInfo.Text = busEntity.TimeString;

      }
   }
}