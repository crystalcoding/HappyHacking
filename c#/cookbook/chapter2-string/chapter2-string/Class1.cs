using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace chapter2_string
{
    public class Class1
    {
        static void Main()
        {   
            Console.WriteLine(Char.IsLetter('a')); //true
            Console.WriteLine(Char.IsNumber("123412",2)); //treu
            Console.WriteLine('a'.Equals('b')); //false
            Console.WriteLine('a' > 'b'); //false

            string splitTestString = "today is, a good= day. yes";
            string[] splitTestResult = splitTestString.Split(new char[4] { ' ', ',', '=', '.' });
            foreach (string tok in splitTestResult) Console.WriteLine(tok);

            Console.WriteLine("str".EndsWith("r")); //true

            StringBuilder sourceString = new StringBuilder("this is a string");
            sourceString.Insert(1, "\"INSERTED STRING HERE\"");
            Console.WriteLine(sourceString);

            StringBuilder stringBuilderRemoveStr = new StringBuilder("1234abc5678", 12);
            stringBuilderRemoveStr.Remove(4, 3);
            Console.WriteLine(stringBuilderRemoveStr);

            StringBuilder stringBuilderReplace = new StringBuilder("123==");
            stringBuilderReplace.Replace('=', '!');
            Console.WriteLine(stringBuilderReplace);

            string intString = "123";
            int theInt = Int32.Parse(intString);
            string DoubleString = "-234.234";
            double theDouble = Double.Parse(DoubleString);
            string boolString = "true";
            bool theBoolean = Boolean.Parse(boolString);

            string testFormat = string.Format("abcdefg{0}ijklmn{1}", 'h', "o");
            Console.WriteLine(testFormat);

            string[] testJoin = new string[5] { "a", "b", "c", "d","f"};
            string joinResult = string.Join(":", testJoin);
            Console.WriteLine(joinResult);

            string iterateString = "abc";
            foreach (char s in iterateString) Console.WriteLine(s);
            //or
            for (int i = 0; i < iterateString.Length; ++i) Console.WriteLine(iterateString[i]);

            string trimTest = "--TEST// ";
            Console.WriteLine(trimTest.Trim(new char[3] { '-', ' ', '/' })); //Print TEST

            StringBuilder appendLineTest = new StringBuilder("single line");
            appendLineTest.AppendLine(); //platform-indepedent new line added.
            Console.WriteLine(appendLineTest); 
        }
    }
}
