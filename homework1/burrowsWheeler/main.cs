using BurrowsWheelerAlgorythm;

Console.WriteLine("Enter a string:");
string inputString = Console.ReadLine();

BurrowsWheelerTransform.ApplyForwardTransform(out int index, out string outputString, inputString);

Console.WriteLine($"Output string is:\n\n\"{outputString}\"\n\nand initial string index is {index}.");
Console.WriteLine();

BurrowsWheelerTransform.ApplyReverseTranform(out string initialString, outputString, index);

Console.WriteLine($"Initial string is:\n\n\"{initialString}\"");
