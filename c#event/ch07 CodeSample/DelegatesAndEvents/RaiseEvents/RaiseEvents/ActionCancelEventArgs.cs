using System;
using System.Collections.Generic;
using System.Text;

namespace Wrox.ProCSharp.Delegates
{
   public class ActionCancelEventArgs : System.ComponentModel.CancelEventArgs
   {
      // string message = String.Empty;

      public ActionCancelEventArgs() : base() { }

      public ActionCancelEventArgs(bool cancel) : base(cancel) { }

      public ActionCancelEventArgs(bool cancel, string message)
         : base(cancel)
      {
         this.Message = message;
      }

      public string Message { get; set; }
      //{
      //   get { return message; }
      //   set { message = value; }
      //}
   }
}
