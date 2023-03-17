using Stack;
using StackBasedCalculator;

Console.WriteLine("Enter an expression in postfix notation:");
string? input = Console.ReadLine();

if (input == null)
{
    Console.WriteLine("No string was read.");
    return;
}

IStack<float>? stackForCalculation = null;

Console.WriteLine("What kind of stack you want to use?\nArray-based stack: press 1\nList-based stack: press 2\n");
int choiseOfStackImplementation = Console.Read();

while (stackForCalculation == null)
{
    switch (choiseOfStackImplementation)
    {
        case (int)StackImplementationOptions.ArrayBasedStack:
            stackForCalculation = new ArrayStack<float>();
            break;
        case (int)StackImplementationOptions.ListBasedStack:
            stackForCalculation = new ListStack<float>();
            break;
        default:
            Console.ReadLine();
            Console.WriteLine("Invalid input. Please try again:\n");
            choiseOfStackImplementation = Console.Read();
            break;
    }
}

float result;

try
{
    result = StackBasedCalculator.StackBasedCalculator.Calculate(input, stackForCalculation);
    Console.WriteLine($"Result:\n{result}");
}
catch (ArgumentNullException ex)
{
    Console.WriteLine($"{ex.ParamName} argument was null.");
}
catch (DivideByZeroException)
{
    Console.WriteLine("Cannot divide by zero.");
}
catch (ArgumentException)
{
    Console.WriteLine("Exception occured:\nInvalid string provided.");
}

enum StackImplementationOptions
{
    ArrayBasedStack = '1',
    ListBasedStack = '2'
}
