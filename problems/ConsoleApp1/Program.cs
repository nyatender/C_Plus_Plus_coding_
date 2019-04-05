using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.Threading;

namespace ConsoleApp1
{
    public class ArgsSpecial : EventArgs
    {
        public ArgsSpecial(string val)
        {
            Operation = val;
        }

        public string Operation { get; set; }
    }

    public class Animal
    {
        // Empty delegate. In this way you are sure that value is always != null 
        // because no one outside of the class can change it.
        public event EventHandler<ArgsSpecial> Run = delegate { };

        public void RaiseEvent()
        {
            Run(this, new ArgsSpecial("Run faster"));
        }
    }
    class Program
    {
        //event EventHandler<abc> myevent;
        delegate void fun(int i, int j);
        delegate void DelFun(int x);
        delegate int CalculateMyNumbers(int x, int y);
        // public int a;
        public static int b;
        static Program()
        {
            b = 10;
        }
        public int FuncForAddingNumbers(int a, int b)
        {
            int c = a + b;
            Console.WriteLine("FuncForAddingNumbers called : result " + c);
            return c;
        }
        public int FuncForMultiplyingNumbers(int a, int b)
        {
            int c = a * b;
            Console.WriteLine("FuncForMultiplyingNumbers called : result " + c);
            return c;
        }
        static void Main(string[] args)
        {
            method();
            int i = 10;
            object o = i;
            int j = (int)o;
            ArrayList aList = new ArrayList();
            Program obj1 = new Program();
            int x = 6;
            int y = 7;
            CalculateMyNumbers addMyNumbers = new CalculateMyNumbers(obj1.FuncForAddingNumbers);
            CalculateMyNumbers multiplyMyNumbers = new CalculateMyNumbers(obj1.FuncForMultiplyingNumbers);
            CalculateMyNumbers multiCast = (CalculateMyNumbers)Delegate.Combine(addMyNumbers, multiplyMyNumbers);
            int re = multiCast.Invoke(x, y);
            Console.WriteLine("multi-cast resul " + re);

            DelFun obj = new DelFun(obj1.myfun);
            obj += new DelFun(obj1.myfun1);
            obj += new DelFun(obj1.myfun2);
            // int re = obj(6);

            //Animal animal = new Animal();
            //animal.Run += (sender, e) => Console.WriteLine("I'm running. My value is {0}", e.Operation);
            //animal.RaiseEvent();


            Dictionary<int, string> myDic = new Dictionary<int, string>();
            myDic.Add(1, "yaten");
            obj(7);
            // Response.Write("<br>");
            // int j = 0;
            //private static readonly Program instanece = new Program();

            // Go to http://aka.ms/dotnet-get-started-console to continue learning how to build a console app! 
        }
        public void myfun(int a)
        {
            Console.WriteLine("i am i myFun" + a);
        }
        public void myfun1(int a)
        {
            Console.WriteLine("i am i myFun1" + a);
        }
        public void myfun2(int a)
        {
            Console.WriteLine("i am i myFun2" + a);
        }
        public static async void method()
        {
            // Thread.Sleep(2000);
            await Task.Run(new Action(Longtask));
            //int i = 5;           
        }
        public static void Longtask()
        {
            Thread.Sleep(5000);
            Console.WriteLine(" Longtask Done ");
        }

        public bool Compare<T>(T a, T b)
        {
            if (a.Equals(b))
                return true;
            return false;
        }
    }
}
