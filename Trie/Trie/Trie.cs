using System.Security.Cryptography;

namespace Trie;

public class Trie
{
    public class Vertex
    {
        private Dictionary<char, Vertex> nextVertices;
        private bool isTerminal;

        public Vertex()
        {
            this.nextVertices = new Dictionary<char, Vertex>();
            this.isTerminal = false;
        }

        public Vertex GetNextVertexWithGivenKey(char key)
        {
            try
            {
                return nextVertices[key];
            }
            catch (KeyNotFoundException)
            {
                throw;
            }
        }

        public void AddNewVertex(char key)
        {
            Vertex newVertex = new();
            nextVertices.Add(key, newVertex);
        }

        public bool IsTerminal()
        {
            return isTerminal;
        }

        public void MakeTerminal()
        {
            isTerminal = true;
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

    public bool Add(string element)
    {
        bool isElementInTrie = true;
        Vertex currentVertex = root;

        for (int i = 0; i < element.Length; i++)
        {
            if (currentVertex.IsSuchKey(element[i]))
            {
                currentVertex = currentVertex.GetNextVertexWithGivenKey(element[i]);
            }
            else
            {
                isElementInTrie = false;

                currentVertex.AddNewVertex(element[i]);
                currentVertex = currentVertex.GetNextVertexWithGivenKey(element[i]);
            }
        }

        currentVertex.MakeTerminal();
        return !isElementInTrie;
    }

    public bool Contains(string element)
    {
        Vertex currentVertex = root;

        for (int i = 0; i < element.Length; i++)
        {
            if (currentVertex.IsSuchKey(element[i]) == false)
            {
                return false;
            }
        }

        return currentVertex.IsTerminal();
    }

    bool Remove(string element)
    {
        Vertex currentVertex = root;

        for (int i = 0; i < element.Length; i++)
        {
            if (currentVertex.IsSuchKey(element[i]) == false)
            {
                return false;
            }
            else
            {
                if (currentVertex.GetNumberOfChildren() == 1)
                {

                }

                currentVertex = currentVertex.GetNextVertexWithGivenKey(element[i]);
            }
        }
    }

    private static void RemoveExecution(string element, Vertex vertex, int depth)
    {
        if (depth == element.Length - 1)
        {
            Vertex lastVertex = vertex.GetNextVertexWithGivenKey(element[element.Length - 1]);
        }
    }

    int HowManyStartsWithPrefix(String prefix);

    int Size()
    {

    }
}
