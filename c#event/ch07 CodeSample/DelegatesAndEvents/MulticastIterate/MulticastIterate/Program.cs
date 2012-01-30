using System;

namespace Wrox.ProCSharp.Delegates
{
   class Program
   {
      static void One()
      {
         Console.WriteLine("One");
         throw new Exception("Error in one");
      }

      static void Two()
      {
         Console.WriteLine("Two");
      }

      public delegate void DemoDelegate();

      static void Main()
      {
         DemoDelegate d1 = One;
         d1 += Two;

         Delegate[] delegates = d1.GetInvocationList();
         foreach (DemoDelegate d in delegates)
         {
            try
            {
               d();
            }
            catch (Exception)
            {
               Console.WriteLine("Exception caught");
            }

         }

         //try
         //{
         //   d1();
         //}
         //catch (Exception)
         //{
         //   Console.WriteLine("Exception caught");
         //}
      }
   }
}
