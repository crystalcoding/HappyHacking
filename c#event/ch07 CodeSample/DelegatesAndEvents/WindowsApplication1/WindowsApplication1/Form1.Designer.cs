namespace WindowsApplication1
{
   partial class Form1
   {
      /// <summary>
      /// Required designer variable.
      /// </summary>
      private System.ComponentModel.IContainer components = null;

      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
      protected override void Dispose(bool disposing)
      {
         if (disposing && (components != null))
         {
            components.Dispose();
         }
         base.Dispose(disposing);
      }

      #region Windows Form Designer generated code

      /// <summary>
      /// Required method for Designer support - do not modify
      /// the contents of this method with the code editor.
      /// </summary>
      private void InitializeComponent()
      {
         this.buttonOne = new System.Windows.Forms.Button();
         this.buttonTwo = new System.Windows.Forms.Button();
         this.labelInfo = new System.Windows.Forms.Label();
         this.SuspendLayout();
         // 
         // buttonOne
         // 
         this.buttonOne.Location = new System.Drawing.Point(72, 46);
         this.buttonOne.Name = "buttonOne";
         this.buttonOne.Size = new System.Drawing.Size(75, 23);
         this.buttonOne.TabIndex = 0;
         this.buttonOne.Text = "buttonOne";
         this.buttonOne.UseVisualStyleBackColor = true;
         this.buttonOne.Click += new System.EventHandler(this.buttonOne_Click);
         // 
         // buttonTwo
         // 
         this.buttonTwo.Location = new System.Drawing.Point(72, 97);
         this.buttonTwo.Name = "buttonTwo";
         this.buttonTwo.Size = new System.Drawing.Size(75, 23);
         this.buttonTwo.TabIndex = 1;
         this.buttonTwo.Text = "buttonTwo";
         this.buttonTwo.UseVisualStyleBackColor = true;
         this.buttonTwo.Click += new System.EventHandler(this.button2_Click);
         // 
         // labelInfo
         // 
         this.labelInfo.AutoSize = true;
         this.labelInfo.Location = new System.Drawing.Point(99, 174);
         this.labelInfo.Name = "labelInfo";
         this.labelInfo.Size = new System.Drawing.Size(35, 13);
         this.labelInfo.TabIndex = 2;
         this.labelInfo.Text = "label1";
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(276, 257);
         this.Controls.Add(this.labelInfo);
         this.Controls.Add(this.buttonTwo);
         this.Controls.Add(this.buttonOne);
         this.Name = "Form1";
         this.Text = "Form1";
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.Button buttonOne;
      private System.Windows.Forms.Button buttonTwo;
      private System.Windows.Forms.Label labelInfo;
   }
}

