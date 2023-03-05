using SortPrograms;

namespace Tests;
internal static class TestsForBubbleSort
{
    internal static bool StartTests()
    {
        int[] testArray1 = { -2, -1, 0, 1, 2 };
        int[] testArray2 = { 0, 0, 0, 0, 0 };
        int[] testArray3 = { 5, 3, 0, -6, -9 };
        int[] testArray4 = { 16, 8, 3, -20, 11 };

        SortUtilities.SortWithBubbleSort(testArray1);
        SortUtilities.SortWithBubbleSort(testArray2);
        SortUtilities.SortWithBubbleSort(testArray3);
        SortUtilities.SortWithBubbleSort(testArray4);

        int[] referrenceArray1 = { -2, -1, 0, 1, 2 };
        int[] referrenceArray2 = { 0, 0, 0, 0, 0 };
        int[] referrenceArray3 = { -9, -6, 0, 3, 5 };
        int[] referrenceArray4 = { -20, 3, 8, 11, 16 };

        bool check1 = testArray1.SequenceEqual(referrenceArray1);
        bool check2 = testArray2.SequenceEqual(referrenceArray2);
        bool check3 = testArray3.SequenceEqual(referrenceArray3);
        bool check4 = testArray4.SequenceEqual(referrenceArray4);

        return check1 && check2 && check3 && check4;
    }
}
