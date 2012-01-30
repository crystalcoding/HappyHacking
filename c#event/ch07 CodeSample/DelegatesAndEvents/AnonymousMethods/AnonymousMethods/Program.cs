using System;

namespace Wrox.ProCSharp.Delegates
{
   class Program
   {
      delegate string DelegateTest(string val);

      static void Main()
      {
         string mid = ", middle part,";

         // Anonymous Method
         DelegateTest anonDel = delegate(string param)
         {
               param += mid;
               param += " and this was added to the string.";
               return param;
         };

         // Lambda Expression
         //DelegateTest anonDel = param =>
         //   {
         //      param += mid;
         //      param += " and this was added to the string.";
         //      return param;
         //   };

         Console.WriteLine(anonDel("Start of string"));

      }

   }
}
