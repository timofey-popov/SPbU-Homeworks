namespace Stack;

public class ListStack<T> : IStack<T>
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
        if (head == -1)
        {
            throw new IndexOutOfRangeException();
        }

        T valueToReturn = listForStack[head];
        listForStack.RemoveAt(head);
        head--;
        return valueToReturn;
    }

    public T Peek()
    {
        if (head == -1)
        {
            throw new IndexOutOfRangeException();
        }

        return listForStack[head];
    }

    public bool IsEmpty()
    {
        return head == -1;
    }
}