namespace Stack;

/// <summary>
/// Реализует интерфейс <see cref="IStack{T}"/> стеком на списке.
/// </summary>
public class ListStack<T> : IStack<T>
{
    private List<T> listForStack = new();
    private int head = -1;

    // <inheritdoc/>
    public void Push(T value)
    { 
        listForStack.Add(value);
        head++;
    }

    // <inheritdoc/>
    /// <exception cref="IndexOutOfRangeException">Бросается при попытке Pop из пустого стека.</exception>
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

    // <inheritdoc/>
    /// <exception cref="IndexOutOfRangeException">Бросается при попытке Peek из пустого стека.</exception>
    public T Peek()
    {
        if (head == -1)
        {
            throw new IndexOutOfRangeException();
        }

        return listForStack[head];
    }

    // <inheritdoc/>
    public bool IsEmpty()
    {
        return head == -1;
    }
}
