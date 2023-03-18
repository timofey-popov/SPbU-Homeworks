namespace Stack;

/// <summary>
/// Реализует интерфейс <see cref="IStack{T}"/> стеком на массиве.
/// </summary>
public class ArrayStack<T> : IStack<T>
{
    private T[] stackArray = new T[1];
    private int head = -1;
    private int size = 1;

    // <inheritdoc/>
    public void Push(T value)
    {
        // Если массив полон - делаем его в два раза больше.
        if (head == size - 1)
        {
            Array.Resize(ref stackArray, size * 2);
            size *= 2;
        }

        head++;
        stackArray[head] = value;
    }

    // <inheritdoc/>
    /// <exception cref="IndexOutOfRangeException">Бросается при попытке Pop из пустого стека.</exception>
    public T Pop()
    {
        if (head == -1)
        {
            throw new IndexOutOfRangeException();
        }

        T valueToReturn = stackArray[head];
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

        return stackArray[head];
    }

    // <inheritdoc/>
    public bool IsEmpty()
    {
        return head == -1;
    }
}
