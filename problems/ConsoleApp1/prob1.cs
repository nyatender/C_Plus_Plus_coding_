//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

//namespace ConsoleApp1
//{
//    //public abstract class prob1
//    interface prob1
//    {
//        //public int a;
//        //static int b;
//        //public prob1()
//        //{
//        //    b = 5;
//        //    b++;
//        //    Console.WriteLine(" static prob1 executed " + b);
//        //}
//        void fun();
//        void prob1_fun();
//        //{
//        //    Console.WriteLine(" prob1 executed ");
//        //}
//    };
//    class D_prob1 : prob1 {
//        static int c;
//        static D_prob1()
//        {
//            c = 10;
//            c++;
//            Console.WriteLine(" static D_prob1 executed ");
//        }
//        public void fun()
//        {

//        }
//        public void prob1_fun()
//        {
//            Console.WriteLine(" prob1 executed ");
//        }
//        public D_prob1()
//        {
//            Console.WriteLine(" D_prob1 executed ");
//        }
//     };
//    class collection<T>
//    {
//        static collection() {
//            size = 100;
//         }

//        static readonly int size;
//        T[] arr = new T[size];
//        public T this[int t]
//        {
//            get
//            {
//                return arr[t];
//            }
//            set
//            {
//                arr[t] = value;
//            }
//        }
//    };
//    class cMain
//    {
//        static void Main(string[] args)
//        {
//           // collection<int> arr = new collection<int>(100);
//          //  int i = 0;
//           // arr[i++] = 10;

//            //prob1 obj1 = new prob1();
//            D_prob1 obj2 = new D_prob1();

//            Console.WriteLine(" In Main ");
//        }
//    }
//}
