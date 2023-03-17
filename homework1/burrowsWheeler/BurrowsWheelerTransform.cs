using System.Text;

namespace BurrowsWheelerAlgorythm;

public static class BurrowsWheelerTransform
{
    public static (int initialStringIndex, string transformedString) ApplyForwardTransform(string inputString)
    {
        // Проверяем, что входная строка не null и не пустая.
        if (string.IsNullOrEmpty(inputString))
        {
            throw new ArgumentException("The string cannot be null or empty.", nameof(inputString));
        }

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

    public static string ApplyReverseTranform(string transformedString, int initialStringIndex)
    {
        if (string.IsNullOrEmpty(transformedString))
        {
            throw new ArgumentException("The string cannot be null or empty.", nameof(transformedString));
        }
        if (initialStringIndex < 0 || initialStringIndex >= transformedString.Length)
        {
            throw new ArgumentOutOfRangeException(nameof(initialStringIndex));
        }

        const int numberOfPossibleSymbols = char.MaxValue + 1;

        // Подсчитываем количество вхождений каждого из символов в строку.
        int[] numbersOfEntries = new int[numberOfPossibleSymbols];
        foreach (char symbol in transformedString)
        {
            numbersOfEntries[symbol]++;
        }

        // Вычисляем накопленные суммы начиная с начала алфавита.
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

        // Вручную присваиваем последнему символу строки "первую сортировку" среди таких же символов.
        vectorOfMoves[initialStringIndex] = cummulativeSums[transformedString[initialStringIndex]];
        cummulativeSums[transformedString[initialStringIndex]]++;

        // Вычисляем индексы последовательности символов в исходной строке от последнего к первому.
        for (int i = 0; i < transformedString.Length; i++)
        {
            if (i == initialStringIndex)
            {
                continue;
            }

            char currentChar = transformedString[i];
            vectorOfMoves[i] = cummulativeSums[transformedString[i]];
            cummulativeSums[transformedString[i]]++;
        }

        StringBuilder result = new();

        // Проходимся по вычисленной последовательности и добавляем эти символы в строку для результата.
        int numberOfCurrentCharacter = initialStringIndex;
        for (int i = 0; i < transformedString.Length; i++)
        {
            result.Insert(0, transformedString[numberOfCurrentCharacter]);
            numberOfCurrentCharacter = vectorOfMoves[numberOfCurrentCharacter];
        }

        initialString = result.ToString();
    }
}
