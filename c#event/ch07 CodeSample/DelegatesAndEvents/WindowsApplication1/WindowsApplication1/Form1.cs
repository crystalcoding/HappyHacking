using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WindowsApplication1
{
   public partial class Form1 : Form
   {
      public Form1()
      {
         InitializeComponent();
         //button1.Click += new EventHandler(button1_Click);
         //button1.Click += new EventHandler(OnButtonClick);

         buttonOne.Click += (sender, e) => labelInfo.Text = "Button One was pressed";
//            delegate { labelInfo.Text = "Button One was pressed"; };
buttonTwo.Click += delegate{labelInfo.Text = "Button Two was pressed";};
buttonTwo.Click += delegate
{
   MessageBox.Show
("This only happens in Button 2 click event");
};

      }

      void button1_Click(object sender, EventArgs e)
      {
         throw new Exception("The method or operation is not implemented.");
      }

      void OnButtonClick(object sender, EventArgs e)
      {
         throw new Exception("The method or operation is not implemented.");
      }

      private void button2_Click(object sender, EventArgs e)
      {

      }

      private void buttonOne_Click(object sender, EventArgs e)
      {

      }
   }
}