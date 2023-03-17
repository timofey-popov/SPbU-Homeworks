using System.Security.Cryptography;
using Stack;

namespace Trie;

public class Trie
{
    private class Vertex
    {
        private Dictionary<char, Vertex> nextVertices;
        private int numberOfUses;
        private bool isTerminal;

        public Vertex()
        {
            nextVertices = new Dictionary<char, Vertex>();
            numberOfUses = 1;
            isTerminal = false;
        }

        public bool IsTerminal
        {
            get { return isTerminal; }
            set { isTerminal = value; }
        }

        public int NumberOfUses
        {
            get { return numberOfUses; }
        }

        public void IncreaseNumberOfUses()
        {
            numberOfUses++;
        }

        public void DecreaseNumberOfUses()
        {
            if (numberOfUses > 0)
            {
                numberOfUses--;
            }
        }

        // Если не получилось - бросает KeyNotFoundException.
        public Vertex? GetNextVertexWithGivenKey(char key)
        {
            if (nextVertices.TryGetValue(key, out Vertex? value))
            {
                return value;
            }

            return null;
        }

        public void AddNewVertex(char key)
        {
            Vertex newVertex = new();
            nextVertices.Add(key, newVertex);
        }

        public bool IsSuchKey(char key)
        {
            return nextVertices.ContainsKey(key);
        }

        public int GetNumberOfChildren()
        {
            return nextVertices.Count;
        }

        public void DeleteChildVertex(char key)
        {
            nextVertices.Remove(key);
        }
    }

    private Vertex root = new();
    private int size = 0;

    public int Size
    {
        get { return size; }
    }

    public bool Add(string element)
    {
        Vertex? currentVertex = root;

        for (int i = 0; i < element.Length; i++)
        {
            if (currentVertex!.IsSuchKey(element[i]))
            {
                currentVertex = currentVertex.GetNextVertexWithGivenKey(element[i]);
                currentVertex!.IncreaseNumberOfUses();
            }
            else
            {
                currentVertex.AddNewVertex(element[i]);
                size++;
                currentVertex = currentVertex.GetNextVertexWithGivenKey(element[i]);
            }
        }

        bool isElementInTrie = (currentVertex!.IsTerminal);

        currentVertex!.IsTerminal = true;
        return !isElementInTrie;
    }

    public bool Contains(string element)
    {
        Vertex? currentVertex = root;

        for (int i = 0; i < element.Length; i++)
        {
            if (currentVertex!.IsSuchKey(element[i]) == false)
            {
                return false;
            }

            currentVertex = currentVertex.GetNextVertexWithGivenKey(element[i]);
        }

        return currentVertex!.IsTerminal;
    }

    public bool Remove(string element)
    {
        IStack<Vertex> operatingStack = new ListStack<Vertex>();
        Vertex currentVertex = root;

        for (int i = 0; i < element.Length - 1; ++i)
        {
            if (currentVertex.IsSuchKey(element[i]))
            {
                Vertex? nextVertex = currentVertex.GetNextVertexWithGivenKey(element[i]);
                operatingStack.Push(nextVertex);
                currentVertex = nextVertex;
            }
            else
            {
                return false;
            }
        }

        if (!currentVertex.IsTerminal)
        {
            return false;
        }

        currentVertex.IsTerminal = false;
        Vertex childVertex = operatingStack.Pop();

        for (int i = element.Length - 1; i >= 0; --i)
        {
            Vertex parentVertex = operatingStack.Pop();

            if (childVertex.NumberOfUses == 1)
            {
                parentVertex.DeleteChildVertex(element[i]);
                size--;
            }
            else
            {
                childVertex.DecreaseNumberOfUses();
            }

            childVertex = parentVertex;
        }

        return true;

    }

    public int HowManyStartsWithPrefix(string prefix)
    {
        Vertex? currentVertex = root;

        for (int i = 0; i < prefix.Length; ++i)
        {
            if (currentVertex!.IsSuchKey(prefix[i]))
            {
                currentVertex = currentVertex.GetNextVertexWithGivenKey(prefix[i]);
            }
            else
            {
                return 0;
            }
        }

        return currentVertex!.NumberOfUses;
    }
}
