using Stack;

namespace StackBasedCalculator.Tests;

public class StackBasedCalculatorTest
{
    [Test, TestCaseSource(nameof(CorrectStringsStacksAndExpectedResults))]
    public void ValidStringsShouldReturnCorrectResults(string input, IStack<float> stack, float expectedResult)
    {
        float result = StackBasedCalculator.Calculate(input, stack);
        Assert.That(result, Is.EqualTo(expectedResult).Within(0.001));
    }

    [Test, TestCaseSource(nameof(IncorrectStringsAndStacks))]
    public void InvalidStringsShouldThrowArgumentException(string input, IStack<float> stack)
    {
        Assert.Throws<ArgumentException>(() => StackBasedCalculator.Calculate(input, stack));
    }

    [Test, TestCaseSource(nameof(StringsWithDivisionByZeroAndStacks))]
    public void DivisionByZeroShouldThrowDivideByZeroException(string input, IStack<float> stack)
    {
        Assert.Throws<DivideByZeroException>(() => StackBasedCalculator.Calculate(input, stack));
    }

    private static IEnumerable<TestCaseData> Stacks
    => new TestCaseData[]
    {
            new TestCaseData(new ArrayStack<float>()),
            new TestCaseData(new ListStack<float>())
    };

    private static IEnumerable<TestCaseData> StringsWithDivisionByZeroAndStacks
=>
new TestCaseData[]
{
            new TestCaseData("2 2 + 0 /", new ArrayStack<float>()),
            new TestCaseData("14 0 + 13 - 0 * 3 / -15 + 70 + 5 / 0 /", new ListStack<float>()),
            new TestCaseData("10 3 / 3 + 0 /", new ArrayStack<float>()),
            new TestCaseData("0 0 + 0 / 0 +", new ListStack<float>()),
            new TestCaseData("-14 -7 / 0 / 3 4 *", new ArrayStack<float>())
};

    private static IEnumerable<TestCaseData> IncorrectStringsAndStacks
    =>
    new TestCaseData[]
    {
            new TestCaseData("2 2 + 0", new ArrayStack<float>()),
            new TestCaseData("14 0 + 13 - 0 * 3 / -15 + 70 + 5 / 16", new ListStack<float>()),
            new TestCaseData("10 3 / 3 11", new ArrayStack<float>()),
            new TestCaseData("0 0 + 0 - 0 * +", new ListStack<float>()),
            new TestCaseData("-14 -7 / 3 4 * - /", new ArrayStack<float>())
    };

    private static IEnumerable<TestCaseData> CorrectStringsStacksAndExpectedResults
        =>
        new TestCaseData[]
        {
            new TestCaseData("2 2 + ", new ArrayStack<float>(), 4f),
            new TestCaseData("14 0 + 13 - 0 * 3 / -15 + 70 + 5 /", new ListStack<float>(), 11f),
            new TestCaseData("10 3 /", new ArrayStack<float>(), 3.333f),
            new TestCaseData("0 0 + 0 - 0 *", new ListStack<float>(), 0f),
            new TestCaseData("-14 -7 /", new ArrayStack<float>(), 2f)
        };
}