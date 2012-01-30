using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Wrox.ProCSharp.Delegates
{
   public delegate void CarInfoHandler(object sender, CarInfoEventArgs e);

   public class CarInfoEventArgs : EventArgs
   {
      public CarInfoEventArgs(string car)
      {
         this.car = car;

      }

      private string car;
      public string Car
      {
         get
         {
            return car;
         }
      }
   }

   public class CarFactory
   {
      private CarInfoHandler carCreated;

      public event CarInfoHandler CarCreated
      {
         add
         {
            carCreated += value;
         }
         remove
         {
            carCreated -= value;
         }
      }

      public void CreateACar(string car)
      {
         Console.WriteLine("Factory - car {0} created", car);

         OnCarCreated(car);
      }

      protected void OnCarCreated(string car)
      {
         if (carCreated != null)
         {
            CarInfoEventArgs e = new CarInfoEventArgs(car);
            carCreated(this, e);
         }
      }
     
   }
}
