namespace SortPrograms
{
    class Program
    {
        static void Main()
        {
            int[] inputArray = { 5, 4, 3, 2, 1 };

            BubbleSort.BubbleSortExecution(inputArray);

            string resultString = string.Join(" ", inputArray);
            Console.WriteLine(resultString);
        }
    }

    class BubbleSort
    {
        public static void BubbleSortExecution(int[] arrayForSort)
        {
            for (int i = 0; i < arrayForSort.Length - 1; i++)
            {
                for (int j = 0; j < arrayForSort.Length - i - 1; j++)
                {
                    (arrayForSort[j + 1], arrayForSort[j])=(arrayForSort[j], arrayForSort[j + 1]);
                }
            }
        }
    }
}
