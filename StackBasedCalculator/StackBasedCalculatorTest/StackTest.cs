using Stack;

namespace StackBasedCalculator.Test;

public class StackTest
{
    [Test, TestCaseSource(nameof(Stacks))]
    public void StackConstructorShouldWork(IStack<float> stack)
    {
        Assert.That(stack, Is.Not.Null);
    }

    [Test, TestCaseSource(nameof(Stacks))]
    public void AfterPushShouldNotBeEmpty(IStack<float> stack)
    {
        stack.Push(0);
        Assert.That(!stack.IsEmpty());
    }

    [Test, TestCaseSource(nameof(StacksAndArraysOfNumbers))]
    public void PopAfterSeveralPushesShouldReturnLastValue(IStack<float> stack, float[] arrayOfNumbers)
    {
        foreach (var number in arrayOfNumbers)
        {
            stack.Push(number);
        }

        Assert.That(stack.Pop(), Is.EqualTo(arrayOfNumbers[^1]));
    }

    [Test, TestCaseSource(nameof(StacksAndArraysOfNumbers))]
    public void PeekAfterSeveralPushesShouldReturnLastValue(IStack<float> stack, float[] arrayOfNumbers)
    {
        foreach (var number in arrayOfNumbers)
        {
            stack.Push(number);
        }

        Assert.That(stack.Peek(), Is.EqualTo(arrayOfNumbers[^1]));
    }

    [Test, TestCaseSource(nameof(Stacks))]
    public void PopFromEmptyStackShouldThrowException(IStack<float> stack)
    {
        Assert.Throws<IndexOutOfRangeException>(() => stack.Pop());
    }

    [Test, TestCaseSource(nameof(Stacks))]
    public void PeekFromEmptyStackShouldThrowException(IStack<float> stack)
    {
        Assert.Throws<IndexOutOfRangeException>(() => stack.Peek());
    }

    [Test, TestCaseSource(nameof(Stacks))]
    public void InitialyShouldBeEmpty(IStack<float> stack)
    {
        Assert.That(stack.IsEmpty());
    }

    [Test, TestCaseSource(nameof(Stacks))]
    public void AfterPushAndPeekShouldNotBeEmpty(IStack<float> stack)
    {
        stack.Push(0);
        stack.Peek();
        Assert.That(!stack.IsEmpty());
    }

    [Test, TestCaseSource(nameof(Stacks))]
    public void AfterLastPopShouldBeEmpty(IStack<float> stack)
    {
        stack.Push(0);
        stack.Pop();
        Assert.That(stack.IsEmpty());
    }

    private static IEnumerable<TestCaseData> Stacks
        => new TestCaseData[]
        {
            new TestCaseData(new ArrayStack<float>()),
            new TestCaseData(new ListStack<float>())
        };

    private static IEnumerable<TestCaseData> StacksAndArraysOfNumbers
        => new TestCaseData[]
        {
            new TestCaseData(new ArrayStack<float>(), new float[] { 0, 0, 0, 0, 0 }),
            new TestCaseData(new ArrayStack<float>(), new float[] { -2, -1, 0, 1, 2 }),
            new TestCaseData(new ListStack<float>(), new float[] { 10, 5, 0, -6, -11 }),
            new TestCaseData(new ListStack<float>(), new float[] { 15, 145, -300, 191, 0 })
        };
}