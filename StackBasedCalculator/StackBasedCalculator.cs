using Stack;
using System.Data;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace StackBasedCalculator;

/// <summary>
/// Калькулятор на основе стека.
/// Поддерживает операции сложения, вычитания, умножения и деления.
/// </summary>
public class StackBasedCalculator
{
    /// <summary>
    /// Переменная для хранения токенов из входной строки.
    /// </summary>
    private List<string> tokens = new();

    /// <summary>
    /// Получить два верхних значения из стека.
    /// Возвращает их в том же порядке, сначала верхний элемент, потом нижележащий.
    /// </summary>
    /// <param name="operatingStack">Стек, из которого нужно извлечь значения.</param>
    /// <returns>Два float числа.</returns>
    /// <exception cref="ArgumentException">Бросается, если извлечь значения из стека не удалось.</exception>
    private static (float, float) GetTwoFloatsFromStack(IStack<float> operatingStack)
    {
        float float1, float2;
        
        try
        {
            float1 = operatingStack.Pop();
            float2 = operatingStack.Pop();
        }
        catch (IndexOutOfRangeException)
        {
            throw new ArgumentException("Invalid string provided.");
        }

        return (float1, float2);
    } 

    /// <summary>
    /// Парсит строку на токены и выполняет указанные операции.
    /// </summary>
    /// <param name="input">Входная строка.</param>
    /// <param name="operatingStack">Стек для осуществления операций.</param>
    /// <returns>Float результат вычислений.</returns>
    /// <exception cref="ArgumentNullException">Бросается, если строка или ссылка на стек была null.</exception>
    /// <exception cref="ArgumentException">Бросается, если в ходе выполнения выяснилось, что строка не была валидной.</exception>
    /// <exception cref="DivideByZeroException">Бросается, если была попытка поделить на ноль.</exception>
    public static float Calculate(string input, IStack<float> operatingStack)
    {
        if (input == null)
        {
            throw new ArgumentNullException(nameof(input));
        }
        if (operatingStack == null)
        {
            throw new ArgumentNullException(nameof(operatingStack));
        }

        // Переменная для постепенного считывания длинных (более одного знака) чисел.
        StringBuilder variableForLongTokens = new();

        // Идём по символам строки.
        for (int i = 0; i < input.Length; i++)
        {
            char token = input[i];

            if (token == '-')
            {
                // Если за минусом следует число - это знаковое число. Начинаем записывать его в специальную переменную.
                if (i + 1 < input.Length && input[i + 1] >= '0' && input[i + 1] <= '9')
                {
                    variableForLongTokens.Append(token);
                }
                // Если это последний символ или за ним следует пробел - это оператор вычитания.
                else if (i == input.Length - 1 || input[i + 1] == ' ')
                {
                    float minuend, subtrahend;

                    try
                    {
                        (subtrahend, minuend) = GetTwoFloatsFromStack(operatingStack);
                    }
                    catch (IndexOutOfRangeException)
                    {
                        throw new ArgumentException("Invalid string provided.");
                    }

                    operatingStack.Push(minuend - subtrahend);
                }
                // Если ничего из вышеперечисленного - строка некорректна.
                else
                {
                    throw new ArgumentException("Invalid string provided.");
                }
            }
            else if (token == '+')
            {
                float summand1, summand2;

                try
                {
                    (summand1, summand2) = GetTwoFloatsFromStack(operatingStack);
                }
                catch (IndexOutOfRangeException)
                {
                    throw new ArgumentException("Invalid string provided.");
                }

                operatingStack.Push(summand1 + summand2);
            }
            else if (token == '*')
            {
                float multiplicand, multiplier;

                try
                {
                    (multiplicand, multiplier) = GetTwoFloatsFromStack(operatingStack);
                }
                catch (IndexOutOfRangeException)
                {
                    throw new ArgumentException("Invalid string provided.");
                }

                operatingStack.Push(multiplicand * multiplier);
            }
            else if (token == '/')
            {
                float dividend, divider;

                try
                {
                    (divider, dividend) = GetTwoFloatsFromStack(operatingStack);
                }
                catch (IndexOutOfRangeException)
                {
                    throw new ArgumentException("Invalid string provided.");
                }

                if (divider == 0)
                {
                    throw new DivideByZeroException();
                }

                operatingStack.Push(dividend / divider);
            }
            else if (token >= '0' && token <= '9')
            {
                variableForLongTokens.Append(token);
            }
            else if (token == ' ')
            {
                // Если токен - пробел, то пытаемся считать число из специальной переменной.
                if (variableForLongTokens.Length > 0)
                {
                    string newNumberInStringType = variableForLongTokens.ToString();
                    variableForLongTokens.Clear();

                    bool isACorrectNumber = float.TryParse(newNumberInStringType, out float newNumber);

                    // Если не удалось сделать из получившейся строки float, то входная строка некорректна.
                    if (!isACorrectNumber)
                    {
                        throw new ArgumentException("Invalid string provided.");
                    }

                    operatingStack.Push(newNumber);
                }
            }
            // Если ни один из вариантов не подошёл - в строке был неизвестный символ.
            else
            {
                throw new ArgumentException("Invalid symbols in string.");
            }

            if (i == input.Length - 1 && variableForLongTokens.Length > 0)
            {
                string newNumberInStringType = variableForLongTokens.ToString();

                bool isACorrectNumber = float.TryParse(newNumberInStringType, out float newNumber);

                // Если не удалось сделать из получившейся строки float, то входная строка некорректна.
                if (!isACorrectNumber)
                {
                    throw new ArgumentException("Invalid string provided.");
                }

                operatingStack.Push(newNumber);
            }
        }

        float result;
        try
        {
            result = operatingStack.Pop();
        }
        catch (IndexOutOfRangeException)
        {
            throw new ArgumentException("Invalid string provided.");
        }

        if (!operatingStack.IsEmpty())
        {
            throw new ArgumentException("Invalid string provided.");
        }

        return result;
    }
}
