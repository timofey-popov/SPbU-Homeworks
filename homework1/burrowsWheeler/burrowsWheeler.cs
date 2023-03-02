using System.Text;
class BurrowsWheelerTransform
{
    public static void ForwardTransform(out int initialStringIndex, out string resultString, string inputString)
    {
        string[] rotations = new string[inputString.Length];

        for (int i = 0; i < rotations.Length; i++)
        {
            string rotation = inputString[i..] + inputString[..i];
            rotations[i] = rotation;
        }

        Array.Sort(rotations, StringComparer.OrdinalIgnoreCase);

        initialStringIndex = -1;
        for (int i = 0; i < rotations.Length; i++) 
        {
            if (inputString == rotations[i])
            {
                initialStringIndex = i;
                break;
            }
        }

        resultString = "";
        for (int i = 0; i < rotations.Length; i++)
        {
            resultString += rotations[i][inputString.Length - 1];
        }
    }

    public static void ReverseTransform(out string initialString, string transformedString, int initialStringIndex)
    {
        char[] transformedStringArray = transformedString.ToCharArray();
        Array.Sort(transformedStringArray, StringComparer.OrdinalIgnoreCase);
        string sortedTransformedString = new string(transformedStringArray);


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
        string inputString = "abraca";

        BurrowsWheelerTransform.ForwardTransform(out int index, out string outputString, inputString);

        Console.WriteLine($"Output string is {outputString} and initial string index is {index}");
        Console.WriteLine();

        BurrowsWheelerTransform.ReverseTransform(out string test, outputString, index);

        Console.WriteLine($"Initial string is {test}");
    }
}
