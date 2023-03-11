namespace StackBasedCalculator;
class StackBasedCalculator
{
    List<string> tokens = new();
    IStack<int> stackForCalculating = new();

    private string ExtractWholeNumber()

    public static int Calculate(string input)
    {
        for (int i = 0; i < input.Length; i++)
        {
            char token = input[i];

            if (token == '-')
            {
                if (i + 1 < input.Length && input[i + 1] >= '0' && input[i + 1] <= '9')
                {
                    string wholeToken = "-";
                    int counter = i + 1;

                    while (counter < input.Length && input[counter] != ' ')
                    {
                        wholeToken += input[counter];
                    }

                    tokens.Add(wholeToken);
                }
            }

            if (token >= '0' && token <= '9')
            {

            }
        }
    }
}