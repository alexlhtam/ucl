# intro
- functions are associations of each element of one set to a particular element of another set
- sequences are ordered lists of elements
- sequences of particular importance:
  - arithmetic and geometric progressions
  - strings of characters
- summations are the sum of a numerical sequence and procuts are the product
- cardinality measures the relative size of sets

# functions
- let $A$ and $B$ be non-empty sets
  a function f from $A$ to $B$ is an association of `exactly one` element from $B$ to each element of $A$
$$ f(a) = f(b) $$
  if $b$ is the unique element of $B$ associated through $f$ to the element $a$ of $A$

- if $f$ is a function from $A$ to $B$, we write
$$ f: A \longrightarrow B$$
to denote the type of the function

the set $A$ is called the `domain` of $f$

the set $B$ is called the `co-domain` or `target set` of $f$

the `image` of $f$ is the set of values that $f$ can take:
$$ \text{image of } f = \{b \in B \vert b = f(a) \text{ for some } a \in A \}$$

the `inverse image` of an element $b \in B$ is the set of values $a \in A$ that are mapped to $b$ by $f$:
$$ \text{inverse image of } b = \{a \in A \vert f(a) = b\} $$

## equality of functions
- two functions $f$ and $g$ are equal if and only if they:
  - have the `same domain`
  - have the `same co-domain`
  - map each elmeent of the domain to the `same element` of the co-domain
$$ f = g \quad \text{iff} \quad \forall a \in A : f(a) = g(a) $$

## injective function
- a function $f: A \longrightarrow B$ is an `injective function` (or `one-to-one`) iff for all $a_1, a_2 \in A$
$$ a_1 \neq a_2 \longrightarrow f(a_1) \neq f(a_2)$$
or, equivalently, $$f(a_1) = f(a_2) \longrightarrow a_1 = a_2$$

## surjective function
- a function $f: A \longrightarrow B$ is a surjective function (or `onto function`) iff for every $b \in B$ it is possible to find an $a \in A$ such that $f(a) = b$

- or, equivalently, every element of the co domain is the image of at least one element of the domain

## bijective function
- a function $f: A \longrightarrow B$ is a `bijective function` (or a `bijection`) iff $f$ is `both injective and subjective`

## inverse function
- let $f: A \longrightarrow B$ be a bijective function
  the inverse function of $f$ is $f^{-1}: B \longrightarrow A$ such that 
$$ f^{-1}(y) = x \quad \text{iff} \quad y = f(x) $$

## composition of functions
let $g : A \longrightarrow B'$ and $f: B \longrightarrow C$ be functions such that the image of $g$ is a subset of the domain of $f$, i.e. $B' \subseteq B$

the composite function of $f$ with $g$, denoted by $f \circ g: A \longrightarrow C$, is defined for every $a \in A$ as follows:
$$ (f \circ g)(a) = f(g(a)) $$

the function $f \circ g$ is called the `composition of f and g`

## composition and the identity function
- give a domain $A$, the identity function $i_A: A \longrightarrow A$ is deinfed as:
$$ i_A(a) = a, \forall a \in A$$
- theorem: if $f : X \longrightarrow Y$ is a bijective function with inverse $f^{-1}: Y \longrightarrow X$ then
$$ f^{-1} \circ f = i_X \\ f\circ f^{-1}  = i_Y$$
- theorem: if $f: X \longrightarrow Y$ and $g: Y \longrightarrow Z$ are injective functions, then $g \circ f$ is injective

## important funcs: floor and ceiling
- `floor` function associates each real number $x$ with the greatest integer less than or equal to it
  - the value of the floor function is denoted by $\lfloor x \rfloor$
- `ceiling` function associates each real number $x$ with the smallest ingeger less than or equal to it
  - the value of the ceiling function is denoted by $\lceil x \rceil$
- both `floor`, `ceiling` functions have type $\R \longrightarrow \Z$
- useful properties of `floor`/`ceiling` functions:
  1. $\lfloor -x \rfloor = - \lceil x \rceil$
  2. $\lceil -x \rceil = - \lfloor x \rfloor$
  3. $x - 1 < \lfloor x \rfloor \leq x \leq \lceil x \rceil < x + 1$

## partial functions
a `partial` function $f$ from a set $A$ to a set $B$ is an association of each element $a$ in a subset of $A$, called the domain of definition of $f$, to a single element $b$ of $B$

the sets $A$ and $B$ are called the `domain` and `co-domain` of $f$ respectively

we say that $f$ is `undefined` for elements of $A$ that are not in the domain of the definition of $f$

when the domain of definition of $f$ is the entire domain of $A$, we say that $f$ is a total function


# sequences
- a sequence ($\set{a_n}$) is a function defined from the set of natural numbers to an arbitrary set $S$
    each $a_n$ is called a term of the sequence
- an `arithmetic progression` is a sequence of the form 
$$  a, \quad a + d, \quad a + 2d, \quad a + 3d, \quad\dots, \quad a + nd,\quad\dots$$
where the initial term $a$ and the common difference $d$ are real numbers
- a `geometric progression` is a sequence of the form
$$ a, \quad ar, \quad ar^2, \quad ar^3, \quad \dots, \quad ar^n, \quad \dots$$
where the initial term $a$ and the ratio $r$ are real numbers

## explicit formulas for sequences
- an explicit formula defines how to obtain the $k$th term of a sequence directly as a function of $k$
the same sequence can be defined by more than one explicit formula

## defining a sequence from its terms
- common problem: given some intial terms of a sequence, determine a rule to generate the sequence as a whole
- typical ways of defining a sequence are:
  - providing an `explicit formula` for each term of the sequence
  - providing an `algorithm` that generates the sequence
  - providing a `recursive formula` for each term of the sequence 

## providing a recursive formula to generate the sequence
- a recursive formula for a sequence defines each term as a function of previous terms

  recursive definitions are based on recurrence relations 

- a `recurrence relation` for a sequence $\set{a_n}$ is an equation that expresses $a_n$ in terms of one or more previous terms in the sequence for each $n \geq n_0$, where $n_0$ is a non-negative integer

# summations and products

## summations
let $\set{a_k}$ be a sequence
- the sumattion of the terms $a_m, a_m+1, a_m+2, \dots, a_n$ of $\set{a_k}$ is the sum
$$ \sum_{i=m}^n a_i = a_m + a_{m+1} + a_{m+2} + \dots + a_n$$
- two summations are identical if and only if they have identical terms

## products
- the product of the terms  $a_m, a_m+1, a_m+2, \dots, a_n$ of $\set{a_k}$ is the product 
$$ \prod_{i=m}^n a_i = a_m + a_{m+1} + a_{m+2} + \dots + a_n$$
- given two sequence sequence sof real numbers
$$ a_m, a_m+1, a_m+2, \dots \\ b_m, b_m+1, b_m+2, \dots$$
  and let $c$ be any real number
  then the folowing equations are valid for any $n \geq m$:
  1. $ \sum_{k=m}^n a_k + \sum_{k=m}^n b_k = \sum_{k=m}^n (a_k + b_k)$'
  2. $c \cdot \sum_{k=m}^n a_k = \sum_{k=m}^n c \cdot a_k $
  3. $(\prod_{k=m}^n a_k)\cdot(\prod_{k=m}^n b_k) = \prod_{k=m}^n(a_k \cdot b_k)$