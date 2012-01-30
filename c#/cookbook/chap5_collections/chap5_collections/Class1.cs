using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace chap5_collections
{
    public class Class1
    {
        static void Main()
        {
            //5.2 reversing an array average time, N/2
            int[] someArray = new int[] { 1, 2, 3, 4, 5 };
            //or int[] someArray = new int[5] { 1, 2, 3, 4, 5 };
            ReverseHelper reverseHelper = new ReverseHelper();
            reverseHelper.reverse<int>(someArray);
            foreach (int i in someArray) Console.WriteLine(i);

            //or we can just use .Net
            Array.Reverse(someArray);
            foreach (int i in someArray) Console.WriteLine(i);

            //5.2.1 reverse a stirng
            string tryReverseString = "ABCDEFGHI";
            string reverseTryReverseString = new String(tryReverseString.ToCharArray().Reverse().ToArray());

            //5.2.1 use customize helper to reverse a string
            StringBuilder reverseStringBuilder = new StringBuilder(tryReverseString);
            reverseHelper.reverseString(reverseStringBuilder);
            for (int i = 0; i < reverseStringBuilder.Length; ++i) Console.WriteLine(reverseStringBuilder[i]);
            
            //foreach does not work with string builder
            //foreach (char c in reverseStringBuilder) Console.WriteLine(c);


            //5.16 foreach with anonymous delegate
            List<Data> myDataList = new List<Data>();
            myDataList.Add(new Data(5));
            myDataList.Add(new Data(2));
            myDataList.Add(new Data(3));

            int total = 0;
            myDataList.ForEach(delegate(Data obj)
            {
                total += obj.Value;
            });

            Console.WriteLine("total is:{0}", total);
        }
    }

    public class Data
    {
        //remember to declare constructor public
        public Data(int value)
        {
            Value = value;
        }

        public int Value { get; set; }
    }

    public class ReverseHelper
    {
        public void reverse<T>(T[] theArray)
        {
            T tempArray = default(T);

            for (int i = 0; i < theArray.Length / 2; ++i)
            {
                tempArray = theArray[theArray.Length - 1 - i]; //store the back (among second half)
                theArray[theArray.Length - 1 - i] = theArray[i]; //set back = front, back is lost
                theArray[i] = tempArray; // restore front with the old back
            }
        }

        public void reverseString(StringBuilder s)
        {
            //tringBuilder temp = new StringBuilder(1);
            char temp = new char();
            for (int count = 0; count < s.Length/2; ++count)
            {
                temp = s[s.Length - 1 - count];
                s[s.Length - 1 - count] = s[count];
                s[count] = temp;
            }
        }
    }
}
