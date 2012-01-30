using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Threading;
using System.Windows.Threading;

namespace wpfthread
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        delegate void mydelegate();
        static int progress;
        //mydelegate myd = new mydelegate(ThreadMain);
        //Error	1	A field initializer cannot reference the non-static field, method, or property 'wpfthread.Window1.ThreadMain()'	C:\Documents and Settings\bps\Desktop\wpfthread\wpfthread\Window1.xaml.cs	27	26	wpfthread

        public Window1()
        {
            InitializeComponent();
            progress = 0;

        }


        public void mybutton_click(object s, RoutedEventArgs e)
        {
            

            mytext.Text = "mybutton is clicked";
            
            Thread t1 = new Thread(runMyThreadMain);
            t1.Start();

            Thread updateTextThread = new Thread(runUpdateText);
            updateTextThread.Start();
  
            mytext.Text += "Finished Clicked thread";


            mytext.Text += "progress is:" + progress+"\n";


            
        }


        public void runMyThreadMain()
        {            

            mydelegate myd = new mydelegate(ThreadMain);
            for (; progress < 100;++progress )
            {
                Thread.Sleep(1000); //simulate some time-consuming work
                this.Dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Input, myd);
            }
      
  
       





            //The calling thread cannot access this object because a different thread owns it.
            //mytext.Text += "The work is done~\n";


        }

        public void ThreadMain()
        {

            //don't sleep inside this thread, this is a separate thread already! sleeping here is a waste~
            for (int i = 0; i <= 5; ++i)
            {
                //Thread.Sleep(10); //I just want to simulate some task. It does not mean this thread is sleeping!

                mytext.Text += i + "Running in a thread\n " + ++progress; 
                
                
            }
        }

        public void runUpdateText()
        {
            
            mydelegate md = new mydelegate(updateText);
            while (progress<100)
            {
                Thread.Sleep(1000);
                this.Dispatcher.BeginInvoke(DispatcherPriority.Normal, md);
            }
        }

        public void updateText()
        {
            //Thread.Sleep(3000); don't put sleep here, because it's kinda useless, it's a waste, 
            //why? you want a background process, but you ask it to sleep? unless it is waiting for something
            //or it does not make sense to sleep here. 
            mytext.Text += "progress is:"+progress+"%(from the updateText() thread)\n";
        }

    }
}
