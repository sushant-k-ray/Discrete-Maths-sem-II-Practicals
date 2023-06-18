<h2 align="center">Solutions for B.Sc.(Hons) Computer Science Sem II 2023 Discrete Maths Practical</h2>
<br>

This project requires a compiler that supports at least C++ 11

## Questions and implementations

<ol>
<li> Create a class SET. Create member functions to perform following set operations:
<ol>
	<li>
    	ismember: check whether an element belongs to the set or not and return value as true/false<br>
    </li>
    <li>
    	powerset: list all the elements of the power set of a set
    </li>
    <li>
    	subset: Check whether one set is a subset of the other or not
    </li>
    <li>
    	union and Intersection of two Sets
    </li>
    <li>
    	complement: Assume Universal Set as per the input elements from the user
    </li>
    <li>
    	set Difference and Symmetric Difference between two sets
    </li>
    <li>
    	cartesian Product of Sets
    </li>
</ol>
Write a menu driven program to perform the above functions on an instance of the SET class
<h4>implementation</h4>
The SET class is designed to work with any domain that is comparable. It stores its elements as a sorted vector in order to reduce time complexity
<h5>Time complexity</h5>
<ul>
<li>Array Initialisation : O(n log n) </li>
<li>Addition : O(log n) </li>
<li>Search : O(log n) </li>
<li>Union : O(n log n) </li>
<li>Intersection: O(n log n) </li>
<li>Check whether given set is a Subset: O(n log n) </li>
<li>Difference and symmetric difference: O(n log n) </li>
<li>Cartesian Product: O(n<sup>2</sup>) </li>
</ul>

</li>
<li>

Create a class RELATION, use Matrix notation to represent a relation. Include member functions to check if the relation is Reflexive, Symmetric, Anti-symmetric, Transitive. Using these functions check whether the given relation is: Equivalence or Partial Order relation or None
<h4>implementation</h4>
The RELATION class is designed to work with any domain that is comparable. It stores its domain as a sorted vector in order to reduce time complexity. Relation is implemented with help of a 2d array(vector) of booleans
<h5>Time complexity</h5>
<ul>
<li>Array Initialisation : O(n log n) </li>
<li>Connect : O(log n) </li>
<li>isReflexive : O(n) </li>
<li>isSymmetric : O(n<sup>2</sup>) </li>
<li>isAntiSymmetric : O(n<sup>2</sup>) </li>
<li>isTransitive : O(n<sup>3</sup>) </li>
<li>isEquivalence : O(n<sup>3</sup>) </li>
<li>isPartialOrder : O(n<sup>3</sup>) </li>
</ul>

</li>
<li>

Write a Program that generates all the permutations of a given set of digits, with or without repetition
<h4>implementation</h4>
The functions use recursion as an approach without recursion would be needlessly complicated.

There exist 2 user facing and 2 internal functions(used for recursion)
<h5>Time complexity</h5>
Time complexity is O(n<sup>m</sup>) regardless of whether repetition is allowed.
Where n is size of character set and m is number of letters per sentence

</li>
<li>

For any number n, write a program to list all the solutions of the equation x<sub>1</sub> + x<sub>2</sub> + x<sub>3</sub> + ... + x<sub>n</sub> = C, where C is a constant (C <= 10) and x<sub>1</sub>, x<sub>2</sub>, x<sub>3</sub>, ... , x<sub>n</sub> are nonnegative integers using brute force strategy.
<h4>implementation</h4>
The function uses recursion as it is ensured that C is less than or equal to 10. There is a check for the value of n(n must be less than 32) to ensure that stack doesn't overflow

</li>
<li>

Write a Program to evaluate a polynomial function. (For example store f(x) = 4n<sup>2</sup> + 2n+ 9 in an array and for a given value of n, say n=5, compute the value of f(n))
<h4>implementation</h4>
Main inputs a P<sub>n</sub> vector from user and calculates result for given value of the variable

</li>
<li>

Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency Matrix representation
<h4>implementation</h4>
The graph is assumed to be an undirected simple graph. It internally uses matrix representation to store the edges
<h5>Time complexity</h5>
<ul>
<li>Graph Initialisation : O(n<sup>2</sup>)</li>
<li>connect : O(1)</li>
<li>isComplete : O(n<sup>2</sup>)</li>
</ul>

</li>
<li>

Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency List representation
<h4>implementation</h4>
The graph is assumed to be an undirected simple graph. It internally uses list representation to store the edges
<h5>Time complexity</h5>
<ul>
<li>Graph Initialisation : O(1)</li>
<li>connect : O(1)</li>
<li>isComplete : O(n)</li>
</ul>

</li>
<li>

Write a Program to accept a directed graph G and compute the in-degree and out-degree of each vertex.
<h4>implementation</h4>
It internally uses matrix representation to store the edges
<h5>Time complexity</h5>
<ul>
<li>Graph Initialisation : O(n<sup>2</sup>)</li>
<li>connect : O(1)</li>
<li>in-degree : O(n)</li>
<li>out-degree : O(n)</li>
</ul>

</li>
</ol>