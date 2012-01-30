using System;
using System.Collections.ObjectModel;

namespace data_binding
{
    public class BookList : ObservableCollection<book>
    {
        public BookList()
        {
            Add(new book("C++ Primer", 50));
            Add(new book("Programming Python", 40));
            Add(new book("Pro C# 2008", 50));
        }
    }

    public class book
    {
        public int Price { get; set; }
        public string Name { get; set; }

        public book(string n, int p)
        {
            Price = p;
            Name = n;
        }

        //public override string ToString()
        //{
        //    return string.Format("BookName: {0}, Price: {1}", name, price);
        //}
    }
}