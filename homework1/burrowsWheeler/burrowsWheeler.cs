using System.Security.Cryptography;
using System.Text;
class BurrowsWheelerTransform
{
    public static void ForwardTransform(out int initialStringIndex, out string transformedString, string inputString)
    {
        int inputStringLength = inputString.Length;
        // Строим массив индексов суффиксов от 0 до длины строки - 1.
        // Индекс обозначает номер символа, с которого этот суффикс начинается в изначальной строке.
        int[] suffixIndexesArray = Enumerable.Range(0, inputStringLength).ToArray();

        // Сортируем эти индексы как связанный массив. Основное сравнение - суффиксы сравниваются друг с другом.
        Array.Sort(suffixIndexesArray, (i, j) => string.CompareOrdinal(inputString[i..], inputString[j..]));

        char[] transformedChars = new char[inputStringLength];
        initialStringIndex = -1;

        // Проходимся по отсортированному массиву индексов и добавляем в строку результата символ,
        // который является предыдущим для i-того суффикса (для 0 индекса возьмём последний символ строки).
        // Когда находим нулевой суффикс (т. е. всю строку), добавляем её индекс в специальную переменную.
        for (int i = 0; i < inputStringLength; i++)
        {
            if (suffixIndexesArray[i] == 0)
            {
                initialStringIndex = i;
                transformedChars[i] = inputString[inputStringLength - 1];
            }
            else
            {
                transformedChars[i] = inputString[suffixIndexesArray[i] - 1];
            }
        }

        transformedString = new string(transformedChars);
    }

    public static void ReverseTransform(out string initialString, string transformedString, int initialStringIndex)
    {
        const int numberOfPossibleSymbols = char.MaxValue + 1;

        int[] numbersOfEntries = new int[numberOfPossibleSymbols];
        foreach (char symbol in transformedString)
        {
            numbersOfEntries[symbol]++;
        }

        int[] cummulativeSums = new int[numberOfPossibleSymbols];
        int cummulativeSum = 0;
        for (int i = 0; i < numberOfPossibleSymbols; i++)
        {

            if (numbersOfEntries[i] != 0)
            {
                cummulativeSums[i] = cummulativeSum;
                cummulativeSum += numbersOfEntries[i];
            }
        }

        int[] vectorOfMoves = new int[transformedString.Length];
        for (int i = 0; i < transformedString.Length; i++)
        {
            char currentChar = transformedString[i];
            vectorOfMoves[i] = cummulativeSums[transformedString[i]];
            cummulativeSums[transformedString[i]]++;
        }

        StringBuilder result = new();

        int numberOfCurrentCharacter = initialStringIndex;
        for (int i = 0; i < transformedString.Length; i++)
        {
            result.Insert(0, transformedString[numberOfCurrentCharacter]);
            numberOfCurrentCharacter = vectorOfMoves[numberOfCurrentCharacter];
        }

        initialString = result.ToString();
    }
}

class Program
{
    static void Main()
    {
        string inputString = "Enter any sentence without punctuation and it will work";

        BurrowsWheelerTransform.ForwardTransform(out int index, out string outputString, inputString);

        Console.WriteLine($"Output string is \"{outputString}\" and initial string index is {index}");
        Console.WriteLine();

        BurrowsWheelerTransform.ReverseTransform(out string test, outputString, index);

        Console.WriteLine($"Initial string is \"{test}\"");
    }
}
