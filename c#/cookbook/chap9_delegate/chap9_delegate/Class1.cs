using System;
using System.Runtime.Remoting.Messaging;

namespace chap9_delegate
{
    public class Class1
    {  
        static void Main()
        {
            //9.1 GetInvocationList to obtain an array of Delegate objects
            Multicast multicast = new Multicast();
            multicast.useMulticastDelegate();
            //9.2 You can get the return value of multicast delegate
            //9.3 Catch individual exception in a multicast delegate

            //9.4 asynchronous delegate
            //9.5 wrap in sealed class, FileSystemWatcher 12.23

            //9.12 anonymous methods, 3 ways to do it
            Class2 class2 = new Class2();
            class2.WorkItOut();
            class2.WorkItOutAnonymous();

            //9.13 Generic Event Handler //p369, Pro c#2008, 
            //The advantage of using EventHandler<(Of <(TEventArgs>)>) 
            //is that you "do not need to code your own custom delegate" if your event generates event data.


            //chap 11, pro c#2008, andrew troelsen
            UnderstandEvent understandEvent = new UnderstandEvent();
            //you can register event handler to the accelerate event at the client side, in this case, speedup. 
            //you can directly assign the method name to the event, the IL will write "new" for you
            understandEvent.accelerate += understandEvent.speedup;
            //or you can register this way, no syntatic sugar but still work
            understandEvent.accelerate += new UnderstandEvent.CardHandler(understandEvent.speedup);
            understandEvent.onAccelerate();   // call speedup twice


            //p.363,WHY USE EVENT?
            // the following line will not compile, the "accelerate" event is private to its class!
            // , so now you can only REGISTER/DE-REGISTER the event handler on accelerate event, 
            // to call the accelerate event, you need to define a public function inside acclerate's class to call it
            //understandEvent.accelerate("call speedup through event");



            // Generic delegate p.360
            //what's the point? we can write our delegate once, since the argument in the handler is generic
            GenericDelegate genericDelegate = new GenericDelegate();
            genericDelegate.typeString = new GenericDelegate.myGenericDelegate<string>(genericDelegate.methodTypeString);
            genericDelegate.typeInt = new GenericDelegate.myGenericDelegate<int>(genericDelegate.methodTypeInt);
            genericDelegate.typeString("call string type generic delegate");
            genericDelegate.typeInt(10);          
       

            //p.591 c# pro Asyn Delegate
            //play with the following for method yourself
            MyAsyncDelegate myAsyncDelegate = new MyAsyncDelegate();
            //myAsyncDelegate.runAddManyNumberDelegate1();
            //myAsyncDelegate.runAddManyNumberDelegate2();
            //myAsyncDelegate.runAddManyNumberDelegate3();
            myAsyncDelegate.runAddManyNumberDelegate4();
             
        }        
    }

    public class Class2
    {
        delegate int DoWork(string s);

        public void WorkItOutAnonymous()
        {
            DoWork dw = delegate(string s) //do not put "new" here; argument and return type must match too
            {
                Console.WriteLine(s);
                return s.GetHashCode();
            };

            int result = dw("WorkItOutAnonymous");
        }

        public void WorkItOut()
        {
            DoWork dw = new DoWork(DoWorkMethodImpl);
            //C# Magic,  same as the above, C# writes the IL to create the delegate object,
            //no more "new Delegate()"
            //DoWork dw = DoWorkMethodImpl;

            int i = dw("DoWorkMethodImpl1");
        }

        public int DoWorkMethodImpl(string s)
        {
            Console.WriteLine(s);
            return s.GetHashCode();
        }
    }

    public class Multicast
    {
        delegate int myDelegate(string s);

        public void useMulticastDelegate()
        {
            myDelegate m1 = new myDelegate(method1);
            myDelegate m2 = new myDelegate(method2);
            myDelegate m3 = new myDelegate(method3);

            myDelegate myDelegateMulticast = m1 + m2 + m3;
            //myDelegate[] allMethodInMyDelegate = (myDelegate[])myDelegateMulticast.GetInvocationList(); //does not work
            Delegate[] allMethodInMyDelegate = myDelegateMulticast.GetInvocationList();

            for (int i = 0; i < allMethodInMyDelegate.Length; ++i)
            {
                int returnValue; //we can capture each return value from each delegate
                returnValue = ((myDelegate)allMethodInMyDelegate[i])(string.Format("{0}, this is the argument string", i));
            }
        }

