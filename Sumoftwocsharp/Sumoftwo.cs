static void Main(string[] args)
        {
            int num1, num2, sum;
            Console.WriteLine(" How to Calculate the sum of two numbers:");
            Console.Write(" Input number 1: ");
            num1 = Convert.ToInt32(Console.ReadLine());
            Console.Write(" Input number 2: ");
            num2 = Convert.ToInt32(Console.ReadLine());
            sum = num1 + num2;
            Console.Write(" {0} + {1} = {2}",num1,num2,sum);
 
            Console.ReadKey();
        }