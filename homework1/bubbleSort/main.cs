using SortPrograms;

if (!Tests.TestsForBubbleSort.StartTests())
{
    Console.WriteLine("Tests failed.\n");
    return;
}
else
{
    Console.WriteLine("*tests passed*\n");
}

int[] inputArray = { 5, 4, 3, 2, 1 };

try
{
    SortUtilities.SortWithBubbleSort(inputArray);
}
catch (ArgumentNullException exception)
{
    Console.WriteLine($"Error: {exception.Message}");
}
catch (Exception exception)
{
    Console.WriteLine($"Unexpected error occured: {exception.Message}");
}

string resultString = string.Join(" ", inputArray);
Console.WriteLine($"Sorted array:\n\n{resultString}");
