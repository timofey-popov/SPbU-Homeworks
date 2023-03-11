using StackBasedCalculator;

class ListStack<T> : IStack<T>
{
    private List<T> listForStack = new();
    private int head = -1;

    public void Push(T value)
    {
        listForStack.Add(value);
        head++;
    }

    public T Pop()
    {
        T valueToReturn = listForStack[head];
        listForStack.RemoveAt(head);
        head--;
        return valueToReturn;
    }

    public T Peek()
    {
        return listForStack[head];
    }

    public bool IsEmpty()
    {
        return head == -1;
    }
}