        public int method1(string s)
        {
            Console.WriteLine(s);
            return 1;
        }

        public int method2(string s)
        {
            Console.WriteLine(s);
            return 2;
        }

        public int method3(string s)
        {
            Console.WriteLine(s);
            return 3;
        }
    }

    public class UnderstandEvent
    {
        //p349, p364, Pro C#2008 a. declare delegate type, b. define member variable
        public delegate void CardHandler(string s);
        public event CardHandler accelerate;

        public void speedup(string s)
        {
            Console.WriteLine(s);
        }

        public void onAccelerate()
        {
            if (accelerate != null)
            {
                accelerate("accelerated event is invoked");
            }
            else
            {
                Console.WriteLine("you must register (listening the incoming event before calling the event");
            }
        }
    }

    public class GenericDelegate
    {
        public delegate void myGenericDelegate<T>(T myGenericType);

        public myGenericDelegate<string> typeString;
        public myGenericDelegate<int> typeInt;
        
        public void methodTypeString(string s) { Console.WriteLine("call method type string"); }
        public void methodTypeInt(int s) { Console.WriteLine("call method type int"); }
    }

    public class MyAsyncDelegate
    {
        public delegate int myDelegate(string s);

        public int addManyNumber(string s)
        {
            Random random = new Random();
            int ret = 0;
            for (int i = 0; i < 1000; ++i)
                ret += random.Next(500);

            return ret;
        }

        public int runAddManyNumberDelegate1()
        {
            myDelegate md = new myDelegate(addManyNumber);
            //or, myDelegate md = addManyNumber;

            //this will return right away
            IAsyncResult iftAR = md.BeginInvoke("run beginInvoke", null,null );

            //busy loop to appreciate the multithreading feeling
            while (!iftAR.IsCompleted)
            {               
                Console.WriteLine("MyAsyncDelegate is not completed");
            }

            Console.WriteLine("\n\nMyAsyncDelegate is now compleged");

            //calling thread is now blocked until EndInvoke is completed
            int answer = md.EndInvoke(iftAR);

            return answer;
        }

        //AsyncCallback
        public int runAddManyNumberDelegate2()
        {
            myDelegate md = addManyNumber;
            IAsyncResult itfAT = md.BeginInvoke("run beginInvoke", messageCallback1, null);
            int answer = 0;

            return answer;
        }

        //the callback for BeginInvoke, the sygnature must be the following pattern 
        //Note the IAsyncResult argument
        public void messageCallback1(IAsyncResult itfAR)
        {
            Console.WriteLine("beginInvoke compleged, callback call!");
        }

        public int runAddManyNumberDelegate3()
        {
            myDelegate md = addManyNumber;

            md.BeginInvoke("dummy arg", messageCallback2, null);

            int answer = 0;
            return answer;
        }

        // so you can get the reference of the orignal delegate from the callback
        // and you can call EndInvoke to get the return value from the orignal delegate
        public void messageCallback2(IAsyncResult iftAR)
        {
            Console.WriteLine("messageCallback2 call, beginInvoke completed");

            AsyncResult ar = (AsyncResult)iftAR;
            myDelegate md = (myDelegate)ar.AsyncDelegate;

            //calling thread is no blocked until EndInvoke is compleged
            int returnValueFromDelegate = md.EndInvoke(iftAR);
            Console.WriteLine("return value from messageCallback2 is {0}:", returnValueFromDelegate);
        }

        //use the last argument in BeginInvoke
        public int runAddManyNumberDelegate4()
        {
            myDelegate md = addManyNumber;

            md.BeginInvoke("dummy arg", messageCallback3, "Stuff in the last argument in BeginInvoke");

            int answer = 0;
            return answer;
        }

        //use AsyncState
        public void messageCallback3(IAsyncResult iftAR)
        {
            Console.WriteLine("messageCallback3 call, beginInvoke completed");
            string arg = (string)iftAR.AsyncState;
            Console.WriteLine(arg);
        }

    }
}
