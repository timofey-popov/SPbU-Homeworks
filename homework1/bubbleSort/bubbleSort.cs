namespace SortPrograms;
public static class SortUtilities
{
    public static void SortWithBubbleSort(int[] arrayForSort)
    {
        if (arrayForSort == null)
        {
            throw new ArgumentNullException(nameof(arrayForSort));
        }

        for (int i = 0; i < arrayForSort.Length - 1; i++)
        {
            for (int j = 0; j < arrayForSort.Length - i - 1; j++)
            {
                if (arrayForSort[j] > arrayForSort[j + 1])
                {
                    (arrayForSort[j + 1], arrayForSort[j]) = (arrayForSort[j], arrayForSort[j + 1]);
                }
            }
        }
    }
}
