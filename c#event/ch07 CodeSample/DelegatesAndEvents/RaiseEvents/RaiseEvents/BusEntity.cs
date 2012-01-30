using System;
using System.Collections.Generic;
using System.Text;

namespace Wrox.ProCSharp.Delegates
{
   public class BusEntity
   {

      string time = String.Empty;

      public BusEntity()
      {
         Form1.Action += new Form1.ActionEventHandler(Form1_Action);
      }

      private void Form1_Action(object sender, ActionCancelEventArgs e)
      {
         e.Cancel = !DoActions();
         if (e.Cancel)
            e.Message = "Wasn't the right time.";
      }

      private bool DoActions()
      {
         bool retVal = false;
         DateTime tm = DateTime.Now;

         if (tm.Second < 30)
         {
            time = "The time is " + DateTime.Now.ToLongTimeString();
            retVal = true;
         }
         else
            time = "";

         return retVal;

      }

      public string TimeString
      {
         get { return time; }
      }

   }

}
