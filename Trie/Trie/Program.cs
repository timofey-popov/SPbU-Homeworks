using Trie;

Trie.Trie myTrie = new();

bool check1 = myTrie.Add("cucumber");
bool check2 = myTrie.Add("cecember");
bool check3 = myTrie.Add("cumberbatch");
bool check4 = myTrie.Add("cucumberbatch");
bool check5 = myTrie.Add("catafalque");
bool check6 = myTrie.Add("cat");

if (check1 && check2 && check3 && check4 && check5 && check6)
{
    Console.WriteLine("All strings added successfully.");
}

Console.WriteLine("Does Trie contain cat? " + myTrie.Contains("cat"));
Console.WriteLine("Does Trie contain cucumbeR? " + myTrie.Contains("cucumbeR"));
Console.WriteLine("How many starts with \"cu\" " + myTrie.HowManyStartsWithPrefix("cu"));
Console.WriteLine("What's the size of Trie? " + myTrie.Size);
