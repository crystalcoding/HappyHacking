using System;
using System.Collections.Generic;
using System.Text;

namespace Wrox.ProCSharp.Delegates
{
   delegate bool Comparison(object x, object y);

   class BubbleSorter
   {
      static public void Sort(object[] sortArray, Comparison comparer)
      {
         for (int i = 0; i < sortArray.Length; i++)
         {
            for (int j = i + 1; j < sortArray.Length; j++)
            {
               if (comparer(sortArray[j], sortArray[i]))
               {
                  object temp = sortArray[i];
                  sortArray[i] = sortArray[j];
                  sortArray[j] = temp;
               }
            }
         }
      }
   }
}
