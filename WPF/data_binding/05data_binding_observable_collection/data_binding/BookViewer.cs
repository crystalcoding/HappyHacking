using System;
using System.Collections.ObjectModel;

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
    public string name;
    public int price;
    
    public book(string n, int p)
    {
        price = p;
        name = n;
    }

    public override string ToString()
    {
        return string.Format("BookName: {0}, Price: {1}", name, price);
    }
}
