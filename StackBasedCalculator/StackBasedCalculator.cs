using Stack;
using System.Data;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace StackBasedCalculator;

public class StackBasedCalculator
{
    private List<string> tokens = new();

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
            throw;
        }

        return (float1, float2);
    } 

    public static float Calculate(string input, IStack<float> operatingStack)
    {
        if (input == null || operatingStack == null)
        {
            throw new ArgumentNullException();
        }

        StringBuilder variableForLongTokens = new();

        for (int i = 0; i < input.Length; i++)
        {
            char token = input[i];

            if (token == '-')
            {
                if (i + 1 < input.Length && input[i + 1] >= '0' && input[i + 1] <= '9')
                {
                    variableForLongTokens.Append(token);
                }
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
                catch (DivideByZeroException)
                {
                    throw;
                }
                catch (IndexOutOfRangeException)
                {
                    throw new ArgumentException("Invalid string provided.");
                }

                operatingStack.Push(dividend / divider);
            }
            else if (token >= '0' && token <= '9')
            {
                variableForLongTokens.Append(token);
            }
            else if (token == ' ')
            {
                if (variableForLongTokens.Length > 0)
                {
                    string newNumberInStringType = variableForLongTokens.ToString();
                    variableForLongTokens.Clear();

                    bool isACorrectNumber = float.TryParse(newNumberInStringType, out float newNumber);

                    if (!isACorrectNumber)
                    {
                        throw new ArgumentException("Invalid string provided.");
                    }

                    operatingStack.Push(newNumber);
                }
            }
            else
            {
                throw new ArgumentException("Invalid symbols in string.");
            }
        }

        float result = operatingStack.Pop();

        if (!operatingStack.IsEmpty())
        {
            throw new ArgumentException("Invalid string provided.");
        }

        return result;
    }
}