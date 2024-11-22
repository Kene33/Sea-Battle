using System;


namespace Ship
{
    internal class Program
    {
        static void Main(string[] args)
        {

            Console.Write("Enter number of lines: ");   int rows = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter number of columns: "); int cols = Convert.ToInt32(Console.ReadLine());


            bool[,] array_rand = new bool[rows, cols];

            Random random = new Random();

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    array_rand[i, j] = random.Next(2) == 1;
                }
            }


            void ShowMap()
            {

                Console.WriteLine("You see the map with ship.");

                Console.WriteLine("X Y- - - - - - - - - - - - - - - - - -");
                for (int i = 0; i < rows; i++)
                {
                    Console.Write($"{i}|");
                    for (int j = 0; j < cols; j++)
                    {

                        Console.Write($"{array_rand[i, j]}\t");

                    }
                    Console.WriteLine();
                }

                for (int i = 0; i < cols; i++)
                {
                    Console.Write($"   {i}\t");
                }
                Console.WriteLine();
                Console.WriteLine("- - - - - - - - - - - - - - - - - - - -");
            }
            
            Console.Write("Show a map with ships? (Yes or No): "); string seeMap = Console.ReadLine();
            if (seeMap == "Y" || seeMap == "Yes" || seeMap == "yes")
            {
                ShowMap();
            }
            else
            {
                Console.WriteLine("You dont see a map.\n");
            }


            Console.WriteLine();

            bool win = AllElementsEqual(array_rand);
            
            Console.WriteLine("Let's go!");
            while (!win)
            {

                Console.Write("Enter X coordinate: "); int guessX = Convert.ToInt16(Console.ReadLine());
                Console.Write("Enter Y coordinate: "); int guessY = Convert.ToInt16(Console.ReadLine());


                try // for check out a correct X and Y
                {
                    bool ship = array_rand[guessX, guessY];

                    if (ship == true)
                    {
                        Console.WriteLine($"The ship was shot down! | X{guessX} Y{guessY}\n");
                        array_rand[guessX, guessY] = false;
                    }
                    else
                    {
                        Console.WriteLine($"Sorry, nothing there. | X{guessX} Y{guessY}\n");
                    }

                }
                catch
                {
                    Console.WriteLine("Some problem! Maybe you write uncorrect coordinate.\n");
                }

                win = AllElementsEqual(array_rand);
                if (win)
                {
                    Console.WriteLine("You shoted down all ships.\n");
                    break;
                }
            }


            bool AllElementsEqual(bool[,] Array)
            {
                for (int i = 0; i < Array.GetLength(0); i++)
                {
                    for (int j = 0; j < Array.GetLength(1); j++)
                    {
                        if (Array[i, j] != false)
                        {
                            return false;
                        }
                    }
                }

                return true;
            }
        }
    }
}
