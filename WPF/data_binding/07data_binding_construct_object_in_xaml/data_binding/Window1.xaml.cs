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
        //private BookList myBookList;
        public Window1()
        {
            InitializeComponent();
            //myBookList = new BookList();
        }

        public void MyWindowLoaded(Object sender, RoutedEventArgs e)
        {
            //1.this time we construct a BookList object directly in xaml inside resources (first we tell
            // xaml the namespace where to find the booklist definition, and then we declare the resource)
            //2. we can bind the entire booklist object using Binding Source, bind to the StaticResource

            //bookListBox.ItemsSource = myBookList; WORKS TOO?
            //bookListBox.DataContext = myBookList; 
                      
        }
    }
}
