Console.WriteLine("Enter an expression in postfix notation:");
string? input = Console.ReadLine();

if (input == null)
{
    Console.WriteLine("No string was read.");
    return;
}

int result = StackBasedCalculator.Calculate(input);

Console.WriteLine($"Result:\n{result}");