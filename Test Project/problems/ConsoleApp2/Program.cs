using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            //Method1();
            //Console.ReadKey();
            Dictionary<int, int> mList = new Dictionary<int, int>() { { 1, 2 }, { 2, 4 }, { 3, 6 } };
          //  IEnumerator<int> it = mList.GetEnumerator<int>();
            foreach(KeyValuePair<int,int> it in mList)
            {
                Console.WriteLine(it.Value);
            }
            Hashtable hTable = new Hashtable() { { 1, "yes" }, { 2, "No" } };
            foreach(DictionaryEntry it in hTable)
            {
                Console.WriteLine(it.Value);
            }
            Console.ReadKey();
        }

        public async static void Method1()
        {
            Task<int> t1 = Method2();
            Method3();
            int count = await t1;
            Method4(count);
        }
        public static async Task<int> Method2()
        {
            int count = 0;
            await Task.Run(() => {
                for (int i = 0; i < 10; i++)
                {
                    Console.WriteLine("Method1");
                    count++;
                }

            });

            return count;
        }
        static void Method3()
        {
            for (int i = 50; i < 60; i++)
                Console.WriteLine(i);
        }
        static void Method4(int count)
        {
                Console.WriteLine("Total Count is "+ count);
        }
    }
        
}
