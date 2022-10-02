static void Main(string[] args) 
{
    var logger = ILoggerFactory.CreateLogger("SumOfTwoCSharp");

    var left = args[0];
    var right = args[1];

    left = int.TryParse(left, out var leftInt) 
        ? throw new ArgumentException("Left is not an integer") 
        : left;
    right = int.TryParse(right, out var rightInt) 
        ? throw new ArgumentException("Right is not an integer") 
        : right;
    
    logger.LogInformation($"Left: {leftInt}, Right: {rightInt}");
    var sum = leftInt + rightInt;
    
    logger.LogInformation($"Sum: {sum}");

    Console.ReadKey();
}