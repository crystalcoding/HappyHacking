using System;
using System.Collections.Generic;
using System.Text;

namespace Wrox.ProCSharp.Delegates
{
   class Employee
   {
      private string name;
      private decimal salary;

      public Employee(string name, decimal salary)
      {
         this.name = name;
         this.salary = salary;
      }

      public override string ToString()
      {
         return string.Format("{0}, {1:C}", name, salary);
      }

      public static bool CompareSalary(object x, object y)
      {
         Employee e1 = (Employee)x;
         Employee e2 = (Employee)y;
         return (e1.salary < e2.salary);
      }
   }

}
