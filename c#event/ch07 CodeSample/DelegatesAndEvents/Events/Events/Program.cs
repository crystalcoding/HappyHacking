using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Wrox.ProCSharp.Delegates
{
   class Program
   {
      static void Main(string[] args)
      {
         CarFactory factory = new CarFactory();
         Consumer nick = new Consumer("Nick");
         factory.CarCreated += nick.NewCarArrived;

         factory.CreateACar("Ferrari");
         Consumer kimi = new Consumer("Kimi");
         factory.CarCreated += kimi.NewCarArrived;

         factory.CreateACar("BMW");

         factory.CarCreated -= nick.NewCarArrived;

         factory.CreateACar("Mercedes");
         


      }
   }
}
