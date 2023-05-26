namespace Stack;

/// <summary>
/// Интерфейс, представляющий стек.
/// Методы: Push, Pop, Peek, IsEmpty.
/// </summary>
/// <typeparam name="T">Тип значений, принимаемых стеком.</typeparam>
public interface IStack<T>
{
    /// <summary>
    /// Добавить в стек переданное значение.
    /// </summary>
    public void Push(T value);

    /// <summary>
    /// Вернуть верхнее значение из стека. Значение при этом удаляется.
    /// </summary>
    public T Pop();

    /// <summary>
    /// Вернуть верхнее значение стека, не удаляя его.
    /// </summary>
    public T Peek();

    /// <summary>
    /// Узнать, пуст ли стек.
    /// </summary>
    /// <returns>True, если стек пуст, и false в противном случае.</returns>
    public bool IsEmpty();
}
