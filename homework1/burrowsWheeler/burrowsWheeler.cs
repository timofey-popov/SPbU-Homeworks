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
        char[] transformedStringArray = transformedString.ToCharArray();
        Array.Sort(transformedStringArray);
        string sortedTransformedString = new(transformedStringArray);


        StringBuilder stringToReturn = new();

        int currentIndex = initialStringIndex;
        char currentCharacter = ' ';

        while (sortedTransformedString.Length > 0)
        {
            currentCharacter = transformedString[currentIndex];

            stringToReturn.Insert(0, currentCharacter);

            transformedString = transformedString.Remove(currentIndex, 1);
            sortedTransformedString = sortedTransformedString.Remove(currentIndex, 1);

            currentIndex = sortedTransformedString.IndexOf(currentCharacter);
        }

        initialString = stringToReturn.ToString();
    }
}

class Program
{
    static void Main()
    {
        string inputString = "AaBbCc";

        BurrowsWheelerTransform.ForwardTransform(out int index, out string outputString, inputString);

        Console.WriteLine($"Output string is {outputString} and initial string index is {index}");
        Console.WriteLine();

        BurrowsWheelerTransform.ReverseTransform(out string test, outputString, index);

        Console.WriteLine($"Initial string is {test}");
    }
}
