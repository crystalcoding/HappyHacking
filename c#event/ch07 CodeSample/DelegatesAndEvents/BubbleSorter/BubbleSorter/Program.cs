using System;
using System.Collections.Generic;
using System.Text;

namespace Wrox.ProCSharp.Delegates
{

   class Program
   {
      static void Main()
      {
         Employee[] employees =
         {
           new Employee("Bugs Bunny", 20000),
           new Employee("Elmer Fudd", 10000),
           new Employee("Daffy Duck", 25000),
           new Employee("Wiley Coyote", (decimal)1000000.38),
           new Employee("Foghorn Leghorn", 23000),
           new Employee("RoadRunner'", 50000)};

         BubbleSorter.Sort(employees, Employee.CompareSalary);

         foreach (var employee in employees)
         {
            Console.WriteLine(employee);
         }
         //for (int i = 0; i < employees.Length; i++)
         //   Console.WriteLine(employees[i].ToString());
      }
   }
}
