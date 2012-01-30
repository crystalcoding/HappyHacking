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

namespace data_binding
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        private BookList myBookList;
        public Window1()
        {
            InitializeComponent();
            myBookList = new BookList();
        }

        public void MyWindowLoaded(Object sender, RoutedEventArgs e)
        {
            bookListBox.ItemsSource = myBookList;            
        }
    }
}
