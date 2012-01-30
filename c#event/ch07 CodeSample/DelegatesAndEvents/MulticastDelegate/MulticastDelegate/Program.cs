using System;
using System.Collections.Generic;
using System.Text;

namespace MulticastDelegate
{
   delegate void DoubleOp(double value);

   class MathOperations
   {
      public static void MultiplyByTwo(double value)
      {
         double result = value * 2;
         Console.WriteLine(
            "Multiplying by 2: {0} gives {1}", value, result);
      }

      public static void Square(double value)
      {
         double result = value * value;
         Console.WriteLine("Squaring: {0} gives {1}", value, result);
      }
   }


   class Program
   {

      static void ProcessAndDisplayNumber(DoubleOp action, double valueToProcess)
      {
         Console.WriteLine("\nProcessAndDisplayNumber called with value = " +
                            valueToProcess);
         action(valueToProcess);
      }

      static void Main()
      {
         DoubleOp operations = MathOperations.MultiplyByTwo;
         operations += MathOperations.Square;

         ProcessAndDisplayNumber(operations, 2.0);
         ProcessAndDisplayNumber(operations, 7.94);
         ProcessAndDisplayNumber(operations, 1.414);
         Console.WriteLine();

      }
   }
}
