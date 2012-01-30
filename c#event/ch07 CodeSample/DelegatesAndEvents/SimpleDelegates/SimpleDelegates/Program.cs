using System;
using System.Collections.Generic;
using System.Text;

namespace SimpleDelegates
{
   struct Currency
   {
      public uint Dollars;
      public ushort Cents;

      public Currency(uint dollars, ushort cents)
      {
         this.Dollars = dollars;
         this.Cents = cents;
      }

      public override string ToString()
      {
         return string.Format("${0}.{1,-2:00}", Dollars, Cents);
      }

      public static explicit operator Currency(float value)
      {
         checked
         {
            uint dollars = (uint)value;
            ushort cents = (ushort)((value - dollars) * 100);
            return new Currency(dollars, cents);
         }
      }

      public static implicit operator float(Currency value)
      {
         return value.Dollars + (value.Cents / 100.0f);
      }

      public static implicit operator Currency(uint value)
      {
         return new Currency(value, 0);
      }

      public static implicit operator uint(Currency value)
      {
         return value.Dollars;
      }

      public static string GetCurrencyUnit()
      {
         return "Dollar";
      }

   }


   class Program
   {

      private delegate string GetAString();

      static void Main()
      {

         int x = 40;
         // GetAString firstStringMethod = new GetAString(x.ToString);
         GetAString firstStringMethod = x.ToString;
         Console.WriteLine("String is " + firstStringMethod());
         // With firstStringMethod initialized to x.ToString(), 
         // the above statement is equivalent to saying 
         // Console.WriteLine("String is" + x.ToString());

         Currency balance = new Currency(34, 50);

         // firstStringMethod references an instance method
         firstStringMethod = new GetAString(balance.ToString);
         Console.WriteLine("String is " + firstStringMethod());

         // firstStringMethod references a static method
         firstStringMethod = new GetAString(Currency.GetCurrencyUnit);
         Console.WriteLine("String is " + firstStringMethod());


      }
   }
}
