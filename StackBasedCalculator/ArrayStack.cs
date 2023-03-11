﻿using StackBasedCalculator;

class ArrayStack<T> : IStack<T>
{
    private T[] stackArray = new T[1];
    private int head = -1;
    private int size = 1;

    public void Push(T value)
    {
        if (head == size - 1)
        {
            Array.Resize(ref stackArray, size * 2);
            size *= 2;
        }

        head++;
        stackArray[head] = value;
    }

    public T Pop()
    {
        T valueToReturn = stackArray[head];
        head--;
        return valueToReturn;
    }

    public T Peek()
    {
        return stackArray[head];
    }

    public bool IsEmpty()
    {
        return head == -1;
    }
}
